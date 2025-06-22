#ifndef WIN_SCREENPRESENTER_HPP
#define WIN_SCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Win_ScreenView;

class Win_ScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Win_ScreenPresenter(Win_ScreenView& v);

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

    virtual ~Win_ScreenPresenter() {}

private:
    Win_ScreenPresenter();

    Win_ScreenView& view;
};

#endif // WIN_SCREENPRESENTER_HPP
