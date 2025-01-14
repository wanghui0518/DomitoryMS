#pragma once
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <xfunctional>
#include <iostream>
#include <xlocbuf>
#include <codecvt>

using namespace std;

#ifdef _UNICODE
#define string_t wstring
#else
#define string_t string
#endif

#define CODE_CONVERT_USE_WIN32

class string_util
{
public:
	string_util();
	~string_util();
        static std::string& trim_l(std::string &str);
        static std::string& trim_r(std::string &str);
        static std::string& trim(std::string &str);
	static std::string& reverse(std::string &str);

	static std::string& to_upper(std::string &str);
	static std::string to_upper_copy(std::string &str);

	static std::string& to_lower(std::string &str);
	static std::string to_lower_copy(std::string &str);

	static std::string left(std::string &str, size_t n_count);
	static std::string right(std::string &str, size_t n_count);
	static std::string mid(std::string &str, size_t i_start, size_t n_count);
	static std::string mid_l_r(std::string &str, std::string str_left, std::string str_right, bool b_inc_start = false, bool b_inc_end = false);
	static std::string span_including(std::string& str, std::string str_key);
	static std::string span_excluding(std::string& str, std::string str_key);

	static bool start_with(std::string &str, std::string str_begin);
	static bool end_with(std::string &str, std::string str_end);
	static bool contain(std::string &str, std::string str_sub);
	static bool is_empty(std::string &str);

	static std::string format(const std::string fmt, ...);
	static std::string& append_format(std::string& str, const std::string fmt, ...);
	static std::string& erase(std::string& str, char ch);
	static bool replace(std::string& str, const std::string& from, const std::string& to);
	static void replace_all(std::string& str, const std::string& from, const std::string& to);
	static int string_i_cmp(std::string lhs, std::string rhs);
	static void split(std::string& str, std::string pattern, vector<std::string>& arrout);
	static std::string join(std::vector<string>& arr_string, std::string pattern = "");

	static std::wstring a2w_string(std::string str_a);
	static std::string w2a_string(std::wstring str_w);

	static string_t to_string(std::string str_a);
	static string_t to_string(std::wstring str_w);
};

