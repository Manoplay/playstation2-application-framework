//
// Created by Alessandro Mascolo on 23/06/24.
//

#include "FontM.h"
#include <gsKit.h>
#include <cstring>
#include <utility>

void FontM::Render(GSGLOBAL * gsglobal) {
    gsKit_fontm_print(gsglobal, gsfontm, x, y, 3, color, message.c_str())
}

FontM::FontM(GSFONTM *fontM, int x, int y, std::string message, unsigned long color): gsfontm(fontM), x(x), y(y), color(color), message(std::move(message)) {
    // this->message = new char [strlen(message) + 1];
}

void FontM::Move(int x, int y) {
    this->x = x;
    this->y = y;
}

void FontM::SetText(std::string newText) {
    // delete this->message;
    // this->message = new char [strlen(message) + 1];
    message = std::move(newText);
}