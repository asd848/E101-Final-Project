/*
  Digital FIR Filter
 
 Reads analog input pin (range 0-1023) and
 prints the filtered output to the serial monitor
 
 The circuit:
 * analog signal connected to analog pin A1

*/
const int inputPin = A1;  // Analog input pin  

// filter coefficients
const float b0=0.333;
const float b1=0.333;
const float b2=0.333;

// initial values for internal signals
int xstore1 = 0;
int xstore2 = 0;

int yn = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  // analogRead value from pin A1 (0-1023)
  int xn = analogRead(inputPin);
  
  
  // difference equation for filter                    
   yn= b0*xn  + b1*xstore1 + b2*xstore2;
   
  // print to output
 Serial.print(xn);
 Serial.print("  ");
 Serial.println(yn); 
  
  // update stored values
xstore2 = xstore1;
xstore1 = xn;
  
  delay(10);  // sample time ms               
}



