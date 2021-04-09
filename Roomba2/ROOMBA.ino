const int MD_IN1 = 5;
const int MD_IN2 = 6;
const int MD2_IN1 = 10;
const int MD2_IN2 = 11;

const int FAN = 13;

const int IR_R = 3;
const int IR_L = 2; //not used

int isObstacle = HIGH;

void MD_forward(int rate) {
  analogWrite(MD_IN1, rate);
  analogWrite(MD_IN2, 0);
}

void MD2_forward(int rate) {
  analogWrite(MD2_IN1, rate);
  analogWrite(MD2_IN2, 0);
}
void MD_backward(int rate) {
  analogWrite(MD_IN1, 0);
  analogWrite(MD_IN2, rate);
}

void MD2_backward(int rate) {
  analogWrite(MD2_IN1, 0);
  analogWrite(MD2_IN2, rate);
}

void MD_brake() {
  digitalWrite(MD_IN1, HIGH);
  digitalWrite(MD_IN2, HIGH);
}

void MD2_brake() {
  digitalWrite(MD2_IN1, HIGH);
  digitalWrite(MD2_IN2, HIGH);
}

void setup() {
  pinMode(MD_IN1,OUTPUT);
  pinMode(MD_IN2,OUTPUT);
  pinMode(MD2_IN1,OUTPUT);
  pinMode(MD2_IN2,OUTPUT);
  
  pinMode(FAN,OUTPUT);
  pinMode(IR_R, INPUT);
  pinMode(IR_L, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(FAN,HIGH);
  
  isObstacle = digitalRead(IR_L);

  if (isObstacle == LOW){
    //safe
    Serial.println("safe");
    MD_forward(100);
    MD2_forward(100);
  } else {
    //fall
    Serial.println("fall");
    MD_backward(100);
    MD2_backward(100);
    delay(2000);
    MD_forward(100);
    MD2_backward(100);
    delay(1500);
  }
delay(20);
}
