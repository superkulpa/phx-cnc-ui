#!/bin/bash
#./essi2iso $1
DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
echo $DIR
java -classpath $DIR/libs/jcpc.jar:$DIR/libs/commons-logging-1.0.4.jar:$DIR/libs/log4j-1.2.11.jar:$DIR/libs/jdom.jar:$DIR/libs/xml.jar:$DIR/libs/commons-collections-3.2.1.jar:$DIR/libs/commons-net-1.4.1.jar ru.autogenmash.core.utils.compiler.Compiler
#java -cp ./libs ru.autogenmash.core.utils.compiler.Compiler
