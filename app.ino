
char msg = 'a';

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Serial.begin(9600);
}

void loop()
{
    if(Serial.available()){
        msg = Serial.read();
    }

    digitalWrite(LED_BUILTIN, msg == 'a'? LOW : HIGH);
}
