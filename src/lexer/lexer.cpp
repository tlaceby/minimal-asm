#include "lexer.h"
#include <iostream>

using std::vector, std::string;

vector<Token> Tokenizer::tokenize(const lib::fs::File &file) {
  init();
  std::optional<string> contents = lib::fs::read_file(file);

  if (contents.has_value() == false) {
    std::cout << "Could not open file " << file.file_name << "\n";
    exit(1);
  }

  source = contents.value();

  while (not_eof()) {
    produce_token();
  }

  push_tk(TokenKind::end_file);
  return m_tokens;
}

void Tokenizer::produce_token() {
  //
}

void Tokenizer::handle_symbol() {
  //
}

void Tokenizer::handle_number() {
  //
}

void Tokenizer::handle_comment() {
  //
}