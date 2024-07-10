//
// Created by Alessandro Mascolo on 23/06/24.
//

#include <cstdlib>
#include "Screen.h"

void Screen::Render(GSGLOBAL* gsGlobal) {
    for (int i = 0; i < renderableCount; i++)
        renderables[i]->Render(gsGlobal);
}

unsigned long Screen::GetBackgroundColor() {
    return bkColor;
}

void Screen::SetRenderableCount(int newCount) {
    if (renderableCount == 0)
        renderables = static_cast<Renderable **>(malloc(sizeof(Renderable *) * newCount));
    else
        renderables = static_cast<Renderable **>(realloc(renderables, sizeof(Renderable *) * newCount));
    renderableCount = newCount;
}
