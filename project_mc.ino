
#include <english.h>
#include <sound.h>
#include <TTS.h>


#include <LiquidCrystal.h>
TTS text2speech (10);  // speech output is digital pin 10

LiquidCrystal lcd(13, 12, A5, A4,A3 ,A2 );
const int r1 = 7;
const int r2 = 6;
const int r3 = 5;
const int r4 = 4;
const int c1 = 3;
const int c2 = 2;
const int c3 = 8;
void alphkeypad();
int posx, posy;
int index;
char array[32];
void setup()
{
  Serial.begin(9600);
  posx = 0;
  posy = 0;
  index = 0;

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

  lcd.setCursor(posx, posy);
  lcd.print("Welcome!");

  for (int i = 0; i < 32; i++)
    array[i] = '\0';

  _delay_ms(1000);
  lcd.clear();
}

void loop()
{

  // get the posxition of cursor
  if (posx == 16 && posy == 0)
  {
    posx = 0;
    posy = 1;
  }
  else if (posx == 16 && posy == 1)
  {
    lcd.clear();

    int g = 0;
    for (int i = index - 16; i < index; i++)
    {
      lcd.setCursor(g, 0);
      lcd.print(array[i]);
      g++;
    }
    posx = 0;
    posy = 1;
  }

  lcd.setCursor(posx, posy);

  alphkeypad();
  int i = 0;
  while (array[i] != '\0')
  {
    Serial.print(array[i]);
    i++;
  }
  Serial.println();
  index++;
}

int checker(int c, char l1, char l2, char l3)
{
  if (digitalRead(c) == LOW)
  {
    lcd.setCursor(posx, posy);
    lcd.print(l1);
    array[index] = l1;
    delay(500);
    if (digitalRead(c) == LOW)
    {
      lcd.setCursor(posx, posy);
      lcd.print(l2);
      array[index] = l2;

      delay(500);
      if (digitalRead(c) == LOW)
      {
        lcd.setCursor(posx, posy);
        lcd.print(l3);
        array[index] = l3;
        delay(500);
      }
    }
    // here we have a or b or c letter
    // it indicate that a button is pressed
    posx++;   // inc the posx of cursor
    return 1; // break out from while loop
  }
  return 0;
}
void Text2Speech(){
  int i =0;
 
  // to do : get the real size of the input
  int mxSize=32;
  while(i<mxSize)
  {
    // to do : get the real size of the max word
    const int mxWordSize=20;
    char str[mxWordSize];
    int idx = 0;
    while((array[i]>=65&&array[i]<=90)||(array[i]>=97&&array[i]<=122)) // if it's not space 
    {
      str[idx++] = array[i++];
    }
    i++;
    for(int j=0;j<idx;j++)
      Serial.print(str[j]);
    Serial.print("\n");
    
    text2speech.setPitch(6); //higher values = lower voice pitch
    text2speech.sayText(str);
 
 
    delay(1000);
    if(array[i]=='\0')break; // when reach to end of input will break
  }
  Serial.println("finish...............");
  
}

void alphkeypad()
{

  while (true)
  {
    // set col 1->3 to be high
    digitalWrite(c1, HIGH);
    digitalWrite(c2, HIGH);
    digitalWrite(c3, HIGH);
    //set one row with low and rest with high
    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, HIGH);

    // c1 is low then the pressed is either a or b or c
    // a will be printed
    // we have 0.5 sec delay, if the same button  pressed it will be changed to b then c
    if (checker(c1, 'a', 'b', 'c'))
      break;

    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, HIGH);

    if (checker(c2, 'd', 'e', 'f'))
      break;

    digitalWrite(r1, LOW);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, HIGH);

    if (checker(c3, 'g', 'h', 'i'))
      break;

    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, HIGH);

    if (checker(c1, 'j', 'k', 'l'))
      break;

    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, HIGH);

    if (checker(c2, 'm', 'n', 'o'))
      break;

    digitalWrite(r1, HIGH);
    digitalWrite(r2, LOW);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, HIGH);

    if (checker(c3, 'p', 'q', 'r'))
      break;

    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, LOW);
    digitalWrite(r4, HIGH);

    if (checker(c1, 's', 't', 'u'))
      break;

    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, LOW);
    digitalWrite(r4, HIGH);

    if (checker(c2, 'v', 'w', 'x'))
      break;

    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, LOW);
    digitalWrite(r4, HIGH);

    if (digitalRead(c3) == LOW)
    {
      lcd.setCursor(posx, posy);
      lcd.print('y');
      array[index] = 'y';
      delay(500);
      if (digitalRead(c3) == LOW)
      {
        lcd.setCursor(posx, posy);
        lcd.print('z');
        array[index] = 'z';
        delay(500);
      }
      posx++;
      break;
    }

    //CLEAR
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, LOW);

    if (digitalRead(c1) == LOW)
    {
      if (posx == 0 && posy == 0)
      {
        break;
      }
      if (posx == 0 && posy == 1)
      {
        posx = 16;
        posy = 0;
      }
      posx--;
      lcd.setCursor(posx, posy);
      lcd.print(' ');
      delay(500);

      array[--index] = ' ';
      index--;
      break;
    }

    // SPACE
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, LOW);
    if (digitalRead(c2) == LOW)
    {
      lcd.setCursor(posx, posy);
      lcd.print(' ');
      delay(500);

      array[index] = ' ';
      posx++;
      break;
    }

    // ENTER
    digitalWrite(r1, HIGH);
    digitalWrite(r2, HIGH);
    digitalWrite(r3, HIGH);
    digitalWrite(r4, LOW);
    if (digitalRead(c3) == LOW)
    {
      lcd.clear();
      posx = 0;
      posy = 0;
      lcd.setCursor(posx, posy);

      Text2Speech();
      // call function that convert text2speech
      for (int i = 0; i < 32; i++)
        array[i] = '\0';
      index = -1;
      Serial.println("sent completed");
      delay(500);
      break;
    }
  } //WHILE ENDING

} //KEYPA
