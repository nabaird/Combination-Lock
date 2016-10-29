const int green = 12;//Green light illuminates when the correct code has been entered
const int red = 13;//Red light illuminates when the incorrect code has been entered
const int yellow = 11;//Yellow light is illuminated so long as a code has not been set

const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;
const int button5 = 6;
const int button6 = 7;

bool isOn = false; //is any button being held down?
int onButton; //the button being pressed
bool buttonReset = true; //can a button be activated? 

int combination[6]; //the array of values in the combination
int comboLength = 5;//the length of the code
int currentValue = 0; //the current value of the code order being checked

bool codeSet = false; //has the code been set? 

void setup() 
{
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
}

void Success()
{
  digitalWrite(green, HIGH);
  delay(2000);
  digitalWrite(green,LOW);
}

void Failure()
{
  digitalWrite(red, HIGH);
  delay(2000);
  digitalWrite(red, LOW); 
}

void loop() 
{
  bool tempIsOn = false;//a temporary 'isOn' check, so we don't turn off isOn needlesly through every pass
  for(int i = 2; i<8; i++)//scan through the buttons and see which one is being pressed
  {
    if(digitalRead(i)==true)
    {
      tempIsOn = true; 
      onButton = i; 
    }
  }
  isOn = tempIsOn; 

  if(isOn == false)
  {
    buttonReset = true; 
  }
  else if (buttonReset == true)
  {
    if(codeSet == true)//if the code is set, enter the code 
    {
      if(combination[currentValue] == onButton)
      {
      
        if(currentValue==comboLength)
        {
          Success(); 
          currentValue=0; 
        }
        else
        {
          currentValue ++;
        }
      }
      else
      {
        Failure();
        currentValue = 0; 
      }
    }
    else//if the code is not set, set the code
    {
      combination[currentValue]=onButton;
      if(currentValue==comboLength)
      {
        codeSet = true;
        currentValue = 0;
        digitalWrite(yellow, LOW);
      }
      else
      {
        currentValue++;  
      }
    }
    delay(200);
    buttonReset = false; 
  }
}
