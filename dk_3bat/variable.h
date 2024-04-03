#ifndef robot
#define robot

// khai báo chân điều khiển driver TB6600
#define pulsePin1 46 //pin driver --- pin arduino 
#define dirPin1   48 // mức 0 thì chạy thuận , mức 1 nghịch
#define enpin1    50 // mức 0 thì driver hoạt động

#define pulsePin2 40
#define dirPin2   42
#define enpin2    44

#define pulsePin3 34
#define dirPin3   36
#define enpin3    38
//khai báo nút bấm
#define buttonStart 5
#define buttonStop 4
#define buttonReset 3
//khai báo đèn tín 
#define redLed 8
#define greenLed 7
#define yellowLed 6

#define onLed 1
#define offLed 0


#define step1Max 4200 // 4.5(tỉ số truyền) * 1600(số bước quay 1 vòng step) * 210/360 độ
#define step2Max 1600 // 1(tỉ số truyền)*1600(số bước quay 1 vòng step)
#define step3Max 21408  // 83.77 * 400 * 230/360
#define Angle_joint_Max1  210
#define Angle_joint_Max2  360
#define Angle_joint_Max3  230  // 225 220

FaBoPWM faboPWM;
//khai báo biến cho chương trình code
volatile bool timer1Enabled = false; // biến sử dụng để tạo timer cho step1 felse step 1 ko chạy, true step chay
volatile bool timer2Enabled = false;
volatile bool timer3Enabled = false;
// trạng thái pin của pulsePin
bool statePin1 = 0; 
bool statePin2 = 0;
bool statePin3 = 0;
unsigned int countPulse1; //đếm số lượng xung
unsigned int countPulse2; 
unsigned int countPulse3;
unsigned int numPulse1; // nhận số lượng xung từ mãng joint1
unsigned int numPulse2;
unsigned int numPulse3;
int counterTim1 =0;
int counterTim2 =0;
int counterTim3 =0;
int curAngle1 =0;
int curAngle2 =0;
int curAngle3 =0;
int lastAngle1=100;
int lastAngle2=100;
int lastAngle3=100;

volatile bool start = 0; //biến ghi nhớ trạng thái của nút bấm start stop
volatile bool reset = 0;

int bstart =0;
int breset =0;
int bstop =0;
int timer = 0;

int speed = 5;
int joint1 = 0;
int joint2 = 0;
int joint3 = 0;
int gipper = 0;

bool c =0;//biến định vị trí của hàm controlJoint

#endif
