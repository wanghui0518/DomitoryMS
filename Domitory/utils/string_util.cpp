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
