//
// Created by Alessandro Mascolo on 19/08/24.
//

#include <ScreenManager.h>
#include <Renderables/Texture.h>
#include <Renderables/Square.h>

class MainScreen: public Screen {
public:
    explicit MainScreen(ScreenManager* manager): opX(1), opY(1), opA(1), bkg(0, 0, manager->GetGSGLobal()->Width, manager->GetGSGLobal()->Height, Colors::Red), x(0), y(0), alpha(1) {
        pafLogo = manager->EmitTextureRenderable("host:res/paf.tiff", 0, 0);
        Renderables = {&bkg, &pafLogo};
        w = manager->GetGSGLobal()->Width - pafLogo.GetWidth();
        h = manager->GetGSGLobal()->Height - pafLogo.GetHeight();
    }
    void Update() override {
        x += opX;
        y += opY;
        alpha += 0.01f * opA;
        pafLogo.SetAlpha(alpha);
        pafLogo.Move(x, y);
    }

    void PreUpdate() override {
        if (x > w) opX = -1;
        if (x < 0) opX = 1;
        if (y > h) opY = -1;
        if (y < 0) opY = 1;
        if (alpha >= 1) opA = -1;
        if (alpha <= 0) opA = 1;
    }
private:
    int opX, opY, opA;
    int w;
    int h;
    Texture pafLogo;
    Square bkg;
    int x;
    int y;
    float alpha;
};

int main() {
    ScreenManager manager;
    MainScreen screen(&manager);
    manager.SwitchScreen(&screen);
    manager.Main();
}