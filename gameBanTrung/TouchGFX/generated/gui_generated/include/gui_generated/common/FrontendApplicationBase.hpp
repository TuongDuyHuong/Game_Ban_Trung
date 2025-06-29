/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    virtual void changeToStartScreen()
    {
        gotoScreen1ScreenNoTransition();
    }

    // Screen1
    void gotoScreen1ScreenNoTransition();

    void gotoScreen1ScreenSlideTransitionWest();

    // Screen2
    void gotoScreen2ScreenNoTransition();

    // Screen1_5
    void gotoScreen1_5ScreenSlideTransitionEast();

    // Win_Screen
    void gotoWin_ScreenScreenNoTransition();

    // Lose_Screen
    void gotoLose_ScreenScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Screen1
    void gotoScreen1ScreenNoTransitionImpl();

    void gotoScreen1ScreenSlideTransitionWestImpl();

    // Screen2
    void gotoScreen2ScreenNoTransitionImpl();

    // Screen1_5
    void gotoScreen1_5ScreenSlideTransitionEastImpl();

    // Win_Screen
    void gotoWin_ScreenScreenNoTransitionImpl();

    // Lose_Screen
    void gotoLose_ScreenScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
