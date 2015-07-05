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
#ifndef _JSON_VALUE_H_
#define _JSON_VALUE_H_

#include <string>

namespace fdream {

/**
 * \brief
 */
class JsonValue
{
public:
    virtual ~JsonValue() = default; 

    /**
     * \brief
     * \param value
     * \returns always false
     */
    virtual bool GetValue(std::string & value)
    {
        return false;
    }

    /**
     * \brief
     * \param value
     * \returns always false
     */
    virtual bool GetValue(uint32_t & value)
    {
        return false;
    }

    /**
     * \brief
     * \param value
     * \returns always false
     */
    virtual bool GetValue(bool & value)
    {
        return false;
    }

    /**
     * \brief
     * \param value
     * \returns always false
     */
    virtual bool IsNull()
    {
        return false;
    }
};

} // fdream

#endif //_JSON_VALUE_H_
