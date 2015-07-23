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
#include "json_parser.h"

namespace fdream {
 
JsonValue *
JsonParser::Parse()
{
    JsonTokenizer tokenizer(_text);

    return BuildJsonValue(&tokenzier);
}

JsonValue *             
JsonParser::BuildJsonValue(JsonTokenizer * tokenizer)
{
    return BuildJsonValue(tokenzier, nullptr);
}

JsonValue *             
JsonParser::BuildJsonValue(JsonTokenizer * tokenizer, JsonValue * parent)
{
    JsonValue * value = nullptr;

    if (tokenzier->HasNext()) {
        return nullptr;
    }

    const JsonToken & token = tokenizer->GetNext();
    switch (token.GetId()) {
    case JSON_TOKEN_ID_OBJECT_START:
        value = new JsonObject();
        BuildJsonObject(tokenizer, value);
        break;

    case JSON_TOKEN_ID_OBJECT_STRING:
        value = new JsonStringValue(token.GetContent());
        break;

    case JSON_TOKEN_ID_OBJECT_NUMBER:
        value = new JsonNumberValue(token.GetContent());
        break;

    case JSON_TOKEN_ID_OBJECT_BOOLEAN:
        value = new JsonBooleanValue(token.GetContent());
        break;

    case JSON_TOKEN_ID_OBJECT_NULL:
        value = new JsonNullValue(token.GetContent());
        break;

    default:
        break;
    }
    return value;
}

bool
JsonParser::BuildJsonObject(Tokenizer * tokenizer, JsonObject * object)
{
    JsonValue * value;
    bool isDone, isError;

    isDone = isError = false;
    while (!isDone && !isError && tokenzier->HasNext()) {
        const JsonTken & token = tokenizer.GetNext();
        switch (token.GetId()) {
        case JSON_TOKEN_ID_OBJECT_END:
            isDone = true;
            break; 

        case JSON_TOKEN_ID_NAME:
            value = BuildJsonValue(tokenizer, object);
            object->AddValue(token.GetContent(), value);
            break; 

        default:
            isError = true;
            break; 
        }
    }

    if (isError) {
        return false;
    }

    if (isDone && !tokenizer.HasNext()) {
        return true;
    }

    return false;
}

} // fdream
