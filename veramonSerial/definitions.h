#define R1 251          // Line 1
#define R2 252          // Line 2
#define R3 253          // Line 3
#define R4 254          // Line 4
#define ACK_INM 0       // Display on receive
#define ACK_AR2 2       // Display after receiving line 2
#define ACK_AR3 3       // Display after receiving line 3
#define ACK_AR4 4       // Display after receiving line 4
#define SCREEN_WIDTH 20  // Screen Width of the Veramon is 20

struct LineData {
  const char* text;  // Text to display
  int position;      // Starting position on the line
  int duration;      // Duration to display the text
  int ack;           // Acknowledgment type
};
