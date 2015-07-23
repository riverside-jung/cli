/*
 * Copyright (c) 2015 FDREAM, Jay Jung
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * Author: Jay Jung <riverside.jung@gmail.com>
 */

#include "string_utils.h"

#include <algorithm>
#include <locale>
#include <sstream>

namespace fdream {

 
bool StringUtils::IsEmpty(const std::string & str)
{
    return (str.length() == 0);
}

bool StringUtils::IsBlank(const std::string & str)
{
    if (str.length() == 0)
        return true;

    for (char ch : str) {
        if (!std::isspace(ch))
            return false;
    }

    return true;
}

std::string StringUtils::TrimLeft(const std::string & str)
{
    std::string trimmedStr;

    std::for_each(str.begin(), str.end(),
                  [ &trimmedStr ](const char & ch) {
                      if (trimmedStr.length()) {
                        trimmedStr.push_back(ch);
                      } else {
                          if (!std::isspace(ch)) 
                              trimmedStr.push_back(ch); 
                      }                          
                  });        

    return trimmedStr;
}

std::string StringUtils::TrimRight(const std::string & str)
{
    std::string trimmedStr;

    std::for_each(str.rbegin(), str.rend(),
                  [ &trimmedStr ](const char & ch) {
                      if (trimmedStr.length()) {
                        trimmedStr.insert(trimmedStr.begin(), ch);
                      } else {
                          if (!std::isspace(ch)) 
                              trimmedStr.insert(trimmedStr.begin(), ch); 
                      }                          
                  });        

    return trimmedStr;
}

std::string StringUtils::Trim(const std::string & str)
{
    return TrimLeft(TrimRight(str));
}

std::string StringUtils::ToUpperCase(const std::string & str)
{
    std::string upperCaseStr;

    std::for_each(str.begin(), str.end(),
                  [ &upperCaseStr ] (const char & ch) {
                      upperCaseStr.push_back(std::toupper(ch));
                  });

    return upperCaseStr;
}

std::string StringUtils::ToUpperCase(const std::string & str, const std::locale & locale)
{
    std::string upperCaseStr;

    std::for_each(str.begin(), str.end(),
                  [ &upperCaseStr, &locale ](const char & ch) {
                      upperCaseStr.push_back(std::toupper(ch, locale));
                  });

    return upperCaseStr;
}

std::string StringUtils::ToLowerCase(const std::string & str)
{
    std::string lowerCaseStr;

    std::for_each(str.begin(), str.end(),
                  [ &lowerCaseStr ](const char & ch) {
                      lowerCaseStr.push_back(std::tolower(ch));
                  });

    return lowerCaseStr;
}

std::string StringUtils::ToLowerCase(const std::string & str, const std::locale & locale)
{
    std::string lowerCaseStr;

    std::for_each(str.begin(), str.end(),
                  [ &lowerCaseStr, &locale ](const char & ch) {
                      lowerCaseStr.push_back(std::tolower(ch, locale));
                  });

    return lowerCaseStr;
}

bool StringUtils::AreEqual(const std::string & rhs, const std::string & lhs)
{
    if (rhs.length() != lhs.length())
        return false;

    for (std::size_t index = 0; index < rhs.length(); index++) {
        if (rhs.at(index) != lhs.at(index))
            return false; 
    }

    return true; 
}

bool StringUtils::AreEqualIgnoreCase(const std::string & rhs, const std::string & lhs)
{
    if (rhs.length() != lhs.length())
        return false;

    for (std::size_t index = 0; index < rhs.length(); index++) {
        if (std::toupper(rhs.at(index)) != std::toupper(lhs.at(index)))
            return false; 
    }

    return true; 
}

bool StringUtils::Contains(const std::string & rhs, char searchChar) 
{
    return (rhs.find(searchChar) != std::string::npos);
}

bool StringUtils::Contains(const std::string & rhs, const std::string & searchStr)
{
    return (rhs.find(searchStr) != std::string::npos);
}

std::vector<std::string> &
split(const std::string & str, char delimeter, std::vector<std::string> & stringsDelimeted) 
{
    std::stringstream ss;
    std::string item;

    while (std::getline(ss, item, delimeter)) {
        if (item.length() > 0) {
            stringsDelimeted.push_back(item);
        }
    }
    return stringsDelimeted;
}

std::vector<std::string>
split(const std::string & str, char delimeter)
{
    std::vector<std::string> stringsDelimeted; 
    split(str, delimeter, stringsDelimeted);
    return stringsDelimeted; 
}

} // fdream

