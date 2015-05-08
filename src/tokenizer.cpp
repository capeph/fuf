#import <iostream>
#import <cctype>
#import "tokenizer.h"

using namespace std;


Tokenizer::Tokenizer(string input) {
    code = input;
    if (input.size() == 0) {
        pos = 0;
        lastch = 0;
    } else {    
         pos = 1;
         lastch = input[0];
    }
}

int Tokenizer::getchar() {
    int result = lastch;
    if (pos >= code.size()) {
        lastch = '0';
    }
    lastch = code[pos++];
    return result;
}


Token Tokenizer::next() {
    while(isspace(lastch) && lastch != '\n') {
        getchar();
    }
//    cout << "next: " << (char) lastch << endl;
    if (0 == lastch) {
        return Token(TokenType::EndOfFile, "");
    }
    else if ('#' == lastch) {   
        // handle comments
        do {
            getchar();
        } while ( !(lastch == '\n' || lastch == 0));
        return next();
    }
    else if ('"' == lastch) {
        // handle strings
        string value = "";
        getchar();     // eat first double quote
        while (lastch != '"') {
            value += getchar();
//            cout << "-string: " << value << endl;
        }            
        getchar();  // eat last double quote        
        return Token(TokenType::String, value);
    }
    else if ('\n' == lastch) {
        getchar();
        return Token(TokenType::EndOfLine, "");
    }
    else if (isalpha(lastch) || ispunct(lastch)) {
        string id;
        do {
            id += getchar();
        } while (isalpha(lastch) || ispunct(lastch));
        return Token(TokenType::Symbol, id);
    }
    else if (isdigit(lastch)) {
        string id;
        do {
            id += getchar();
        } while (isdigit(lastch));
        return Token(TokenType::Number, id);
    }
    return Token(TokenType::Invalid, "");
}

void Tokenizer::consume() {
}

    