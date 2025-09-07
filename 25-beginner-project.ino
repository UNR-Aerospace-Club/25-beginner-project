// this is poor c++ paradigm, we're only doing this for the sake of everything being one file
// this class will represent a simple interface with our 8-bit shift register
class Register {
private:

  // our clock input
  const uint8_t serialClock = 10;
  // our data input
  const uint8_t serialData = 11;
  // pulling this pin high will clear the shift register
  const uint8_t serialClear = 5;
  // the rising edge of this pin will cause the storage registers to apply to the output pins
  const uint8_t registerClock = 9;
  // pulling this high will disable output
  const uint8_t outputEnable = 6;


public:

  // our class constructor
  Register() {
    // initialize our pins
    pinMode(serialClock, OUTPUT);
    pinMode(serialData, OUTPUT);
    pinMode(serialClear, OUTPUT);
    pinMode(registerClock, OUTPUT);
    pinMode(outputEnable, OUTPUT);

    // clear the register of extrainious data when the program boots
    clear();
  }

  void pushSerialIn(bool bit) {
    // push in our bit
    digitalWrite(serialClock, LOW);
    digitalWrite(serialData, bit ? LOW : HIGH);
    // pulse the serial clock pin
    digitalWrite(serialClock, HIGH);
    digitalWrite(serialClock, LOW);
  }

  // push a full byte of data in one function call
  // we are taking advantage of an arduino feature to make our lives easier
  // under the hood, this is the same as pushing out 8 bits, one at a time
  void pushSerialInParallel(uint8_t byte) {
    digitalWrite(serialClock, LOW);
    shiftOut(serialData, serialClock, MSBFIRST, byte);
  }

  void pushParallelOut() {
    // pulse our register clock to shove our serial data to the output pins
    digitalWrite(registerClock, HIGH);
    digitalWrite(registerClock, LOW);
  }

  // just for fun and convenince
  void displayByte(uint8_t byte) {
    pushSerialInParallel(byte);
    pushParallelOut();
  }

  void clear() {
    digitalWrite(serialClear, LOW);
    delay(50);
    digitalWrite(serialClear, HIGH);
  }
};

///////////////////////////////////////////////
//////////// END OF CLASS DEF ///////////////
/////////////////////////////////////////////

// make a register pointer
// we dont really need to worry about deleting this because memory will clear on poweroff
Register* bitRegister = nullptr;

void setup() {
  // put your setup code here, to run once:
  bitRegister = new Register();

  // will shift out to turn on all of the leds to ensure everything is working
  bitRegister -> displayByte(0b11111111);
  delay(1000);
}


// basic example of an animation loop
void loop() {
  // put your main code here, to run repeatedly:
  // display this on off pattern
  bitRegister -> displayByte(0b11010110);
  // push in a new bit
  bitRegister -> pushSerialIn(0);
  // display
  bitRegister -> pushParallelOut();
  // push new bits in
  bitRegister -> pushSerialIn(1);
  bitRegister -> pushSerialIn(1);
  // display
  bitRegister -> pushParallelOut();

}
