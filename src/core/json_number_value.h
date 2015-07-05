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
#ifndef _JSON_NUMBER_VALUE_H_
#define _JSON_NUMBER_VALUE_H_

#include <string>

namespace fdream {

class JsonValue;

/**
 * \brief
 */
class JsonNumberValue : public JsonValue
{
public:
    virtual ~JsonNumberValue() = default; 

    /**
     * \brief
     * \param value
     */
    JsonNumberValue(const std::string & value)
    {
        _value = std::stod(value);
    }
    
    /**
     * \brief
     * \param value
     * \returns always true
     */
    virtual bool GetValue(uint32_t & value)
    {
        value = static_cast<uint32_t >(_value);
        return true;
    }

private:
    double _value;
};

} // fdream

#endif //_JSON_NUMBER_VALUE_H_
