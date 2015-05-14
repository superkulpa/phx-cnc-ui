#!/bin/bash
PATH=.:$PATH
runget.py /CNC/backup-ini.sh ini_CNC.tar.gz "Резервирование параметров" > logs/backup-ini.last
runsave.py "tar -czf ./cnc.ini.tar.gz ./logs/ini_CNC.tar.gz ./jini" ./cnc.ini.tar.gz "Резервирование параметров" >> logs/backup-ini.last