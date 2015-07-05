#include "json_value.h"
#include "json_number_value.h"
#include "json_string_value.h"
#include "json_object.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace fdream;

TEST(json_object_test, AddValue)
{
    JsonObject jsonObject;

    jsonObject.AddValue("method", new JsonStringValue("get"));
    jsonObject.AddValue("url", new JsonStringValue("//localhost/protocols/ip"));
    jsonObject.AddValue("version", new JsonNumberValue("13579"));

    std::string method;
    jsonObject.GetValue("method", method);
    EXPECT_EQ("get", method);

    std::string url;
    jsonObject.GetValue("url", url);
    EXPECT_EQ("//localhost/protocols/ip", url);

    uint32_t version = 0;
    jsonObject.GetValue("version", version);
    EXPECT_EQ(13579, version);
}

