#pragma once
#include "../lib/fs.h"
#include "cstdint"
#include <string>

enum TokenKind {
  end_file,
  open_bracket,
  close_bracket,
  open_brace,
  close_brace,
  number,
  string,
  symbol,
  colon,
  comma,
  hashtag,
  bang,
  dot,
  equals,
};

const char *token_kind_str(TokenKind kind);

struct FileLocation {
  uint64_t line;
  uint64_t start;
  uint64_t length;
};

struct Token {
  TokenKind kind;
  FileLocation location;
  std::string value;
};

Token token(TokenKind, FileLocation, std::string);