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
#ifndef _JSON_TOKEN_H_
#define _JSON_TOKEN_H_

#include <string>

namespace fdream {

enum JsonTokenId
{
    JSON_TOKEN_ID_OBJECT_START,
    JSON_TOKEN_ID_OBJECT_END,
    JSON_TOKEN_ID_ARRAY_START,
    JSON_TOKEN_ID_ARRAY_END,
    JSON_TOKEN_ID_NAME,
    JSON_TOKEN_ID_STRING,    
    JSON_TOKEN_ID_NUMBER,    
    JSON_TOKEN_ID_BOOLEAN,    
    JSON_TOKEN_ID_NULL,    
};

/**
 * \brief
 */
class JsonToken
{
public:
    JsonToken(JsonTokenId id, const std::string & content)
        : _id(id), _content(content)
    {} 

    JsonTokenId GetId() const
    {
        return _id;
    }

    const std::string & GetContent() const
    {
        return _content;
    }

private:
    JsonTokenId _id;
    std::string _content;
};

} // fdream

#endif // _JSON_TOKEN_H_

