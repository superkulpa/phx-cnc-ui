#!/bin/bash
#CNC_DIR=`pwd`
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
#cd $DIR/libs
#java -Djava.library.path=$DIR/libs -classpath BaseClasses.jar:BaseMacros.jar:AdditionalMacros.jar:swt-gtk-3.7.2.jar ru.autogenmash.macros.cometmacros.MacrosLauncher 2> $CNC_DIR/logs/macro.log
$DIR/libs/macro/macro.sh > logs/macro.log