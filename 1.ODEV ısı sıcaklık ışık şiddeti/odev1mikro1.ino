#define echoPin 5
#define trigPin 4

int cmetre;
int sure;
int yesilled= 12;
int ledkirmizi= 11;


int lm35Pin = A0;
int temperature ;

int light = A1;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);   
  pinMode(yesilled, OUTPUT);   
  pinMode(ledkirmizi, OUTPUT);
  pinMode(light, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);  
  
  cmetre = ((sure/29.1)/2);
  
  if(cmetre < 10){
    
   temperature = ((analogRead(lm35Pin) * 4.88)-500)/10;
   light = analogRead(A1);
    
    if ((temperature > 20)&&(light < 240)){
      digitalWrite(ledkirmizi,LOW);
      digitalWrite(yesilled,HIGH);
    } 
    else if((temperature < 20) && (light < 240)){
      digitalWrite(ledkirmizi,HIGH);
      digitalWrite(yesilled,HIGH);
    }
    else if((temperature > 20) && (light > 240)){
      digitalWrite(ledkirmizi,LOW);
      digitalWrite(yesilled,LOW);
    }
    else if((temperature < 20) && (light > 240)){
      digitalWrite(ledkirmizi,HIGH);
      digitalWrite(yesilled,LOW);
    }
 
   
  
  }
  else{
  temperature = ((analogRead(lm35Pin) * 4.88)-500)/10;
   light = analogRead(A1);
  
    Serial.print(cmetre);
  Serial.println(" santimetre");
   
  
  Serial.print("SICAKLIK=");
  Serial.println(temperature);
 
  Serial.print("ISIK=");
  Serial.println(light);
   delay(500);
  }
}
 