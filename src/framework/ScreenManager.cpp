//
// Created by Alessandro Mascolo on 26/05/24.
//

#include "ScreenManager.h"
#include <dmaKit.h>

ScreenManager::ScreenManager() {
    currentScreen = nullptr;

    gsGlobal = gsKit_init_global();
    gsFontM = gsKit_init_fontm();
    dmaKit_init(D_CTRL_RELE_OFF,D_CTRL_MFD_OFF, D_CTRL_STS_UNSPEC,
                D_CTRL_STD_OFF, D_CTRL_RCYC_8, 1 << DMA_CHANNEL_GIF);

    gsGlobal->PSM = GS_PSM_CT32;
    gsGlobal->PSMZ = GS_PSMZ_16S;
    gsGlobal->ZBuffering = GS_SETTING_ON;

    // Initialize the DMAC
    dmaKit_chan_init(DMA_CHANNEL_GIF);

    gsGlobal->PrimAlphaEnable = GS_SETTING_ON;

    gsKit_init_screen(gsGlobal);
    gsKit_fontm_upload(gsGlobal, gsFontM);
    gsFontM->Spacing = 0.95f;

    gsKit_mode_switch(gsGlobal, GS_ONESHOT);

    gsKit_set_clamp(gsGlobal, GS_CMODE_CLAMP);
    gsKit_set_test(gsGlobal, GS_ZTEST_OFF);

}

[[noreturn]] void ScreenManager::Main() {
    while (true) {
        currentScreen->PreUpdate();
        gsKit_clear(gsGlobal, currentScreen->GetBackgroundColor());
        // gsKit_prim_sprite(gsGlobal, 0, 0, gsGlobal->Width, gsGlobal->Height, 0, currentScreen->GetBackgroundColor());
        currentScreen->Render(gsGlobal);
        gsKit_sync_flip(gsGlobal);
        gsKit_queue_exec(gsGlobal);
        // gsKit_queue_reset(gsGlobal->Per_Queue);
        gsKit_TexManager_nextFrame(gsGlobal);
        currentScreen->Update();
    }
}

void ScreenManager::SwitchScreen(Screen *screen) {
    currentScreen = screen;
}

GSGLOBAL *ScreenManager::GetGSGLobal() {
    return gsGlobal;
}

FontM ScreenManager::EmitFontMRenderable(const char *text, int x, int y) {
    return {gsFontM, x, y, text};
}

Texture ScreenManager::EmitTextureRenderable(char *path, int x, int y) {
    char* extension = (char*) path + strlen(path) - 3;
    TextureType type = RAW;
    if (!strcmp(extension, "jpg")) type = JPEG;
    if (!strcmp(extension, "png")) type = PNG;
    if (!strcmp(extension, "bmp")) type = BMP;
    if (!strcmp(extension, "iff")) type = TIFF;
    return {gsGlobal, path, type, x, y};
}
