#include "json_value.h"
#include "json_number_value.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace fdream;

TEST(json_number_value_test, GetValue)
{
    bool result;
    uint32_t value;

    /* Test 1 */
    JsonNumberValue jsonNumberValue1("1234");
    result = jsonNumberValue1.GetValue(value);

    EXPECT_EQ(result, true);
    EXPECT_EQ(value, 1234);

    /* Test 2 */
    JsonNumberValue jsonNumberValue2("56789");
    result = jsonNumberValue2.GetValue(value);

    EXPECT_EQ(result, true);
    EXPECT_EQ(value, 56789);
}

