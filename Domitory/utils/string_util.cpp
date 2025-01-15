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

bool string_util::is_empty(std::string &str)
{
	return str.size() > 0 ? true : false;
}

std::string string_util::format(const std::string fmt, ...)
{
	std::string str_ret;
	int size = ((int)fmt.size()) * 2 + 50;   // Use a rubric appropriate for your code
	va_list ap;
	while (true)
	{
		// Maximum two passes on a POSIX system...
		str_ret.resize(size);
		va_start(ap, fmt);
		int n = vsnprintf((char *)str_ret.data(), size, fmt.c_str(), ap);
		va_end(ap);
		if (n > -1 && n < size)
		{
			// Everything worked
			str_ret.resize(n);
			return str_ret;
		}

		if (n > -1)  // Needed size returned
			size = n + 1;   // For null char
		else
			size *= 2;      // Guess at a larger size (OS specific)
	}

	return str_ret;
}

std::string& string_util::append_format(std::string& str, const std::string fmt, ...)
{
	std::string str_ret;
	int size = ((int)fmt.size()) * 2 + 50;   // Use a rubric appropriate for your code
	va_list ap;
	while (true)
	{
		// Maximum two passes on a POSIX system...
		str_ret.resize(size);
		va_start(ap, fmt);
		int n = vsnprintf((char *)str_ret.data(), size, fmt.c_str(), ap);
		va_end(ap);
		if (n > -1 && n < size)
		{
			// Everything worked
			str_ret.resize(n);
			str += str_ret;
			return str;
		}

		if (n > -1)  // Needed size returned
			size = n + 1;   // For null char
		else
			size *= 2;      // Guess at a larger size
	}

	str += str_ret;
	return str;
}

std::string& string_util::erase(std::string& str, char ch)
{
	if (str.size() <= 0) return str;
	str.erase(remove_if(str.begin(), str.end(), bind2nd(equal_to<char>(), ch)), str.end()); //
	return str;
}

bool string_util::replace(std::string& str, const std::string& from, const std::string& to)
{
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos) return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

void string_util::replace_all(std::string& str, const std::string& from, const std::string& to)
{
	if (from.empty()) return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); //In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}

int string_util::string_i_cmp(std::string lhs, std::string rhs)
{
	return _stricmp(lhs.c_str(), rhs.c_str());
}

void string_util::split(std::string& str, std::string pattern, vector<std::string>& arrout)
{
	arrout.clear();
	size_t idx = 0, pos = 0;
	size_t size = str.size();
	for (idx = 0; idx < size; ++idx)
	{
		pos = str.find(pattern, idx);
		if (pos != std::string::npos)
		{
			std::string s = str.substr(idx, pos - idx);
			if (s.size() > 0) arrout.push_back(s);
			idx = pos + pattern.size() - 1;
		}
		else
		{
			if (idx < size)
			{
				std::string s = str.substr(idx, str.size() - idx);
				if (s.size() > 0) arrout.push_back(s);
				break;
			}
		}
	}
}

std::string string_util::join(std::vector<string>& arr_string, std::string pattern)
{
	string str_ret;
	if (arr_string.size() <= 0) return "";
	for (size_t idx = 0; idx < arr_string.size(); ++idx)
	{
		if (str_ret.size() <= 0) str_ret = arr_string[idx];
		else str_ret += pattern + arr_string[idx];
	}

	return str_ret;
}

std::wstring string_util::a2w_string(std::string str_a)
{
	return gbk2unicode(str_a);
}

std::string string_util::w2a_string(std::wstring str_w)
{
	return unicode2gbk(str_w);
}

string_t string_util::to_string(std::string str_a)
{
#ifdef _UNICODE
	std::wstring str_ret = a2w_string(str_a);
#else
	std::string str_ret = str_a;
#endif
	return str_ret;
}

string_t string_util::to_string(std::wstring str_w)
{
#ifdef _UNICODE
	std::wstring str_ret = str_w;
#else
	std::string str_ret = w2a_string(str_w);
#endif
	return str_ret;
}
