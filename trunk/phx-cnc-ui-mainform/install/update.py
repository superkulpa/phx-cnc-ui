#!/usr/bin/env python
# -*- coding: utf-8 -*-
from PyQt4 import QtGui
from PyQt4 import QtCore
from PyQt4.QtCore import pyqtSlot,pyqtSignal
from PyQt4.QtCore import QString
import sys
import os
import time

import rcmd
import ftpcmd
from PyQt4.Qt import QFileDialog
# import pexpect

CNC_IP=os.getenv("CNC_IP")
if CNC_IP == None :
    CNC_IP = u"192.168.0.125"
   
print("select&put:" + CNC_IP)

class CDlgBar(QtGui.QDialog):
    value = 0  
    nextStep = pyqtSignal(int)
    def __init__(self):
        super(CDlgBar, self).__init__()
#         print("ctor")
        self.setModal(True)
        
        
        self.progressBar = QtGui.QProgressBar(self)
#         
# #         self.nextStep.connect(self.increaseValue, QtCore.Qt.QueuedConnection)
#         self.buttonBox = QtGui.QDialogButtonBox(self)
#         self.buttonBox.setGeometry(QtCore.QRect(150, 250, 341, 32))
#         self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
#         self.buttonBox.setStandardButtons(QtGui.QDialogButtonBox.Cancel)
#         self.buttonBox.setObjectName("buttonBox")
        self.progressBar.resize(450, 150);
        self.resize(450,150)
        
        layout = QtGui.QVBoxLayout()
#        layout.addStretch(1)
        layout.addWidget(self.progressBar)
#         layout.addWidget(self.buttonBox, 1)
        self.setLayout(layout)
 
        
        self.show()
        self.nextStep.connect(app.closeAllWindows)
        self.emitStep(self.stepSelect)
    
    def emitStep(self, stepFunc, phase = 0):
        self.nextStep.disconnect()
        self.nextStep.connect(stepFunc, QtCore.Qt.QueuedConnection)#stub
        self.nextStep.emit(phase)
       
    archiveName = "" 
    @pyqtSlot(int)
    def stepSelect(self, phase = 0):
        if phase == 0:
            self.setWindowTitle(QString(u'Выбрать архив'))
            self.progressBar.setValue(30)
            self.emitStep(self.stepSelect, 1)
            return
        
#         print("archive")
        self.archiveName = QFileDialog.getOpenFileName(None, u"Выберите архив",
                                                    u"cps/updates",
                                                    'CNC.upd.tar.gz')
        if(self.archiveName == ""):
            print("archiveName is null, exit")
            app.closeAllWindows()
            
        print("open " + self.archiveName)
#         time.sleep(5)
        self.emitStep(self.stepUpload)
        
    @pyqtSlot(int)
    def stepUpload(self, phase = 0):
        if phase == 0:
            self.setWindowTitle(QString(u'Выгрузка файла'))
            self.progressBar.setValue(60)
            self.emitStep(self.stepUpload, 1)
            return
        
#         print("download")
        finfo = QtCore.QFileInfo(self.archiveName)
        print(finfo)
        ftpcmd.main(CNC_IP,
        'put ' + str((self.archiveName + ' CNC.upd.tar.gz').toUtf8()))
        
#         time.sleep(5)
        self.emitStep(self.stepReboot)

    @pyqtSlot(int)
    def stepReboot(self, phase = 0):
        if phase == 0:
            self.setWindowTitle(QString(u'Перезагрузка контроллера'))
            self.progressBar.setValue(90)
            self.emitStep(self.stepReboot, 1)
            return
        
#         print("exit")
        rcmd.main(CNC_IP, 'cust', 'cust', "reboot.sh")
        time.sleep(10)
        app.closeAllWindows()


app      = QtGui.QApplication(sys.argv)
progressBar     = CDlgBar()

 
sys.exit(app.exec_())
