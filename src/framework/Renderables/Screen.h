//
// Created by Alessandro Mascolo on 23/06/24.
//

#ifndef PS2APP_SCREEN_H
#define PS2APP_SCREEN_H

#include <cstdio>
#include "Renderable.h"
#include "Color.h"

class Screen: public Renderable {
public:
    virtual void PreUpdate() = 0;
    virtual void Update() = 0;
    void Render(GSGLOBAL* gsGlobal) override;
    unsigned long GetBackgroundColor();
    void SetRenderableCount(int newCount);

protected:
    int renderableCount = 0;
    Renderable** renderables = nullptr;
    unsigned long bkColor = Colors::White;
};

#endif //PS2APP_SCREEN_H
