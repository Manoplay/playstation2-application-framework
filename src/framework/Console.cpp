//
// Created by Alessandro Mascolo on 26/05/24.
//

#include "Console.h"
#include <debug.h>


namespace Console {
    void Write(const char * format, ...) {
        va_list opt;
        va_start(opt, format);
        scr_vprintf(format, opt);
        va_end(opt);
    }

    void Init() {
        init_scr();
    }

    void SetCursor(bool enabled) {
        scr_setCursor(enabled);
    }

    void Clear() {
        scr_clear();
    }

    void Move(int x, int y) {
        scr_setXY(x, y);
    }

    int GetX() {
        return scr_getX();
    }

    int GetY() {
        return scr_getY();
    }
}
