import time
import sys
import serial
import io

ser = serial.Serial(
    port=sys.argv[1],
    baudrate=115200,
    parity=serial.PARITY_ODD,
    stopbits=serial.STOPBITS_TWO,
    bytesize=serial.SEVENBITS
)

PATH = "../data/"

if len(sys.argv) > 2:
    FILE_NAME = sys.argv[2]
else:
    FILE_NAME = "new_data_file.csv"

writingFile = open(FILE_NAME, "a",  )

print('''
    Usage:  R for Red
            g for green
            b for blue
            y for yellow
            d for black
''')

while True:

    ser.flush();
    label = input("Which color are you sampling?  :  ")
    ser.write(label.encode())

    time.sleep(0.5)
    text = str(ser.read_all().decode("UTF-8"))
    writingFile.write(text)
    print(text)
