#include <gui/screen2_screen/Screen2View.hpp>

#include<math.h>
#include <cstdlib>
Egg::Egg(int x, int y, int c) : x(x), y(y), c(c) {}
Egg arrEgg[100];
int isEvenRow = 0;
int arrEggLen = 0;
int desEgg[100];
int desEggLen = 0;
int statusEgg[100];
int head[8];
int headLen=0;
int visited[100];
int randColor(){
    return rand() % 4 + 1;
}
void addRowEgg(){
    for(int i=0;i<arrEggLen;i++){
        arrEgg[i].y+=32;
    }
    int addCount=(isEvenRow==0?7:6);
    // arrEggLen+=addCount;
    isEvenRow=1-isEvenRow;
    for(int i=0;i<addCount;i++){
        arrEgg[arrEggLen++] = Egg(32*i-isEvenRow*16+24,0,randColor());
    }
}
void destroyEgg(Egg e){
    for(int i=0;i<arrEggLen;i++){
        if(isCollide(arrEgg[i],e)&&arrEgg[i].c==e.c&&visited[i]==0){
            desEgg[desEggLen++]=i;
            visited[i]=1;
            destroyEgg(arrEgg[i]);
        }
    }
}
void updateStatus(Egg e){
    for(int i=0;i<arrEggLen;i++){
        if(isCollide(e,arrEgg[i])&&statusEgg[i]==0){
            statusEgg[i]=2;
            updateStatus(arrEgg[i]);
        }
    }
}
void standardization(Egg &e){
    for(int i=0;i<arrEggLen;i++){
        if(isCollide(arrEgg[i],e)){
            int centerx=arrEgg[i].x,centery=arrEgg[i].y;
            int x[6]={centerx+16,centerx-16,centerx+32,centerx-32,centerx+16,centerx-16};
            int y[6]={centery+32,centery+32,centery,centery,centery-32,centery-32};
            int indexMin = 0;
            int minDistance = distance(e,x[0],y[0]);
            for(int j=1;j<6;j++){
                int d = distance(e,x[j],y[j]);
                if(minDistance>d){
                    indexMin=j;
                    minDistance = d;
                }
            }
            e.x=x[indexMin];
            e.y=y[indexMin];
            return;
        }
    }
    if(e.y==0){
    	//1:8 0:24
    	int marginLeft = (isEvenRow==0?24:8);
    	int x = (e.x-marginLeft)/32;
    	if(distance(e,x*32+marginLeft,0)>distance(e,x*32+32+marginLeft,0)){
    		e.x=x*32+32+marginLeft;
    	} else e.x=x*32+marginLeft;
    }
}
int distance(Egg e,int x,int y){
    return (e.x-x)*(e.x-x)+(e.y-y)*(e.y-y);
}
void updateGridEgg(Egg e){
    standardization(e);
    Egg tmp[100];
    int tmpLen = 0;
    for(int i=0;i<arrEggLen;i++){
        if(arrEgg[i].c<5) {
            tmp[tmpLen++] = arrEgg[i];
        }
    }
    arrEggLen=tmpLen;
    for(int i=0;i<arrEggLen;i++){
            arrEgg[i]=tmp[i];
    }
    headLen=0;
    desEggLen=1;
    desEgg[0]=arrEggLen;
    arrEgg[arrEggLen++]=e;
    for(int i=0;i<arrEggLen;i++){
        visited[i]=0;
    }
    visited[arrEggLen-1]=1;
    destroyEgg(e);
    if(desEggLen<3) return;
    for(int i=0;i<arrEggLen;i++){
        statusEgg[i]=0;
    }
    for(int i=0;i<desEggLen;i++){
        statusEgg[desEgg[i]]=1;
    }
    for(int i=0;i<arrEggLen;i++){
        if(statusEgg[i]==0&&arrEgg[i].y==0) head[headLen++]=i;
    }
    for(int i=0;i<headLen;i++){
        statusEgg[head[i]]=2;
        updateStatus(arrEgg[head[i]]);
    }
    for(int i=0;i<arrEggLen;i++){
        switch (statusEgg[i]) {
            case 0:
                arrEgg[i].c=6;
                break;
            case 1:
                arrEgg[i].c=5;
                break;
            default:
                break;
        }
    }
//   tmpLen = 0;
//   for(int i=0;i<arrEggLen;i++){
//	   if(arrEgg[i].c<5) {
//		   tmp[tmpLen++] = arrEgg[i];
//	   }
//   }
//   arrEggLen=tmpLen;
//   for(int i=0;i<arrEggLen;i++){
//		   arrEgg[i]=tmp[i];
//   }
}
void deleteEggDesAndFall(){
	    Egg tmp[100];
	    int tmpLen = 0;
	    for(int i=0;i<arrEggLen;i++){
	        if(arrEgg[i].c<5) {
	            tmp[tmpLen++] = arrEgg[i];
	        }
	    }
	    arrEggLen=tmpLen;
	    for(int i=0;i<arrEggLen;i++){
	            arrEgg[i]=tmp[i];
	    }
}
int isCollide(Egg e1,Egg e2){
	if(e1.c>4||e2.c>4) return 0;
    if(abs(e1.x - e2.x)==0&&abs(e1.y-e2.y)==0) return 0;
    if(abs(e1.x - e2.x)<=32&&abs(e1.y-e2.y)<=32) return 1;
    return 0;
}
int isFinishGame(){
    for(int i=0;i<arrEggLen;i++){
        if(arrEgg[i].c<5&&arrEgg[i].y>=224) return 1;
    }
    return 0;
}
int isStop(Egg e){
	for(int i=0;i<arrEggLen;i++){
		if(isCollide(e,arrEgg[i])==1) return 1;
	}
	return 0;
}
touchgfx::BitmapId Screen2View::getEggBitmap(int color)
{
    switch (color)
    {
        case 1: return BITMAP_EGG_RED_ID;
        case 2: return BITMAP_EGG_BLUE_ID;
        case 3: return BITMAP_EGG_GREEN_ID;
        case 4: return BITMAP_EGG_YELLOW_ID;
        default: return BITMAP_EGG_RED_ID;
    }
}
void Screen2View::Show() {
    for (int i = 0; i < imageLen; i++) {
    	image[i].invalidate();
    	remove(image[i]);
    }
    imageLen = 0;

    for (int i = 0; i < arrEggLen; i++) {
    	if(arrEgg[i].c>4){
    		image[i].setVisible(false);
    	}
        image[i].setBitmap(getEggBitmap(arrEgg[i].c));
        image[i].setXY(arrEgg[i].x, arrEgg[i].y + 30);
        if (image[imageLen].getParent() == nullptr) {
                    add(image[imageLen]);
                }
        image[i].invalidate();
        imageLen++;
    }
}



Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
    arrEggLen=0;
    isEvenRow=0;
    egg1Color = randColor();
    egg2Color = randColor();
    egg1.setBitmap(getEggBitmap(egg1Color));
    egg2.setBitmap(getEggBitmap(egg2Color));
    line.updateZAngle((tickCount%360)*3.14f/180);
    gun.updateZAngle((tickCount%360)*3.14f/180);
    egg1.invalidate();
    egg2.invalidate();
    addRowEgg();
    Show();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}
