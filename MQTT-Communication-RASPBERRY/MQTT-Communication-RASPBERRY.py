import time
import paho.mqtt.client as mqtt
import RPi.GPIO as GPIO
from time import sleep
from gpiozero import LED

varLED1 = LED(17)
varLED2 = LED(27)
varLED3 = LED(22)
varLED4 = LED(10)

# WiFi credentials
ssid = "WIFI-NAME"
password = "**********"

# MQTT credentials
mqttServer = "IP-OFF-MQTT"
mqttPort = 1883
mqttUser = "MQTT-USERNAME"
mqttPassword = "*********"
clientID = "CUSTOM RASP NAME"

# Topics
Woonkamer_topic = "huis/Woonkamer/licht"
Keuken_topic = "huis/Keuken/licht"
Gang_topic = "huis/Gang/licht"
Slaapkamer_topic = "huis/Slaapkamer/licht"


# Callback function
def on_message(client, userdata, message):
    print("Message arrived in topic: {}".format(message.topic))
    print("Message: {}".format(message.payload.decode()))
    print("-----------------------")
    if message.payload.decode() == "knop 1":
        print("Toggling LED")
        varLED1.toggle()
    if message.payload.decode() == "knop 2":
        print("Toggling LED")
        varLED2.toggle()
    if message.payload.decode() == "knop 3":
        print("Toggling LED")
        varLED3.toggle()
    if message.payload.decode() == "knop 4":
        print("Toggling LED")
        varLED4.toggle()

# Create MQTT client instance
client = mqtt.Client(clientID)
client.username_pw_set(mqttUser, mqttPassword)
client.on_message = on_message

# Connect to MQTT broker
client.connect(mqttServer, mqttPort)
client.subscribe("huis/#")
print("Connected to MQTT broker")

# Main loop
try:
    client.loop_forever()
except KeyboardInterrupt:
    print("Interrupted")
    client.disconnect()
