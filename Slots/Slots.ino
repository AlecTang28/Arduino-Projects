int bot[7] = {2, 3, 4, 5, 6, 7, 8};
int top[7] = {9, 12, A1, A4, 13, A3, A2};
int redPin = 10;
int grnPin = 11;
bool blinkState = false;
int blinkTime = 0;
int state = 0;
int cycles = 0;
long topValue = 0;
long botValue = 0;

void setup() {

  randomSeed(analogRead(A5));
  blinkTime = millis();
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);  
  for (int i = 0; i <= 6; i++) {
    pinMode(bot[i], OUTPUT);
    pinMode(top[i], OUTPUT);
  }
}

int one(int screen[]) {

  for (int i = 0; i <= 6; i++) {
    if (i == 1 || i == 2) {
      digitalWrite(screen[i], HIGH);
    }
    else {
      digitalWrite(screen[i], LOW);
    }
  }
}

int two(int screen[]) {

  for (int i = 0; i <= 6; i++) {
    if (i == 2 || i == 5) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int three(int screen[]) {

  for (int i = 0; i <= 6; i++) {
    if (i == 4 || i == 5) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int four(int screen[]) {

  for (int i = 0; i <= 6; i++) {
    if (i == 0 || i == 3 || i == 4) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int five(int screen[]) {

  for (int i = 0; i <= 6; i++) {
    if (i == 1 || i == 4) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int six(int screen[]) {

  for (int i = 0; i <= 6; i++) {
    if (i == 1) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int seven(int screen[]) {

  for (int i = 0; i <= 6; i++) {
    if (i == 0 || i == 1 || i == 2) {
      digitalWrite(screen[i], HIGH);
    }
    else {
      digitalWrite(screen[i], LOW);
    }
  }
}

int eight(int screen[]) {

  for (int i = 0; i <= 6; i++) {
    digitalWrite(screen[i], HIGH);
  }
}

int nine(int screen[]) {

  for (int i = 0; i <= 6; i++) {
    if (i == 3 || i == 4) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int zero(int screen[]) {

  for (int i = 0; i <= 6; i++) {
    if (i == 6) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int blank(int screen[]) {
  for (int i = 0; i <= 6; i++) {
    digitalWrite(screen[i], LOW);
  }
}

int (*nums[10])(int screen[]) = {one, two, three, four, five, six, seven, eight, nine, zero};

void colour(int redValue, int grnValue){
  analogWrite(redPin, redValue);
  analogWrite(grnPin, grnValue);
}

void loop() {

  if(state == 0 || state == 1){
    colour(0,0);
    cycles = 0;
    if(millis() >= blinkTime + 500){
      blinkTime = millis();
      if(blinkState == false){
        blank(top);
        blank(bot);
        blinkState = true; 
      }
      else if(blinkState == true){
        eight(top);
        eight(bot);
        blinkState = false; 
      }
    }
  }
  
  if(digitalRead(A0) == LOW && state == 0){
    state = 1;
  }
  
  if(digitalRead(A0) == HIGH && state == 1){
    state = 2;
  }
  if(state == 2){
    if(cycles <= 30){
      cycles = cycles + 1;
      topValue = random(0,10);
      botValue = random(0,10);
      nums[topValue](top);
      nums[botValue](bot);
      delay(100);
    }
    else if(cycles > 30){
      if(topValue == botValue){
        colour(0,255);//green
      }
      else if(abs(topValue - botValue) <= 2){
        colour(255,255);//yellow
      }
      else{
        colour(255,0);//red
      }
    }
    if(digitalRead(A0) == LOW){
      state = 3;
    }
  }
  if(state == 3){
    if(digitalRead(A0) == HIGH){
      state = 0; 
    }
  }
}
