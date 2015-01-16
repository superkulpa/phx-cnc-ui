#!/usr/bin/env python
from __future__ import absolute_import
from __future__ import print_function
from __future__ import unicode_literals

import time
import sys
import pexpect

#def ftpget(fname):
def main(cnc_ip, cmd):
    print("ftpcmd:"+cnc_ip, cmd)
    child = pexpect.spawnu('ftp ' + cnc_ip)
    child.logfile=sys.stdout
    child.expect([u'(?i)name .*: '])
    child.sendline('ftp')
    child.expect([u'Password:'])
    child.sendline('ftp')
    time.sleep(3)
    child.expect([u'ftp>'])
    child.sendline('cd pub/updates')
    child.expect([u'ftp>'])
     
    child.sendline('binary')
    child.expect([u'ftp>'])
     
    child.sendline(cmd)
    child.expect([u'ftp>'])
    
    child.sendline('bye')
    child.close()

if __name__ == '__main__':
    import os

    CNC_IP=os.getenv("CNC_IP")
    if CNC_IP == None :
        CNC_IP = u"192.168.0.125"
    
    ftp_cmd = u"" + sys.argv[1] + " " + sys.argv[2]#put/get
    main(CNC_IP, ftp_cmd)