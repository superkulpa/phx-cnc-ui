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
   
runScript = sys.argv[1]#'/CNC/backup-logs.sh; '
getFile = sys.argv[2]# LOG.tar.gz
 
print("run&get:" + CNC_IP, runScript, getFile)

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
        self.emitStep(self.stepArchive)
    
    def emitStep(self, stepFunc, phase = 0):
        self.nextStep.disconnect()
        self.nextStep.connect(stepFunc, QtCore.Qt.QueuedConnection)#stub
        self.nextStep.emit(phase)
        
    @pyqtSlot(int)
    def stepArchive(self, phase = 0):
        if phase == 0:
            self.setWindowTitle(QString(u'Архивация'))
            self.progressBar.setValue(30)
            self.emitStep(self.stepArchive, 1)
            return
        
#         print("archive")
        rcmd.main(CNC_IP, 'cust', 'cust', runScript)
#         time.sleep(5)
        self.emitStep(self.stepDownload)
        
    @pyqtSlot(int)
    def stepDownload(self, phase = 0):
        if phase == 0:
            self.setWindowTitle(QString(u'Копирование файла'))
            self.progressBar.setValue(60)
            self.emitStep(self.stepDownload, 1)
            return
        
#         print("download")
        ftpcmd.main(CNC_IP, 'get ' + getFile)
#         time.sleep(5)
        self.emitStep(self.stepSaveAs)
    
    @pyqtSlot(int)
    def stepSaveAs(self, phase = 0):
        if phase == 0:
            self.setWindowTitle(QString(u'Сохранение файла'))
            self.progressBar.setValue(90)
            self.emitStep(self.stepSaveAs, 1)
            return
        
        saveCat = QFileDialog.getExistingDirectory(None, u"Сохранить в каталог",
                                                    u"./logs",
                                                    QFileDialog.ShowDirsOnly
                                                  | QFileDialog.DontResolveSymlinks);
        print("save to " + saveCat)
        QtCore.QFile.remove( saveCat+'/' + getFile)
        if False == QtCore.QFile.copy(getFile, saveCat+'/' + getFile):
            print("error");
#         print("exit")
#         time.sleep(5)
        app.closeAllWindows()


app      = QtGui.QApplication(sys.argv)
progressBar     = CDlgBar()

 
sys.exit(app.exec_())
