# How-to-Set-Up-MQTT-Communication-Between-ESP32-and-Raspberry-Pi-for-Controlling-LEDs
This guide will walk you through the process of setting up MQTT communication between an ESP32 microcontroller and a Raspberry Pi. The ESP32 will send button signals to the Raspberry Pi, which will control LEDs accordingly. We'll use the MQTT protocol for communication between the two devices

Requirements:
1.	ESP32 microcontroller
2.	Raspberry Pi
3.	LEDs (and appropriate resistors)
4.	Jumper wires
5.	Breadboard
6.	Internet connection

Step 1: Set up the Raspberry Pi

1.1.	Install Required Libraries:

•	Make sure your Raspberry Pi is connected to the internet.

•	Open the terminal on your Raspberry Pi.

•	Install the required libraries by running the following commands:

sudo apt-get update

sudo apt-get install python3-pip

pip3 install paho-mqtt
 
1.2.	Prepare Your Raspberry Pi GPIO Pins:

•	Connect LEDs to GPIO pins on the Raspberry Pi. In this example:

•	LED 1: GPIO 17

•	LED 2: GPIO 27

•	LED 3: GPIO 22

•	LED 4: GPIO 10

Step 2: Set up the ESP32

1.3.	Install Required Libraries:

•	Install the Arduino IDE if you haven't already.

•	Install the ESP32 board support package in the Arduino IDE. Follow these instructions.

1.4.	Prepare Your ESP32 Pins:

•	Connect buttons to GPIO pins on the ESP32. In this example:

•	Button 1: GPIO 19

•	Button 2: GPIO 4

•	Button 3: GPIO 5

•	Button 4: GPIO 18

Step 3: Write the ESP32 Code

•	Open the Arduino IDE.

•	Copy the provided ESP32 code into a new sketch.

•	Replace the placeholders for WiFi credentials (ssid and password) and MQTT credentials (mqttServer, mqttUser, and mqttPassword) with your actual credentials.

•	Upload the code to your ESP32.

Step 4: Write the Raspberry Pi Code

•	Create a new Python script on your Raspberry Pi.

•	Copy the provided Python code into the script.

•	Replace the placeholders for WiFi credentials (ssid and password) and MQTT credentials (mqttServer, mqttUser, and mqttPassword) with your actual credentials.

•	Modify the GPIO pin numbers if necessary to match your hardware setup.

•	Save the script.

Step 5: Run the Programs

•	Run the Python script on your Raspberry Pi.

python3 you_script_name.py
 
•	Press the buttons connected to the ESP32.

•	The corresponding LEDs on the Raspberry Pi should turn on and off accordingly.

Congratulations! You have successfully set up MQTT communication between an ESP32 and a Raspberry Pi to control LEDs. You can expand upon this project by adding more functionalities or integrating additional sensors and actuators.

Step 6: Wiring Setup

•	Before proceeding, ensure that you have wired your components correctly according to the provided instructions.

 
•	Verify that your connections match the diagram to avoid any issues during testing.

•	Double-check the connections between the buttons, LEDs, GPIO pins, and power sources to ensure everything is properly connected.

By referring to the wiring diagram, you can ensure that your hardware setup matches the recommended configuration. This will help in troubleshooting any potential issues and ensure smooth functionality of your project.
