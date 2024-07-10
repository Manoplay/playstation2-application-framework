//
// Created by Alessandro Mascolo on 02/07/24.
//

#include <cstdlib>
#include <loadfile.h>
#include <sifrpc.h>
#include <libpad.h>
#include "PAFInput.h"

Input *Input::instance = new Input();

Input *Input::Shared() {
    return Input::instance;
}

Input::Input() {
    SifInitRpc(0);
    SifLoadModule("rom0:SIO2MAN", 0, nullptr);
    SifLoadModule("rom0:PADMAN", 0, nullptr);
    padInit(0);
    if (padGetPortMax() < 0) {
        padEnd();
        return;
    }
    padPortOpen(0, 0, padBuf);
    waitPadReady();
    padSetMainMode(0, 0, PAD_MMODE_DUALSHOCK, PAD_MMODE_UNLOCK);
    waitPadReady();
    actuators = padInfoAct(0, 0, -1, 0);
    if (actuators != 0) {
        actAlign[0] = 0;
        actAlign[1] = 1;
        actAlign[2] = 0xff;
        actAlign[3] = 0xff;
        actAlign[4] = 0xff;
        actAlign[5] = 0xff;
        padSetActAlign(0, 0, actAlign);
    }
    waitPadReady();
}

int Input::GetPadCount() {
    return padGetPortMax();
}

void Input::waitPadReady() {
    int state;

    state = padGetState(0, 0);

    while ((state != PAD_STATE_STABLE) && (state != PAD_STATE_FINDCTP1)) {
        state = padGetState(0, 0);
    }
}

bool Input::GetButton(int button) {
    struct padButtonStatus buttons{};
    padRead(0, 0, &buttons);
    oldPad = (0xffff ^ buttons.btns);
    return oldPad & button;
}

void Input::Rumble(bool small) {
    actAlign[small ? 0 : 1] = 1;
    padSetActDirect(0, 0, actAlign);
}

void Input::StopRumble(bool small) {
    actAlign[small ? 0 : 1] = 0;
    padSetActDirect(0, 0, actAlign);
}

bool Input::GetButtonDown(int button) {
    struct padButtonStatus buttons{};
    padRead(0, 0, &buttons);
    int padData = 0xffff ^ buttons.btns;
    int newPad = padData & ~oldPad;
    oldPad = padData;
    return newPad & button;
}
