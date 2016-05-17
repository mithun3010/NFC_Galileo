String voice;
int led1 = 13; 

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(led1, OUTPUT);
}

void loop() {
  while (Serial1.available()){  
  delay(10); 
  char c = Serial1.read(); 
  if (c == '#') {
  break;
  } 
  voice += c; 
  } 
  if (voice.length() > 0) {
    Serial1.println(voice);

   if(voice == "*lock on") 
   {
   digitalWrite(led1, HIGH);
   }
  else if(voice == "*lock off")
  {
  digitalWrite(led1, LOW);
  }

voice="";
  }
} 
