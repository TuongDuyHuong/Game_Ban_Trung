#ifndef SCREEN1_5VIEW_HPP
#define SCREEN1_5VIEW_HPP

#include <gui_generated/screen1_5_screen/Screen1_5ViewBase.hpp>
#include <gui/screen1_5_screen/Screen1_5Presenter.hpp>

extern int gameMode; // chế độ chơi: 0: giới hạn, 1 : không giới hạn
extern int number_of_lines;

class Screen1_5View : public Screen1_5ViewBase
{
public:
    Screen1_5View();
    virtual void set_classic_mode();
    virtual void set_new_mode();
    virtual ~Screen1_5View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREEN1_5VIEW_HPP
