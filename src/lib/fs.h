#pragma once
#include <optional>
#include <string>

namespace lib::fs {
struct File {
  std::string file_name{"test.s"};
  std::string path{"./inputs/"};
};

std::optional<std::string> read_file(const File &file);
} // namespace lib::fs