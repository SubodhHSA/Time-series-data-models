from socket import timeout
import serial
import time
from datetime import datetime, timezone
import keyboard
import atexit

port        = 'COM15'
baudrate    = 9600

pause = 'esc'
start = 'insert'

closed = 0

def exit_handler():
    if closed == 1:
        return
    closed = 1
    ser.__del__()
    print('\nclosing....')
    time.sleep(1)

atexit.register(exit_handler)

try:
    while True:
        print('\nopening port.....\n')
        while True:
            try:
                ser = serial.Serial(port, baudrate, timeout=1)
                break
            except serial.serialutil.SerialException:
                pass
            time.sleep(1)
            if keyboard.is_pressed(pause):
                print('\nstopped!\npress ' + start + ' to reopen')
                keyboard.wait(start)
        utc_dt = datetime.now(timezone.utc) # UTC time
        dt = utc_dt.astimezone() # local time
        t = int(utc_dt.timestamp()) + dt.utcoffset().seconds
        ser.write((str(t)+ "\n").encode('utf-8'))
        while True:
            print(str(ser.readline()).replace("b'", "").replace("'", "").replace("\\t", "\t").replace("\\n", "\n").replace("\\r", ""), end='')
            if keyboard.is_pressed(pause):
                ser.__del__()
                print('\nport closed!\npress ' + start + ' to reopen')
                break
        keyboard.wait(start)
except KeyboardInterrupt:
    exit_handler()