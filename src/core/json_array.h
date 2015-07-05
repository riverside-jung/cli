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
 * Authors: Jay Jung <riverside.jung@gmail.com>,
 */
#ifndef _JSON_ARRAY_H_
#define _JSON_ARRAY_H_

namespace fdream {

/**
 * \brief
 */
class JsonArray
{
public:
    virtual ~JsonArray() = default;

private:
    std::vector<JsonValue *> _values;
};

} //fdream

#endif // _JSON_ARRAY_H_

