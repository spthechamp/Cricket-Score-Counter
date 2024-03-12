Cricket Score Counter with Arduino UNO

This repository contains the code and circuit diagram for a Cricket Score Counter built using Arduino UNO, a 16x2 LCD I2C Display, push buttons, resistors, and LEDs.

Features:
Tracks runs, wickets, overs, and current run rate.
Accounts for wide balls and no balls (adding runs but not balls bowled).
Separate buttons for various scoring events (1 run, 2 run, etc.).
"Publish" button to potentially output the score (implementation details not included).

Hardware Required:
Arduino UNO
16x2 LCD I2C Display
10 Push buttons
Resistors (values depend on specific LED setup)
LEDs (optional, for visual feedback)

Software Required:
Arduino IDE (https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE)

Libraries:
Download and install the LiquidCrystal_I2C library from the Library Manager in Arduino IDE.

Search for "LiquidCrystal_I2C" in the library manager and follow the installation instructions.
Circuit Diagram:
A schematic diagram showcasing the connections between Arduino, LCD, buttons, resistors, and LEDs is included in the repository (file name: circuit.jpg or similar).

Code:
The Arduino code file (e.g., cricket_score_counter.ino) handles button presses, calculates scores, and updates the LCD display.

Instructions:
Download Libraries: Install the LiquidCrystal_I2C library as mentioned earlier.
Connect Hardware: Refer to the circuit diagram for wiring the components.
Upload Code: Open the Arduino IDE,
Navigate to File -> Open ("cricket_score_counter.ino" or similar).
Select your Arduino board and port from the Tools menu.
Click the upload button to program the Arduino.

Note:
The provided code might require adjustments based on your specific hardware configuration (e.g., button pin assignments).
The "Publish" button functionality is not implemented in the code. You can modify the code to transmit the score data (e.g., via serial communication) based on your requirements.

Additional Resources:
Arduino UNO documentation: https://www.arduino.cc/en/Guide
16x2 LCD I2C Display information (refer to your specific display model for details)
LiquidCrystal_I2C library documentation: https://github.com/johnrickman/LiquidCrystal_I2C

Disclaimer: This information provides a general guideline. You might need to modify the code and circuit based on your specific hardware setup and desired functionalities.
