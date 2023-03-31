#pragma once
#include "tokens.h"
#include <vector>

class Tokenizer {
private:
  std::vector<Token> m_tokens;
  std::string source;

  uint64_t position{0};
  uint64_t line{0};
  uint64_t offset{0};

public:
  std::vector<Token> tokenize(const lib::fs::File &file);

private:
  void init();
  bool not_eof();
  FileLocation location();
  char next();
  char peak();
  char at();

  Token push_tk(TokenKind);
  Token push_tk(TokenKind, std::string);
  void produce_token();

  bool is_numeric();
  bool is_symbol();
  void handle_symbol();
  void handle_number();
  void handle_comment();
};