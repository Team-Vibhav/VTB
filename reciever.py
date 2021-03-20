from _future_ import print_function
from flask import Flask, render_template
import time
from RF24 import *
import RPi.GPIO as GPIO
irq_gpio_pin = None
########### USER CONFIGURATION ###########
radio = RF24(RPI_V2_GPIO_P1_15, BCM2835_SPI_CS0, BCM2835_SPI_SPEED_8MHZ)

def try_read_data(channel=0):
    if radio.available():
        while radio.available():
            len = radio.getDynamicPayloadSize()
            receive_payload = radio.read(len)
            receive_payload.decode('utf-8')))
            # First, stop listening so we can talk
            print(receive_payload)
            #print("Sent the message: {}".format(receive_payload))
            radio.stopListening()
            # Send the final one back.
            radio.write(receive_payload)
            print('Got response.')
            # Now, resume listening so we catch the next packets.
            radio.startListening()
pipes = [0xF0F0F0F0E1, 0xF0F0F0F0D2]
print('pyRF24/examples/pingpair_dyn/')
radio.begin()
radio.setAutoAck(False);
radio.enableDynamicPayloads()
radio.setRetries(5,15)
radio.printDetails()
inp_role = '0'
if inp_role == '0':
    print('Role: Pong Back, awaiting transmission')
    if irq_gpio_pin is not None:
        # set up callback for irq pin
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(irq_gpio_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
        GPIO.add_event_detect(irq_gpio_pin, GPIO.FALLING, callback=try_read_data)
    radio.openWritingPipe(pipes[1])
    radio.openReadingPipe(1,pipes[0])
    radio.startListening()
# forever loop
while 1: 
       # if there is data ready
        if irq_gpio_pin is None:
            # no irq pin is set up -> poll it
            try_read_data()
        else:
            # callback routine set for irq pin takes care for reading -
            # do nothing, just sleeps in order not to burn cpu by looping
            time.sleep(1000)
