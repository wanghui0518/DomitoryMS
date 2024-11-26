#include "stdafx.h"
#include "string_util.h"
#include <windows.h>


string_util::string_util()
{
}

string_util::~string_util()
{
}

std::string& string_util::trim_l(std::string &str)
{
	if (str.empty()) return str;

	str.erase(0, str.find_first_not_of(" \n\r\t"));
	return str;
}

std::string& string_util::trim_r(std::string &str)
{
	if (str.empty()) return str;

	str.erase(str.find_last_not_of(" \n\r\t") + 1);
	return str;
}

std::string& string_util::trim(std::string &str)
{
	return trim_l(trim_r(str));
}

std::string& string_util::reverse(std::string &str)
{
	std::reverse(str.begin(), str.end());
	return str;
}


std::string& string_util::to_upper(std::string &str)
{
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}

std::string string_util::to_upper_copy(std::string &str)
{
	std::string string_str_ret = str;
	transform(string_str_ret.begin(), string_str_ret.end(), string_str_ret.begin(), ::toupper);
	return string_str_ret;
}

std::string& string_util::to_lower(std::string &str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

std::string string_util::to_lower_copy(std::string &str)
{
	std::string string_str_ret = str;
	transform(string_str_ret.begin(), string_str_ret.end(), string_str_ret.begin(), ::tolower);
	return string_str_ret;
}

std::string string_util::left(std::string &str, size_t n_count)
{
	if (str.size() <= 0 || n_count <= 0) return "";
	if (str.size() <= n_count) return str;
	return str.substr(0, n_count);
}

std::string string_util::right(std::string &str, size_t n_count)
{
	if (str.size() <= 0 || n_count <= 0) return "";
	if (str.size() <= n_count) return str;
	return str.substr(str.size() - n_count, n_count);
}

std::string string_util::mid(std::string &str, size_t i_start, size_t n_count)
{
	if (str.size() <= 0 || n_count <= 0 || i_start >= str.size()) return "";
	return str.substr(i_start, n_count);
}

std::string string_util::mid_l_r(std::string &str, std::string str_left, std::string str_right, bool b_inc_start, bool b_inc_end)
{
	if (str.size() <= 0 || str_left.size() <= 0 || str_right.size() <= 0 || str.size() < str_left.size() || str.size() < str_right.size()) return "";

	std::string str_ret;
	std::string::size_type pos_begin = str.find(str_left);
	if (pos_begin != std::string::npos)
	{
		if (!b_inc_start) pos_begin += str_left.size();

		std::string::size_type pos_end = str.find(str_right, pos_begin + 1);
		if (pos_end != std::string::npos)
		{
			if (!b_inc_end)
			{
				str_ret = str.substr(pos_begin, pos_end - pos_begin);
			}
			else{
				pos_end += str_right.size();
				str_ret = str.substr(pos_begin, pos_end - pos_begin);
			}
		}
	}

	return str_ret;
}

std::string string_util::span_including(std::string& str, std::string str_key)
{
	if (str.size() <= 0 || str_key.size() <= 0) return str;

	std::string str_ret;
	std::size_t found = str.find_first_of(str_key);
	while (found != std::string::npos)
	{
		str_ret.push_back(str[found]);
		found = str.find_first_of(str_key, found + 1);
	}

	return str_ret;
}

std::string string_util::span_excluding(std::string& str, std::string str_key)
{
	if (str.size() <= 0 || str_key.size() <= 0) return str;

	std::string str_ret;
	std::size_t found = str.find_first_not_of(str_key);
	while (found != std::string::npos)
	{
		str_ret.push_back(str[found]);
		found = str.find_first_not_of(str_key, found + 1);
	}

	return str_ret;
}

bool string_util::start_with(std::string &str, std::string str_begin)
{
	if (str.size() <= 0 || str_begin.size() <= 0) return false;
	bool startwith = str.compare(0, str_begin.size(), str_begin) == 0;
	return startwith;
}

bool string_util::end_with(std::string &str, std::string str_end)
{
	if (str.size() <= 0 || str_end.size() <= 0) return false;
	bool endwith = str.compare(str.size() - str_end.size(), str_end.size(), str_end) == 0;
	return endwith;
}

bool string_util::contain(std::string &str, std::string str_sub)
{
	if (str.size() <= 0 || str_sub.size() <= 0 || str_sub.size() > str.size()) return false;
	std::string::size_type pos = str.find(str_sub);
	if (pos == std::string::npos) return false;
	return true;
}
