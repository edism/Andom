void myg_stats(){
 // pauze mygukas ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
if (bpauze == LOW && previous_p == HIGH && millis()- firstTime_p > 10){
    firstTime_p = millis();}
if (bpauze == LOW && ((millis() - firstTime_p)) > 20){ 
    count_p++;  }
if (bpauze == HIGH && previous_p == LOW && count_p >=3){
    if (prog_start == true && prog_stop == false){
      prog_pauze=true;
      prog_start=false;
    } else if (prog_start == false && prog_stop == false){
      prog_pauze=false;
      prog_start=true;
    }  }

 // Ilgas pauze
    
if (bpauze == HIGH && previous_p == LOW && count_p > 150){
programavimas = true;
prog_seks=sekd*10+sekv;
prog_mins=minds*100+mind*10+minv;
}   

if (bpauze == HIGH){ // reset the counter if the button is not pressed
    count_p = 0; }
previous_p = bpauze;

// start mygtukas ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
if (bstart == LOW && previous_start == HIGH && millis()- firstTime_start > 10){
    firstTime_start = millis();}
if (bstart == LOW && ((millis() - firstTime_start)) > 20){ 
    count_start++;  }
if (bstart == HIGH && previous_start == LOW && count_start >=3){
  if (prog_pauze == false){
      prog_start=true;
      prog_stop=false;
      ipliusa=false;
      prog_geltonas = false;
      prog_raudonas = false;

  u_sek = prog_sekd*10 + prog_sekv;
  u_min = prog_minds*100+prog_mind*10+prog_minv;
    }  } 
if (bstart == HIGH){ // reset the counter if the button is not pressed
    count_start = 0; }
previous_start = bstart;

// stop mygtukas trumpas  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

if (bstop == LOW && previous_stop == HIGH && millis()- firstTime_stop > 20){
    firstTime_stop = millis();}
if (bstop == LOW && ((millis() - firstTime_stop)) > 20){ 
    count_stop++;  }
if (bstop == HIGH && previous_stop == LOW && count_stop >=3 && count_stop < 150){
  if (prog_pauze==false){
    prog_stop=true;
    prog_start=false;
    prog_geltonas = false;
    prog_raudonas = false;
    }  }

if (bstop == HIGH){ // reset the counter if the button is not pressed
    count_stop = 0; }
previous_stop = bstop;

// geltonas mygtukas ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

if (bgeltonas == LOW && previous_bgeltonas == HIGH && millis()- firstTime_bgeltonas > 10){
    firstTime_bgeltonas = millis();}
if (bgeltonas == LOW && ((millis() - firstTime_bgeltonas)) > 20){ 
    count_bgeltonas++;  }
if (bgeltonas == HIGH && previous_bgeltonas == LOW && count_bgeltonas >=3){
    if (prog_pauze == false && prog_stop == false){
      prog_geltonas = true;
      prog_raudonas = false;
      digitalWrite(raudonas, LOW);// kad nebutu geltono ir raudono kartu
    }  } 
if (bgeltonas == HIGH){ // reset the counter if the button is not pressed
    count_bgeltonas = 0; }
previous_bgeltonas = bgeltonas;

// raudonas mygtukas ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

if (braudonas == LOW && previous_braudonas == HIGH && millis()- firstTime_braudonas > 20){
    firstTime_braudonas = millis();}
if (braudonas == LOW && ((millis() - firstTime_braudonas)) > 30){ 
    count_braudonas++;  }
if (braudonas == HIGH && previous_braudonas == LOW && count_braudonas >=3){
    if (prog_pauze == false && prog_stop == false){
      prog_geltonas = false;  // kad nebutu geltono ir raudono kartu
      prog_raudonas = true;
    }  } 
if (braudonas == HIGH){ // reset the counter if the button is not pressed
    count_braudonas = 0; }
previous_braudonas = braudonas;

// zalias mygtukas ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

if (bzalias == LOW && previous_bzalias == HIGH && millis()- firstTime_bzalias > 10){
    firstTime_bzalias = millis();}
if (bzalias == LOW && ((millis() - firstTime_bzalias)) > 20){ 
    count_bzalias++;  }
if (bzalias == HIGH && previous_bzalias == LOW && count_bzalias >=3){
    if (prog_pauze == false && prog_stop == false){
 prog_geltonas = false;
 prog_raudonas = false;
 digitalWrite(geltonas, LOW);
 digitalWrite(raudonas, LOW);
    }  } 
if (bzalias == HIGH){ // reset the counter if the button is not pressed
    count_bzalias = 0; }
previous_bzalias = bzalias;
}

