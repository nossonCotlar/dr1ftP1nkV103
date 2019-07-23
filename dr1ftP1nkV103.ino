//Nosson Cotlar 2017
//This code is in the Public Domain, use it at your leisure, just be nice n' shit

#include <avr/pgmspace.h> // In order not to run out of memory, the frames are stored in program storage, not RAM. 
//Therefor, follow proper notation when using variables. Look in tab "ref" 
//positive - top to bottom
const int row[] = {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
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
//booming();
//booming();

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
