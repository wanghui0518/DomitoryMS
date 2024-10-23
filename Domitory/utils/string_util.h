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

class string_util
{
public:
	string_util();
	~string_util();
};

