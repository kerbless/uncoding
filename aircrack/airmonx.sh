#!/bin/bash

sudo airmon-ng start wlp2s0
sudo airodump-ng check kill
sudo airodump-ng -t WEP -t WPA -t WPA1 -t WPA2 -a  -w dumpOUT --output-format csv wlp2s0mon
sleep 5s
python 	getapmacs.py

