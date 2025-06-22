#ifndef WIN_SCREENVIEW_HPP
#define WIN_SCREENVIEW_HPP

#include <gui_generated/win_screen_screen/Win_ScreenViewBase.hpp>
#include <gui/win_screen_screen/Win_ScreenPresenter.hpp>

class Win_ScreenView : public Win_ScreenViewBase
{
public:
    Win_ScreenView();
    virtual ~Win_ScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // WIN_SCREENVIEW_HPP
