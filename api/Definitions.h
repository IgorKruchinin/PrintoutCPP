#pragma once

#include <vector>
#include <string>

template <typename T>
using serialContainer = std::vector<T>;

using Date = std::string; // Find the date container!

using String = std::string;

using Int = int;

using ID = long;

#define DATE_FORMAT_STRING "yyyy-MM-dd"

#define DATE_FORMAT_VIEW_STRING "dd.MM.yyyy"
