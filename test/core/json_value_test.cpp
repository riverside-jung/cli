#include "json_value.h"
#include "json_string_value.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace fdream;

TEST(json_value_test, GetValue)
{
    bool result = true;
    uint32_t intValue = 10;   
    std::string stringValue("");

    JsonValue jsonValue1;
    result = jsonValue1.GetValue(stringValue);

    EXPECT_EQ(result, false);
    EXPECT_EQ(stringValue, "");

    result = jsonValue1.GetValue(intValue);

    EXPECT_EQ(result, false);
    EXPECT_EQ(intValue, 10);

    result = false;
    intValue = 20;   
    stringValue = "hello";

    JsonValue jsonValue2;
    result = jsonValue2.GetValue(stringValue);

    EXPECT_EQ(result, false);
    EXPECT_EQ(stringValue, "hello");

    result = jsonValue2.GetValue(intValue);

    EXPECT_EQ(result, false);
    EXPECT_EQ(intValue, 20);
}
