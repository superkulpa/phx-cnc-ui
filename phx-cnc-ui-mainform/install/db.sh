#!/bin/bash
#cd  /home/cnc/CNC
export PATH=$PATH:.
#LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libs
phx-dbclient $@ > logs/dbclient.log
exit $?
