#import "catch.hpp"
#import <iostream>
#import <tokenizer.h>

TEST_CASE("Getting basic tokens") {
    REQUIRE(1 == 1);
}

TEST_CASE("Reading chars from string") {
    Tokenizer t = Tokenizer("test");
    REQUIRE('t' == t.getchar());
    REQUIRE('e' == t.getchar());
    REQUIRE('s' == t.getchar());
    REQUIRE('t' == t.getchar());
    REQUIRE(0 == t.getchar());
}

TEST_CASE("Reading tokens") {
    Tokenizer tn = Tokenizer("identifier = 123 + \"String\"\n");
    Token t = tn.next();
    REQUIRE(t.get_content() == "identifier");
    REQUIRE(t.get_type() == TokenType::Symbol);
    t = tn.next();
    REQUIRE(t.get_content() == "=");
    REQUIRE(t.get_type() == TokenType::Symbol);
    t = tn.next();
    REQUIRE(t.get_content() == "123");
    REQUIRE(t.get_type() == TokenType::Number);
    t = tn.next();
    REQUIRE(t.get_content() == "+");
    REQUIRE(t.get_type() == TokenType::Symbol);
    t = tn.next();
    REQUIRE(t.get_content() == "String");
    REQUIRE(t.get_type() == TokenType::String);
    t = tn.next();
//    cout << "type: " << static_cast<int>(t.get_type());
//    cout << " expecting " << static_cast<int>(TokenType::EndOfLine) << endl;
    REQUIRE(t.get_type() == TokenType::EndOfLine);
}
