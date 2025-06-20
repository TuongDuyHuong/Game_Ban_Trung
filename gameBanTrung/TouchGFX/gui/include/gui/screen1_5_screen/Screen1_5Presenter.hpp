#ifndef SCREEN1_5PRESENTER_HPP
#define SCREEN1_5PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen1_5View;

class Screen1_5Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen1_5Presenter(Screen1_5View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Screen1_5Presenter() {}

private:
    Screen1_5Presenter();

    Screen1_5View& view;
};

#endif // SCREEN1_5PRESENTER_HPP
