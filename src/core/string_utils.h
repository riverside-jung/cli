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
#ifndef _STRING_UTILS_H_
#define _STRING_UTILS_H_

#include <string>
#include <cstdlib>
#include <vector>

namespace fdream {

class StringUtils
{
private:
    std::vector<std::string> &
    split(const std::string & str, char delimiter, std::vector<std::string> & stringsDelimeted);

public:
    /**
     * \brief Check if the specified string is empty("")  
     * \param str the string to check
     * \returns true if the string is whitespace or empty
     */
    static bool IsEmpty(const std::string & str);

    /**
     * \brief Check if the specified string is whitespace, empty("")
     * \param str the string to check
     * \returns true if the string is whitespace or empty
     */
    static bool IsBlank(const std::string & str);

    /**
     * \brief Returns a copy of the string, with leading whitesace removed
     */
    static std::string TrimLeft(const std::string & str);

    /**
     * \brief Returns a copy of the string, with trailing whitesace removed
     */
    static std::string
    TrimRight(const std::string & str);

    /**
     * \brief Returns a copy of the string, with leading and trailing whitesace removed
     */
    static std::string
    Trim(const std::string & str);

    /**
     * \brief Converts all of the character in the specified string to upper case
     */
    static std::string
    ToUpperCase(const std::string & str);

    /**
     * \brief Converts all of the character in the specified string to upper case,
     *        using the conversion rules specified by the given locale
     */
    static std::string
    ToUpperCase(const std::string & str, const std::locale & locale);

    /**
     * \brief Converts all of the character in the specified string to lower case
     */
    static std::string
    ToLowerCase(const std::string & str);

    /**
     * \brief Converts all of the character in the specified string to lower case
     *        using the conversion rules specified by the given locale
     */
    static std::string
    ToLowerCase(const std::string & str, const std::locale & locale);

    /**
     * \brief Converts all of the character in the specified string to lower case
     */
    static bool
    AreEqual(const std::string & rhs, const std::string & lhs);

    /**
     * \brief Converts all of the character in the specified string to lower case
     */
    static bool
    AreEqualIgnoreCase(const std::string & rhs, const std::string & lhs);

    /**
     * \brief Checks if the string contains a search character
     */
    static bool
    Contains(const std::string & str, char searchChar);

    /**
     * \brief Checks if the string contains a search string
     */
    static bool
    Contains(const std::string & str, const std::string & searchStr);

    static std::vector<std::string>
    split(const std::string & str, char delimiter);
};

} // fdream

#endif //_STRING_UTILS_H_
