//
// Created by Alessandro Mascolo on 23/06/24.
//

#ifndef PS2APP_FONTM_H
#define PS2APP_FONTM_H

#include <cstdio>
#include "Renderable.h"
#include "Color.h"
#include "Closeable.h"

class FontM: public Renderable {
public:
    void Render(GSGLOBAL *) override;
    FontM(GSFONTM* fontM, int x, int y, const char* message, unsigned long color = Colors::Black);
    void Move(int x, int y);
    void SetText(const char* newText);
    FontM() = default;

private:
    GSFONTM* gsfontm = nullptr;
    int x = 0;
    int y = 0;
    unsigned long color = Colors::Black;
    char* message{};
};

#endif //PS2APP_FONTM_H
