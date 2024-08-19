//
// Created by Alessandro Mascolo on 01/07/24.
//

#include "Texture.h"
#include "Color.h"
#include "System.h"
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

Texture::Texture(GSGLOBAL* gsGlobal, const char *path, TextureType type, int x, int y): gsglobal(gsGlobal), x(x), y(y) {
    System::Shared()->AddResource(this);
    texture.Delayed = true;
    char* xpath = const_cast<char *>(path);
    switch (type) {
        case PNG:
            gsKit_texture_png(gsGlobal, &texture, xpath);
            break;
        case BMP:
            gsKit_texture_bmp(gsGlobal, &texture, xpath);
            break;
        case JPEG:
            gsKit_texture_jpeg(gsGlobal, &texture, xpath);
            break;
        case RAW:
            gsKit_texture_raw(gsGlobal, &texture, xpath);
            break;
        case TIFF:
            gsKit_texture_tiff(gsGlobal, &texture, xpath);
            break;
    }
    w = texture.Width;
    h = texture.Height;
}

Texture::Texture(): gsglobal(nullptr), texture(), x(0), y(0), w(0), h(0) {

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

void Texture::Close() {
    gsKit_TexManager_free(gsglobal, &texture);
}
