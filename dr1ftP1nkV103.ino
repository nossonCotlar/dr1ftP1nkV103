//Nosson Cotlar 2017
//This code is in the Public Domain, use it at your leisure, just be nice n' shit

#include <avr/pgmspace.h> // In order not to run out of memory, the frames are stored in program storage, not RAM. 
//Therefor, follow proper notation when using variables. Look in tab "ref" 

//positive - top to bottom
const int row[] = {21, 20, 19, 18, 17, 
  16, 15, 14, 2, 3, 
  4, 5, 6, 7, 8, 
  9, 10, 11, 12, 13};
//Negative - Left to right, viewed from outside
const int col[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 
33, 34, 35, 36, 37, 38, 39, 40, 41};
const boolean O = false;
const boolean X = true;
int pixel;
const int timer = 1;
int frame[400];
//delay between scans (Microseconds) 
const int theDelay = 750;

const int scan(int timer) {
  //MAKE SURE you wire up negs and pos's correctly ;)
  for(int repeat = 0; repeat < timer * 3; repeat++){
    pixel = 0;
    while(pixel < 400){
    for(int noRow = 0; noRow < 20; noRow++){
      digitalWrite(row[noRow], HIGH);
      for(int noCol = 0; noCol < 20; noCol++){
        if(frame[pixel] == true){
          digitalWrite(col[noCol], LOW);
        }
        else if(frame[pixel] == false){
          digitalWrite(col[noCol], HIGH);
        }
        pixel++;
      }
      delayMicroseconds(theDelay);
      for(int noCol = 0; noCol < 20; noCol++){
        digitalWrite(col[noCol], HIGH);
      }
      digitalWrite(row[noRow], LOW); 
      }
    }
  }
}

const int scanInverse(int timer) {
  for(int repeat = 0; repeat < timer * 3; repeat++){
    pixel = 0;
    while(pixel < 400){
    for(int noRow = 0; noRow < 20; noRow++){
      digitalWrite(row[noRow], HIGH);
      for(int noCol = 0; noCol < 20; noCol++){
        if(frame[pixel] == false){
          digitalWrite(col[noCol], LOW);
        }
        else if(frame[pixel] == true){
          digitalWrite(col[noCol], HIGH);
        }
        pixel++;
      }
      delayMicroseconds(theDelay);
      for(int noCol = 0; noCol < 20; noCol++){
        digitalWrite(col[noCol], HIGH);
      }
      digitalWrite(row[noRow], LOW); 
      }
    }
  }
}


//allignment and wiring tests
const int test(int testTime) {
  for(int lel = 0; lel < 20; lel++) {
    digitalWrite(col[lel], LOW);
    for(int kek = 0; kek < 20; kek++) {
      
      digitalWrite(row[kek], HIGH);
    }
    delay(testTime);
    for(int kek = 0; kek < 20; kek++) {
      digitalWrite(row[kek], LOW);
    }
    digitalWrite(col[lel], HIGH);
  }
}

const int testAll(){
  for(int var = 0; var < 20; var++){
    digitalWrite(row[var], HIGH);
    digitalWrite(col[var], LOW);
  }
}


//Frame Initiation, stored as Constant variables in PROGRAM MEMORY
const PROGMEM int eyesPlain[400] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };

