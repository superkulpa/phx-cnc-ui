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
mainLabelText = sys.argv[3].decode("utf-8");
 
print("run&get:" + CNC_IP, runScript, getFile)

class CDlgBar(QtGui.QDialog):
    value = 0  
    nextStep = pyqtSignal(int)
    def __init__(self):
        super(CDlgBar, self).__init__()
#         print("ctor")
        self.setModal(True)
        
        
        self.progressBar = QtGui.QProgressBar(self)
        self.mainLabel = QtGui.QLabel(self)
        self.mainLabel.setText(QString(mainLabelText))
        
        self.closeButton = QtGui.QPushButton(self)
        self.closeButton.setText(u"Прервать и закрыть")
        self.closeButton.clicked.connect(app.closeAllWindows)
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
        layout.addWidget(self.mainLabel)
        layout.addWidget(self.progressBar)
        layout.addWidget(self.closeButton)

#         layout.addWidget(self.buttonBox, 1)
        self.setLayout(layout)
 
        
        self.show()
        self.nextStep.connect(app.closeAllWindows)
        self.emitStep(self.stepRunRemote)
    
    def emitStep(self, stepFunc, phase = 0):
        self.nextStep.disconnect()
        self.nextStep.connect(stepFunc, QtCore.Qt.QueuedConnection)#stub
        self.nextStep.emit(phase)
        
    @pyqtSlot(int)
    def stepRunRemote(self, phase = 0):
        if phase == 0:
            self.setWindowTitle(QString(u'Архивация'))
            self.progressBar.setValue(30)
            self.emitStep(self.stepRunRemote, 1)
            return
        
#         print("archive")
        if( 0 == rcmd.main(CNC_IP, 'cust', 'cust', runScript)):
            self.emitStep(self.stepDownload)
        else:
            self.setWindowTitle(QString(u'Ошибка архивации'))
        
    @pyqtSlot(int)
    def stepDownload(self, phase = 0):
        if phase == 0:
            self.setWindowTitle(QString(u'Выгрузка'))
            self.progressBar.setValue(60)
            self.emitStep(self.stepDownload, 1)
            return
        
#         print("download")
        if( 0 == ftpcmd.main(CNC_IP, 'get ' + getFile + " ./logs/"+getFile)):
            self.emitStep(self.stepFinish)
        else:
            self.setWindowTitle(QString(u'Ошибка при выгрузке'))
    
    @pyqtSlot(int)
    def stepFinish(self, phase = 0):
		self.setWindowTitle(QString(u'Сохранение файла'))
		self.progressBar.setValue(100)
		app.closeAllWindows()
		return
       
 

app      = QtGui.QApplication(sys.argv)
progressBar     = CDlgBar()

sys.exit(app.exec_())
