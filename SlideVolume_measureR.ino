//Measure a slide volume's potentiometer value

//target pin num
#define FIN 32
#define RIN 33
#define ADC_POTENTIO 34
#define HIGHPIN 4

void setup() {
  Serial.begin(115200);
  while(!Serial);
  ledcAttachPin(FIN,1);
  ledcAttachPin(RIN,2);
  ledcSetup(1,39000,11);
  ledcSetup(2,39000,11);
  pinMode(HIGHPIN,OUTPUT);
}

int vals[20],ind=0;
float average,val;
void loop() {
  digitalWrite(HIGHPIN,HIGH);
  
  //Averaging filter * 20
  vals[ind=(ind+1)%20]=analogRead(ADC_POTENTIO);
  average=0;
  for(int i=0;i<20;i++)
    average+=vals[i];
  average/=20;
  Serial.println(average);
  val=average;

  //Press return key in serial monitor to record val
  if(Serial.available()>0){
    if(Serial.read()=='\n'){
      Serial.println(val);
      Serial.println('\n');
    }
  }
}
