#import "token.h"

Token::Token(TokenType token_type, string data) {
	type = token_type;
	content = data;
}

TokenType Token::get_type() {
	return type;
}

string Token::get_content() {
	return content;
}	
