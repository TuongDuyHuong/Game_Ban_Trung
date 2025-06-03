#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include "cmsis_os.h"
#include <touchgfx/widgets/Image.hpp>
#include <math.h>
extern osMessageQueueId_t Queue1Handle;
class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void shoot();
    void handleTickEvent();
    uint32_t tickCount=290;
    uint32_t status = 0;
    uint32_t isShoot = 0;
	float rad=0;
	uint32_t tmpCount;
protected:
};

#endif // SCREEN2VIEW_HPP
