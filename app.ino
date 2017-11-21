
char msg = 'a';
const int lightPin  = 0;
int light           = 0;


void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Serial.begin(9600);
}

void loop()
{

    light = analogRead(lightPin);

    if(Serial.available()){
        msg = Serial.read();
        if(msg == 'r'){
            Serial.write('r');
        }
        digitalWrite(LED_BUILTIN, msg == 'a' ? LOW : HIGH);
    }
}
