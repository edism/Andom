// Skaiciuoja laika

void taimeris(){
  if (prog_start == true) {
    
  if (ipliusa == true){ // Jei einam i pliusa
    if (u_sek >= 59){
        u_sek = 0;
        u_min++;
        } else {
            u_sek++;
  }}
  if (ipliusa == false) { //Jei einam i minusa
  if (u_sek == 1) {
    if (u_min <= 0) {
    ipliusa = true;
    }}
  if (u_sek == 0){
    if (u_min > 0){
       u_min--;
       u_sek=59;
}}      else {
          u_sek--;
}}
}
sekv = u_sek%10;
sekd = (u_sek/10)%10;
minv = u_min%10;
mind = (u_min/10)%10;
minds = (u_min/100)%10;
}
