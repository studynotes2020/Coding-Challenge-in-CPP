#include <iostream>
using namespace std;

// YOU WILL NEED TO CALL THIS FUNCTION
// Function for taking a string and creating a "checksum" in ASCII
// Reminder: The input string should be more than just the "command"
//           Review problem description for more info
unsigned char checksum(string input) {
  unsigned char accumulated = 0;
  for(char& c : input) {
    accumulated += c;
  }
  return (accumulated % 26) + 'A';
}

// Required output format
const string MSG_HEADER = "ZOOX";

const string MSG_LEFT = "LEFT";
const string MSG_RIGHT = "RIGHT";
const string MSG_FORWARD = "FORWARD";
const string MSG_BEEP = "BEEP";

const string OUTPUT_LEFT = "L";
const string OUTPUT_RIGHT = "R";
const string OUTPUT_FORWARD = "F";
const string OUTPUT_BEEP = "!";

// You should not need to call this function
// Util used by execute_packet_command(...)
void execute_command(string cmd, int repeat) {
  for (int i = 0; i < repeat; i++) {
    cout << cmd;
  }
}

// YOU WILL NEED TO CALL THIS FUNCTION
// Provide the content of the command packet as inputs.
// cmd should be the command string from the packet
// repeat should be the repeat byte from the packet
void execute_packet_command(string cmd, int repeat) {
  if (cmd.compare(MSG_LEFT) == 0) {
    execute_command(OUTPUT_LEFT, repeat);
  }
  if (cmd.compare(MSG_RIGHT) == 0) {
    execute_command(OUTPUT_RIGHT, repeat);
  }
  if (cmd.compare(MSG_FORWARD) == 0) {
    execute_command(OUTPUT_FORWARD, repeat);
  }
  if (cmd.compare(MSG_BEEP) == 0) {
    execute_command(OUTPUT_BEEP, repeat);
  }
}

// Required prototype and main
void parse(char c);
int main() {
  string input;
  input = "ZOOX5LEFT2QZOOX5BEEP3C";
  cout << "Cmd: ";
  for(char& c : input) {
    parse(c);
  }
  return 0;
}

// ------ Do not modify above this line ----------
// ----------- Add your code below ---------------
void parse(char c) {
    static string header = "";
    static int index = 0;
    static string command = "";
    static int len = 0;
    static int rpt = 0;
    static bool check = false;

    index += 1;
//    cout << "i: " << index << " c:" << c << endl;
    if (index < 5) {
        header += c;
    }

    if (index == 4) {
//     cout << header;
     ;
    }
    if (index == 5) {
        len = c - 48;
    }

    if (index == 6) {
        header = c;
    }

    if (len == 6 && index == 11) {
        rpt = c - 48;
        execute_packet_command(MSG_RIGHT, rpt);
        check = true;
    }

    if (len == 5 && index == 10) {
        rpt = c - 48;
        if (header == "L") {
            command = MSG_LEFT;
        }
        else if (header == "B") {
            command = MSG_BEEP;
        }
        execute_packet_command(command, rpt);
        check = true;
    }

    if (len == 8 && index == 13) {
        rpt = c - 48;
        execute_packet_command(MSG_FORWARD, rpt);
        check = true;
    }

    if (c == 81) {
        index = 0;
        command = "";
        rpt = 0;
        header = "";
        check = false;
    }
}