const PROGMEM int blink1[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int blink2[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,X,X,X,X,O,O,O,O,X,X,X,X,X,X,O,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,O,X,X,X,X,X,X,O,O,O,O,X,X,X,X,X,X,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int blink3[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,X,X,X,X,X,X,X,X,O,O,X,X,X,X,X,X,X,X,O,
  O,X,X,X,X,X,X,X,X,O,O,X,X,X,X,X,X,X,X,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int lookRight0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,O,X,X,O,X,O,O,X,O,O,O,X,X,O,X,O,
  O,X,O,O,O,X,X,O,X,O,O,X,O,O,O,X,X,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int lookRight1[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,O,O,X,X,X,O,O,X,O,O,O,O,X,X,X,O,
  O,X,O,O,O,O,X,X,X,O,O,X,O,O,O,O,X,X,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int lookLeft0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,X,X,O,O,O,X,O,O,X,O,X,X,O,O,O,X,O,
  O,X,O,X,X,O,O,O,X,O,O,X,O,X,X,O,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int lookLeft1[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,X,X,O,O,O,O,X,O,O,X,X,X,O,O,O,O,X,O,
  O,X,X,X,O,O,O,O,X,O,O,X,X,X,O,O,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  

  
const PROGMEM int eyesRoll0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,X,X,O,O,O,O,X,O,O,X,X,X,O,O,O,O,X,O,
  O,X,X,X,O,O,O,O,X,O,O,X,X,X,O,O,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
  
const PROGMEM int eyesRoll1[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,X,X,O,O,X,O,O,O,O,X,X,X,O,O,X,O,O,
  O,X,O,X,X,O,O,O,X,O,O,X,O,X,X,O,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int eyesRoll2[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,X,X,O,X,O,O,O,O,X,O,X,X,O,X,O,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int eyesRoll3[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,X,X,O,O,O,O,X,O,O,O,X,X,O,O,
  O,X,O,O,O,O,X,X,X,O,O,X,O,O,O,O,X,X,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
  
const PROGMEM int eyesRoll4[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,O,O,O,O,X,X,X,O,O,X,O,O,O,O,X,X,X,O,
  O,X,O,O,O,O,X,X,X,O,O,X,O,O,O,O,X,X,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int eyesDevil0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,X,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,
  O,X,O,X,X,O,O,O,O,O,O,O,O,O,O,X,X,O,X,O,
  O,X,O,O,O,X,O,O,O,O,O,O,O,O,X,O,O,O,X,O,
  O,X,O,O,X,X,X,O,O,O,O,O,O,X,X,X,O,O,X,O,
  O,X,O,O,X,X,X,X,O,O,O,O,X,X,X,X,O,O,X,O,
  O,X,O,O,X,X,X,O,X,O,O,X,O,X,X,X,O,O,X,O,
  O,O,X,O,O,O,O,O,X,O,O,X,O,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,X,X,O,O,X,X,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int error0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,X,X,O,X,X,X,O,O,X,X,X,O,O,O,O,O,
  O,O,X,O,O,O,O,X,O,O,X,O,X,O,O,X,O,O,O,O,
  O,O,X,O,O,O,O,X,O,O,X,O,X,O,O,X,O,O,O,O,
  O,O,X,X,X,O,O,X,X,X,O,O,X,X,X,O,O,O,O,O,
  O,O,X,O,O,O,O,X,O,X,O,O,X,O,O,X,O,O,O,O,
  O,O,X,O,O,O,O,X,O,O,X,O,X,O,O,X,O,X,X,O,
  O,O,X,X,X,X,O,X,O,O,X,O,X,O,O,X,O,X,X,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int exclamationMark0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int marioQuestion0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,X,X,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,X,
  X,O,X,X,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,X,
  X,O,O,O,O,O,X,X,X,X,X,X,X,X,O,O,O,O,O,X,
  X,O,O,O,O,X,X,X,X,X,X,X,X,X,X,O,O,O,O,X,
  X,O,O,O,O,X,X,X,O,O,O,O,X,X,X,O,O,O,O,X,
  X,O,O,O,O,X,X,X,O,O,O,O,X,X,X,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,X,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,X,
  X,O,X,X,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,X,
  X,O,X,X,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X, };
  
const PROGMEM int marioQuestion1[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,X,X,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,X,
  X,O,X,X,O,O,X,X,X,X,X,X,X,X,O,O,X,X,O,X,
  X,O,O,O,O,X,X,X,X,X,X,X,X,X,X,O,O,O,O,X,
  X,O,O,O,O,X,X,X,O,O,O,O,X,X,X,O,O,O,O,X,
  X,O,O,O,O,X,X,X,O,O,O,O,X,X,X,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,X,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,X,X,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,X,
  X,O,X,X,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X, };
  
const PROGMEM int marioQuestion2[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,X,X,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,X,
  X,O,X,X,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,X,X,X,X,X,X,X,X,O,O,O,O,O,X,
  X,O,O,O,O,X,X,X,X,X,X,X,X,X,X,O,O,O,O,X,
  X,O,O,O,O,X,X,X,O,O,O,O,X,X,X,O,O,O,O,X,
  X,O,O,O,O,X,X,X,O,O,O,O,X,X,X,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,X,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,X,
  X,O,X,X,O,O,O,O,X,X,X,X,O,O,O,O,X,X,O,X,
  X,O,X,X,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X, };
  
const PROGMEM int bigLick0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,X,X,X,O,O,O,O,X,X,X,O,O,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,X,X,O,O,O,O,O,O,O,O,X,X,O,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,O,O,X,X,X,X,X,X,X,X,X,X,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int bigLick1[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,X,X,X,O,O,O,O,X,X,X,O,O,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,X,X,O,O,X,X,X,X,X,X,O,O,X,X,O,O,O,
  O,O,O,O,X,X,O,O,O,O,O,O,O,O,X,X,O,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,O,O,X,X,X,X,X,X,X,X,X,X,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int bigLick2[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,X,X,X,O,O,O,O,X,X,X,O,O,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,X,X,O,O,X,X,X,X,X,X,O,O,X,X,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,O,O,X,X,X,X,X,X,X,X,X,X,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int bigLick3[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,X,X,X,O,O,O,O,X,X,X,O,O,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,X,X,O,O,X,X,X,X,X,X,O,O,X,X,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,O,O,X,X,X,X,X,X,X,X,X,X,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };

const PROGMEM int bigLick4[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,X,X,X,O,O,O,O,X,X,X,O,O,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,X,X,O,O,X,X,X,X,X,X,O,O,X,X,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,O,O,X,X,X,X,X,X,X,X,X,X,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int bigLick5[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,X,X,X,O,O,O,O,X,X,X,O,O,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,X,X,O,O,X,X,X,X,X,X,O,O,X,X,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,O,O,X,X,X,X,X,X,X,X,X,X,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const unsigned int PROGMEM DOS0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const unsigned int PROGMEM DOS1[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  X,O,O,X,X,X,X,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };

const PROGMEM int smile0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };

const PROGMEM int smile1[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,O,O,
  O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };

const PROGMEM int smile2[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,O,O,
  O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,
  O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,
  O,O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,O,
  O,O,O,O,X,X,X,X,X,X,X,X,X,X,X,X,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };

const PROGMEM int smile3[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,O,O,
  O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,
  O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,
  O,O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,O,
  O,O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,O,
  O,O,O,O,X,O,O,O,O,O,O,O,O,O,O,X,O,O,O,O,
  O,O,O,O,O,X,X,X,X,X,X,X,X,X,X,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };

const PROGMEM int smile4[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,O,O,
  O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,
  O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,
  O,O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,O,
  O,O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,O,
  O,O,O,O,X,O,O,O,O,O,O,O,O,O,O,X,O,O,O,O,
  O,O,O,O,O,X,O,O,O,O,O,O,O,O,X,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int smile5[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,O,O,O,O,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,O,O,
  O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,
  O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,
  O,O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,O,
  O,O,O,X,O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,O,
  O,O,O,O,X,O,O,O,O,O,O,O,O,O,O,X,O,O,O,O,
  O,O,O,O,O,X,O,O,O,O,O,O,O,O,X,O,O,O,O,O,
  O,O,O,O,O,O,X,X,O,O,O,O,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O };

const PROGMEM int wink0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,X,X,X,X,O,O,O,O,O,X,O,O,O,O,X,O,O,
  O,X,X,O,O,O,O,X,X,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,X,O,O,O,O,X,X,O,O,X,O,O,O,O,O,O,X,O,
  O,O,O,X,X,X,X,O,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int wink1[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,X,X,X,X,X,X,O,O,O,X,O,O,O,O,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,O,O,X,X,O,O,X,O,O,X,O,O,X,X,O,O,X,O,
  O,O,X,X,X,X,X,X,O,O,O,X,O,O,O,O,O,O,X,O,
  O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int wink2[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,O,O,O,O,O,O,O,O,X,O,O,O,O,O,O,X,O,
  O,X,X,X,X,X,X,X,X,O,O,X,O,O,X,X,O,O,X,O,
  O,X,X,X,X,X,X,X,X,O,O,X,O,O,X,X,O,O,X,O,
  O,O,O,O,O,O,O,O,O,O,O,X,O,O,O,O,O,O,X,O,
  O,O,O,O,O,O,O,O,O,O,O,O,X,O,O,O,O,X,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int heartEmoji0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,X,O,X,O,O,O,O,O,O,O,O,X,O,X,O,O,O,
  O,O,X,O,X,O,X,O,O,O,O,O,O,X,O,X,O,X,O,O,
  O,O,X,O,O,O,X,O,O,O,O,O,O,X,O,O,O,X,O,O,
  O,O,O,X,O,X,O,O,O,O,O,O,O,O,X,O,X,O,O,O,
  O,O,O,O,X,O,O,O,O,O,O,O,O,O,O,X,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,O,O,
  O,O,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,O,O,
  O,O,X,X,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,
  O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,X,X,O,O,O,O,O,O,O,O,X,X,O,O,O,O,
  O,O,O,O,O,X,X,O,O,O,O,O,O,X,X,O,O,O,O,O,
  O,O,O,O,O,O,X,X,O,O,O,O,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O };
  
const PROGMEM int heartEmoji1[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,O,O,O,O,O,O,X,X,O,X,X,O,O,
  O,X,O,O,X,O,O,X,O,O,O,O,X,O,O,X,O,O,X,O,
  O,X,O,O,O,O,O,X,O,O,O,O,X,O,O,O,O,O,X,O,
  O,O,X,O,O,O,X,O,O,O,O,O,O,X,O,O,O,X,O,O,
  O,O,O,X,O,X,O,O,O,O,O,O,O,O,X,O,X,O,O,O,
  O,O,O,O,X,O,O,O,O,O,O,O,O,O,O,X,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,O,O,
  O,O,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,O,O,
  O,O,X,X,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,
  O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,X,X,O,O,O,O,O,O,O,O,X,X,O,O,O,O,
  O,O,O,O,O,X,X,O,O,O,O,O,O,X,X,O,O,O,O,O,
  O,O,O,O,O,O,X,X,O,O,O,O,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,O,O };
  
const PROGMEM int tetris0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris1[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris2[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris3[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris4[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris5[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris6[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris7[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris8[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris9[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };

const PROGMEM int tetris10[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris11[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris12[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris13[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris14[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris15[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris16[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris17[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,O,O,O,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,O,O,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
const PROGMEM int tetris18[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,X,X,X,X,X,X,O,O,O,X,X,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,
  O,O,X,X,O,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,
  O,O,X,X,O,O,O,X,X,O,O,O,X,X,O,O,O,O,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X,
  X,X,X,X,X,X,O,X,X,X,X,O,X,X,O,X,X,X,X,X };
  
  



const PROGMEM int eNH0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,O,
  O,O,O,X,X,X,O,O,X,O,X,O,O,X,O,X,O,X,O,O,
  O,O,X,O,O,O,X,O,X,O,X,O,O,X,O,X,O,X,O,O,
  O,O,X,O,O,X,O,O,X,O,O,X,O,X,O,X,X,X,O,O,
  O,O,X,X,X,O,O,O,X,O,O,X,O,X,O,X,O,X,O,O,
  O,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,O,
  O,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,O,
  O,O,O,X,X,X,X,O,X,O,O,O,O,X,O,X,O,X,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int eNH1[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,O,
  O,O,O,X,X,X,O,O,X,O,X,O,O,X,O,X,O,X,O,O,
  O,O,X,O,O,O,X,O,X,O,X,O,O,X,O,X,O,X,O,O,
  X,O,X,O,O,X,O,O,X,O,O,X,O,X,O,X,X,X,O,X,
  X,O,X,X,X,O,O,O,X,O,O,X,O,X,O,X,O,X,O,X,
  O,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,O,
  O,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,O,
  O,O,O,X,X,X,X,O,X,O,O,O,O,X,O,X,O,X,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int eNH2[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,O,
  O,O,O,X,X,X,O,O,X,O,X,O,O,X,O,X,O,X,O,O,
  X,O,X,O,O,O,X,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,X,O,O,X,O,O,X,O,X,O,X,X,X,O,X,
  X,O,X,X,X,O,O,O,X,O,O,X,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  O,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,O,
  O,O,O,X,X,X,X,O,X,O,O,O,O,X,O,X,O,X,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int eNH3[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,O,
  X,O,O,X,X,X,O,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,X,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,X,O,O,X,O,O,X,O,X,O,X,X,X,O,X,
  X,O,X,X,X,O,O,O,X,O,O,X,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  O,O,O,X,X,X,X,O,X,O,O,O,O,X,O,X,O,X,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int eNH4[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,O,
  X,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,X,
  X,O,O,X,X,X,O,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,X,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,X,O,O,X,O,O,X,O,X,O,X,X,X,O,X,
  X,O,X,X,X,O,O,O,X,O,O,X,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,O,X,X,X,X,O,X,O,O,O,O,X,O,X,O,X,O,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int eNH5[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  X,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,X,
  X,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,X,
  X,O,O,X,X,X,O,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,X,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,X,O,O,X,O,O,X,O,X,O,X,X,X,O,X,
  X,O,X,X,X,O,O,O,X,O,O,X,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,O,X,X,X,X,O,X,O,O,O,O,X,O,X,O,X,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int eNH6[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,X,
  X,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,X,
  X,O,O,X,X,X,O,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,X,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,X,O,O,X,O,O,X,O,X,O,X,X,X,O,X,
  X,O,X,X,X,O,O,O,X,O,O,X,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,O,X,X,X,X,O,X,O,O,O,O,X,O,X,O,X,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int eNH7[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,X,
  X,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,X,
  X,O,O,X,X,X,O,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,X,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,X,O,O,X,O,O,X,O,X,O,X,X,X,O,X,
  X,O,X,X,X,O,O,O,X,O,O,X,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,O,X,X,X,X,O,X,O,O,O,O,X,O,X,O,X,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int eNH8[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  X,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,X,
  X,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,X,
  X,O,O,X,X,X,O,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,X,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,X,O,O,X,O,O,X,O,X,O,X,X,X,O,X,
  X,O,X,X,X,O,O,O,X,O,O,X,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,O,X,X,X,X,O,X,O,O,O,O,X,O,X,O,X,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int eNH9[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  X,X,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,X,
  X,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,X,
  X,O,O,X,X,X,O,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,X,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,X,O,O,X,O,O,X,O,X,O,X,X,X,O,X,
  X,O,X,X,X,O,O,O,X,O,O,X,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,O,X,X,X,X,O,X,O,O,O,O,X,O,X,O,X,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,X,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  
const PROGMEM int eNH10[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  X,X,X,X,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,X,
  X,O,O,O,O,O,O,O,X,X,O,O,O,X,O,X,O,X,O,X,
  X,O,O,X,X,X,O,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,X,O,X,O,X,O,O,X,O,X,O,X,O,X,
  X,O,X,O,O,X,O,O,X,O,O,X,O,X,O,X,X,X,O,X,
  X,O,X,X,X,O,O,O,X,O,O,X,O,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,X,O,O,O,O,O,X,O,O,O,X,X,O,X,O,X,O,X,
  X,O,O,X,X,X,X,O,X,O,O,O,O,X,O,X,O,X,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,
  X,X,X,X,O,O,O,O,O,O,O,O,O,O,O,O,O,X,X,X,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };

const PROGMEM int purim0[] = {
//0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,X,X,X,X,X,X,O,O,O,O,O,X,X,X,X,X,O,O,
  O,X,O,O,O,O,O,O,X,O,O,O,X,O,O,O,O,O,X,O,
  O,X,O,O,O,O,O,O,O,X,X,X,O,O,O,O,O,O,X,O,
  O,X,O,X,O,O,O,O,O,O,O,O,O,O,O,O,X,O,X,O,
  O,X,O,X,X,X,X,X,O,O,O,O,X,X,X,X,X,O,X,O,
  O,X,O,O,X,O,O,X,O,O,O,O,X,O,O,X,O,O,X,O,
  O,X,O,O,O,X,X,X,X,O,O,X,X,X,X,O,O,O,X,O,
  O,X,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,X,O,
  O,O,X,O,O,O,O,O,O,X,X,O,O,O,O,O,O,X,O,O,
  O,O,O,X,X,X,X,X,X,O,O,X,X,X,X,X,X,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
  O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O };
  

//Initiation for Single and Animation Frame Functions
const int blinking() {
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesPlain[load]);
    }
scan(20);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&blink1[load]);
    }
scan(1);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&blink2[load]);
    }
scan(1);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&blink3[load]);
    }
scan(1);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&blink2[load]);
    }
scan(1);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&blink1[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesPlain[load]);
    }
scan(8);
}

const int winking() {
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesPlain[load]);
    }
scan(2);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&wink0[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&wink1[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&wink2[load]);
    }
scan(3);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&wink1[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&wink0[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesPlain[load]);
    }
scan(6);
}

const int looking(){
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesPlain[load]);
    }
scan(20);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&lookRight0[load]);
    }
scan(1);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&lookRight1[load]);
    }
scan(7);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&lookRight0[load]);
    }
scan(1);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesPlain[load]);
    }
scan(1);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&lookLeft0[load]);
    }
scan(1);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&lookLeft1[load]);
    }
scan(7);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&lookLeft0[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesPlain[load]);
    }
scan(5);
}

const int rolling() {
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesPlain[load]);
}
scan(2);

for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&lookLeft0[load]);
}
scan(1);

for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&lookLeft1[load]);
}
scan(1);

for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesRoll0[load]);
}
scan(1);

for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesRoll1[load]);
}
scan(1);

for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesRoll2[load]);
}
scan(1);

