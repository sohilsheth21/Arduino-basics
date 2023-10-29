const int flexPin_1 = A0;
const int flexPin_2 = A1;
int fsrPin = 2;     // the FSR and 10K pulldown are connected to a0
int fsrReading;  
const int button=3;
int Button;
int flexValue1, flexValue2;
void setup() 
{ 
  Serial.begin(9600);
} 
 
void loop() 
{ 
  
  flexValue1 = analogRead(flexPin_1);
  Serial.print("sensor1: ");
  Serial.println(flexValue1);
  flexValue2 = analogRead(flexPin_2);
  Serial.print("sensor2: ");
  Serial.println(flexValue2);
  fsrReading = analogRead(fsrPin);
  Button=digitalRead(button);
  Serial.println(Button);  
  

  int fv1=flexValue1;
  int fv2=flexValue2;
  String st;

  Serial.print("Analog reading = ");
  Serial.print(fsrReading);     // print the raw analog reading
  int fsrR=0;
  if (fsrReading < 10) {
    Serial.println(" - No pressure");
    fsrR=0;
  } else if (fsrReading < 200) {
    Serial.println(" - Light touch");
    fsrR=1;
  } else if (fsrReading < 300) {
    Serial.println(" - Light squeeze");
    fsrR=2;
  } else if (fsrReading < 400) {
    Serial.println(" - Medium squeeze");
    fsrR=3;
  } else {
    Serial.println(" - Big squeeze");
    fsrR=4;
  }
  while(Button==1){

  if((fv1>=200)&&(fv2>=195)&&(fsrR==1)){
    st="Hello";
  }
  else if((fv1>=150)&&(fv1<=200)&&(fv2>=195)&&(fsrR==1)){
    st="Sorry";
  }
  else if((fv1>=100)&&(fv1<=150)&&(fv2>=195)&&(fsrR==1)){
    st="Stop";
  }
  else if((fv1<=100)&&(fv2>=195)&&(fsrR==1)){
    st="Go";
  }
  else
  Serial.println("nothing");
  Serial.println(st);
  }
  
  delay(3000);
}
