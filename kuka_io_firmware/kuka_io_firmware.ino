/*
              _     __ 
 /__//  //__//_|  //  )
/  )(__//  )(  | ((__/ 

Send values to KUKA from Arduino by encoding them as 1-Byte (0-255) outputing them as 
8 digital ouputs in parallel to a KUKA digital IN module. Value is received in KUKA KRC as BYTE 
by setting the IO Mapping to 1-Byte output.

*/

const byte totalIO = 8;

const byte parallelIO[totalIO] = {
  2,3,4,5,6,7,8,12
};

void setup() {
  Serial.begin(9600);
  setupParallelByte();
}

void loop() {
  int sensor = analogRead(A0);
  sensor = map(sensor, 0, 1023, 0, 255);
  setParallelByteEnd(sensor);
  delay(100);
}

void setParallelByte(byte value){
  // Unsigned Char to Parallel Bit register
  Serial.print("V: ");
  Serial.print(value);
  Serial.print("\t|\t ");
  for (int i = 0; i < totalIO; i++){
    byte thisBit = bitRead(value, i);
    Serial.print(thisBit);
    digitalWrite(parallelIO[i], !thisBit);
  } 
  Serial.print("\n");
}

void setParallelByteEnd(byte value){
  Serial.print("V: ");
  Serial.print(value);
  Serial.print("\t|\t ");
  for (int i = totalIO-1; i >= 0; i--){
    byte thisBit = bitRead(value, i);
    Serial.print(thisBit);
    digitalWrite(parallelIO[i], !thisBit);
  } 
  Serial.print("\n");
}


void setupParallelByte(){
  for (int i = 0; i < totalIO; i++){
    pinMode(parallelIO[i], OUTPUT);
  } 
}

/* Test Functions */

void setParallelByteAllOff(){
  for (int i = 0; i < totalIO; i++){
    digitalWrite(parallelIO[i], HIGH);
  } 
}

void setParallelByteAllOn(){
  for (int i = 0; i < totalIO; i++){
    digitalWrite(parallelIO[i], LOW);
  } 
}
