#include "MyApplication/Core/Inc/banTrung.h"
#include<math.h>
#include <cstdlib>
// #include "stm32f4xx_hal.h" 
Egg::Egg(int x, int y, int c) : x(x), y(y), c(c) {}
Egg arrEgg[maxEggCount];
int isEvenRow = 0;
int arrEggLen = 0;
int desEgg[maxEggCount];
int desEggLen = 0;
int statusEgg[maxEggCount];
int head[lenRow+1];
int headLen=0;
int visited[maxEggCount];
extern int maxCountRow;
extern int countRow;
int randColor(){
    return rand() % 4 + 1;
}
// int randColor() {
//     uint32_t randomNumber;
//     if (HAL_RNG_GenerateRandomNumber(&hrng, &randomNumber) == HAL_OK) {
//         return (randomNumber % 4) + 1; // Giá trị từ 1 đến 4
//     } else {
//         return 1; 
//     }
// }
void addRowEgg(){
    if(maxCountRow<0);
    else if(countRow>=maxCountRow) return;
    for(int i=0;i<arrEggLen;i++){
        arrEgg[i].y+=sizeEgg;
    }
    int addCount=(isEvenRow==0?lenRow:lenRow-1);
    // arrEggLen+=addCount;
    isEvenRow=1-isEvenRow;
    for(int i=0;i<addCount;i++){
        arrEgg[arrEggLen++] = Egg(sizeEgg*i+(1-isEvenRow)*(sizeEgg/2)+(240-sizeEgg*lenRow)/2,0,randColor());
    }
    countRow++;
}
// void destroyEgg(Egg e){
//     for(int i=0;i<arrEggLen;i++){
//         if(isCollide(arrEgg[i],e)&&arrEgg[i].c==e.c&&visited[i]==0){
//             desEgg[desEggLen++]=i;
//             visited[i]=1;
//             destroyEgg(arrEgg[i]);
//         }
//     }
// }
void destroyEgg(Egg e) {
    Egg stack[maxEggCount]; // Đặt giới hạn kích thước phù hợp với ứng dụng
    int top = -1;

    // Đưa quả trứng đầu tiên vào ngăn xếp
    stack[++top] = e;

    while (top >= 0) {
        // Lấy quả trứng từ ngăn xếp
        Egg current = stack[top--];

        for (int i = 0; i < arrEggLen; i++) {
            if (isCollide(arrEgg[i], current) && arrEgg[i].c == current.c && visited[i] == 0) {
                desEgg[desEggLen++] = i;
                visited[i] = 1;
                stack[++top] = arrEgg[i]; // Đưa quả trứng này vào ngăn xếp để xử lý tiếp
            }
        }
    }
}
void updateStatus(Egg e) {
    Egg stack[maxEggCount]; // Tùy chỉnh kích thước phù hợp với hệ thống
    int top = -1;

    stack[++top] = e;

    while (top >= 0) {
        Egg current = stack[top--];

        for (int i = 0; i < arrEggLen; i++) {
            if (isCollide(current, arrEgg[i]) && statusEgg[i] == 0) {
                statusEgg[i] = 2;
                stack[++top] = arrEgg[i];
            }
        }
    }
}

// void updateStatus(Egg e){
//     for(int i=0;i<arrEggLen;i++){
//         if(isCollide(e,arrEgg[i])&&statusEgg[i]==0){
//             statusEgg[i]=2;
//             updateStatus(arrEgg[i]);
//         }
//     }
// }
void standardization(Egg &e){
    for(int i=0;i<arrEggLen;i++){
        if(isCollide(arrEgg[i],e)){
            int centerx=arrEgg[i].x,centery=arrEgg[i].y;
            int x[6]={centerx+sizeEgg/2,centerx-sizeEgg/2,centerx+sizeEgg,centerx-sizeEgg,centerx+sizeEgg/2,centerx-sizeEgg/2};
            int y[6]={centery+sizeEgg,centery+sizeEgg,centery,centery,centery-sizeEgg,centery-sizeEgg};
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
    	int marginLeft = (1-isEvenRow)*(sizeEgg/2)+(240-sizeEgg*lenRow)/2;
    	int x = (e.x-marginLeft)/sizeEgg;
    	if(distance(e,x*sizeEgg+marginLeft,0)>distance(e,x*sizeEgg+sizeEgg+marginLeft,0)){
    		e.x=x*sizeEgg+sizeEgg+marginLeft;
    	} else e.x=x*sizeEgg+marginLeft;
    }
}
int distance(Egg e,int x,int y){
    return (e.x-x)*(e.x-x)+(e.y-y)*(e.y-y);
}
void updateGridEgg(Egg e){
    standardization(e);
    Egg tmp[maxEggCount];
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
}
void deleteEggDesAndFall(){
	    Egg tmp[maxEggCount];
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
    if(abs(e1.x - e2.x)<=sizeEgg&&abs(e1.y-e2.y)<=sizeEgg) return 1;
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
int isWin(){
    return arrEggLen<=0;
}