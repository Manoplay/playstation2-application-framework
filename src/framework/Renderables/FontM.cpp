//
// Created by Alessandro Mascolo on 23/06/24.
//

#include "FontM.h"
#include <gsKit.h>
#include <cstring>
#include <cstdlib>

void FontM::Render(GSGLOBAL * gsglobal) {
    gsKit_fontm_print(gsglobal, gsfontm, x, y, 3, color, message);
}

FontM::FontM(GSFONTM *fontM, int x, int y, const char* message, unsigned long color): gsfontm(fontM), x(x), y(y), color(color) {
    // this->message = new char [strlen(message) + 1];
    this->message = static_cast<char *>(malloc(sizeof(char) * strlen(message) + 1));
    strcpy(this->message, message);
}

void FontM::Move(int x, int y) {
    this->x = x;
    this->y = y;
}

void FontM::SetText(const char *newText) {
    // delete this->message;
    // this->message = new char [strlen(message) + 1];
    strcpy(this->message, newText);
}