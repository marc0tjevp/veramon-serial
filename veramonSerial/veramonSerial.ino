#include "definitions.h"
#include "debug.h"
#include "instructions.h"

void setup() {
  Serial.begin(9600, SERIAL_8N1);  // Use 8 data bits, no parity, 1 stop bit
}

void loop() {
  LineData lines[4] = {
    { "Veramon Serial", -1, 3, ACK_INM },
    { nullptr, 0, 3, ACK_AR2 },
    { "Extended version", -1, 3, ACK_AR3 },
    { nullptr, 0, 3, ACK_AR4 }
  };

  sendMultilineInstruction(lines);

  delay(500);
}