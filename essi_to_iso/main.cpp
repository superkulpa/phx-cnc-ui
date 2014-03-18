#include <QtCore/QCoreApplication>
#include <QtCore/QFile>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QDebug>

bool IsG00_active = 0;
bool IsBracked = 0;
QString SetGeoCommand(QString _isoStr){
    //позиция в строке
    int pos = 0;
    //Id колонки параметра
    char cur_operator = 'X';
    //буффер параметра
    QString arg_str =  _isoStr.at(pos);
    QString res = "";
    pos++;

    while(pos < _isoStr.size()){
        if((_isoStr[pos] == '+')||(_isoStr[pos] == '-')){
            if(arg_str.size() > 1)
                res = res + cur_operator + arg_str;
            arg_str =  _isoStr[pos];
            switch(cur_operator){
                case 'X':{
                    //Х кончился дальше Y
                    cur_operator = 'Y';
                };
                break;
                case 'Y':{
                    //Y кончился дальше I
                    cur_operator = 'I';
                };
                break;
                case 'I':{
                    //I кончился дальше J
                    cur_operator = 'J';
                };
                break;
                case 'J':{
                    //J кончился дальше признак по/против часовой
                    if(_isoStr[pos] == '+') res = "G03" + res;
                    else res = "G02" + res;
                    return res;
                };
            };
            pos++;
            continue;
        };

        if((pos == (_isoStr.size() - 1)) && (cur_operator == 'Y')){
            //завершаем линию
            if(arg_str.size() > 1)
              res = res + cur_operator + arg_str;
            //если до этого вкл быстрый ход
            if(IsG00_active)  res = "G00" + res;
            else  res = "G01" + res;
        };
        arg_str = arg_str + _isoStr.at(pos);
        pos++;
    };
    return res;
}

//выбираем T значения из строки
QString SetTCommandValue(QString _isoStr, int _pos){
    int TValue = 0;
    QString res = "";
    while(_pos < _isoStr.size()){
        //считываем значение формата +nnn, n - номер суппорта
        //if(IsEssiOperator(_string[_pos])){
        QString nSupp = _isoStr.at(_pos);
        int mask = nSupp.toInt();
        if(mask != 0)
            TValue |= (1 << (mask - 1));
        _pos++;
        //}else return "";
    };
    if(TValue > 0) res =  "T" + QString(TValue);
    return res;
};

QString SetDCommandValue(QString _isoStr, int _pos){
//    while(_pos < _isoStr.size()){
//        //считываем значение формата +nnn
//        //if(IsEssiOperator(_string[_pos])){
//        tmp_char[arg_pos++] = _string[_pos];
//        tmp_char[arg_pos] = '\0';
//        _pos++;
//        //}else return -1;
//    };
//    set(tmp_char,OPERATOR_D);
    return "D" + _isoStr.mid(_pos);
};

QString SetEkvCommandValue(QString _isoStr){
    QString res = "";
    switch(_isoStr.at(0).toAscii()){
        case '2':
            //29->G41
            res = "G41";
        return res;
        case '3':
        switch(_isoStr.at(1).toAscii()){
                case '0':
                    //30->G42
                    res = "G42";
                return res;
                case '8':
                    //38->G40
                    res = "G40";
                return res;
                default:return "";
            };
        break;
        case '4':
            if(_isoStr.at(1).toAscii() == '0'){
                    //40+nnn->D+nnn
                    res = SetDCommandValue(_isoStr,3);
            }else return "";
        return res;
        default:return "";
    };
    return res;
};

QString SetFeedCommandValue(QString _isoStr, int _pos){
    QString res = "";
    /*
    int arg_pos = 0;
    //считать значение
    while(_pos < _sizeof_str){
        if(IsEssiOperator(_string[_pos])){
            tmp_char[arg_pos++] = _string[_pos];
            tmp_char[arg_pos] = '\0';
            _pos++;
        }else return -1;
    };
    set(tmp_char,OPERATOR_F);*/
    return "F" + _isoStr.mid(_pos);
};

//создание команд пробивки с T командами
QString SetMCommandValue(QString _isoStr){
    //позиция в строке
    int pos = 0;
    QString res;
    switch(_isoStr.at(pos).toAscii()){
        case '0':
            //0->M00
            res = "M00";
        return res;
        case '1':
            switch(_isoStr.at(1).toAscii()){
                case '7':
                    //17->M72
                    res = "M72";
                    res = res + SetTCommandValue(_isoStr,3);
                return res;
                case '8':
                    //18->m73
                    res = "M73";
                    res = res + SetTCommandValue(_isoStr, 3);
                return res;
                case '9':
                  //19->m19
                  res = "M19";
                  res = res + SetTCommandValue(_isoStr,3);
                return res;
                default: return "";
            };
        break;
        case '2':
            //2->M02
            res = "M02";
        return res;
        case '4':
            switch(_isoStr.at(1).toAscii()){
                case '3':
                    //43->M74
                    res = "M74";
                    res = res + SetTCommandValue(_isoStr,3);
                return res;
                case '9':
                    //49->M70
                    res = "M70";
                    res = res + SetTCommandValue(_isoStr,3);
                return res;
            default: return "";
            };
        break;
        case '5':
            switch(_isoStr.at(1).toAscii()){
                case '3':
                    //53->M82
                    res = "M82";
                    res = res + SetTCommandValue(_isoStr,3);
                return res;
                case '4':
                    //54->M83
                    res = "M83";
                    res = res + SetTCommandValue(_isoStr,3);
                return res;
                case '5':
                    //55->M81
                    res = "M81";
                    res = res + SetTCommandValue(_isoStr,3);
                return res;
                default: return "";
            };
        break;
        case '6':
            switch(_isoStr.at(1).toAscii()){
                case '3':
                    //63->M02
                    res = "M02";
                return res;
                case '4':
                    //64->M17
                    res = "17";
                return res;
                default: return "";
            };
        break;
        case '7':
            //7->M71
            res = "M81";
            res = res + SetTCommandValue(_isoStr,3);
        return res;
        case '8':
            //8->M75
            res = "M83";
            res = res + SetTCommandValue(_isoStr,3);
        break;
    };
    return res;
};

