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
    res = 0
    child = pexpect.spawnu('ftp ' + cnc_ip)
    child.logfile=sys.stdout
    try:
        child.expect([u'(?i)name .*: '])
        child.sendline('ftp')
        child.expect([u'Password:'])

        child.sendline('ftp')
        child.expect([u'ftp>'])

        child.sendline('cd pub/updates')
        child.expect([u'ftp>'])
         
        child.sendline('binary')
        child.expect([u'ftp>'])
         
        child.sendline(cmd)
        child.expect([u'ftp>'])
        
    except pexpect.TIMEOUT as e:
        print("ftpcmd: time out of operation")
        res = -1
    except pexpect.EOF:
        print("ftpcmd: end of operation")
        res = -2
        
    child.sendline('bye')
    child.close()
    return res

if __name__ == '__main__':
    import os

    CNC_IP=os.getenv("CNC_IP")
    if CNC_IP == None :
        CNC_IP = u"192.168.0.125"
    
	ftpcmd = sys.argv[1]
	remoteFile = sys.argv[2]
	if len(sys.argv)>2:
		localFile = sys.argv[3]
	else:
		localFile = remoteFile

    ftp_cmd = u"" + ftpcmd + " " + remoteFile + " " + localFile
    res = main(CNC_IP, ftp_cmd)
    sys.exit(res)