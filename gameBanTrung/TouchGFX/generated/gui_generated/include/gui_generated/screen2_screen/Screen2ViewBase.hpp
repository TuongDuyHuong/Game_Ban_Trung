/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN2VIEWBASE_HPP
#define SCREEN2VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ButtonWithIcon.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextureMapper.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class Screen2ViewBase : public touchgfx::View<Screen2Presenter>
{
public:
    Screen2ViewBase();
    virtual ~Screen2ViewBase();
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void Shoot()
    {
        // Override and implement this function in Screen2
    }
    virtual void Left()
    {
        // Override and implement this function in Screen2
    }
    virtual void Right()
    {
        // Override and implement this function in Screen2
    }
    virtual void Swap()
    {
        // Override and implement this function in Screen2
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image image1;
    touchgfx::ButtonWithIcon home;
    touchgfx::ButtonWithIcon right;
    touchgfx::Button left;
    touchgfx::Image egg2;
    touchgfx::ButtonWithIcon swap;
    touchgfx::ButtonWithIcon shoot;
    touchgfx::TextureMapper line;
    touchgfx::TextureMapper gun;
    touchgfx::Image egg1;
    touchgfx::TextAreaWithOneWildcard point;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen2ViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // SCREEN2VIEWBASE_HPP
