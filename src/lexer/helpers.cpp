#include "lexer.h"
#include "string.h"

using std::vector, std::string;

void Tokenizer::init() {
  line = 0;
  position = 0;
  offset = 0;
  m_tokens.clear();
}

char Tokenizer::at() { return source[position]; }
char Tokenizer::peak() { return source[position + 1]; }
char Tokenizer::next() { return source[position++]; }
bool Tokenizer::not_eof() { return position < source.length(); }

FileLocation Tokenizer::location() { return FileLocation{line, offset, 1}; }

Token Tokenizer::push_tk(TokenKind kind) {
  FileLocation loc = location();
  Token tk = token(kind, loc, "");
  next();
  return tk;
}

Token Tokenizer::push_tk(TokenKind kind, std::string value) {
  FileLocation loc = location();
  loc.length = value.size();
  Token tk = token(kind, loc, value);
  return tk;
}

bool Tokenizer::is_numeric() { return isdigit(at()); }
bool Tokenizer::is_symbol() {
  char a = at();
  return (isalnum(a) || a == '$' || a == '_');
}