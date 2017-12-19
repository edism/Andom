void firstst (){
digitalWrite(zalias, HIGH);
delay(200);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B01000000);   
digitalWrite(latchPin, HIGH);
digitalWrite(digit6, HIGH);
delay(200);
digitalWrite(digit5, HIGH);
delay(200);
digitalWrite(digit4, HIGH);
delay(200);
digitalWrite(digit3, HIGH);
delay(200);
digitalWrite(digit2, HIGH);
delay(200);
digitalWrite(digit1, HIGH);
delay(200);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, B00000000);   
digitalWrite(latchPin, HIGH);
digitalWrite(digit1, LOW);
digitalWrite(geltonas, LOW);
digitalWrite(raudonas, LOW);
  prog_stop=true;
  prog_pauze=false;
  first_start=false;
  ipliusa=false;
  u_sek = sekd*10 + sekv;
  u_min = minds*100+mind*10+minv;
}


