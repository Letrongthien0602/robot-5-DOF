#ifndef robot
#define robot
// khai báo chân điều khiển driver TB6600
#define pulsePin1 46 //pin driver --- pin arduino 
#define dirPin1   48 // mức 0 thì chạy thuận , mức 1 nghịch
#define enpin1    50 // mức 0 thì driver hoạt động
//khai báo nút bấm
#define buttonStart 5
#define buttonStop 4
//khai báo đèn tín 
//khai báo đèn tín 
#define redLed 8
#define greenLed 7
#define yellowLed 6

#define onLed 1
#define offLed 0

#define step1Max 4200 // 4.5(tỉ số truyền) * 1600(số bước quay 1 vòng step)
//khai báo biến cho chương trình code
FaBoPWM faboPWM;
volatile bool timer1Enabled = false; 
bool statePin1 = 0; // trạng thái pin của pulsePin1
bool start = 0; //biến ghi nhớ trạng thái của nút bấm start stop
unsigned int countPulse1; //đếm số lượng xung
unsigned int numPulse1; // nhận số lượng xung từ mãng joint1
String inputString; // biến nhận dữ liệu từ máy tính
int timer = 0;
bool T1 = false;
int curAngle =0;
int lastAngle =0;
#endif
