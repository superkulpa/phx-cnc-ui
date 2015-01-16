#!/bin/sh
python ./rcmd.py "/CNC/shutdown.sh" > ./logs/shutdown.last
lxsession-logout -p "Завершение работы"