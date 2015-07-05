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
#include "json_value.h"
#include "json_object.h"

using namespace fdream;
 
bool
JsonObject::AddValue(const std::string & name, JsonValue * value)
{
    std::map<std::string, JsonValue * >::iterator it;

    it = _members.find(name);
    if (it != _members.end()) {
        //LOG_I("the given name '%s' already exists\n", name.c_str()); 
        return false;
    }

    _members.insert(std::pair<std::string, JsonValue *>(name, value));
    return true;
}

JsonValue *
JsonObject::GetValue(const std::string & name)
{
    std::map<std::string, JsonValue * >::iterator it;

    it = _members.find(name);
    if (it == _members.end()) {
        return NULL;
    }

    return it->second;
}

bool
JsonObject::GetValue(const std::string & name, std::string & value)
{
    JsonValue * memberValue = GetValue(name);

    if (memberValue) {
        memberValue->GetValue(value);
    }

    return false;
}

bool
JsonObject::GetValue(const std::string & name, uint32_t & value)
{
    JsonValue * memberValue = GetValue(name);

    if (memberValue) {
        return memberValue->GetValue(value);
    }

    return false;
}

bool
JsonObject::IsNull(const std::string & name)
{
    JsonValue * memberValue = GetValue(name);

    if (memberValue) {
        return memberValue->IsNull();
    }

    return false;
}

