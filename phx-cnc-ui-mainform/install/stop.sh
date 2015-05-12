#!/bin/bash
PATH=.:$PATH
rcmd.py "/CNC/stop" > logs/stop.last
