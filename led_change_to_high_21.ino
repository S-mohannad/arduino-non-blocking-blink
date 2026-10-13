unsigned long t1=0,t2=0;
bool s=0;
void setup() {
pinMode(13,OUTPUT);
}
void loop() { 
t1=millis();
if(t1>t2+500){
s=!s;
digitalWrite(13,s);
t2=t1;}
}