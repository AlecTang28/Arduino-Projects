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

void one(screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 1 || i == 2) {
      digitalWrite(screen[i], HIGH);
    }
    else {
      digitalWrite(screen[i], LOW);
    }
  }
}

void two(screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 2 || i == 5) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

void three(screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 4 || i == 5) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

void four(screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 0 || i == 3 || i == 4) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

void five(screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 1 || i == 4) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

void six(screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 1) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

void seven(screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 0 || i == 1 || i == 2) {
      digitalWrite(screen[i], HIGH);
    }
    else {
      digitalWrite(screen[i], LOW);
    }
  }
}

void eight(screen) {

  for (int i = 0; i <= 6; i++) {
    digitalWrite(screen[i], HIGH);
  }
}

void nine(screen) {

  for (int i = 0; i <= 6; i++) {
    if (i == 3 || i == 4) {
      digitalWrite(screen[i], LOW);
    }
    else {
      digitalWrite(screen[i], HIGH);
    }
  }
}

void zero(screen) {

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
