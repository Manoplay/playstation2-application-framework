//
// Created by Alessandro Mascolo on 19/08/24.
//

#ifndef PS2APP_SYSTEM_H
#define PS2APP_SYSTEM_H


#include <vector>
#include "Closeable.h"

class System {
public:
    static System* Shared();
    static void Shutdown();
    void AddResource(Closeable* closeable);
private:
    static System *instance;
    std::vector<Closeable*> closeables;
};


#endif //PS2APP_SYSTEM_H
