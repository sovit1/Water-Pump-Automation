
int signal1=6;
int signal2=4;
int relay=8,c=1;
//signal1 for higher pin in PVC and signal2 for lower pin in PVC
//c=0 -> Condition-> Emptying ----- c=1-> Condition->Filling
//RELAY - Normally Open
void setup()
{
  Serial.begin(9600);
 
  pinMode(signal1,INPUT_PULLUP);
  pinMode(signal2,INPUT_PULLUP);
  pinMode(relay,OUTPUT);
  
}
void loop()
{
  if(digitalRead(signal1)==LOW && digitalRead(signal2)==LOW)//LOW means shorted else not
  {
    digitalWrite(relay,LOW);//Turning off the pump
    c=0;
  }
  else if(digitalRead(signal1)==HIGH && digitalRead(signal2)==LOW)
  {
    if(c==0)
    digitalWrite(relay,LOW);//Keeping the pump off
    else
    digitalWrite(relay,HIGH);//Keeping the pump ON
  }
  else if(digitalRead(signal1)==HIGH && digitalRead(signal2)==HIGH)
  {
    digitalWrite(relay,HIGH);//Turning ON the relay
    c=1;
  }
  else
  digitalWrite(relay,LOW);//Keeping the relay OFF as there is no other option
 
 
 
}
