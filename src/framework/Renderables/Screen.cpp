//
// Created by Alessandro Mascolo on 23/06/24.
//

#include "Screen.h"

void Screen::Render(GSGLOBAL* gsGlobal) {
    for (const auto & Renderable : Renderables)
        Renderable->Render(gsGlobal);
}

unsigned long Screen::GetBackgroundColor() const {
    return bkColor;
}