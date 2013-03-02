#!/usr/bin/env python
""" 
basketPInfo data procesors (rrdtool output)

Rafal Zawadzki <bluszcz@bluszcz.net>
BSD License (license.txt)
"""
import sys

def exit_failure():
    " Nice info on failure "
    print "usage: %s int\n" % sys.argv[0]
    print "int should be 2 (humidity) or 3 (temperature)"
    sys.exit(-1)

if len(sys.argv)!=2:
    exit_failure()

ARG = int(sys.argv[1])

if ARG not in (2, 3):
    exit_failure()

FILENAME = "/home/pi/logs/temphum.txt"
HANDLER = open(FILENAME)

def transpose_data(data):
    " Parses data "
    return [ll.lstrip('\t') for ll in data.strip().split(',')] 

for line in (transpose_data(l) for l in HANDLER.xreadlines()):
    if len(line)>1:
        try:
            print 'rrdtool update temp.rrd %s:%s' % (line[0], line[ARG])
        except KeyError:
            pass
