int bot[7] = {2, 3, 4, 5, 6, 7, 8};
int top[7] = {9, 10, 11, 12, 13, A3, A2};
int lights[3] = {A1,A4,A5};
long randNum;
unsigned long previousTime = 0;
unsigned long afkBefore = 0;

void setup() {

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

int (*nums[10])(int screen[]) = {one, two, three, four, five, six, seven, eight, nine, zero};

void cycle(int interval) {
  
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= interval){
    randNum = random(0, 10);
    nums[randNum](top);
    randNum = random(0, 10);
    nums[randNum](bot);
    previousTime = currentTime;
  }
}

void afk() {
  
  unsigned long afkNow = millis();

  for (int i = 0; i <= 9; i++){
    if (afkNow - afkBefore >= 500){
      nums[i](top);
      nums[abs(i-9)](bot);
      afkBefore = afkNow;
    }
  }
}

void loop() {
  afk();
}
