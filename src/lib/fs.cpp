#include "fs.h"

#include <fstream>

using namespace lib::fs;
using std::string, std::optional, std::ifstream;

optional<string> read_file(const File &file) {
  string path = file.path + file.file_name;
  ifstream ifs(path);
  string content((std::istreambuf_iterator<char>(ifs)),
                 (std::istreambuf_iterator<char>()));

  return content;
}