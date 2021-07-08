//Measure a slide volume's potentiometer value

//target pin num
#define ADC_POTENTIO 34

void setup() {
  Serial.begin(115200);
  while(!Serial);
}

int vals[20],average,val,ind=0;
void loop() {
  //Averaging filter * 20
  vals[ind=(ind+1)%20]=analogRead(ADC_POTENTIO);
  average=0;
  for(int i=0;i<20;i++)
    average+=vals[i];
  average/=20;
  val=average;

  //Press return key in serial monitor to record val
  if(Serial.available()>0){
    if(Serial.read()=='\n'){
      Serial.println(val);
      Serial.println('\n');
    }
  }
}
