#!/bin/bash
PATH=.:$PATH
runget.py /CNC/backup-logs.sh LOG.tar.gz "Архивация журнала работы" > logs/backup-logs.last