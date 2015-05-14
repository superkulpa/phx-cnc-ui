#!/bin/bash
PATH=.:$PATH
runget.py /CNC/backup-logs.sh LOG.tar.gz "Архивация журнала работы" > logs/backup-logs.last
runsave.py "tar -czf ./cnc.logs.tar.gz ./logs ./tmp ./jini" ./cnc.logs.tar.gz "Архивация журнала работы" >> logs/backup-logs.last