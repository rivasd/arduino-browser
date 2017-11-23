
const int lightPin  = 3;
int lptPin = 2;
int statusPin = 7;
bool status = true;

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
    if(! digitalRead(lightPin)){
        //we should start timing
        unsigned long start = micros();
        //Serial.println("ready");
        digitalWrite(LED_BUILTIN, HIGH);
        while(1){
            if(digitalRead(lptPin)){
                
                //delay(100);
                //we got a signal! calculate delay
                latency = micros() - start;
                digitalWrite(statusPin, HIGH);
                
                //send to computer
                Serial.print(latency);
                //delay(5); //wait out the time to trigger to end
                
                while(1){
                    if(digitalRead(lightPin)){
                        digitalWrite(LED_BUILTIN, LOW);
                        digitalWrite(statusPin, LOW);
                        delay(2);
                        break;
                    }
                    //Serial.println("waiting for reset...");
                }
                break; 
            }
        }
        
    }
    
    

    // if(digitalRead(lptPin)){
    //     Serial.println("Trigger detected!");
    //     delay(5);
    // }
}
