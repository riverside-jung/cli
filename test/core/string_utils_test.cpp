#include "string_utils.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace fdream;

TEST(string_utils_test, IsEmpty)
{
    std::string testString = ""; 
    EXPECT_EQ(StringUtils::IsEmpty(testString), true);

    testString = "\t"; 
    EXPECT_EQ(StringUtils::IsEmpty(testString), false);

    testString = "\n"; 
    EXPECT_EQ(StringUtils::IsEmpty(testString), false);

    testString = "\r"; 
    EXPECT_EQ(StringUtils::IsEmpty(testString), false);

    testString = " "; 
    EXPECT_EQ(StringUtils::IsEmpty(testString), false);

    testString = "testString"; 
    EXPECT_EQ(StringUtils::IsEmpty(testString), false);
}

TEST(string_utils_test, IsBlank)
{
    std::string testString = ""; 
    EXPECT_EQ(StringUtils::IsBlank(testString), true);

    testString = "  "; 
    EXPECT_EQ(StringUtils::IsBlank(testString), true);

    testString = "\t"; 
    EXPECT_EQ(StringUtils::IsBlank(testString), true);

    testString = "\r"; 
    EXPECT_EQ(StringUtils::IsBlank(testString), true);

    testString = "\n"; 
    EXPECT_EQ(StringUtils::IsBlank(testString), true);

    testString = " \t\r\n"; 
    EXPECT_EQ(StringUtils::IsBlank(testString), true);

    testString = "testString"; 
    EXPECT_EQ(StringUtils::IsBlank(testString), false);

    testString = " testString"; 
    EXPECT_EQ(StringUtils::IsBlank(testString), false);

    testString = "	testString"; 
    EXPECT_EQ(StringUtils::IsBlank(testString), false);

    testString = "\rtestString"; 
    EXPECT_EQ(StringUtils::IsBlank(testString), false);

    testString = "\ntestString"; 
    EXPECT_EQ(StringUtils::IsBlank(testString), false);

    testString = " \n\r\ntestString"; 
    EXPECT_EQ(StringUtils::IsBlank(testString), false);
}

TEST(string_utils_test, TrimLeft)
{
    std::string testString = "Hello"; 

    EXPECT_EQ(StringUtils::TrimLeft(testString), "Hello");

    testString = " Hello"; 
    EXPECT_EQ(StringUtils::TrimLeft(testString), "Hello");

    // a tab at the beginning of the string 
    testString = "	Hello"; 
    EXPECT_EQ(StringUtils::TrimLeft(testString), "Hello");

    testString = "\rHello"; 
    EXPECT_EQ(StringUtils::TrimLeft(testString), "Hello");

    testString = "\nHello"; 
    EXPECT_EQ(StringUtils::TrimLeft(testString), "Hello");

    testString = "Hello "; 
    EXPECT_EQ(StringUtils::TrimLeft(testString), "Hello ");

    // a tab at the end of the string 
    testString = "Hello	"; 
    EXPECT_EQ(StringUtils::TrimLeft(testString), "Hello	");

    testString = "Hello\r"; 
    EXPECT_EQ(StringUtils::TrimLeft(testString), "Hello\r");

    testString = "Hello\n"; 
    EXPECT_EQ(StringUtils::TrimLeft(testString), "Hello\n");

    testString = " Hello "; 
    EXPECT_EQ(StringUtils::TrimLeft(testString), "Hello ");
}

TEST(string_utils_test, TrimRight)
{
    std::string testString = "Hello"; 

    EXPECT_EQ(StringUtils::TrimRight(testString), "Hello");

    testString = "Hello "; 
    EXPECT_EQ(StringUtils::TrimRight(testString), "Hello");

    // a tab at the end of the string 
    testString = "Hello	"; 
    EXPECT_EQ(StringUtils::TrimRight(testString), "Hello");

    testString = "Hello\r"; 
    EXPECT_EQ(StringUtils::TrimRight(testString), "Hello");

    testString = "Hello\n"; 
    EXPECT_EQ(StringUtils::TrimRight(testString), "Hello");

    testString = " Hello"; 
    EXPECT_EQ(StringUtils::TrimRight(testString), " Hello");

    // a tab at the beginning of the string 
    testString = "	Hello"; 
    EXPECT_EQ(StringUtils::TrimRight(testString), "	Hello");

    testString = "\rHello"; 
    EXPECT_EQ(StringUtils::TrimRight(testString), "\rHello");

    testString = "\nHello"; 
    EXPECT_EQ(StringUtils::TrimRight(testString), "\nHello");

    testString = " Hello "; 
    EXPECT_EQ(StringUtils::TrimRight(testString), " Hello");
}

