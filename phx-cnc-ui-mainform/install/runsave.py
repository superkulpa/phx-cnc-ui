#!/usr/bin/env python
# -*- coding: utf-8 -*-
from PyQt4 import QtGui
from PyQt4 import QtCore
from PyQt4.QtCore import pyqtSlot,pyqtSignal
from PyQt4.QtCore import QString
import sys
import os
import time
from subprocess import call
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

		self.progressBar.resize(450, 150);
		self.resize(450,150)
		
		layout = QtGui.QVBoxLayout()
#        layout.addStretch(1)
		layout.addWidget(self.mainLabel)
		layout.addWidget(self.progressBar)
		layout.addWidget(self.closeButton)

		self.setLayout(layout)
	 
		self.show()
		self.nextStep.connect(app.closeAllWindows)
		self.emitStep(self.stepRun)
	
	def emitStep(self, stepFunc, phase = 0):
		self.nextStep.disconnect()
		self.nextStep.connect(stepFunc, QtCore.Qt.QueuedConnection)#stub
		self.nextStep.emit(phase)
			
	@pyqtSlot(int)
	def stepRun(self, phase = 0):
		if phase == 0:
			self.setWindowTitle(QString(u'Архивация'))
			self.progressBar.setValue(30)
			self.emitStep(self.stepRun, 1)
			return
			
			#print("archive", runScript)  "'"+runScript+"'"
		if( 0 == call((runScript.split()))):
			self.emitStep(self.stepSaveAs)
		else:
			self.setWindowTitle(QString(u'Ошибка архивации'))
			
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
		QtCore.QFile.remove( getFile)
			 
		app.closeAllWindows()


app      = QtGui.QApplication(sys.argv)
progressBar     = CDlgBar()

sys.exit(app.exec_())
