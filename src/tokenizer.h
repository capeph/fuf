#include <iostream>
#include "token.h"

using namespace std;

class Tokenizer {

private:
	string code;
	int pos;
	int lastch;
public:
	Tokenizer(string input);
	int getchar();
    Token next();
    void consume();
};