
char msg = 'a';
const int lightPin  = 0;
int light           = 0;

int lptPin = 2;
int statusPin = 7;

unsigned long latency;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(statusPin, OUTPUT);
    pinMode(lptPin, INPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Serial.begin(9600);
}

void loop()
{

    digitalWrite(statusPin, digitalRead(lptPin) ? HIGH : LOW);

    if(Serial.available()){
        msg = Serial.read();
        if(msg == 'r'){
            //we should start timing
            unsigned long start = micros();
            while(1){
                if(digitalRead(lptPin)){
                    //we got a signal! calculate delay
                    latency = micros() - start;
                    //send to computer
                    Serial.print(latency);
                    delay(5); //wait out the time to trigger to end
                    break;
                }
            }
        }
        digitalWrite(LED_BUILTIN, msg == 'a' ? LOW : HIGH);
    }

    if(digitalRead(lptPin)){
        Serial.println("Trigger detected!");
        delay(5);
    }
}
