//
// Created by Alessandro Mascolo on 26/05/24.
//

#ifndef PS2APP_SCREENMANAGER_H
#define PS2APP_SCREENMANAGER_H


#include <gsKit.h>
#include <cstdio>
#include "Renderables/Screen.h"
#include "Renderables/FontM.h"
#include "Renderables/Texture.h"

class ScreenManager {
public:
    ScreenManager();
    void SwitchScreen(Screen* screen);

    [[noreturn]] void Main();
    GSGLOBAL* GetGSGLobal();
    FontM EmitFontMRenderable(const char* text, int x, int y);
    Texture EmitTextureRenderable(char* path, int x, int y);

private:
    GSFONTM* gsFontM;
    GSGLOBAL* gsGlobal;
    Screen* currentScreen;
};


#endif //PS2APP_SCREENMANAGER_H
