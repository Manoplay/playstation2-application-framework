//
// Created by Alessandro Mascolo on 01/07/24.
//

#include "Texture.h"
#include "Color.h"
#include <gsKit.h>
#include <gsToolkit.h>

void Texture::Render(GSGLOBAL * gsGlobal) {
    gsKit_TexManager_bind(gsGlobal, &texture);
    gsKit_set_primalpha(gsGlobal, GS_SETREG_ALPHA(0, 1, 0, 1, 0), 0);
    gsKit_set_test(gsGlobal, GS_ATEST_OFF);
    gsKit_prim_sprite_texture(gsGlobal, &texture,	x,  // X1
                              y,  // Y1
                              0.0f,  // U1
                              0.0f,  // V1
                              texture.Width + x, // X2
                              texture.Height +  y, // Y2
                              texture.Width, // U2
                              texture.Height, // V2
                              3,
                              Colors::TextureColor);
    gsKit_set_test(gsGlobal, GS_ATEST_ON);
    gsKit_set_primalpha(gsGlobal, GS_BLEND_BACK2FRONT, 0);

}

Texture::Texture(GSGLOBAL* gsGlobal, char *path, TextureType type, int x, int y): x(x), y(y) {
    texture.Delayed = true;
    switch (type) {
        case PNG:
            gsKit_texture_png(gsGlobal, &texture, path);
            break;
        case BMP:
            gsKit_texture_bmp(gsGlobal, &texture, path);
            break;
        case JPEG:
            gsKit_texture_jpeg(gsGlobal, &texture, path);
            break;
        case RAW:
            gsKit_texture_raw(gsGlobal, &texture, path);
            break;
        case TIFF:
            gsKit_texture_tiff(gsGlobal, &texture, path);
            break;
    }
    w = texture.Width;
    h = texture.Height;
}

Texture::Texture(): texture(), x(0), y(0), w(0), h(0) {

}

void Texture::Move(int x, int y) {
    this->x = x;
    this->y = y;
}

int Texture::GetWidth() const {
    return w;
}

int Texture::GetHeight() const {
    return h;
}