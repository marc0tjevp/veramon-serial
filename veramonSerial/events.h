LineData welcome[4] = {
  { "Welcome!", -1, 3, ACK_INM },
  { "To Veramon", -1, 3, ACK_AR2 },
  { "Serial Control", -1, 3, ACK_AR3 },
  { "Enjoy!", -1, 3, ACK_AR4 }
};

LineData connectionLost[4] = {
  { "Communication Lost", -1, 3, ACK_INM },
  { nullptr, -1, 3, ACK_AR2 },
  { "ECU not responding", -1, 3, ACK_AR3 },
  { nullptr, -1, 3, ACK_AR4 }
};

LineData oilTemp[4] = {
  { "Oil Temperature", -1, 3, ACK_INM },
  { nullptr, -1, 3, ACK_AR2 },
  { "94C", -1, 3, ACK_AR3 },
  { nullptr, -1, 3, ACK_AR4 }
};

LineData goodbye[4] = {
  { "Goodbye!", -1, 3, ACK_INM },
  { "Thanks for using", -1, 3, ACK_AR2 },
  { "Veramon Serial", -1, 3, ACK_AR3 },
  { "See you soon!", -1, 3, ACK_AR4 }
};

LineData* dataSets[] = { nullptr, welcome, connectionLost, oilTemp, goodbye };