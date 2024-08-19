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
#include "Path.h"

class ScreenManager: public Closeable {
public:
    void Close() override;

    ScreenManager();
    void SwitchScreen(Screen* screen);

    [[noreturn]] void Main();
    GSGLOBAL* GetGSGLobal();
    FontM EmitFontMRenderable(const char* text, int x, int y);
    FontM EmitFontMRenderable(const std::string& text, int x, int y) {
        return EmitFontMRenderable(text.c_str(), x, y);
    };
    Texture EmitTextureRenderable(const char* path, int x, int y);
    Texture EmitTextureRenderable(Path path, int x, int y) {
        return EmitTextureRenderable(path.GeneratePath().c_str(), x, y);
    }

private:
    GSFONTM* gsFontM;
    GSGLOBAL* gsGlobal;
    Screen* currentScreen;
};


#endif //PS2APP_SCREENMANAGER_H
