//
// Created by Alessandro Mascolo on 19/08/24.
//

#include <string>
#include <sstream>
#include <vector>

#ifndef PS2APP_STRINGS_H
#define PS2APP_STRINGS_H

/// Various useful function for manipulating Strings
namespace Strings {
    std::string Join(std::vector<std::string> elements, const std::string delimiter);
}

#endif //PS2APP_STRINGS_H
