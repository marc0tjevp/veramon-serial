void printInstructionReadable(LineData lines[4]) {
  Serial.println("\n--- Instructions Sent ---");
  for (int i = 0; i < 4; i++) {
    if (lines[i].text != nullptr) {
      char buffer[128];
      snprintf(buffer, sizeof(buffer), "line: %d, position: %d, length: %d, duration: %d, ack: %d, data: %s",
               R1 + i, lines[i].position, strlen(lines[i].text), lines[i].duration, lines[i].ack, lines[i].text);
      Serial.println(buffer);
    }
  }
  Serial.println("--------------------------\n");
}

void printScreenRepresentation(LineData lines[4]) {
  Serial.println("\n+--------------------+");

  for (int i = 0; i < 4; i++) {
    if (lines[i].text != nullptr && strlen(lines[i].text) > 0) {
      char lineBuffer[SCREEN_WIDTH + 1];
      memset(lineBuffer, ' ', SCREEN_WIDTH);
      lineBuffer[SCREEN_WIDTH] = '\0';

      // Ensure position is within bounds
      int position = lines[i].position >= 0 ? lines[i].position : 0;
      position = position < SCREEN_WIDTH ? position : SCREEN_WIDTH - 1;

      // Copy the text into the buffer at the calculated position
      strncpy(lineBuffer + position, lines[i].text, SCREEN_WIDTH - position);

      // Ensure trailing spaces
      for (int j = strlen(lineBuffer); j < SCREEN_WIDTH; j++) {
        lineBuffer[j] = ' ';
      }

      Serial.print("|");
      Serial.print(lineBuffer);
      Serial.println("|");
    } else {
      Serial.println("|                    |");
    }
  }

  Serial.println("+--------------------+");
}
