int bot[7] = {2, 3, 4, 5, 6, 7, 8};
int top[7] = {9, 10, 11, 12, 13, A3, A2};
int lights[3] = {A0,A4,A5};
long randNum;

void setup() {

  Serial.begin(9600);
  for (int i = 0; i <= 3; i++) {
    pinMode(lights[i], OUTPUT);
  }
  
  for (int i = 0; i <= 6; i++) {
    pinMode(bot[i], OUTPUT);
    pinMode(top[i], OUTPUT);
  }
}

int one(int screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 1 || i == 2) {
      digitalWrite(screen[i], HIGH);
    }
    else {
      digitalWrite(screen[i], LOW);
    }
  }
}

int two(int screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 2 || i == 5) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int three(int screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 4 || i == 5) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int four(int screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 0 || i == 3 || i == 4) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int five(int screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 1 || i == 4) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int six(int screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 1) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int seven(int screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 0 || i == 1 || i == 2) {
      digitalWrite(screen[i], HIGH);
    }
    else {
      digitalWrite(screen[i], LOW);
    }
  }
}

int eight(int screen) {

  for (int i = 0; i <= 6; i++) {
    digitalWrite(screen[i], HIGH);
  }
}

int nine(int screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 3 || i == 4) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int zero(int screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 6) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

int (*nums[10])() = {one, two, three, four, five, six, seven, eight, nine, zero};

void cycle() {
  randNum = random(0, 10);
  nums[randNum](top);
  randNum = random(0, 10);
  nums[randNum](bot);
  delay(75);
}

void loop() {
  cycle();
  /*
  green light if both numbers are the same
  yellow light if both numbers are odd/even
  red light if none of the above
  
  if (topList == 11 && botList == 11) {
    cycle();
  }

  //pushbutton default state is HIGH)
  if (digitalRead(A0) == LOW) {
    topList = random(0, 10);
    botList = random(0, 10);
  }
  if (topList != 11 && botList != 11) {
    nums[topList]();
    nums2[botList]();
  }

  if (topList == botList && topList != 11 && (digitalRead(A0) == HIGH)){
    digitalWrite(lights[0],HIGH);
    digitalWrite(lights[2],LOW);
  }
  if (topList != botList && topList != 11 && (digitalRead(A0) == HIGH)){
    digitalWrite(lights[2],HIGH);
  }
  if(digitalRead(A0) == HIGH){
    for (int i = 0; i <= 3; i++) {
      digitalWrite(lights[i],LOW);
    }
  }*/
}
