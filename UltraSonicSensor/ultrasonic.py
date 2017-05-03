#Import GPIO python
import RPi.GPIO as GPIO
import time
#GPIO setmode
GPIO.setmode(GPIO.BOARD)
#Variable Declaration
TRIG = 7
ECHO = 12
#init PINS
GPIO.setup(TRIG,GPIO.OUT)
GPIO.output(TRIG,0)
GPIO.setup(ECHO,GPIO.IN)
#sleep for 0.1 Sec
time.sleep(0.1)

print "Starting Measurement...."

GPIO.output(TRIG,1)
#wait for 10ns
time.sleep(0.00001)
GPIO.output(TRIG,0)
while GPIO.input(ECHO)==0:
    pass
start =time.time()
while GPIO.input(ECHO)==1:
    pass
stop = time.time()
d=(stop-start) *17000
print d
GPIO.cleanup()
