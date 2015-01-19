#!/bin/sh
#cd  /home/cnc/CNC
export PATH=$PATH:.
#LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libs
./dbclient $@
exit $?
