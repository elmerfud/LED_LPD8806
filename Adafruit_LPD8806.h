#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

// I don't know of any LPD8806 strips that aren't GRB, but I don't know everything
// Adding this option because it seems handing, defaulting class to use GRB
#define COLOR_ORDER_RGB 0
#define COLOR_ORDER_GRB 1

// Pause after latch
#define PAUSE_TIME 3

class Adafruit_LPD8806 {

 public:

  Adafruit_LPD8806(uint16_t n, uint8_t dpin, uint8_t cpin, uint8_t order=COLOR_ORDER_GRB); // Configurable pins
  Adafruit_LPD8806(uint16_t n, uint8_t order=COLOR_ORDER_GRB); // Use SPI hardware; specific pins only
  Adafruit_LPD8806(void); // Empty constructor; init pins/strip length later
  void
    begin(void),
    show(void),
    setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b),
    setPixelColor(uint16_t n, uint32_t c),
    updatePins(uint8_t dpin, uint8_t cpin), // Change pins, configurable
    updatePins(void), // Change pins, hardware SPI
    updateLength(uint16_t n), // Change strip length
    updateOrder(uint8_t order); // Change data order
  uint16_t
    numPixels(void);
  uint32_t
    getPixelColor(uint16_t n);

  uint8_t
    pause;  // Delay (in milliseconds) after latch

 private:

  uint16_t
    numLEDs; // Number of RGB LEDs in strip
  uint8_t
    *pixels, // Holds LED color values (3 bytes each)
    rgb_order, // Color order; RGB vs GRB (or others, if needed in future)
    clkpin    , datapin,     // Clock & data pin numbers
    clkpinmask, datapinmask; // Clock & data PORT bitmasks
  volatile uint8_t
    *clkport  , *dataport;   // Clock & data PORT registers
  void
    alloc(uint16_t n),
    startSPI(void),
    writeLatch(uint16_t n);
  boolean
    hardwareSPI, // If 'true', using hardware SPI
    begun;       // If 'true', begin() method was previously invoked
};