for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesRoll3[load]);
}
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesRoll4[load]);
}
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&lookRight1[load]);
}
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&lookRight0[load]);
}
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesPlain[load]);
}
scan(5);

}


const int smiling() {
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesPlain[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&smile0[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&smile1[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&smile2[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&smile3[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&smile4[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&smile5[load]);
    }
scan(20);
}

const int DOS() {
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&DOS0[load]);
    }
scan(7);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&DOS1[load]);
    }
scan(7);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&DOS0[load]);
    }
scan(7);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&DOS1[load]);
    }
scan(7);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&DOS0[load]);
    }
scan(7);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&DOS1[load]);
    }
scan(7);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&DOS0[load]);
    }
scan(7);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&DOS1[load]);
    }
scan(7);
}

const int error() {
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&error0[load]);
    }
scan(10);
delay(500);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&error0[load]);
    }
scan(10);
delay(500);for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&error0[load]);
    }
scan(10);
delay(500);for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&error0[load]);
    }
scan(10);
delay(500);
}


const int licking() {
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&bigLick0[load]);
    }
scan(2);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&bigLick1[load]);
    }
scan(2);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&bigLick2[load]);
    }
scan(2);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&bigLick3[load]);
    }
scan(2);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&bigLick4[load]);
    }
scan(2);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&bigLick5[load]);
    }