TEST(string_utils_test, Trim)
{
    std::string testString = "Hello"; 

    EXPECT_EQ(StringUtils::Trim(testString), "Hello");

    testString = " Hello "; 
    EXPECT_EQ(StringUtils::Trim(testString), "Hello");

    testString = "	Hello	"; 
    EXPECT_EQ(StringUtils::Trim(testString), "Hello");

    testString = "\rHello\n"; 
    EXPECT_EQ(StringUtils::Trim(testString), "Hello");

    testString = "\nHello\n"; 
    EXPECT_EQ(StringUtils::Trim(testString), "Hello");

    testString = " 	\r\nHello 	\r\n"; 
    EXPECT_EQ(StringUtils::Trim(testString), "Hello");
}

TEST(string_utils_test, ToUpperCase)
{
    std::string testString = "Hello, World"; 

    EXPECT_EQ(StringUtils::ToUpperCase(testString), "HELLO, WORLD");
}

TEST(string_utils_test, ToLowerCase)
{
    std::string testString = "Hello, World";
 
    EXPECT_EQ(StringUtils::ToLowerCase(testString), "hello, world");
}

TEST(string_utils_test, AreEqual)
{
    std::string testString = "Hello, World"; 

    EXPECT_EQ(StringUtils::AreEqual(testString, "Hello, World"), true);
    EXPECT_EQ(StringUtils::AreEqual(testString, "hello, world"), false);
    EXPECT_EQ(StringUtils::AreEqual(testString, "HELLO, WORLD"), false);
    EXPECT_EQ(StringUtils::AreEqual(testString, "Hello World"), false);
    EXPECT_EQ(StringUtils::AreEqual(testString, "Hello! World"), false);
}

TEST(string_utils_test, AreEqualIgnoreCase)
{
    std::string testString = "Hello, World"; 

    EXPECT_EQ(StringUtils::AreEqualIgnoreCase(testString, "Hello, World"), true);
    EXPECT_EQ(StringUtils::AreEqualIgnoreCase(testString, "hello, world"), true);
    EXPECT_EQ(StringUtils::AreEqualIgnoreCase(testString, "HELLO, WORLD"), true);
    EXPECT_EQ(StringUtils::AreEqualIgnoreCase(testString, "HeLLo, wORLd"), true);

    EXPECT_EQ(StringUtils::AreEqualIgnoreCase(testString, "Hello World"), false);
    EXPECT_EQ(StringUtils::AreEqualIgnoreCase(testString, "Hello! World"), false);
}

TEST(string_utils_test, Contains)
{
    std::string testString = "Hello, World"; 

    EXPECT_EQ(StringUtils::Contains(testString, 'H'), true);
    EXPECT_EQ(StringUtils::Contains(testString, ' '), true);
    EXPECT_EQ(StringUtils::Contains(testString, ','), true);
    EXPECT_EQ(StringUtils::Contains(testString, 'l'), true);
    EXPECT_EQ(StringUtils::Contains(testString, 'd'), true);

    EXPECT_EQ(StringUtils::Contains(testString, 'h'), false);
    EXPECT_EQ(StringUtils::Contains(testString, 'k'), false);
    EXPECT_EQ(StringUtils::Contains(testString, '\n'), false);

    EXPECT_EQ(StringUtils::Contains(testString, "Hello, World"), true);
    EXPECT_EQ(StringUtils::Contains(testString, "Hello"), true);
    EXPECT_EQ(StringUtils::Contains(testString, "World"), true);
    EXPECT_EQ(StringUtils::Contains(testString, ", Wo"), true);
    EXPECT_EQ(StringUtils::Contains(testString, "W"), true);
    EXPECT_EQ(StringUtils::Contains(testString, " "), true);

    EXPECT_EQ(StringUtils::Contains(testString, "hello, world"), false);
    EXPECT_EQ(StringUtils::Contains(testString, "hello"), false);
    EXPECT_EQ(StringUtils::Contains(testString, "world"), false);
    EXPECT_EQ(StringUtils::Contains(testString, ", wo"), false);

    EXPECT_EQ(StringUtils::Contains(testString, "HELLO, WORLD"), false);
    EXPECT_EQ(StringUtils::Contains(testString, "HELLO"), false);
    EXPECT_EQ(StringUtils::Contains(testString, "WORLD"), false);
    EXPECT_EQ(StringUtils::Contains(testString, ", WO"), false);

    EXPECT_EQ(StringUtils::Contains(testString, "abc"), false);
    EXPECT_EQ(StringUtils::Contains(testString, "\n"), false);
    EXPECT_EQ(StringUtils::Contains(testString, "\t"), false);
}
