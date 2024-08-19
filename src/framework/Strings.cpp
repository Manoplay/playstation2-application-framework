//
// Created by Alessandro Mascolo on 19/08/24.
//
#include "Strings.h"

namespace Strings {
    std::string Join(std::vector<std::string> elements, const std::string delimiter) {
        std::ostringstream os;

        for(int i = 0; i < elements.size() - 1; i++) {
            os << elements[i] << delimiter;
        }

        if (!elements.empty())
            os << elements[elements.size() - 1];

        return os.str();
    }
}