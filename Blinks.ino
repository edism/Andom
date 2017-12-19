// pastovus blink
void led_blink(int ledas) {
      if (ledstate == LOW) {
        ledstate=HIGH;
      } else {
        ledstate=LOW;
      }
      digitalWrite(ledas,ledstate);
    }
// vienakart blink
void single_blink (int color, int tarp){
  digitalWrite(color, HIGH);
  delay (tarp);
  digitalWrite(color, LOW);
  delay (tarp);
  digitalWrite(color, HIGH);
  delay (tarp);
  digitalWrite(color, LOW);
  delay (tarp);  
}
void lcd_blink(){
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
  digitalWrite(digit5, LOW);  
  digitalWrite(digit6, LOW);
}
