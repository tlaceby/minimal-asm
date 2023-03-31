#include "tokens.h"

Token token(TokenKind kind, FileLocation location, std::string value) {
  return Token{kind, location, value};
}

const char *token_kind_str(TokenKind kind) {
  switch (kind) {
  case TokenKind::bang:
    return "bang";
  case TokenKind::close_brace:
    return "close_brace";
  case TokenKind::close_bracket:
    return "close_bracket";
  case TokenKind::colon:
    return "colon";
  case TokenKind::comma:
    return "comma";
  case TokenKind::dot:
    return "dot";
  case TokenKind::end_file:
    return "end_file";
  case TokenKind::equals:
    return "equals";
  case TokenKind::hashtag:
    return "hashtag";
  case TokenKind::number:
    return "number";
  case TokenKind::open_brace:
    return "open_brace";
  case TokenKind::open_bracket:
    return "open_bracket";
  case TokenKind::string:
    return "string";
  case TokenKind::symbol:
    return "symbol";

  default:
    return "unknown";
  }
}
