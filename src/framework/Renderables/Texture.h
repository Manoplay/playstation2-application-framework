//
// Created by Alessandro Mascolo on 01/07/24.
//

#ifndef PS2APP_TEXTURE_H
#define PS2APP_TEXTURE_H

#include "Renderable.h"

enum TextureType {
    PNG,
    BMP,
    JPEG,
    RAW,
    TIFF
};

class Texture: public Renderable {
public:
    Texture(GSGLOBAL *gsGlobal, char *path, TextureType type, int x, int y);
    Texture();
    void Move(int x, int y);
    void Render(GSGLOBAL *) override;
private:
    GSTEXTURE texture{};
    int x;
    int y;
};

#endif //PS2APP_TEXTURE_H
