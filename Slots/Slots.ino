int bot[7] = {2,3,4,5,6,7,8};
int top[7] = {9,10,11,12,13,A3,A2};
long randNum;

void setup() {

  Serial.begin(9600);
  pinMode(A0,INPUT);
  for (int i = 0; i <= 6; i++){
    pinMode(bot[i],OUTPUT);
    pinMode(top[i],OUTPUT);
  }
}

void one() {

  for(int i = 0; i <= 6; i++){
    if (i == 1 || i == 2){
      digitalWrite(bot[i],HIGH);
    }
    else {
      digitalWrite(bot[i],LOW);
    }
  }
}

void two() {
  
  for(int i = 0; i <= 6; i++){
    if (i == 2 || i == 5){
      digitalWrite(bot[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
    }
  }
}

void three() {
  
  for(int i = 0; i <= 6; i++){
    if (i == 4 || i == 5){
      digitalWrite(bot[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
    }
  }
}

void four() { 

  for(int i = 0; i <= 6; i++){
    if (i == 0 || i == 3 || i == 4){
      digitalWrite(bot[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
    }
  }
}

void five() {
  
  for(int i = 0; i <= 6; i++){
    if (i == 1 || i == 4){
      digitalWrite(bot[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
    }
  }
}

void six() {
  
  for(int i = 0; i <= 6; i++){
    if (i == 1){
      digitalWrite(bot[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
    }
  }
}

void seven() {

  for(int i = 0; i <= 6; i++){
    if (i == 0 || i == 1 || i == 2){
      digitalWrite(bot[i],HIGH);
    }
    else {
      digitalWrite(bot[i],LOW);
    }
  }
}

void eight() {
  
  for(int i = 0; i <= 6; i++){
    digitalWrite(bot[i],HIGH);
  }
}

void nine() {
  
  for(int i = 0; i <= 6; i++){
    if (i == 3 || i == 4){
      digitalWrite(bot[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
    }
  }
}

void zero() {
  
  for(int i = 0; i <= 6; i++){
    if (i == 6){
      digitalWrite(bot[i],LOW);
    }
    else {
      digitalWrite(bot[i],HIGH);
    }
  }
}

void one2() {
  
  for(int i = 0; i <= 6; i++){
    if (i == 1 || i == 2){
      digitalWrite(top[i],HIGH);
    }
    else {
      digitalWrite(top[i],LOW);
    }
  }
}

void two2() {
  
  for(int i = 0; i <= 6; i++){
    if (i == 2 || i == 5){
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(top[i],HIGH);
    }
  }
}

void three2() {
  
  for(int i = 0; i <= 6; i++){
    if (i == 4 || i == 5){
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(top[i],HIGH);
    }
  }
}

void four2() { 

  for(int i = 0; i <= 6; i++){
    if (i == 0 || i == 3 || i == 4){
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(top[i],HIGH);
    }
  }
}

void five2() {
  
  for(int i = 0; i <= 6; i++){
    if (i == 1 || i == 4){
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(top[i],HIGH);
    }
  }
}

void six2() {
  
  for(int i = 0; i <= 6; i++){
    if (i == 1){
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(top[i],HIGH);
    }
  }
}

void seven2() {

  for(int i = 0; i <= 6; i++){
    if (i == 0 || i == 1 || i == 2){
      digitalWrite(top[i],HIGH);
    }
    else {
      digitalWrite(top[i],LOW);
    }
  }
}

void eight2() {
  
  for(int i = 0; i <= 6; i++){
    digitalWrite(top[i],HIGH);
  }
}

void nine2() {
  
  for(int i = 0; i <= 6; i++){
    if (i == 3 || i == 4){
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(top[i],HIGH);
    }
  }
}

void zero2() {
  
  for(int i = 0; i <= 6; i++){
    if (i == 6){
      digitalWrite(top[i],LOW);
    }
    else {
      digitalWrite(top[i],HIGH);
    }
  }
}

int (*nums[10])() = {one,two,three,four,five,six,seven,eight,nine,zero};
int (*nums2[10])() = {one2,two2,three2,four2,five2,six2,seven2,eight2,nine2,zero2};

void cycle() {
  randNum = random(0,10);
  nums[randNum]();
  randNum = random(0,10);
  nums2[randNum]();
  delay(75);
}

void loop() {

  int topList;
  int botList;
  int pressed;
  
  cycle();
  //pushbutton default state is HIGH)
  if(digitalRead(A0) == LOW){
    pressed = 1;
  }
  else{
    pressed = 0;
  }
  Serial.println(pressed);
}
