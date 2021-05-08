#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
const int r1 = 7;
const int r2 = 6;
const int r3 = 5;
const int r4 = 4;
const int c1 = 3;
const int c2 = 2;
const int c3 = 1;
void alphkeypad();
int pos, posy;

void setup()
{
  pos = 0;
  posy = 0;
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(c1, INPUT);
  pinMode(c2, INPUT);
  pinMode(c3, INPUT);
  //first position
  
  lcd.setCursor(pos, posy);
  lcd.print("Welcome!");
  delay(1000);
  lcd.clear();
}

void loop()
{

  // get the posxition of cursor
  if (pos > 15 && posy != 1)
  {
    pos = 0;
    posy = 1;
  }
  lcd.setCursor(pos, posy);

  alphkeypad();
  
}

void alphkeypad(){

char a='[';

while(a!='*'){
  // set col 1->3 to be high 
digitalWrite(c1,HIGH);  digitalWrite(c2,HIGH);digitalWrite(c3,HIGH);
//set one row with low and rest with high
    digitalWrite(r1,LOW);digitalWrite(r2,HIGH);
    digitalWrite(r3,HIGH);digitalWrite(r4,HIGH);

// c1 is low then the pressed is either a or b or c 
// a will be printed
// we have 0.5 sec delay, if the same button  pressed it will be changed to b then c

      if(digitalRead(c1)==LOW){
   lcd.setCursor(pos, 0);   lcd.print('a');delay(500);
        if(digitalRead(c1)==LOW){
       lcd.setCursor(pos, 0);  lcd.print('b');delay(500);
          if(digitalRead(c1)==LOW){
        lcd.setCursor(pos, 0);   lcd.print('c');delay(500);}}
        // here we have a or b or c letter 
          a='*'; // it indicate that a button is pressed 
          pos++; // inc the posx of cursor
          break; // break out from while loop
        }
  

  
  
    digitalWrite(r1,LOW);digitalWrite(r2,HIGH);
    digitalWrite(r3,HIGH);digitalWrite(r4,HIGH);

      if(digitalRead(c2)==LOW){
      lcd.setCursor(pos, 0);lcd.print('d');delay(500);
        if(digitalRead(c2)==LOW){
        lcd.setCursor(pos, 0);lcd.print('e');delay(500);
          if(digitalRead(c2)==LOW){
          lcd.setCursor(pos, 0);lcd.print('f');delay(500);}}
      a='*';
      pos++;
      break;
     }
            

  
   
    digitalWrite(r1,LOW);digitalWrite(r2,HIGH);
    digitalWrite(r3,HIGH);digitalWrite(r4,HIGH);

      if(digitalRead(c3)==LOW){
      lcd.setCursor(pos, 0);lcd.print('g');delay(500);
        if(digitalRead(c3)==LOW){
       lcd.setCursor(pos, 0);lcd.print('h');delay(500);
          if(digitalRead(c3)==LOW){
          lcd.setCursor(pos, 0);lcd.print('i');delay(500);}}
           a='*';  
           pos++;
           break;
      }
  
  
   
    digitalWrite(r1,HIGH);digitalWrite(r2,LOW);
    digitalWrite(r3,HIGH);digitalWrite(r4,HIGH);

      if(digitalRead(c1)==LOW){
      lcd.setCursor(pos, 0);lcd.print('j');delay(500);
        if(digitalRead(c1)==LOW){
       lcd.setCursor(pos, 0);lcd.print('k');delay(500);
          if(digitalRead(c1)==LOW){
          lcd.setCursor(pos, 0);lcd.print('l');delay(500);}}
          a='*';  
           pos++;
           break;  
      }
  
     
    digitalWrite(r1,HIGH);digitalWrite(r2,LOW);
    digitalWrite(r3,HIGH);digitalWrite(r4,HIGH);

      if(digitalRead(c2)==LOW){
      lcd.setCursor(pos, 0);lcd.print('m');delay(500);
        if(digitalRead(c2)==LOW){
        lcd.setCursor(pos, 0);lcd.print('n');delay(500);
          if(digitalRead(c2)==LOW){
          lcd.setCursor(pos, 0);lcd.print('o');delay(500);}}
           a='*';  
           pos++;
           break;
          }
           
  
  
  
     
    digitalWrite(r1,HIGH);digitalWrite(r2,LOW);
    digitalWrite(r3,HIGH);digitalWrite(r4,HIGH);

      if(digitalRead(c3)==LOW){
      lcd.setCursor(pos, 0);lcd.print('p');delay(500);
        if(digitalRead(c3)==LOW){
        lcd.setCursor(pos, 0);lcd.print('q');delay(500);
          if(digitalRead(c3)==LOW){
          lcd.setCursor(pos, 0);lcd.print('r');delay(500);}}
          a='*'; 
          pos++;
          break;          
          }
          
    
  
      
    digitalWrite(r1,HIGH);digitalWrite(r2,HIGH);
    digitalWrite(r3,LOW);digitalWrite(r4,HIGH);

      if(digitalRead(c1)==LOW){
      lcd.setCursor(pos, 0);lcd.print('s');delay(500);
        if(digitalRead(c1)==LOW){
        lcd.setCursor(pos, 0);lcd.print('t');delay(500);
          if(digitalRead(c1)==LOW){
          lcd.setCursor(pos, 0);lcd.print('u');delay(500);}}
          a='*'; 
          pos++;
          break;
          }
         
    
  
     
    digitalWrite(r1,HIGH);digitalWrite(r2,HIGH);
    digitalWrite(r3,LOW);digitalWrite(r4,HIGH);

      if(digitalRead(c2)==LOW){
      lcd.setCursor(pos, 0);lcd.print('v');delay(500);
        if(digitalRead(c2)==LOW){
        lcd.setCursor(pos, 0);lcd.print('w');delay(500);
          if(digitalRead(c2)==LOW){
         lcd.setCursor(pos, 0);lcd.print('x');delay(500);}}
          a='*'; 
          pos++;
          break;}
         
    
  
    digitalWrite(r1,HIGH);digitalWrite(r2,HIGH);
    digitalWrite(r3,LOW);digitalWrite(r4,HIGH);
      if(digitalRead(c3)==LOW){
      lcd.setCursor(pos, 0);lcd.print('y');delay(500);
        if(digitalRead(c3)==LOW){
        lcd.setCursor(pos, 0);lcd.print('z');delay(500);
          }
         a='*'; 
          pos++;
          break;
          }
        
    //CLEAR
     digitalWrite(r1,HIGH);digitalWrite(r2,HIGH);
    digitalWrite(r3,HIGH);digitalWrite(r4,LOW);

      if(digitalRead(c1)==LOW){
        pos--;
     lcd.setCursor(pos, 0);
     lcd.print(' ');
     delay(500);
         
          a='*'; 
          break;}
         
    
  // SPACE
    digitalWrite(r1,HIGH);digitalWrite(r2,HIGH);
    digitalWrite(r3,HIGH);digitalWrite(r4,LOW);
if(digitalRead(c2)==LOW){
     lcd.setCursor(pos, 0);lcd.print(' ');delay(500);
        
          a='*'; 
          pos++;
          break;}
        

 
  }//WHILE ENDING

}//KEYPAD  ENDING
