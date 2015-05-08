#include <string>

using namespace std;

enum class TokenType { Symbol, Number, String, EndOfLine, EndOfFile, Invalid };

class Token {

private:
	TokenType type;
	string content;
public:
	Token(TokenType type, string label);
	TokenType get_type();
	string get_content();
};