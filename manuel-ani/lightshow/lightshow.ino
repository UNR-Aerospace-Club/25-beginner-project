int serialClock = 5;
int registerClock = 4;
int serial = 6;

void clearRegister() {
  digitalWrite(serialClock, LOW);
  for (int i = 0; i < 8; i++) {
    digitalWrite(serial, LOW);
    digitalWrite(serialClock, HIGH);
    digitalWrite(serialClock, LOW);
  }

}

void setup() {
  // put your setup code here, to run once:

  pinMode(serialClock, OUTPUT);
  pinMode(registerClock, OUTPUT);
  pinMode(serial, OUTPUT);


  clearRegister();

  //output
  digitalWrite(registerClock, HIGH);
  digitalWrite(registerClock, LOW);

  delay(1000);
}



int tick = 0;

void loop() {

  clearRegister();

  digitalWrite(serial, HIGH);
  digitalWrite(serialClock, HIGH);
  digitalWrite(serialClock, LOW);

  // put your main code here, to run repeatedly:

  digitalWrite(serial, LOW);
  digitalWrite(registerClock, HIGH); //flashes led 1
  digitalWrite(registerClock, LOW);
  delay(250);
  for(int j=0;j<2;j++){ //moves to led 3
    digitalWrite(serialClock, HIGH);
    digitalWrite(serialClock, LOW);
  }
  digitalWrite(serial, LOW);
  digitalWrite(registerClock, HIGH); //flashes led 3
  digitalWrite(registerClock, LOW);
  delay(250);
  for(int j=0;j<3;j++){ // moves to led 6
    digitalWrite(serialClock, HIGH);
    digitalWrite(serialClock, LOW);
  }
  digitalWrite(serial, LOW);
  digitalWrite(registerClock, HIGH); //flashes led 6
  digitalWrite(registerClock, LOW);
  delay(250);
  for(int j=0;j<2;j++){ //moves to led 8
    digitalWrite(serialClock, HIGH);
    digitalWrite(serialClock, LOW);
  }
  digitalWrite(serial, LOW);
  digitalWrite(registerClock, HIGH); //flashes led 8
  digitalWrite(registerClock, LOW);
  delay(250);

  clearRegister(); //clear
  digitalWrite(serial, HIGH); //reset to led 1
  digitalWrite(serialClock, HIGH);
  digitalWrite(serialClock, LOW);

  digitalWrite(serial, LOW);
  for(int j=0;j<3;j++){ //moves to led 4
    digitalWrite(serialClock, HIGH);
    digitalWrite(serialClock, LOW);
  }
  digitalWrite(registerClock, HIGH); //flashes led 4
  digitalWrite(registerClock, LOW);
  delay(250);

  for(int j=0;j<3;j++){ //moves to led 7
    digitalWrite(serialClock, HIGH);
    digitalWrite(serialClock, LOW);
  }
  digitalWrite(serial, LOW);
  digitalWrite(registerClock, HIGH); //flashes led 7
  digitalWrite(registerClock, LOW);
  delay(250);
  
  clearRegister(); //clear
  digitalWrite(serial, HIGH);
  digitalWrite(serialClock, HIGH); //reset to led 1
  digitalWrite(serialClock, LOW);

  digitalWrite(serial, LOW);
  for(int j=0;j<4;j++){ //move to led 5
    digitalWrite(serialClock, HIGH);
    digitalWrite(serialClock, LOW);
  }
  digitalWrite(registerClock, HIGH); //flashes led 5
  digitalWrite(registerClock, LOW);
  delay(250);

  clearRegister(); //clea
  digitalWrite(serial, HIGH);
  digitalWrite(serialClock, HIGH); //reset to 1
  digitalWrite(serialClock, LOW);

  digitalWrite(serial, LOW);
  for(int j=0;j<1;j++){ //move to led 2
    digitalWrite(serialClock, HIGH);
    digitalWrite(serialClock, LOW);
  }
  digitalWrite(registerClock, HIGH); //flases led 2
  digitalWrite(registerClock, LOW);
  delay(250);

  
  // if (tick % 2 != 0) {
  //   digitalWrite(serial, LOW);
  // } else {
  //   digitalWrite(serial,HIGH);
  // }



 // digitalWrite(serial, tick % 7 != 0 ? HIGH : LOW);
  
//output
  digitalWrite(registerClock, HIGH);
  digitalWrite(registerClock, LOW);


  tick++;
}


