#include <EEPROM.h>
// 7 segmentai ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int digit1 = 7;
int digit2 = 6;
int digit3 = 5;
int digit4 = 4;
int digit5 = 3;
int digit6 = 2;
// 74HC595 pins ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dataPin=10;
int latchPin=9;
int clockPin=8;
// regular LEDs  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int zalias = 13;
int geltonas = 12;
int raudonas = 11;
// mygtukai ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int b_start = A5;
int b_stop = A4;
int b_pauze = A3;
int b_gelt = A1;
int b_zalias = A2;
int b_raudonas = A0;
// mygtuku statusas
int bstart;
int bpauze;
int bstop;
int bgeltonas;
int bzalias;
int braudonas;
boolean prog_start = false;
boolean prog_pauze = false;
boolean prog_stop = false;
boolean prog_zalias = false;
boolean prog_geltonas = false;
boolean prog_raudonas = false;
boolean p_sekv = false;
boolean p_sekd = false;
boolean p_minv = false;
boolean p_mind = false;
boolean p_minds =false;
int u_sek = 0;
int u_min = 0;
unsigned long lastp=0;
unsigned long firstTime_p;
unsigned long firstTime_start;
unsigned long firstTime_stop;
unsigned long firstTime_bzalias;
unsigned long firstTime_bgeltonas;
unsigned long firstTime_braudonas;
byte previous_p = HIGH;
byte previous_start = LOW;
byte previous_stop = HIGH;
byte previous_bzalias = HIGH;
byte previous_bgeltonas = HIGH;
byte previous_braudonas = HIGH;
int count_p; 
int count_start; 
int count_stop; 
int count_bzalias;
int count_bgeltonas;
int count_braudonas;
int segmentas = 1;
boolean ipliusa = false;
unsigned long paskk = 0;
int gsekv = EEPROM.read(1);
int gsekd = EEPROM.read(2);
int gminv = EEPROM.read(3);
int gmind = EEPROM.read(4);
int gminds = EEPROM.read(5);
int sekv = gsekv;
int sekd=gsekd;
int minv=gminv;
int mind=gmind;
int minds=gminds;
boolean zals = false;
unsigned long led_time;
int ledstate=HIGH;
unsigned long ledt;
boolean programavimas=false;
unsigned long program_last;
boolean prog_sekundes=true;
int prog_seks=gsekv;
int prog_mins;
int prog_sekv=gsekv;
int prog_sekd=gsekd;
int prog_minv=gminv;
int prog_mind=gminv;
int prog_minds=gminds;
boolean first_prog=true;
boolean first_start=true;
void setup() {
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  pinMode(digit5, OUTPUT);
  pinMode(digit6, OUTPUT);
  pinMode(zalias, OUTPUT);
  pinMode(geltonas, OUTPUT);
  pinMode(raudonas, OUTPUT);
  pinMode(b_start, INPUT);
  pinMode(b_stop, INPUT);
  pinMode(b_pauze, INPUT);
  pinMode(b_gelt, INPUT);
  pinMode(b_zalias, INPUT);
  pinMode(b_raudonas, INPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN CODE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void loop() {
unsigned long dabar;
unsigned long progT;
dabar = millis();
bstart=digitalRead(b_start);
bstop=digitalRead(b_stop);
bpauze=digitalRead(b_pauze);
bgeltonas=digitalRead(b_gelt);
bzalias=digitalRead(b_zalias);
braudonas=digitalRead(b_raudonas);
// pirmas start
if (first_start==true) {
firstst();
}

// jei ne programavimo rezimas
if (programavimas == false) {
myg_stats(); 
if (dabar - paskk >= 998) {
   taimeris();
   paskk = dabar;  }
show_digit(minds,mind,minv,sekd,sekv);
if (dabar - ledt >=250){
leds();
ledt=dabar;
}}
// jei programavimo rezimas
if (programavimas == true){
  if (first_prog == true){
      digitalWrite(zalias, LOW);
      digitalWrite(geltonas, LOW);
      digitalWrite(raudonas, LOW);
      single_blink(zalias, 100);
      digitalWrite(zalias, LOW);
      prog_sekv = EEPROM.read(1);
      prog_sekd = EEPROM.read(2);
      prog_minv = EEPROM.read(3);
      prog_mind = EEPROM.read(4);
      prog_minds = EEPROM.read(5);
      first_prog=false;
      ipliusa=false;
} else if (dabar - progT >=200){
      program();
      progT=dabar;  }
      show_digit(prog_minds,prog_mind,prog_minv,prog_sekd,prog_sekv);
}
}