scan(20);
}

const int question() {
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&marioQuestion0[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&marioQuestion1[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&marioQuestion0[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&marioQuestion2[load]);
    }
scan(1);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&marioQuestion0[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&marioQuestion1[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&marioQuestion0[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&marioQuestion2[load]);
    }
scan(1);
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&marioQuestion0[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&marioQuestion1[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&marioQuestion0[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&marioQuestion2[load]);
    }
scan(1);
}

const int exclamation() {
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&exclamationMark0[load]);
    }
    for(int x = 0; x < 20; x++) {
      scan(1);
      scanInverse(1);
  }
}


const int devil() {
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eyesDevil0[load]);
    }
scan(30);
}

const int purim() {
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&purim0[load]);
    }
scan(30);
}


const int heart() {
  for(int x = 0; x < 15; x++) {

  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&heartEmoji0[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&heartEmoji1[load]);
    }
scan(3);
}
}


const int tetris() {
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris0[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris1[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris2[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris3[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris4[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris5[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris6[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris7[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris8[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris9[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris10[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris11[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris12[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris13[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris14[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris15[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris16[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris17[load]);
    }
scan(4);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&tetris18[load]);
    }
scan(4);

for(int x = 0; x < 10; x++) {
    scan(2);
    scanInverse(2);
}
}

const int eNH() {
  for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eNH0[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eNH1[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eNH2[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eNH3[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eNH4[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eNH5[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eNH6[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eNH7[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eNH8[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eNH9[load]);
    }
scan(1);
for(int load = 0; load < 400; load++) {
    frame[load] = pgm_read_word(&eNH10[load]);
    }
scan(45);
}

const int booming() {
for(int load = 0; load < 400; load++) {
  frame[load] = pgm_read_word( &boom0[load] );
}
scan(1);
for(int load = 0; load < 400; load++) {
  frame[load] = pgm_read_word( &boom1[load] );
}
scan(1);
for(int load = 0; load < 400; load++) {
  frame[load] = pgm_read_word( &boom0[load] );
}
scan(1);
for(int load = 0; load < 400; load++) {
  frame[load] = pgm_read_word( &boom2[load] );
}
scan(1);
for(int load = 0; load < 400; load++) {
  frame[load] = pgm_read_word( &boom3[load] );
}
scan(1);
for(int load = 0; load < 400; load++) {
  frame[load] = pgm_read_word( &boom4[load] );
}
scan(1);
for(int load = 0; load < 400; load++) {
  frame[load] = pgm_read_word( &boom5[load] );
}
scan(7);
}

void setup() {
    for(int var = 0; var < 20; var++) {
      pinMode(col[var], OUTPUT);
      pinMode(row[var], OUTPUT);
      digitalWrite(col[var], HIGH);
    }
  Serial.begin(9600);
}



void loop() {
//ya know, loop and stuff
booing();
booming();

eNH();
purim();
tetris();
heart();
blinking();
blinking();
looking();
rolling();
blinking();
winking();
smiling();
question();
question();
question();
question();
blinking();
blinking();
licking();
devil();
DOS();
error();
exclamation();


}
