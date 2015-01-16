#!/bin/sh
bash ./stop.sh
sleep 5
python ./rcmd.py "/CNC/start &" > ./logs/restart.last