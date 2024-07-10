//
// Created by Alessandro Mascolo on 23/06/24.
//

#ifndef PS2APP_COLOR_H
#define PS2APP_COLOR_H

namespace Colors {
    const static unsigned long White = GS_SETREG_RGBAQ(0xFF,0xFF,0xFF,0x80,0x00);
    const static unsigned long Black = GS_SETREG_RGBAQ(0,0,0,0x80,0x00);
    const static unsigned long TextureColor = GS_SETREG_RGBAQ(0x80,0x80,0x80,0x80,0x00);
    const static unsigned long BlueTrans = GS_SETREG_RGBAQ(0x00,0x00,0xFF,0x40,0x00);
    const static unsigned long Red = GS_SETREG_RGBAQ(0xFF,0x00,0x00,0x00,0x00);
}

#endif //PS2APP_COLOR_H
