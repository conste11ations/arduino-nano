void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) ; // wait for Arduino Serial Monitor
  Serial.println("Setup in progress......");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
    delay(60000); 
  digitalWrite(LED_BUILTIN, LOW);
    delay(2000); 
}
