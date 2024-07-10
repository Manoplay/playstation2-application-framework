//
// Created by Alessandro Mascolo on 03/07/24.
//

#ifndef PS2APP_SQUARE_H
#define PS2APP_SQUARE_H


#include "Renderable.h"

class Square: public Renderable {
public:
    void Move(int x, int y);
    void Resize(int w, int h);
    void Recolor(unsigned long newColor);
    Square();
    Square(int x, int y, int w, int h, unsigned long color);
    void Render(GSGLOBAL *) override;

private:
    int x{};
    int y{};
    int w{};
    int h{};
    unsigned long color{};
};


#endif //PS2APP_SQUARE_H
