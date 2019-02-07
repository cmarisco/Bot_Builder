//Christopher Marisco
//February 6, 2019
//
//Autonomous Platform for the "DOPE SYRINGES" sketch.
//Controls PWM wheel motors, line-sensors, and object detection.
//Will be updated continuously to account for computer vision and
//other add-ons.

/******MOTOR CONTROL PINS******/
//Motors and Arduino interface with the L239D Dual H-Bridge Motor Driver.
//Pin numberings based on the wiring diagram in referenced documentation.

const int motor1_on_pin = 1; //Motor 1 PWM Speed Control Pin
const int motor2_on_pin = 9; //Motor 2 PWM Speed Control Pin

const int motor1_Direction_A = 2; //Motor 1 Directional Control A
const int motor1_Dirction_B = 7; //Motor 1 Directional Control B
const int motor2_Dirction_A = 15; //Motor 2 Directional Control A
const int motor2_Dirction_B = 10; //Motor 2 Directional Control B

/*****Setup*****/

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1_on_pin, OUTPUT); //Sets motor1 and motor2 speed control pins to outputs.
  pinMode(motor2_on_pin, OUTPUT);
  pinMode(motor1_Direction_A, OUTPUT);
  pinMode(motor1_Direction_B, OUTPUT);
  pinMode(motor2_Direction_A, OUTPUT);
  pinMode(motor2_Direction_B, OUTPUT);
}
/*****Loop to start the bot*****/
void loop() {
  //Basic Test
  forward_motors();
  //reverse_motors();
  drive();
  delay(1000);
  park();
  stop_motors();
}

/*****DRIVE*****/
//Sends 5V signal to both motors.
void drive(){
  drive_m1();
  drive_m2();
}

void drive_m1(){
  digitalWrite(motor1_on_pin, HIGH);
}

void drive_m2(){
  digitalWrite(motor2_on_pin, HIGH);  
}
void park(){
  digitalWrite(motor1_on_pin, LOW);
  digitalWrite(motor2_on_pin, LOW);
}
void forward_motors(){
  m1_fwd();
  m2_fwd(); 
}

void reverse_motors(){
  m1_rev();
  m2_rev();  
}
void m1_fwd(){
  digitalWrite(motor1_Direction_A, HIGH);
  digitalWrite(motor1_Direction_B, digitalRead(motor1_Direction_A) ^ 1);
}

void m1_rev(){
  digitalWrite(motor1_Direction_A, LOW);
  digitalWrite(motor1_Direction_B, digitalRead(motor1_Direction_A) ^ 1);
}

void m2_fwd(){
  digitalWrite(motor2_Direction_A, HIGH);
  digitalWrite(motor2_Direction_B, digitalRead(motor2_Direction_A) ^ 1);
}

void m2_rev(){
  digitalWrite(motor2_Direction_A, LOW);
  digitalWrite(motor2_Direction_B, digitalRead(motor2_Direction_A) ^ 1);
}
void stop_motors(){
  stop_m1();
  stop_m2(); 
}
void stop_m1(){
  digitalWrite(motor1_Direction_A, LOW);
  digitalWrite(motor1_Direction_B, LOW);  
}

void stop_m2(){
  digitalWrite(motor2_Direction_A, LOW);
  digitalWrite(motor2_Direction_B, LOW);  
}
