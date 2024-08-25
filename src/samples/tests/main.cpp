//
// Created by Alessandro Mascolo on 19/08/24.
//

#include <Console.h>
#include <Path.h>
#include <sys/unistd.h>
#include <System.h>

int main() {
    Console::Init();
    Path path("host:res/data.txt");
    Console::Write("Generated path: %s\n", path.GeneratePath().c_str());
    path.SwitchToValidRoot();
    Console::Write("Fixed path: %s\n", path.GeneratePath().c_str());
    path.SetFolders({"test", "another", "dir"});
    Console::Write("Last modification: %s\n", path.GeneratePath().c_str());
    sleep(5);
    System::Shutdown();
}