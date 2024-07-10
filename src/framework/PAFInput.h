//
// Created by Alessandro Mascolo on 02/07/24.
//

#ifndef PS2APP_PAFINPUT_H
#define PS2APP_PAFINPUT_H


class Input {
public:
    static Input* Shared();
    static int GetPadCount();
    void Rumble(bool small);
    void StopRumble(bool small);
    bool GetButton(int button);
    bool GetButtonDown(int button);
private:
    Input();
    int oldPad{};
    static void waitPadReady();
    char padBuf[256] __attribute__((aligned(64)));
    char actAlign[6]{};
    int actuators;
    static Input* instance;
};


#endif //PS2APP_PAFINPUT_H
