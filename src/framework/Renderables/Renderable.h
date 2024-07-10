//
// Created by Alessandro Mascolo on 23/06/24.
//

#ifndef PS2APP_RENDERABLE_H
#define PS2APP_RENDERABLE_H

#include <gsKit.h>

class Renderable {
public:
    virtual void Render(GSGLOBAL*) = 0;
};

#endif //PS2APP_RENDERABLE_H
