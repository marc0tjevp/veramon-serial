#include "definitions.h"
#include "debug.h"
#include "instructions.h"
#include "events.h"

void setup() {
  Serial.begin(9600, SERIAL_8N1);  // Use 8 data bits, no parity, 1 stop bit
  Serial.println("Interface awaits event");
}

void loop() {
  if (Serial.available() > 0) {
    int event = Serial.parseInt();

    if (event > 0 && event < (sizeof(dataSets) / sizeof(dataSets[0]))) {
      Serial.println(event);

      // Send the selected LineData array
      sendMultilineInstruction(dataSets[event]);
    }
  }

  delay(500);
}