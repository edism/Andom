void leds() {

// jei programa veikia i neigiama puse
  if (prog_start == true && ipliusa == false && prog_geltonas == false && prog_raudonas == false && prog_stop == false){
    digitalWrite(zalias, HIGH);
    digitalWrite(geltonas, LOW);
    digitalWrite(raudonas, LOW);
    
// jei programa veikia i teigiama puse
  } else if (prog_start==true && ipliusa == true && prog_geltonas == false && prog_raudonas == false && prog_stop == false) { 
    digitalWrite(raudonas, HIGH);
    digitalWrite(zalias, LOW);  }
    
// jei sustabdoma programa    
  if (prog_stop == true) {
    led_blink(zalias);
    digitalWrite(raudonas, LOW);
    digitalWrite(geltonas, LOW);
  }

// geltonas mygtukas
if (prog_geltonas == true){
  digitalWrite(geltonas, HIGH);
  digitalWrite(zalias, LOW);
  digitalWrite(raudonas, LOW);
}

if (prog_raudonas == true){
  digitalWrite(raudonas, HIGH);
  digitalWrite(zalias, LOW);
  digitalWrite(geltonas, LOW);
}

}

