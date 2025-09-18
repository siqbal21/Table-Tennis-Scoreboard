#include <LiquidCrystal.h>

char myTEXT1 [] = "   Player1: ";
char myTEXT2 [] = "   Player2: ";

int score1 = 0;
int score2 = 0;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup()
{
  pinMode (8, INPUT);
  pinMode (9, INPUT);
  pinMode (10, INPUT);
  pinMode (11, INPUT);
  pinMode (12, INPUT);
  pinMode (13, INPUT);

  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print(myTEXT1);
  lcd.print(score1);
  lcd.setCursor(0,1);
  lcd.print(myTEXT2);
  lcd.print(score2);
}

void loop()
{
  if(digitalRead(8) == HIGH)
  {
    score1++;
    printscore();
    delay(3000);
  }
  
  if(digitalRead(13) == HIGH)
  {
    score2++;
    printscore();
    delay(3000);
  }
  
  if (digitalRead(10) == HIGH)
  {
    score1 = 0;
    score2 = 0;
    printscore();
    delay(50);
  }

  if (digitalRead(9) == HIGH)
  {
    score1--;
    printscore();
    delay(1000);
  }

  if (digitalRead(12) == HIGH)
  {
    score2--;
    printscore();
    delay(1000);
  }

  String p1Victory = " Player 1 Wins!";
  //deuces
  if (score1 >= 7 && score1 - 2 >= score2)
  {
    lcd.clear();
    for (int i = 0; i < p1Victory.length(); i++)
    {
      lcd.print(p1Victory.charAt(i));
      delay(100);
    }
    delay(5000);
    score1 = 0;
    score2 = 0;
    printscore();
  }

  String p2Victory = " Player 2 Wins!";
  //deuces
  if (score2 >= 7 && score2 - 2 >= score1)
  {
    lcd.clear();
    for (int i = 0; i < p2Victory.length(); i++)
    {
      lcd.print(p2Victory.charAt(i));
      delay(100);
    }
    delay(5000);
    score1 = 0;
    score2 = 0;
    printscore();
  }
  
}

void printscore()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print(myTEXT1);
  lcd.print(score1);
  lcd.setCursor(0,1);
  lcd.print(myTEXT2);
  lcd.print(score2);
}