QString Set2CommandValue(QString _isoStr){
    QString res = "";
    switch(_isoStr.at(1).toAscii()){
        case '\0':
        case '\n':
            //2->M02
            if(!IsBracked) res = SetMCommandValue(_isoStr);
        return res;
        case '9':
            //29->G41
            if(!IsBracked) res =  SetEkvCommandValue(_isoStr);
        break;
        default: return "";
    };
    return res;
};


QString Set3CommandValue(QString _isoStr){
    QString res = "";
    switch(_isoStr.at(1).toAscii()){
        case '\0':
        case '\n':
            //3->(
            IsBracked = true;
        break;
        case '0':
        case '8':
            //30->G42,38->G40
            res = SetEkvCommandValue(_isoStr);
        return res;
        case '9':{
            //39+nnn->F+nnn
            res = SetFeedCommandValue(_isoStr,3);
        };
        return res;
        default: return "";
    };
    return res;
};

QString Set4CommandValue(QString _isoStr){
    QString res = "";
    switch(_isoStr.at(1).toAscii()){
        case '\0':
        case '\n':
            //4->)
            IsBracked = false;
        break;
        case '0':
            //40+nnn->D+nnn
            if(!IsBracked) res = SetEkvCommandValue(_isoStr);
        return res;
        case '3':
        case '9':{
            //43->M74,49->M70
            if(!IsBracked) res = SetMCommandValue(_isoStr);
        };
        return res;
        default: return "";
    };
    return res;
};

QString Set5CommandValue(QString _isoStr){
    QString res = "";
    switch(_isoStr.at(1).toAscii()){
        case '\0':
        case '\n':
            //5->G00
          IsG00_active = true;
        break;
        case '3':
        case '4':
        case '5':
            //53->M82,54->M83,55->M81
            if(!IsBracked) res = SetMCommandValue(_isoStr);
        return res;
        default: return "";
    };
    return res;
};

QString Set6CommandValue(QString _isoStr){
    QString res = "";
    switch(_isoStr.at(1).toAscii()){
        case '\0':
        case '\n':
            //6->G00(off)
          IsG00_active = false;
        break;
        case '3':
        case '4':
            //63->M02,64->M17
            if(!IsBracked) res = SetMCommandValue(_isoStr);
        break;
        default: return "";
    };
    return res;
};

QString Set8CommandValue(QString _isoStr){
    QString res = "";
    switch(_isoStr.at(1).toAscii()){
        case '\0':
        case '\n':
            //8->M75
          if(!IsBracked) res = SetMCommandValue(_isoStr);
        return res;
        case '1':
            //81->G91
            if(!IsBracked) res = "G91";
        return res;
        case '2':
            //82->G90
            if(!IsBracked) res = "G90";
        break;
        default: return "";
    };
    return res;
};


QString ConverEssiToISO(QString _isoStr){
    QString res = "";
    switch(_isoStr.at(0).toAscii()){
        case '+':
        case '-':
             if(!IsBracked)res = SetGeoCommand(_isoStr);
        break;
        case '0':
        case '1':
            if(!IsBracked) res = SetMCommandValue(_isoStr);
        break;
        case '2':
            if(!IsBracked) res = Set2CommandValue(_isoStr);
        break;
        case '3':
            if(!IsBracked) res = Set3CommandValue(_isoStr);
        break;
        case '4':
            res = Set4CommandValue(_isoStr);
        break;
        case '5':
            if(!IsBracked) res = Set5CommandValue(_isoStr);
        break;
        case '6':
            if(!IsBracked) res = Set6CommandValue(_isoStr);
        break;
        case '7':
            if(!IsBracked) res = SetMCommandValue(_isoStr);
        break;
        case '8':
            if(!IsBracked) res = SetMCommandValue(_isoStr);
        break;
    };
    return res;
};

bool IsEssiOperator(QString _str){
  switch(_str.at(0).toAscii()){
    case '+':
    case '-':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '0':
    return true;
  }
  return false;
}

int main(int argc, char *argv[])
{
    QString fileName = argv[1];
    qDebug()<< fileName + "\n";
    QFile file(fileName);
    QByteArray lst;
    if(file.open(QIODevice::ReadOnly |QIODevice::Text))
    {

        while(!file.atEnd())
        {
            //читаем строку
            QString str = file.readLine();
            //Делим строку на слова разделенные пробелом
            if(IsEssiOperator(str))
              str = ConverEssiToISO(str);
            if((str != "") && (!IsBracked)){
                if(str.indexOf("%") != -1) str = "%1";
                if(str.indexOf("\n") == -1)str += "\n";
                lst.append(str);
                //qDebug() << str;
            };

        };

    }
    else
    {
        qDebug()<< "don't open file\n";
    }
    file.close();
    //удаляем пред значения
    file.open(QIODevice::WriteOnly |QIODevice::Text);
    file.write(lst);
    file.close();
    return 0;
}
