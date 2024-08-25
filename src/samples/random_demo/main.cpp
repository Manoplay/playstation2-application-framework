//
// Created by Alessandro Mascolo on 26/05/24.
//


#include <input.h>
#include <ScreenManager.h>
#include <PAFTimer.h>
#include <PAFInput.h>
#include <Renderables/Square.h>

class MainScreen: public Screen {
public:
    explicit MainScreen(ScreenManager* screenManager): timer(2000) {
        this->mainMessage = screenManager->EmitFontMRenderable("Hello", 20, 20);
        this->testPic = screenManager->EmitTextureRenderable("host:res/alpha.tiff", 60, 60);
        bkColor = Colors::BlueTrans;
        // SetRenderableCount(3);
        Renderables = {&mainMessage, &testPic, &square};
    }

    void Update() override {
        if (timer.Check()) {
            timer.Stop();
            mainMessage.SetText("What's up?");
            testPic.Move(0, 0);
        }
        if (Input::Shared()->GetButton(PAD_CROSS)) {
            mainMessage.Move(45, 45);
        } else {
            mainMessage.Move(20, 20);
        }
    };
    void PreUpdate() override {
    };

private:
    Timer timer;
    FontM mainMessage;
    Texture testPic;
    Square square{90, 90, 100, 100, Colors::Red};
};

int main() {
    ScreenManager screenManager;
    MainScreen mainScreen(&screenManager);
    screenManager.SwitchScreen(&mainScreen);
    screenManager.Main();
}