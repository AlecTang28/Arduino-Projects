int bot[7] = {2, 3, 4, 5, 6, 7, 8};
int top[7] = {9, 10, 11, 12, 13, A3, A2};
int lights[3] = {A1, A4, A5};
unsigned long previousTime = 0;
int x = 0;
int state = 0;
bool blinkOn = false;
void setup() {

  x = millis();
  Serial.begin(9600);
  pinMode(A0, INPUT);

  for (int i = 0; i <= 3; i++) {
    pinMode(lights[i], OUTPUT);
  }
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

void cycle(int interval) {

  unsigned long now = millis();
  unsigned long currentTime = millis();
  Serial.println(now);
  if (now < 3000){
    if (currentTime - previousTime >= interval) {
      nums[random(0,10)](top);
      nums[random(0,10)](bot);
      previousTime = currentTime;
    }
  }
  else{
    now = 0;
    x = 0;
  }
}

void loop() {
  /*
  if(millis() >= x + 500){
    x = millis();
    if(blinkOn == false){
      blank(top);
      blank(bot);
      blinkOn = true; 
    }
    else if(blinkOn == true){
      eight(top);
      eight(bot);
      blinkOn = false; 
    }
  }*/
  cycle(100);
  /*
  if(digitalRead(A0) == LOW && state == 0){
    state = 1;
  }
  if(digitalRead(A0) == HIGH && state == 1){
    x = 1;
    state = 0;
  }
  if(x == 1){
    cycle(100);
  }
  Serial.println(state);*/
}
