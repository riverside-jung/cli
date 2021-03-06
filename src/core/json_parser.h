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
#ifndef _JSON_PARSER_H_
#define _JSON_PARSER_H_

#include "json_value.h"
#include "json_object.h"
#include "json_tokenizer.h"

namespace fdream {

/**
 * \brief
 */
class JsonParser
{
public:
    /**
     *\brief 
     *\param text 
     */
    JsonParser(const std::string & text) : _rootValue(nullptr)
    {}

    JsonValue * Parse();

private:
    JsonValue * _root;
};

} // fdream

#endif // _JSON_PARSER_H_

