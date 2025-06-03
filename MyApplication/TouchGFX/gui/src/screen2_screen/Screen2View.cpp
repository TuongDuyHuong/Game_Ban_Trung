#include <gui/screen2_screen/Screen2View.hpp>
#ifndef SIMULATOR
#include "cmsis_os.h"
#endif
Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}
void Screen2View::handleTickEvent(){
	Screen2ViewBase::handleTickEvent();
	uint8_t res=0;

	uint32_t count = osMessageQueueGetCount(Queue1Handle);
	if(count>0){
		if(status==0){
			tickCount++;
		} else {
			tickCount--;
		}
		if(tickCount==430) status=1;
		if(tickCount==290) status=0;
		osMessageQueueGet(Queue1Handle,&res,NULL,osWaitForever);
		if(res=='P'){
			rad = (tickCount % 360)*3.14f/180;
			gun.updateZAngle(rad);
		}
	}
	// hàm bắn
	if(isShoot==1){
		int x = egg.getX();
		int y = egg.getY();
		// Va vào tường trái
		if (x <= 0 && tmpCount > 0 && tmpCount < 90) {
		    tmpCount = 180 - tmpCount;
		}
		// Va vào tường phải
		if (x >= 240 - 32 && tmpCount > 90) {
		    tmpCount = 180 - tmpCount;
		}
		if (y > 0)
		{
			egg.invalidate();
			float angle = tmpCount * 3.14f / 180.0f;
			egg.setXY(x - 2*tan(angle), y - 2);
			egg.invalidate();
		}
		else
		{
			isShoot=0;
		}
	}

}
void Screen2View::shoot()
{
	isShoot = 1;
	tmpCount = 360 - tickCount;
	if(tmpCount<0) tmpCount=tmpCount+180;
}
