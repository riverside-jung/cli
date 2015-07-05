#include "json_value.h"
#include "json_string_value.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace fdream;

TEST(json_string_value_test, GetValue)
{
    std::string value;

    JsonStringValue jsonStringValue1("Hello");
    jsonStringValue1.GetValue(value);

    EXPECT_EQ("Hello", value);

    JsonStringValue jsonStringValue2("World");
    jsonStringValue2.GetValue(value);

    EXPECT_EQ("World", value);
}

