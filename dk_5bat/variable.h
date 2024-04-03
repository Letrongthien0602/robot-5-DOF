#ifndef robot
#define robot
FaBoPWM faboPWM;
// khai báo chân điều khiển driver TB6600
#define pulsePin1 46 
#define dirPin1   48 
#define enpin1    50 
#define pulsePin2 40
#define dirPin2   42
#define enpin2    44
#define pulsePin3 34
#define dirPin3   36
#define enpin3    38
#define pulsePin4 29
#define dirPin4   31
#define enpin4    33
#define pulsePin5 22
#define dirPin5   24
#define enpin5    26
//khai báo nút bấm
#define buttonStart 3
#define buttonStop 4
#define buttonReset 5
//số bước tối đa cho mỗi joint
#define step1Max 4200     // 4.5(tỉ số truyền) * 1600(số bước quay 1 vòng step) * 210/360 độ
#define step2Max 1600    // 1(tỉ số truyền)*1600(số bước quay 1 vòng step)
#define step3Max 21408  // 83.77 * 400 * 230/360
#define step4Max 7700  // 7.7  * 800 * 225/360
#define step5Max 25324
//góc tối đa cho mỗi joint
#define Angle_joint_Max1  210
#define Angle_joint_Max2  360
#define Angle_joint_Max3  230  // 225 220
#define Angle_joint_Max4  225
#define Angle_joint_Max5  220
//số countTimer cần để tốc độ góc của 5 joint bằng nhau
#define base_joint_speed1 140
#define base_joint_speed2 628
#define base_joint_speed3 30
#define base_joint_speed4 82
#define base_joint_speed5 24
//tạo timer điều chế xung
volatile bool timer1Enabled = false; 
volatile bool timer2Enabled = false;
volatile bool timer3Enabled = false;
volatile bool timer4Enabled = false;
volatile bool timer5Enabled = false;
// trạng thái pin của pulsePin
bool statePin1 = 0;
bool statePin2 = 0;
bool statePin3 = 0;
bool statePin4 = 0;
bool statePin5 = 0;
//đếm số lượng xung
unsigned int countPulse1; 
unsigned int countPulse2;
unsigned int countPulse3;
unsigned int countPulse4;
unsigned int countPulse5;
//biến lưu số lượng xung để điều khiển cho joints
unsigned int numPulse1; 
unsigned int numPulse2;
unsigned int numPulse3;
unsigned int numPulse4;
unsigned int numPulse5;
//biến đếm timer
int counterTim1 = 0;
int counterTim2 = 0;
int counterTim3 = 0;
int counterTim4 = 0;
int counterTim5 = 0;
//góc hiện tại mà joint di chuyển tới
int curAngle1 = 0;
int curAngle2 = 0;
int curAngle3 = 0;
int curAngle4 = 0;
int curAngle5 = 0;
//góc được lưu trước đó
int lastAngle1 = 0;
int lastAngle2 = 0;
int lastAngle3 = 0;
int lastAngle4 = 0;
int lastAngle5 = 0;
//biến ghi nhớ trạng thái của nút bấm start stop
volatile bool start = 0; 
volatile bool reset = 0;
//biến lưu xoá nhiểu của nút nhấn
int bstart = 0;
int breset = 0;
int bstop = 0;
int timer = 0;

int speed[50] ;


int joint1_speed = 0;
int joint2_speed = 0;
int joint3_speed = 0;
int joint4_speed = 0;
int joint5_speed = 0;

int joint1[50];
int joint2[50];
int joint3[50];
int joint4[50];
int joint5[50];
int gipper[50];

int position=0;
int num_position=0;
int addr_offset = 50;
int cell = 2;
int addr = 1;
int mode = 0;
bool c = 0; //biến định vị trí của hàm controlJoint

#endif
