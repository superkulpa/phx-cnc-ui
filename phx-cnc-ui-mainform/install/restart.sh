echo "Restart the CNC Kernel"
. rcmd.sh "slay -f15 phxStarter; /CNC/start > /CNC/logs/last_start &"