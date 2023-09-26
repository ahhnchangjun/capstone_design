// 아두이노에 연결된 3-way 적외선 센서 핀 번호
const int leftSensorPin = A0;
const int middleSensorPin = A1;
const int rightSensorPin = A2;
const int oneSensorPin = A3;

const int wheel_1_1 = 23;
const int wheel_1_2 = 22;
const int wheel_2_1 = 24;
const int wheel_2_2 = 25;
const int wheel_3_1 = 26;
const int wheel_3_2 = 27;
const int wheel_4_1 = 29;
const int wheel_4_2 = 28;


// 모터 제어에 사용되는 핀 번호


// 감지 임계값 설정
const int threshold = 500;
int count = 0;

void setup() {
  // 핀 모드 설정
  pinMode(leftSensorPin, INPUT);
  pinMode(middleSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  pinMode(oneSensorPin, INPUT);

  pinMode(wheel_1_1, OUTPUT);
  pinMode(wheel_1_2, OUTPUT);
  pinMode(wheel_2_1, OUTPUT);
  pinMode(wheel_2_2, OUTPUT);
  pinMode(wheel_3_1, OUTPUT);
  pinMode(wheel_3_2, OUTPUT);
  pinMode(wheel_4_1, OUTPUT);
  pinMode(wheel_4_2, OUTPUT);

  Serial.begin(9600);

}
 

void loop() {
  // 각 센서의 값을 읽음
  int leftValue = analogRead(leftSensorPin);
  int middleValue = analogRead(middleSensorPin);
  int rightValue = analogRead(rightSensorPin);
  
  // 왼쪽 센서 감지 여부 확인
  if ((middleValue > threshold)&&(rightValue > threshold)&&(leftValue < threshold)) {
    // 왼쪽으로 향하는 경우: 오른쪽 모터 회전

  digitalWrite(wheel_1_1,HIGH);
  digitalWrite(wheel_1_2,LOW);
  digitalWrite(wheel_2_1,LOW);
  digitalWrite(wheel_2_2,HIGH);
  digitalWrite(wheel_3_1,LOW);
  digitalWrite(wheel_3_2,HIGH);
  digitalWrite(wheel_4_1,HIGH);
  digitalWrite(wheel_4_2,LOW);
  
  }
  // 오른쪽 센서 감지 여부 확인
  else if ((middleValue > threshold)&&(rightValue < threshold)&&(leftValue > threshold)) {
    // 오른쪽으로 향하는 경우: 왼쪽 모터 회전

  digitalWrite(wheel_1_1,LOW);
  digitalWrite(wheel_1_2,HIGH);
  digitalWrite(wheel_2_1,HIGH);
  digitalWrite(wheel_2_2,LOW);
  digitalWrite(wheel_3_1,HIGH);
  digitalWrite(wheel_3_2,LOW);
  digitalWrite(wheel_4_1,LOW);
  digitalWrite(wheel_4_2,HIGH);
   
  }
  // 가운데 센서 감지 여부 확인
  else if ((middleValue < threshold)&&(rightValue > threshold)&&(leftValue > threshold)) {
    // 직진하는 경우1: 모터
 
  digitalWrite(wheel_1_1,HIGH);
  digitalWrite(wheel_1_2,LOW);
  digitalWrite(wheel_2_1,HIGH);
  digitalWrite(wheel_2_2,LOW);
  digitalWrite(wheel_3_1,HIGH);
  digitalWrite(wheel_3_2,LOW);
  digitalWrite(wheel_4_1,HIGH);
  digitalWrite(wheel_4_2,LOW);
  

  }
   else if ((middleValue > threshold)&&(rightValue > threshold)&&(leftValue > threshold)) {
    // 직진하는 경우2: 모터

  digitalWrite(wheel_1_1,HIGH);
  digitalWrite(wheel_1_2,LOW);
  digitalWrite(wheel_2_1,HIGH);
  digitalWrite(wheel_2_2,LOW);
  digitalWrite(wheel_3_1,HIGH);
  digitalWrite(wheel_3_2,LOW);
  digitalWrite(wheel_4_1,HIGH);
  digitalWrite(wheel_4_2,LOW); 

  }
  // 모두 감지
  else if ((middleValue < threshold)&&(rightValue < threshold)&&(leftValue < threshold)) {
    // 정지
  count=count+1;
  if((count == 4)|(count == 5)|(count == 9)|(count == 10)) {
  digitalWrite(wheel_1_1,HIGH);
  digitalWrite(wheel_1_2,LOW);
  digitalWrite(wheel_2_1,HIGH);
  digitalWrite(wheel_2_2,LOW);
  digitalWrite(wheel_3_1,HIGH);
  digitalWrite(wheel_3_2,LOW);
  digitalWrite(wheel_4_1,HIGH);
  digitalWrite(wheel_4_2,LOW);

  delay(1000);

  while(1) {
  int Value = analogRead(middleSensorPin);
  digitalWrite(wheel_1_1,HIGH);
  digitalWrite(wheel_1_2,LOW);
  digitalWrite(wheel_2_1,LOW);
  digitalWrite(wheel_2_2,HIGH);
  digitalWrite(wheel_3_1,LOW);
  digitalWrite(wheel_3_2,HIGH);
  digitalWrite(wheel_4_1,HIGH);
  digitalWrite(wheel_4_2,LOW);
  if(Value<threshold) break;
  }
  if(count == 10) count = 0;
  }
  
  

  else {
  digitalWrite(wheel_1_1,HIGH);
  digitalWrite(wheel_1_2,HIGH);
  digitalWrite(wheel_2_1,HIGH);
  digitalWrite(wheel_2_2,HIGH);
  digitalWrite(wheel_3_1,HIGH);
  digitalWrite(wheel_3_2,HIGH);
  digitalWrite(wheel_4_1,HIGH);
  digitalWrite(wheel_4_2,HIGH);

  delay(5000);
  
  digitalWrite(wheel_1_1,HIGH);
  digitalWrite(wheel_1_2,LOW);
  digitalWrite(wheel_2_1,HIGH);
  digitalWrite(wheel_2_2,LOW);
  digitalWrite(wheel_3_1,HIGH);
  digitalWrite(wheel_3_2,LOW);
  digitalWrite(wheel_4_1,HIGH);
  digitalWrite(wheel_4_2,LOW);
  delay(300);
  Serial.println(count);
  }

  
  
  }
  // 모든 센서가 감지되지 않은 경우


//  delay(2000);

//  analogWrite(2,255); 
//  analogWrite(5,255);
 // digitalWrite(3,HIGH);
// digitalWrite(4,LOW);
 // digitalWrite(6,HIGH);
 // digitalWrite(7,LOW); 
  
  //delay(2000); 
}