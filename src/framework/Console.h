//
// Created by Alessandro Mascolo on 26/05/24.
//

#ifndef PS2APP_CONSOLE_H
#define PS2APP_CONSOLE_H

namespace Console {

    void Write(const char *, ...) __attribute__((format(printf,1,2)));
    void Init();
    void Move(int x, int y);
    int GetX();
    int GetY();
    void Clear();
    void SetCursor(bool enabled);

}




#endif //PS2APP_CONSOLE_H
