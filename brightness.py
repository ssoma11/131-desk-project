import serial
import csv
import time
import ctypes
import screen_brightness_control as sbc

ser = serial.Serial("COM5", 9600)


# print(brightness)

while True:

    cc = str(ser.readline())
    data = cc[2:][:-5]
    result = data.split(',', 3)
    brightness = int(result[2])

    if brightness < 150:
        ser.write(b"9")
        sbc.set_brightness(40)
    elif 150 < brightness < 300:
        ser.write(b"5")
        sbc.set_brightness(70)
    else:
        ser.write(b"0")
        sbc.set_brightness(100)
    time.sleep(5)

