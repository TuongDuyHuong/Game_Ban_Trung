#ifndef LOSE_SCREENVIEW_HPP
#define LOSE_SCREENVIEW_HPP

#include <gui_generated/lose_screen_screen/Lose_ScreenViewBase.hpp>
#include <gui/lose_screen_screen/Lose_ScreenPresenter.hpp>

extern int finalScore;
class Lose_ScreenView : public Lose_ScreenViewBase
{
public:
    Lose_ScreenView();
    virtual ~Lose_ScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void printScore(int finalScore);
    Unicode::UnicodeChar txtBuffer1[20];
protected:
};

#endif // LOSE_SCREENVIEW_HPP