void Screen2View::handleTickEvent()
{
    Screen2ViewBase::handleTickEvent();
    if(leftEvent==1){
    	if(tickCount>290) tickCount--;
    	gun.updateZAngle((tickCount%360)*3.14f/180);
    	line.updateZAngle((tickCount%360)*3.14f/180);
    	leftEvent=0;
    }
    if(rightEvent==1){
    	if(tickCount<430) tickCount++;
    	gun.updateZAngle((tickCount%360)*3.14f/180);
    	line.updateZAngle((tickCount%360)*3.14f/180);
    	rightEvent=0;
    }
    if(isShoot==1){
    	Egg e = Egg(egg1.getX(),egg1.getY()-30,egg1Color);
    	if(isStop(e)==0&&egg1.getY()>=0){
    	if(egg1.getX()<=0||egg1.getX()>=208) speedx = -speedx;
    	prex-=speedx;
    	prey-=speedy;
    	egg1.invalidate();
    	egg1.setXY(prex,prey);
    	egg1.invalidate();
    	}else{
    		isShoot=2;
    		isFall=1;
    		updateGridEgg(e);
    	}
    }
    if(isFall==1){
    	isFinishFall=1;
		for(int i=0;i<arrEggLen-1;i++){
			if(arrEgg[i].c==6||arrEgg[i].c==5){
				image[i].invalidate();
				image[i].setY(image[i].getY()+3);
				image[i].invalidate();
				if(image[i].getY()<320) isFinishFall=0;
			}
		}
		if(arrEgg[arrEggLen-1].c==5){
			egg1.invalidate();
			egg1.setY(egg1.getY()+3);
			egg1.invalidate();
			if(egg1.getY()<320) isFinishFall=0;
		}
    }
    if(isFinishFall==1){
    	isFall=0;
    	isShoot=0;
    	isFinishFall=0;
    	for(int i=0;i<arrEggLen-1;i++){
			if(arrEgg[i].c==5){
				image[i].setVisible(true);
			}
		}
    	deleteEggDesAndFall();
    	addRowEgg();
		Show();
		if(isFinishGame()==1){
//    			gameover.setVisible(true);
//    			gameover.invalidate();
//    			gameover.front();
			 gameover.setVisible(true);


				remove(gameover);
				add(gameover);

				gameover.invalidate();
			return;
		}
		egg1.invalidate();
		egg2.invalidate();
		egg1.setXY(104,272);
		egg1Color=egg2Color;
		egg2Color=randColor();
		egg1.setBitmap(getEggBitmap(egg1Color));
		egg2.setBitmap(getEggBitmap(egg2Color));
		egg1.invalidate();
		egg2.invalidate();
		isShoot=0;
    }
}
void Screen2View::Shoot()
{
	if(isShoot==0){
	if(360>tickCount){
	speedx = 2*sin((360-tickCount)*3.14f/180);
	speedy = 2*cos((360-tickCount)*3.14f/180);
	} else{
	speedx = -2*sin((tickCount-360)*3.14f/180);
	speedy = 2*cos((tickCount-360)*3.14f/180);
	}
	prex=egg1.getX();
	prey=egg1.getY();
	}
	isShoot=1;
//	addRowEgg();
//	Show();
}
void Screen2View::Left()
{
	leftEvent=1;
}
void Screen2View::Right()
{
	rightEvent=1;
}
void Screen2View::Swap()
{
	int tmp=egg1Color;
	egg1Color=egg2Color;
	egg2Color=tmp;
	egg1.setBitmap(getEggBitmap(egg1Color));
	egg2.setBitmap(getEggBitmap(egg2Color));
	egg1.invalidate();
	egg2.invalidate();
}
