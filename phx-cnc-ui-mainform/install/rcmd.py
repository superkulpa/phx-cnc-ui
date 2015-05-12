#!/usr/bin/env python
from __future__ import absolute_import
from __future__ import print_function
from __future__ import unicode_literals

import time
import pexpect
import sys
def main(cnc_ip, cnc_login, cnc_pass, cmd):
    res = 0
    print("rcmd:" + cnc_ip, cnc_login, cnc_pass, cmd)
    child = pexpect.spawnu('telnet ' + cnc_ip)
    child.logfile=sys.stdout
#    child.logfile_read = sys.stdout
#    child.logfile_send = sys.stdout
    try:
        child.expect([u'login: '])
        child.sendline(cnc_login)
        child.expect([u'Password:'])
        child.sendline(cnc_pass)
        child.expect(['\$'])
        child.sendline(cmd)
        
        while True:
            index = child.expect(['\$', '/'])
            if index == 0:
                break;

    except pexpect.TIMEOUT as e:
        print("rcmd: time out of operation")
        res = -1
    except pexpect.EOF:
        print("rcmd: end of operation")
        res = -2
        
    child.sendline(u'exit;exit;') # Try to ask ftp child to exit.
    child.close()
    return res
#########################################################3
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
    res = main(CNC_IP, CNC_LOGIN, CNC_PASS, arg)
    sys.exit(res)   