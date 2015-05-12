#!/bin/bash
PATH=.:$PATH
runget.py /CNC/backup-ini.sh ini_CNC.tar.gz "Резервирование параметров" > logs/backup-ini.last