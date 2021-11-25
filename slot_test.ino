int bot[7] = {2,3,4,5,6,7,8};
int top[7] = {9,10,11,12,13,A3,A2};

void setup() {

  for (int i = 0; i <= 7; i++){
    pinMode(bot[i],OUTPUT);
    pinMode(bot[i],OUTPUT);
  }
}

void one() {
  
  for(int i = 0; i <= 7; i++){
    if (i == 1 || i == 2){
      digitalWrite(bot[i],HIGH);
      digitalWrite(top[i],HIGH);
    }
    else {
      digitalWrite(bot[i],LOW);
      digitalWrite(top[i],LOW);
    }
  }
}

void two() {
  
  for(int i = 0; i <= 7; i++){
    if (i == 2 || i == 5){
      digitalWrite(bot[i],LOW);
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
      digitalWrite(top[i],HIGH);
    }
  }
}

void three() {
  
  for(int i = 0; i <= 7; i++){
    if (i == 4 || i == 5){
      digitalWrite(bot[i],LOW);
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
      digitalWrite(top[i],HIGH);
    }
  }
}

void four() {
  
  for(int i = 0; i <= 7; i++){
    if (i == 0 || i == 3 || i == 4){
      digitalWrite(bot[i],LOW);
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
      digitalWrite(top[i],HIGH);
    }
  }
}

void five() {
  
  for(int i = 0; i <= 7; i++){
    if (i == 1 || i == 4){
      digitalWrite(bot[i],LOW);
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
      digitalWrite(top[i],HIGH);
    }
  }
}

void six() {
  
  for(int i = 0; i <= 7; i++){
    if (i == 1){
      digitalWrite(bot[i],LOW);
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
      digitalWrite(top[i],HIGH);
    }
  }
}

void seven() {
  
  for(int i = 0; i <= 7; i++){
    if (i == 0 || i == 1 || i == 2){
      digitalWrite(bot[i],HIGH);
      digitalWrite(top[i],HIGH);
    }
    else {
      digitalWrite(bot[i],LOW);
      digitalWrite(top[i],LOW);
    }
  }
}

void eight() {
  
  for(int i = 0; i <= 7; i++){
    digitalWrite(bot[i],HIGH);
    digitalWrite(top[i],HIGH);
  }
}

void nine() {
  
  for(int i = 0; i <= 7; i++){
    if (i == 3 || i == 4){
      digitalWrite(bot[i],LOW);
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
      digitalWrite(top[i],HIGH);
    }
  }
}

void zero() {
  
  for(int i = 0; i <= 7; i++){
    if (i == 6){
      digitalWrite(bot[i],LOW);
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
      digitalWrite(top[i],HIGH);
    }
  }
}

void cycle() {
  
int (*nums[10])() = {one,two,three,four,five,six,seven,eight,nine,zero};
  
  for (int i = 0; i <= 9; i ++) {
    nums[i]();
    delay(750);
  }
}

void loop() {
  cycle();
}
