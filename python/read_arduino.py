#!/usr/bin/env python
""" 
basketPInfo data collector (via serial USB)

Rafal Zawadzki <bluszcz@bluszcz.net>
BSD License (license.txt)
"""
import serial, time

USB = "/dev/ttyACM1" #  change to your USB

SERIALPORT = serial.Serial(USB, 9600, timeout=0.5)
RESPONSE = SERIALPORT.readlines(None)

LOG = "/home/pi/logs/temphum.txt"
MYFILE = open(LOG, 'a')
print RESPONSE

STIMING = time.time()-60
while True:
    while True:
        RESPONSE = SERIALPORT.readlines(None)
        if len(RESPONSE)>0:
            if RESPONSE[0].startswith('OK'):
                MYFILE.write('%s,%s\n' % (time.time(), RESPONSE[0].strip()))
                MYFILE.flush()
                print '%s,%s' % (time.time(), RESPONSE[0].strip())
                break
    time.sleep(300)
	
	
