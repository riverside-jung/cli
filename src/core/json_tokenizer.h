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
#ifndef _JSON_TOKENIZER_H_ 
#define _JSON_TOKENIZER_H_

#include "json_token.h"
#include <string>
#include <vector>

namespace fdream {

/**
 * \brief
 */
class JsonTokenizer
{
public:
    JsonTokenizer(const std::string & text);
    virtual ~JsonTokenizer();

    /**
     * \brief
     */
    const JsonToken & GetNext();

    /**
     * \brief
     */
    bool HasNext();

    /**
     * \brief
     */
    std::string ToString();

private:
    enum JsonTokenStringType
    {
        JSON_TOKEN_STRING_INVALID,
        JSON_TOKEN_STRING_OBJECT_START,
        JSON_TOKEN_STRING_OBJECT_END,
        JSON_TOKEN_STRING_ARRAY_START,
        JSON_TOKEN_STRING_ARRAY_END,
        JSON_TOKEN_STRING_WITH_QUOTATION,
        JSON_TOKEN_STRING_WITHOUT_QUOTATION,
        JSON_TOKEN_STRING_NAME_VALUE_SEPARATOR,
        JSON_TOKEN_STRING_NAME_VALUE_END,
    };

    JsonTokenStringType GetNextTokenString(std::string & tokenString);

    /**
     * \brief
     */
    bool BuildJsonName();

    /**
     * \brief
     */
    bool BuildJsonValue();

    /**
     * \brief
     */
    bool BuildJsonObjectValue();

    /**
     * \brief
     */
    bool BuildJsonArrayValue();

    /**
     * \brief
     */
    bool BuildJsonStringValue(std::string value);
    /**
     * \brief
     */
    bool BuildJsonNonStringValue(std::string value);

    std::string _text;
    std::size_t _cursor;
    std::size_t _next;
    std::vector<JsonToken *> _tokens;

    static const std::vector<char> _ignoreChars;
    static const std::vector<char> _keywordChars;
};
 
} // fdream

#endif // _JSON_TOKENIZER_H_

