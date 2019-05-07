// Pinos dos LEDs
#define RED_PIN  23 // Fio vermelho
#define GREEN_PIN  25 // Fio azul
#define BLUE_PIN  27 // Fio laranja; Fio marrom é o terra

#define LDR_PIN A8 // VCC=vermelho, GND=marrom, SIG(A0)=amarelo


char input;

void setup  (){
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
  String virg = " , ";
  String label;
  
  while(Serial.available() <= 0){}

  input = (char)Serial.read(  );
  Serial.flush();
  
  if(input == 'r' || input == 'R' ){
    label = "red";
  }
  else if(input == 'g' || input == 'G' ){
    label = "green";
  }
  else if(input == 'b' || input == 'B' ){
    label = "blue";
  }
  else{
    Serial.print(input);
    Serial.println(" Deu ruim");
    return;
  }

  int environmentBrightness = analogRead(LDR_PIN);
  int redReflected  = analogRead(LDR_PIN);
  int blueReflected = analogRead(LDR_PIN);
  int greenReflected  = analogRead(LDR_PIN);


  Serial.println(
    environmentBrightness + virg +
    redReflected + virg +
    blueReflected + virg +
    greenReflected + virg +
    label
    );
    
  input = '\t';
  delay(300);
  
}
