#include "json_tokenizer.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace fdream;

TEST(json_tokenizer_test, Constructor)
{
    JsonTokenizer tokenizer1;

    JsonTokenizer tokenizer1("{ \"method\" : \"get\" , \"url\" : \"home\", \"version\" : 123 }");

    std::cout << "<<<< tokenizer 1" << std::endl;
    std::cout << tokenizer1.ToString();

    JsonTokenizer tokenizer2("{ \"method\" : { \"url\" : \"home\" } }");

    std::cout << "<<<< tokenizer 2" << std::endl;
    std::cout << tokenizer2.ToString();

    JsonTokenizer tokenizer3("{\"method\":\"get\",\"url\":\"home\",\"version\":123}");

    std::cout << "<<<< tokenizer 3" << std::endl;
    std::cout << tokenizer3.ToString();

    EXPECT_EQ(tokenizer3.HasNext(), true);    
    const JsonToken & token = tokenizer3.GetNext(); 
    EXPECT_EQ(token.GetId(), 0);    
    EXPECT_EQ(token.GetContent(), "{");    

    EXPECT_EQ(tokenizer3.HasNext(), true);    
    token = tokenizer3.GetNext(); 
    EXPECT_EQ(token.GetId(), 0);    
    EXPECT_EQ(token.GetContent(), "method");    
}
