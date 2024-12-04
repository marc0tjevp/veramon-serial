void preprocessPositions(LineData lines[4]) {
  for (int i = 0; i < 4; i++) {
    if (lines[i].position == -1) {
      lines[i].position = (SCREEN_WIDTH - strlen(lines[i].text)) / 2;
    }
  }
}

void sendInstruction(int line, const LineData& data) {
  int position = data.position;
  int length = strlen(data.text);

  if (data.position == -1) {
    position = (SCREEN_WIDTH - length) / 2;
  }

  Serial.write(line);
  Serial.write(position);
  Serial.write(length);
  Serial.write(data.duration);
  Serial.write(data.ack);
  Serial.write(data.text);
  Serial.flush();

  delay(500);
}

void sendMultilineInstruction(LineData lines[4]) {
  preprocessPositions(lines);

  for (int i = 0; i < 4; i++) {
    if (lines[i].text != nullptr) {
      sendInstruction(R1 + i, lines[i]);
    }
  }

  // Print human-readable debug output
  //printInstructionReadable(lines);
  printScreenRepresentation(lines);
}
