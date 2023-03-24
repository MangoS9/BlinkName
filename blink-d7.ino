// We define MY_LED to be the LED that we want to blink. 
//
// In this tutorial, we're using the blue D7 LED (next to D7 on the Photon 
// and Electron, and next to the USB connector on the Argon and Boron).
const pin_t MY_LED = D7;
const int Mdelay = 250;

//-   .-   ..   -.   --.
//T = 1 dash
//A = 1 dot 1 dash
//I = 2 dot
//N = 1 dash 1 dot
//G = 2 dash 1 dot

// The following line is optional, but recommended in most firmware. It 
// allows your code to run before the cloud is connected. In this case, 
// it will begin blinking almost immediately instead of waiting until 
// breathing cyan,
SYSTEM_THREAD(ENABLED);

// The setup() method is called once when the device boots.
void setup() {
	// In order to set a pin, you must tell Device OS that the pin is 
	// an OUTPUT pin. This is often done from setup() since you only need 
	// to do it once.
	pinMode(MY_LED, OUTPUT);
}

// The loop() method is called frequently.
void loop() {
    
    int Sname[5][3] = {{1,0,0},
                      {1,3,0},
                      {1,1,0},
                      {3,1,0},
                      {3,3,1}};

    for(int i{0};i < 5;i++){
        for(int j{0};j < 3;j++){
            if(Sname[i][j] != 0){
                blink(Sname[i][j]);
            }
        }
        delay(Mdelay* 3);
    }
    
	// Turn on the LED
// 	blink(1);

// 	// Leave it on for one second
// 	delay(1s);

// 	// Turn it off
// 	digitalWrite(MY_LED, LOW);

// 	// Wait one more second
// 	blink(1);

	// And repeat!

}

void blink(int n){
    digitalWrite(MY_LED, HIGH);
    delay(Mdelay * n);
    digitalWrite(MY_LED, LOW);
    delay(Mdelay);
}
