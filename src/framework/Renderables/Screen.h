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
    [[nodiscard]] unsigned long GetBackgroundColor() const;
    // void SetRenderableCount(int newCount);

protected:
    // int renderableCount = 0;
    std::vector<Renderable*> Renderables = {};
    unsigned long bkColor = Colors::White;
};

#endif //PS2APP_SCREEN_H
