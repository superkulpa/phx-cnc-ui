# @echo off
# echo updating software...
# javaw -classpath "updater.jar;form.jar;swt.jar;JavaKernel.jar;commons-net-1.4.1.jar;commons-logging-1.0.4.jar;log4j-1.2.11.jar" ru.autogenmash.softupdate.SoftwareUpdater -u
#:start
echo starting form...
java -classpath "form.jar;cuttingconsoles.jar;longeronCompiler.jar;swt.jar;velocity-dep-1.4.jar;draw2d.jar;pg72jdbc2.jar;core.commands.jar;core.runtime.jar;equinox.common.jar;jface.jar;jface.text.jar;osgi.jar;text.jar;JavaKernel.jar;crimson.jar;jdom.jar;commons-net-1.4.1.jar;commons-logging-1.0.4.jar;log4j-1.2.11.jar;ini4j-0.3.2.jar;commons-collections-3.2.1.jar" ru.autogenmash.gui.Starter root
#goto start
