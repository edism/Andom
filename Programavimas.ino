void program(){
 // pauzes mygtukas trumpas
if (bpauze == LOW && previous_p == HIGH && millis()- firstTime_p > 10){
    firstTime_p = millis();}
if (bpauze == LOW && ((millis() - firstTime_p)) > 10){ 
    count_p++;  }
if (bpauze == HIGH && previous_p == LOW && count_p >=10 && count_p < 150){
segmentas++;
if (segmentas >=6){
  segmentas=1;
}}
  
// pauzes mygtukas ilgas

if (bpauze == HIGH && previous_p == LOW && count_p > 150){
    programavimas =!programavimas;
    first_start=true;
    first_prog=true;
    prog_start=false;
    sekv=prog_sekv;
    sekd=prog_sekd;
    minv=prog_minv;
    mind=prog_mind;
    minds=prog_minds;
    EEPROM.write(1, sekv);
    EEPROM.write(2, sekd);
    EEPROM.write(3, minv);
    EEPROM.write(4, mind);
    EEPROM.write(5, minds);
    }
if (bpauze == HIGH){ // reset the counter if the button is not pressed
    count_p = 0; }
previous_p = bpauze;

// start mygtukas trumpas

if (bstart == LOW && previous_start == HIGH && millis()- firstTime_start > 10){
    firstTime_start = millis();}
if (bstart == LOW && ((millis() - firstTime_start)) > 20){ 
    count_start++;  }
if (bstart == HIGH && previous_start == LOW && count_start >=3 && count_start <=100){
  if (segmentas == 1) {
      if  (prog_sekv >= 9){
          prog_sekv=0;} 
        else {
        prog_sekv++; } }   
    else if (segmentas == 2) {   
         if  (prog_sekd >= 5){
              prog_sekd=0;} 
          else {
              prog_sekd++; } }
    else if (segmentas == 3) {   
          if  (prog_minv >= 9){
              prog_minv=0;} 
          else {
              prog_minv++; } }
    else if (segmentas == 4) {   
          if  (prog_mind >= 9){
              prog_mind=0;} 
          else {
              prog_mind++; } }
    else if (segmentas == 5) {   
          if  (prog_minds >= 9){
              prog_minds=0;} 
          else {
              prog_minds++; } }
  }   

if (bstart == HIGH){ // reset the counter if the button is not pressed
    count_start = 0; }
previous_start = bstart;

// stop mygtukas trumpas
if (bstop == LOW && previous_stop == HIGH && millis()- firstTime_stop > 20){
    firstTime_stop = millis();}
if (bstop == LOW && ((millis() - firstTime_stop)) > 20){ 
    count_stop++;  }
if (bstop == HIGH && previous_stop == LOW && count_stop >=3 && count_stop < 300){
  if (segmentas == 1) {
    if  (prog_sekv <= 0){
        prog_sekv=9;} else {
        prog_sekv--; } }   
        else if (segmentas == 2) {   
          if  (prog_sekd <= 0){
              prog_sekd=5;} 
              else {
              prog_sekd--; } }
              else if (segmentas == 3) {   
          if  (prog_minv <= 0){
              prog_minv=9;} else {
              prog_minv--; } }
                            else if (segmentas == 4) {   
          if  (prog_mind <= 0){
              prog_mind=9;} else {
              prog_mind--; } }
                            else if (segmentas == 5) {   
          if  (prog_minds <= 0){
              prog_minds=9;} else {
              prog_minds--; } }
  }

if (bstop == HIGH){ // reset the counter if the button is not pressed
    count_stop = 0; }
previous_stop = bstop;}

