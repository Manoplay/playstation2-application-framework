//
// Created by Alessandro Mascolo on 19/08/24.
//

#include "System.h"
#include <libpwroff.h>
#include <sifrpc.h>
#include <loadfile.h>
#include <stdio.h>

System* System::instance = new System();

System *System::Shared() {
    return instance;
}

void System::Shutdown() {
    SifInitRpc(0);
    int result;
    SifLoadFileInit();
    if ((result = SifLoadModule("host:poweroff.irx", 0, nullptr)) < 0)
    {
        printf("Could not load \"host:poweroff.irx\": %d\n", result);
        return;
    }
    poweroffInit();
    for (auto & closeable : instance->closeables) {
        closeable->Close();
    }
    poweroffShutdown();
}

void System::AddResource(Closeable* closeable) {
    closeables.push_back(closeable);
}
