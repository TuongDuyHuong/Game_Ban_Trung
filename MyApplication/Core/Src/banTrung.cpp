#include "banTrung.h"
#include<math.h>
#include <cstdlib>
// class Egg {
//     constructor(x = 0, y = 0, c = 1) {
//         this.x = x;
//         this.y = y;
//         this.c = c;
        
//     }
// }
Egg::Egg(int x, int y, int c) : x(x), y(y), c(c) {}
// var arrEgg = [];
// var isEvenRow = 0;
// var n = 0;
// var desEgg = []
// var desCount = 0 
// var statusEgg =[]
// var head = [] 
// var visited = []

Egg arrEgg[100];
int isEvenRow = 0;
int arrEggLen = 0;
int desEgg[100];
int desEggLen = 0;
int statusEgg[100];
int head[8];
int headLen=0;
int visited[100];

// addRowEgg()
// show()
// document.querySelector(".shoot").addEventListener("click",e=>{
//     var e = new Egg(parseInt(document.querySelector(".x").value),
//   parseInt(document.querySelector(".y").value),
//   parseInt(document.querySelector(".c").value)
// )
// // console.log(arrEgg);
// updateGridEgg(e)
// addRowEgg()
// show()
// if(isFinishGame()){
//     document.querySelector(".container").innerHTML="<h1> game over</h1>"
// }
// })
// function rand(){
//     return Math.floor(Math.random() * 4) + 1;
// }
int randColor(){
    return rand() % 4 + 1;
}

// function addRowEgg(){
//     for(var i=0;i<n;i++){
//         arrEgg[i].y+=32;
//     }
//     var addCount=(isEvenRow==0?7:6);
//     n+=addCount;
//     isEvenRow=1-isEvenRow
//     for(var i=0;i<addCount;i++){
//         arrEgg.push(new Egg(32*i-isEvenRow*16+24,0,rand()));
//     }
// }
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
// function destroy(e){
//     console.log(e);
    
//     for(var i=0;i<n;i++){
//         if(isCollide(arrEgg[i],e)&&arrEgg[i].c==e.c&&visited[i]==0){
//             desEgg.push(i)
//             desCount++
//             visited[i]=1
//             destroy(arrEgg[i])
//         }
//     }
// }
void destroyEgg(Egg e){
    for(int i=0;i<arrEggLen;i++){
        if(isCollide(arrEgg[i],e)&&arrEgg[i].c==e.c&&visited[i]==0){
            desEgg[desEggLen++]=i;
            visited[i]=1;
            destroyEgg(arrEgg[i]);
        }
    }
}
// function updateStatus(e){
//     for(var i=0;i<n;i++){
//         if(isCollide(e,arrEgg[i])&&statusEgg[i]==0){
//             statusEgg[i]=2
//             updateStatus(arrEgg[i])
//         } 
//     }
// }
void updateStatus(Egg e){
    for(int i=0;i<arrEggLen;i++){
        if(isCollide(e,arrEgg[i])&&statusEgg[i]==0){
            statusEgg[i]=2;
            updateStatus(arrEgg[i]);
        }
    }
}
// function standardization(e){
//     for(var i=0;i<n;i++){
//         if(isCollide(arrEgg[i],e)){
//             var x = [arrEgg[i].x+16,arrEgg[i].x-16,arrEgg[i].x+32,arrEgg[i].x-32,arrEgg[i].x+16,arrEgg[i].x-16]
//             var y = [arrEgg[i].y+32,arrEgg[i].y+32,arrEgg[i].y,arrEgg[i].y,arrEgg[i].y-32,arrEgg[i].y-32]
//             var indexMin = 0
//             var Min = distance(e,x[0],y[0]) 
//             for(var j=1;j<6;j++){
//                 if(Min>distance(e,x[j],y[j])){
//                     indexMin = j
//                     Min = distance(e,x[j],y[j])
//                 }
//             }
//             e.x=x[indexMin]
//             e.y=y[indexMin]
//             return
//         }
//     }
// }
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
}
// function distance(e,x,y){
//     return (e.x-x)*(e.x-x)+(e.y-y)*(e.y-y)
// }
int distance(Egg e,int x,int y){
    return (e.x-x)*(e.x-x)+(e.y-y)*(e.y-y);
}
// function updateGridEgg(e){
//     standardization(e)
//     var tmp = []
//     var tmpn=0
//     for(var i=0;i<n;i++){
//         if(arrEgg[i].c<5) {tmp.push(arrEgg[i]);tmpn++}
//     }
//     arrEgg.length=0
//     arrEgg = tmp
//     n=tmpn
//     head.length=0
//     desEgg.length=0
//     desCount=0
//     desEgg.push(n)
//     desCount=1
//     n+=1
//     arrEgg.push(e)
//     visited.length=0
//     for(var i=0;i<n;i++){
//         visited.push(0)
//     }
//     visited[n-1]=1
//     destroy(e)
//     if(desCount<3) return
//     statusEgg.length=0
//     for(var i=0;i<n;i++){
//         statusEgg.push(0)
//     }
//     for(var i=0;i<desCount;i++){
//         statusEgg[desEgg[i]]=1
//     }
//     for(var i=0;i<n;i++){
//         if(statusEgg[i]==0&&arrEgg[i].y==0) head.push(i)
//     }
//     for(var i=0;i<head.length;i++){
//         statusEgg[head[i]]=2
//         console.log(statusEgg[head[i]]);
//         updateStatus(arrEgg[head[i]])
//     }
//     console.log(statusEgg);
    
//     for(var i=0;i<n;i++){
//         switch (statusEgg[i]) {
//             case 0:
//                 arrEgg[i].c=6
//                 break;
//             case 1:
//                 arrEgg[i].c=5
//                 break;
//             default:
//                 break;
//         }
//     }
//     // var tmp = []

// }
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
}
// function isCollide(e1,e2){
// if(Math.abs(e1.x-e2.x)==0&&Math.abs(e1.y-e2.y)==0) return false
// if(Math.abs(e1.x-e2.x)<=32&&Math.abs(e1.y-e2.y)<=32) return true;
// return false;
// }
int isCollide(Egg e1,Egg e2){
    if(abs(e1.x - e2.x)==0&&abs(e1.y-e2.y)==0) return 0;
    if(abs(e1.x - e2.x)<=32&&abs(e1.y-e2.y)<=32) return 1;
    return 0;
}
// function isFinishGame(){
//     for(var i=0;i<n;i++){
//         if(arrEgg[i].c<5&&arrEgg[i].y>=224) {return true}
//     }
//     return false;
// }
int isFinishGame(){
    for(int i=0;i<arrEggLen;i++){
        if(arrEgg[i].c<5&&arrEgg[i].y>=224) return 1;
    }
    return 0;
}
// function show() {
//     document.querySelector(".container").innerHTML=""
//     for (var i = 0; i < n; i++) {
//         var div = document.createElement("div");
//         div.classList.add("egg");

//         switch (arrEgg[i].c) {
//             case 1:
//                 div.classList.add("red");
//                 break;
//             case 2:
//                 div.classList.add("blue");
//                 break;
//             case 3:
//                 div.classList.add("green");
//                 break;
//             case 4:
//                 div.classList.add("yellow");
//                 break;
//             case 5:
//                 div.classList.add("destroy");
//                 break;
//             case 6:
//                 div.classList.add("fall");
//                 break;
//         }

//         div.style.position = "absolute";
//         div.style.top = arrEgg[i].y + "px";
//         div.style.left = arrEgg[i].x + "px";

//         document.querySelector(".container").appendChild(div);
//     }
// }
