//
// Created by Alessandro Mascolo on 01/07/24.
//

#ifndef PS2APP_TEXTURE_H
#define PS2APP_TEXTURE_H

#include "Renderable.h"
#include "Closeable.h"

enum TextureType {
    PNG,
    BMP,
    JPEG,
    RAW,
    TIFF
};

class Texture: public Renderable, public Closeable {
public:
    Texture(GSGLOBAL *gsGlobal, const char *path, TextureType type, int x, int y);
    Texture();
    void Close() override;
    [[nodiscard]] unsigned int GetWidth() const;
    [[nodiscard]] unsigned int GetHeight() const;
    void SetAlpha(float a);
    void Move(int x, int y);
    void Render(GSGLOBAL *) override;
private:
    GSGLOBAL* gsglobal;
    GSTEXTURE texture{};
    int x;
    int y;
    unsigned int w;
    unsigned int h;
    float alpha;
};

#endif //PS2APP_TEXTURE_H
