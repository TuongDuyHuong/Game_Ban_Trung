#ifndef BAN_TRUNG_H
#define BAN_TRUNG_H

struct Egg {
    int x, y, c;
    Egg(int x = 0, int y = 0, int c = 1);
};
#define sizeEgg 30 // kích thước của trứng
#define lenRow 7 // số trứng tối đa trên 1 hàng
#define maxEggCount 100 // giá trị tối đa của mảng lưu lưới trứng
#define startShootx 110 // tọa độ đầu tiên của trứng trước khi bắn
#define startShooty 278 
int randColor(); // hàm rand() màu
void addRowEgg();//hàm thêm hàng trứng trên cùng
void destroyEgg(Egg e);// hàm phá hủy trứng
void updateStatus(Egg e); // hàm cập nhật tình trạng trứng
void standardization(Egg &e);// hàm chuẩn hóa vị trí trứng
int distance(Egg e, int x, int y);// hàm tính khoảng cách
void updateGridEgg(Egg e);// hàm cập nhật lưới trứng đưa các trứng bị phá về c=5 bị rơi về c=6
int isCollide(Egg e1, Egg e2);// hàm kiểm tra va chạm của 2 trứng
int isFinishGame();// hàm kiểm tra kết thúc game
int isStop(Egg e);// hàm kiểm tra điều kiện dừng khi trứng đang bay( trứng bay khi được bắn ra)
void deleteEggDesAndFall();// hàm xóa các phần tử có c=5 và 6 (trứng bị phá và bị rơi)
int isWin();// kiểm tra win chưa
// Exported game data
int maxCountRow;// số hàng tối đa, nếu bằng -1 thì có nghĩa là không giới hạn số hàng
int countRow=0;//số hàng trứng hiện tại
extern Egg arrEgg[maxEggCount];// mảng chứa lưới trứng hiện tại
extern int arrEggLen;// số lượng phần tử
extern int statusEgg[maxEggCount];
extern int visited[maxEggCount];
extern int desEgg[maxEggCount];
extern int desEggLen;
extern int head[lenRow+1];
extern int headLen;
extern int isEvenRow;
/*
trứng có 4 màu ứng với các số 1,2,3,4 (red,blue,green,yellow)
trứng có c = 5(là trứng chuẩn bị bị phá hủy)
trứng có c = 6 là trứng chuẩn bị rơi
*/
#endif
