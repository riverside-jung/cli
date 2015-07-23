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
 * Authors: Jay Jung <riverside.jung@gmail.com>
 */
#include "string_utils.h"
#include "json_value.h"
#include "json_tokenizer.h"

#include <iostream>
#include <sstream>

namespace fdream {

const std::vector<char> JsonTokenizer::_ignoreChars = { ' ', '\t', '\n', '\r' };
const std::vector<char> JsonTokenizer::_keywordChars = { ':', ',' };

JsonTokenizer::JsonTokenizer(const std::string & text)
    : _text(text), _cursor(0), _next(0)
{
    BuildJsonValue();
}

JsonTokenizer::~JsonTokenizer()
{
    for (JsonToken * token : _tokens)
        delete token;
}

JsonTokenizer::JsonTokenStringType
JsonTokenizer::GetNextTokenString(std::string & tokenString)
{
    JsonTokenStringType type;
    std::size_t begin, end, length;

    begin = _text.find_first_not_of(" /t/n", _cursor);
    if (begin == std::string::npos)
        return JSON_TOKEN_STRING_INVALID;

    length = 0; 
    char firstChar = _text.at(begin);
    if (firstChar == '{') {
        end = begin + 1;
        length = 1;
        type =  JSON_TOKEN_STRING_OBJECT_START;
    } else if (firstChar == '}') {
        end = begin + 1;
        length = 1;
        type =  JSON_TOKEN_STRING_OBJECT_END;
    } else if (firstChar == '[') {
        end = begin + 1;
        length = 1;
        type =  JSON_TOKEN_STRING_ARRAY_START;
    } else if (firstChar == ']') {
        end = begin + 1;
        length = 1;
        type =  JSON_TOKEN_STRING_ARRAY_END;
    } else if (firstChar == ',') {
        end = begin + 1;
        length = 1;
        type =  JSON_TOKEN_STRING_NAME_VALUE_END;
    } else if (firstChar == ':') {
        end = begin + 1;
        length = 1;
        type =  JSON_TOKEN_STRING_NAME_VALUE_SEPARATOR;
    } else if (firstChar == '\"') {
        ++begin;
        for (end = begin; end < _text.length(); ++end) {
            if (firstChar ==  _text.at(end))
                break;
            length++;
        }
        ++end;
        type =  JSON_TOKEN_STRING_WITH_QUOTATION;
    } else {
        for (end = begin; end < _text.length(); ++end) {
            if (StringUtils::Contains(" \t\n:,}", _text.at(end)))
                break;

            length++;
        }
        type =  JSON_TOKEN_STRING_WITHOUT_QUOTATION;
    }

    _cursor = end;
    tokenString = _text.substr(begin, length);
    return type;
}

bool
JsonTokenizer::BuildJsonName()
{
    bool result = false;
    std::string name;
    
    if (GetNextTokenString(name) == JSON_TOKEN_STRING_WITH_QUOTATION) {
        _tokens.push_back(new JsonToken(JSON_TOKEN_ID_NAME, name));
        result = true;
    }

    return result;
}

bool
JsonTokenizer::BuildJsonValue()
{
    bool result = false;
    std::string value;
    JsonTokenStringType tokenStringType;

    tokenStringType = GetNextTokenString(value);
    if (tokenStringType == JSON_TOKEN_STRING_OBJECT_START) {
        result = BuildJsonObjectValue();
    } else if (tokenStringType == JSON_TOKEN_STRING_WITH_QUOTATION) {
        result = BuildJsonStringValue(value);
    } else {
        result = BuildJsonNonStringValue(value);
    }

    return result; 
}
  
bool
JsonTokenizer::BuildJsonObjectValue()
{
    _tokens.push_back(new JsonToken(JSON_TOKEN_ID_OBJECT_START, "{"));

    JsonTokenStringType type; 
    std::string keyword;
    while (BuildJsonName()) {
        type = GetNextTokenString(keyword);
        if (type == JSON_TOKEN_STRING_NAME_VALUE_SEPARATOR) {
            if (!BuildJsonValue())
                break;
        }
        type = GetNextTokenString(keyword);
        if (type != JSON_TOKEN_STRING_NAME_VALUE_END)
            break;
    }
    _tokens.push_back(new JsonToken(JSON_TOKEN_ID_OBJECT_START, "}"));
    return true;
}
  
bool
JsonTokenizer::BuildJsonStringValue(std::string value)
{
    _tokens.push_back(new JsonToken(JSON_TOKEN_ID_STRING, value));
    return true;
}

bool
JsonTokenizer::BuildJsonNonStringValue(std::string value)
{
    if (StringUtils::AreEqualIgnoreCase(value, "true")) {
        _tokens.push_back(new JsonToken(JSON_TOKEN_ID_BOOLEAN, value));
    } else if (StringUtils::AreEqualIgnoreCase(value, "false")) {
        _tokens.push_back(new JsonToken(JSON_TOKEN_ID_BOOLEAN, value));
    } else if (StringUtils::AreEqualIgnoreCase(value, "null")) {
        _tokens.push_back(new JsonToken(JSON_TOKEN_ID_NULL, value));
    } else {
        _tokens.push_back(new JsonToken(JSON_TOKEN_ID_NUMBER, value));
    }
    return true;
}

bool
JsonTokenizer::HasNext()
{
    if (_next < _tokens.size())
        return true;

    return false;
}

const JsonToken &
JsonTokenizer::GetNext()
{
    return *_tokens[_next++];    
}

std::string
JsonTokenizer::ToString()
{
    std::stringstream ss;

    for (JsonToken * token : _tokens)
        ss << "ID: " << token->GetId() << " , Content: " << token->GetContent() << std::endl;

    return ss.str();
}

} // fdream
