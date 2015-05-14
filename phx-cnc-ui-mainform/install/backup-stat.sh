#!/bin/bash
PATH=.:$PATH
runget.py /CNC/backup-stat.sh LOG.stat.tar.gz "Архивация статистики работы" > logs/backup-stat.last
runsave.py "tar -czf ./cnc.stat.tar.gz ./logs/LOG.stat.tar.gz ./jini" ./cnc.stat.tar.gz "Архивация статистики работы" >> logs/backup-stat.last