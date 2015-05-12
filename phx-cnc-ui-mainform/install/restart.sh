#!/bin/bash
PATH=.:$PATH
stop.sh
sleep 5
rcmd.py "/CNC/start &" > logs/restart.last