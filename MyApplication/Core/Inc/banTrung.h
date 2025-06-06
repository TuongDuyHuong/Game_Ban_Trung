#ifndef BAN_TRUNG_H
#define BAN_TRUNG_H

struct Egg {
    int x, y, c;
    Egg(int x = 0, int y = 0, int c = 1);
};

int randColor(); // hàm rand() màu
void addRowEgg();//hàm thêm hàng trứng trên cùng
void destroyEgg(Egg e);// hàm phá hủy trứng
void updateStatus(Egg e); // hàm cập nhật tình trạng trứng
void standardization(Egg &e);// hàm chuẩn hóa vị trí trứng
int distance(Egg e, int x, int y);// hàm tính khoảng cách
void updateGridEgg(Egg e);// hàm cập nhật lưới trứng
int isCollide(Egg e1, Egg e2);// hàm kiểm tra va chạm của 2 trứng
int isFinishGame();// hàm kiểm tra kết thúc game

// Exported game data
extern Egg arrEgg[100];// mảng chứa lưới trứng hiện tại
extern int arrEggLen; // số lượng phần tử
extern int statusEgg[100];
extern int visited[100];
extern int desEgg[100];
extern int desEggLen;
extern int head[8];
extern int headLen;
extern int isEvenRow;
/*
trứng có 4 màu ứng với các số 1,2,3,4 (red,blue,green,yellow)
trứng có c = 5(là trứng chuẩn bị bị phá hủy)
trứng có c = 6 là trứng chuẩn bị rơi
*/
#endif
