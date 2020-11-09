#define RED 	12
#define GREEN	13
#define INTERVAL_RED	500
#define INTERVAL_GREEN	1000
#define INTERVAL_MESSAGE 2000

unsigned long time = 0;
unsigned long time_red = 0;
unsigned long time_green = 0;
unsigned long time_msg = 0;

bool red_state = 0;
bool green_state = 0;
bool msg_state = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  time = millis();
  
  if(time - time_red > INTERVAL_RED) {
    time_red = time;
    red_state = !red_state;
    digitalWrite(RED, !red_state);
    // Serial.println("RED");
  }
  
  if(time - time_green > INTERVAL_GREEN) {
    time_green = time;
    green_state = !green_state;
    digitalWrite(GREEN, green_state);
    // Serial.println("GREEN");
  }
  
  if(time - time_msg > INTERVAL_MESSAGE) {
    time_msg = time;
    Serial.println("Hello, I come from the future");
    Serial.println();
  }
}

