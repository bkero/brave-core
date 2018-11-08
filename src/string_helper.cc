/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <sstream>

#include "string_helper.h"

namespace helper {

bool String::Split(
    const std::string& str,
    const char delimiter,
    std::vector<std::string>* v) {
  if (!v) {
    return false;
  }

  std::stringstream ss(str);
  std::string token;

  while (std::getline(ss, token, delimiter)) {
    v->push_back(token);
  }

  return true;
}

bool String::Join(
    const std::vector<std::string>& v,
    const char delimiter,
    std::string* str) {
  if (!str) {
    return false;
  }

  str->clear();

  for (auto p = v.begin(); p != v.end(); ++p) {
    *str += *p;
    if (p != v.end() - 1) {
      *str += delimiter;
    }
  }

  return true;
}

}  // namespace helper
