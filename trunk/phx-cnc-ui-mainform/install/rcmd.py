#!/usr/bin/env python
from __future__ import absolute_import
from __future__ import print_function
from __future__ import unicode_literals

import time
import pexpect
import sys
def main(cnc_ip, cnc_login, cnc_pass, cmd):
    print("rcmd:" + cnc_ip, cnc_login, cnc_pass, cmd)
    child = pexpect.spawnu('telnet ' + cnc_ip)
    child.logfile=sys.stdout
    child.expect([u'login: '])
    child.sendline(cnc_login)
    child.expect([u'Password:'])
    child.sendline(cnc_pass)
    time.sleep(3)
    child.expect([u'$'])
    time.sleep(1)
    child.sendline(cmd)
    child.expect([u'$'])
    time.sleep(1)
    child.sendline(u'exit;exit;') # Try to ask ftp child to exit.
    child.close()


if __name__ == '__main__':
    import os
    
    CNC_IP=os.getenv("CNC_IP")
    if CNC_IP == None :
        CNC_IP = u"192.168.0.125"
    
    CNC_LOGIN=os.getenv("CNC_LOGIN")
    if CNC_LOGIN == None :
        CNC_LOGIN = u"cust"
    
    CNC_PASS=os.getenv("CNC_PASS")
    if CNC_PASS == None :
        CNC_PASS = u"cust"
        
    arg = u"" + sys.argv[1]
    main(CNC_IP, CNC_LOGIN, CNC_PASS, arg)   