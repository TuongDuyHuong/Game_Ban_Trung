#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <touchgfx/Bitmap.hpp>
#include <images/BitmapDatabase.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <math.h>
#include <stdio.h>

struct Egg {
    int x, y, c;
    Egg(int x = 0, int y = 0, int c = 1);
};
#define sizeEgg 24
#define lenRow 10
#define maxEggCount 100
#define startShootx 108
#define startShooty 279
#define POINT_SIZE 10
extern Egg arrEgg[maxEggCount];
extern int arrEggLen;
extern int statusEgg[maxEggCount];
extern int visited[maxEggCount];
extern int desEgg[maxEggCount];
extern int desEggLen;
extern int head[lenRow+1];
extern int headLen;
extern int isEvenRow;
extern int isStopShoot;
extern int oldScore;
extern int finalScore;
int randColor();
void addRowEgg();
void destroyEgg(Egg e);
void updateStatus(Egg e);
void standardization(Egg &e);
int distance(Egg e, int x, int y);
void updateGridEgg(Egg e);
int isCollide(Egg e1, Egg e2);
int isFinishGame();
int isStop(Egg e);
void deleteEggDesAndFall();
int CountEggsonScreen();
class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    virtual void Shoot();
    virtual void Left();
    virtual void Right();
    virtual void Swap();
    uint32_t tickCount = 290;
    int leftEvent = 0;
    int rightEvent = 0;
    int egg1Color;
    int egg2Color;
    int isShoot=0;
    float speedx=0;
    float speedy=0;
    float prex,prey;
    int lines;
    int score;
    touchgfx::BitmapId getEggBitmap(int color);
    touchgfx::Image image[100];
    int imageLen=0;
    int isFall=0;
    int isFinishFall=0;
    void Show();
    int CalculateScore();
    Unicode::UnicodeChar txtBuffer[20];
    void updatePoint(int score);
protected:

};

#endif // SCREEN2VIEW_HPP
