//
// Created by Alessandro Mascolo on 03/07/24.
//

#include "Square.h"

void Square::Render(GSGLOBAL * gsglobal) {
    gsKit_prim_sprite(gsglobal, x, y, x + w, y + h, 3, color);
}

Square::Square(int x, int y, int w, int h, unsigned long color): x(x), y(y), w(w), h(h), color(color) {

}

void Square::Recolor(unsigned long newColor) {
    this->color = newColor;
}

void Square::Resize(int w, int h) {
    this->w = w;
    this->h = h;
}

void Square::Move(int x, int y) {
    this->x = x;
    this->y = y;
}

Square::Square() = default;
