/* 6x7 segment display
        ______       ______
       |  A   |     |  A   |        
      F|      |B   F|      |B       |Q7|Q6}Q5|Q4|Q3|Q2|Q1|Q0|
       |______|     |______|        |A |B |C |D |E |F |G |DP|
       |  G   |     |  G   |     
      E|      |C   E|      |C
       |______|     |______|
          D    [DP]     D     [DP]            
B00000000 - all off
B00000001 - A ON only
B00000010 - B ON only
...
B11111111 - ALL ON              */  

// Skaicius su tasku
void skaicius_su_tasku (int skcius){ 
  #define seg_on  LOW
  #define seg_off HIGH
    switch (skcius){
  case 0:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B10111111);   
    digitalWrite(latchPin, HIGH);
    break;
  case 1:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B10000110);  
    digitalWrite(latchPin, HIGH);
    break;
  case 2:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B11011011);   
    digitalWrite(latchPin, HIGH);
    break;
  case 3:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B11001111);  
    digitalWrite(latchPin, HIGH);
    break;
  case 4:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B11100110);   
    digitalWrite(latchPin, HIGH);
    break;
  case 5:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B11101101);   
    digitalWrite(latchPin, HIGH);
    break;
  case 6:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B11111101);
    digitalWrite(latchPin, HIGH);
    break;
  case 7:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B10000111);   
    digitalWrite(latchPin, HIGH);
    break;
  case 8:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B11111111);   
    digitalWrite(latchPin, HIGH);
    break;
  case 9:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B11101111);
    digitalWrite(latchPin, HIGH);
    break;
  case 10:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B00000000);
    digitalWrite(latchPin, HIGH);
    break;
  }} 
// Skaicius be tasko
void skaicius (int skcius){ 
  #define seg_on  LOW
  #define seg_off HIGH
    switch (skcius){
  case 0:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B00111111);   
    digitalWrite(latchPin, HIGH);
    break;
  case 1:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B00000110);  
    digitalWrite(latchPin, HIGH);
    break;
  case 2:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B01011011);   
    digitalWrite(latchPin, HIGH);
    break;
  case 3:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B01001111);  
    digitalWrite(latchPin, HIGH);
    break;
  case 4:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B01100110);   
    digitalWrite(latchPin, HIGH);
    break;
  case 5:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B01101101);   
    digitalWrite(latchPin, HIGH);
    break;
  case 6:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B01111101);   // pakeista i 6 su pagaliuku virsuj
    digitalWrite(latchPin, HIGH);
    break;
  case 7:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B00000111);   
    digitalWrite(latchPin, HIGH);
    break;
  case 8:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B01111111);   
    digitalWrite(latchPin, HIGH);
    break;
  case 9:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B01101111);   // pakeista i 9 su pagaliuku apacioj
    digitalWrite(latchPin, HIGH);
    break;
  case 10:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B00000000);
    digitalWrite(latchPin, HIGH);
    break;
    case 11:
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, B01000000);
    digitalWrite(latchPin, HIGH);
    break;  
  }} 
// parodo segmenta 4 segmentu displejuj
void show_digit(int minutesds, int minutesd, int minutesv, int sekundesd,int sekundesv){ 
unsigned long pradzia;
int ded = 2500;

// sekundziu vienetai ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
skaicius(sekundesv);
digitalWrite(digit6, HIGH);
delayMicroseconds(ded);
digitalWrite(digit6, LOW);

// sekundziu desimtys ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

skaicius(sekundesd);
if (sekundesd > 0 || minutesv > 0 || minutesd > 0 || minutesds > 0){
digitalWrite(digit5, HIGH);
}
delayMicroseconds(ded);
digitalWrite(digit5, LOW);

// minuciu vienetai ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
skaicius_su_tasku(minutesv);
if (minutesv > 0 || minutesd >0 || minutesds >0){ 
digitalWrite(digit4, HIGH);
}
delayMicroseconds(ded);
digitalWrite(digit4, LOW);

// minuciu desimtys ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
skaicius(minutesd);
if (minutesd > 0 || minutesds > 0){
digitalWrite(digit3, HIGH);
}
delayMicroseconds(ded);
digitalWrite(digit3, LOW);

// minuciu simtai ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
skaicius(minutesds);
if (minutesds > 0)
{
digitalWrite(digit2, HIGH);
}
delayMicroseconds(ded);
digitalWrite(digit2, LOW);

//minuso zenklas ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
skaicius(11);
if (ipliusa == true) {
digitalWrite(digit1, HIGH);
delayMicroseconds(ded/2);
digitalWrite(digit1, LOW); }

}
