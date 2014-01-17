/*
 * CXMLReader.cpp
 *
 *  Created on: 20.03.2011
 *      Author: tsvet
 */
#include <QTextStream>
#include <stdio.h>

#include "CXMLReader.h"

#define MAX_CHILDS_COUNT 5

CXMLReader::CXMLReader(QString _path){
  path = _path.toStdString();
  QFile file(QString::fromStdString(path));
   if (!file.open(QIODevice::ReadOnly))
       return;
   if (!doc.setContent(&file)) {
       file.close();
       return;
   }
   file.close();
};

void CXMLReader::setPath(const string& _path){
  path = _path;
  QFile file(QString::fromStdString(path));
  if (!file.open(QIODevice::ReadOnly))
      return;
  if (!doc.setContent(&file)) {
      file.close();
      return;
  }
  file.close();
};

//разбить строку, выбрать подстроку до символа /
string CXMLReader::GetName(string& _path){
  string name = "";
  //проверяем на не пустой путь
  if(_path.size() < 1) return (name = "-1");
  int k = _path.find("/");
  if (k == (int)_path.npos){
    //вме элементы выбрали это последний
    name = _path;
    _path = "";
  }else name = _path.substr(0, k);
  //удаляем выбранный элемент
  _path.replace(0, k + 1, "");\
  return name;
};

//Получить значение элемента
QDomElement CXMLReader::Get(const char* _elementPath){
  string path = _elementPath;
  string nextName = GetName(path);
  QDomElement elem = doc.documentElement().toElement();
  while(!elem.isNull()){
    //смотрим совпали ли имена
    if(elem.tagName() != QString::fromStdString(nextName)){
        while(!(elem = elem.nextSibling().toElement()).isNull()){
          //нашли тогда выходим
          if(elem.tagName() == QString::fromStdString(nextName))  break;
        };
      //не нашли
      if(elem.isNull()) return elem;
    }else{
      //ищем следующее имя
      nextName = GetName(path);
      if(elem.tagName() == "parameter"){
        while(!elem.isNull()){
          if(elem.attribute("name") == QString::fromStdString(nextName))  break;
          elem = elem.nextSibling().toElement();
        };
        return elem;
      };

      //путь кончился возвращаем элемент
      if(nextName == "-1") break;
      //берем следующий элемент
      elem = elem.firstChild().toElement();
    };
  };
  return elem;
};
//получить значение атрибута у заданного элемента
QString CXMLReader::GetAttribute(const char* _elementPath, const char* _attributeName, const char* _defValue){
  //ищем элемент
  QString str = QString::fromUtf8(_defValue);
  QDomElement elem = Get(_elementPath);
  if(elem.isNull()){
    printf("Cannot find element: %s attribute, initialized default value\n",_elementPath);
    return str;
  };
  //ищем атрибут
  QString value = elem.attribute(_attributeName);
  if(value == ""){
    printf("Initialized default attribute value element: %s attribute name: %s\n",_elementPath,_attributeName);
    return str;
  };
  return value;
};

//Получить значение элемента
string CXMLReader::GetValue(const char* _elementPath, const char* _defValue){
    return GetAttribute(_elementPath, "value", _defValue).toStdString();
};

//Получить int-значение элемента
int CXMLReader::GetValueI(const char* _elementPath, int _defValue){
  char svalue[0x100];
  sprintf( svalue, "%d", _defValue);
  return atoi(GetValue(_elementPath, svalue).c_str());
};

//Получить double-значение элемента
double CXMLReader::GetValueF(const char* _elementPath, double _defValue){
  char svalue[0x100];
  sprintf( svalue, "%f", _defValue);
  return atof(GetValue(_elementPath, svalue).c_str());
};

//задать значение атрибута у заданного элемента
bool CXMLReader::SetAttribute(const char* _elementPath, const char* _attributeName, const QString &_attributeValue){
  //ищем элемент
  QDomElement elem =(QDomElement)Get(_elementPath);
  if(elem.isNull()){
    printf("Cannot find element: %s attribute, cannot write value\n",_elementPath);
    return false;
  };
  //записываем значение атрибута
  elem.setAttribute(_attributeName,_attributeValue);
  WriteFile(path);
  return true;
};

//задать значение атрибута value у заданного элемента
bool CXMLReader::SetValue(const char* _elementPath, const char* _attributeValue){
  return SetAttribute(_elementPath,"value",_attributeValue);
};

//задать значение атрибута value у заданного элемента
bool CXMLReader::SetValueI(const char* _elementPath, int _attributeValue){
  char svalue[0x100];
  sprintf( svalue, "%d", _attributeValue);
  return SetValue(_elementPath,svalue);
};

//задать значение атрибута value у заданного элемента
bool CXMLReader::SetValueF(const char* _elementPath, double& _attributeValue){
  char svalue[0x100];
  sprintf( svalue, "%f", _attributeValue);
  return SetValue(_elementPath,svalue);
};

QDomNode CXMLReader::FindElement(const QString &_number){
  QDomElement dElem = doc.documentElement().firstChild().toElement();
  while(!dElem.isNull()){
    if(dElem.attribute("number", "no_number") == _number){
      return dElem;
    };
    dElem = dElem.nextSibling().toElement();
  }
  return dElem;
};

void CXMLReader::addElement( const char* _number, const char* _source, const char* _fileName){
  QDomNode new_element = doc.createElement("Message");

  QDomAttr sourceAttr = doc.createAttribute("source");
  sourceAttr.setValue(QString::fromStdString(_source));

  new_element.attributes().setNamedItem(sourceAttr);

  QDomAttr fileNameAttr = doc.createAttribute("path");
  fileNameAttr.setValue(QString::fromStdString(_fileName));

  new_element.attributes().setNamedItem(fileNameAttr);

  QDomNode destElem;
  QString number = QString::fromStdString(_number);

  if(!(destElem = FindElement(number)).isNull()){
    //
    if(destElem.childNodes().size() >= MAX_CHILDS_COUNT){
      DeleteFirstElement(number);
    }
    destElem.appendChild(new_element);
  }else{
    QDomNode new_abonent = doc.createElement("Abonent");
    QDomAttr numAttr = doc.createAttribute("number");
    numAttr.setValue(number);
    new_abonent.attributes().setNamedItem(numAttr);
    new_abonent.appendChild(new_element);
    doc.appendChild(new_abonent);
  };

  WriteFile(path);
};

void CXMLReader::DeleteFirstElement(QString &_number){
  QDomElement dElem = doc.documentElement();
  QDomNode destElem;
  if((destElem = FindElement(_number)).isNull()) return;
  destElem.firstChild() = destElem.removeChild(destElem.firstChild());
  WriteFile(path);
};

string CXMLReader::getSource(){
  QDomElement dElem = doc.documentElement();
  if(dElem.firstChild().toElement().tagName() != "Message")
    printf("%s, tag = %s\n","invalid format file",dElem.tagName().toStdString().c_str());
  return dElem.firstChild().toElement().attribute("source","no_source").toStdString();
};

string CXMLReader::getFileName(){
  QDomElement dElem = doc.documentElement();
  if(dElem.firstChild().toElement().tagName() != "Message")
    printf("%s, tag = %s\n","invalid format file",dElem.tagName().toStdString().c_str());
  return dElem.firstChild().toElement().attribute("path","no_path").toStdString();
};

int CXMLReader::GetAbonents(QString* &_numbers, QString* &_names,int* &_checks/*, QString* &_sizes*/){
  QDomElement dElem = doc.documentElement();
  int count = dElem.childNodes().size();
  _numbers = new QString[count]; _names = new QString[count]; _checks = new int[count]; //_sizes = new QString[count];
  QDomNode first = dElem.firstChild();
  for(int i = 0; i < count; i++){
    _numbers[i] = first.toElement().attribute("number","no_number");
    _names[i] = first.toElement().attribute("name","no_name");
    _checks[i] = first.toElement().attribute("mail","no_mail").toInt();
    //_sizes[i] = first.toElement().attribute("buffer","no_buffer");
    first = first.nextSibling();
  };
  return count;
};

QDomElement CXMLReader::GetElement(QDomElement _parent, int _nElem){
  if(_nElem > (_parent.childNodes().size() - 1)) return _parent.firstChild().toElement();
  return _parent.childNodes().item(_nElem).toElement();
};

int CXMLReader::GetParams(int _nSect, QString* &_names, QString* &_values){
  QDomElement dElem = GetElement(doc.documentElement().toElement(), _nSect);
  int count = dElem.childNodes().size();
  _names = new QString[count]; _values = new QString[count];
  QDomNode first = dElem.firstChild();
  int countVisible = 0;
  for(int i = 0; i < count; i++){
    if(first.toElement().attribute("visible","0").toInt()){
      _names[countVisible] = first.toElement().attribute("descr","no_descr");
      _values[countVisible++] = first.toElement().attribute("value","no_value");
    };
    first = first.nextSibling();
  };
  return countVisible;
};

int CXMLReader::GetCountElement(const QString &_sectionName){
  QDomElement dElem = doc.documentElement();
  int count = dElem.childNodes().size();
  QDomNode first = dElem.firstChild();
  for(int i = 0; i < count; i++){
    if(first.toElement().tagName() == _sectionName){
      return first.childNodes().size();
    }else
      first = first.nextSibling();
  }
  return 0;
};

int CXMLReader::GetSections(QString* &_sections){
  QDomElement dElem = doc.documentElement();
  int count = dElem.childNodes().size();
  _sections = new QString[count];
  QDomNode first = dElem.firstChild();
  for(int i = 0; i < count; i++){
    _sections[i] = first.toElement().attribute("descr","no_descr");
    first = first.nextSibling();
  };
  return count;
};

int CXMLReader::SetMail(QString &_number, bool _on){
  QDomNode abonent = FindElement(_number);
  if(abonent.isNull()) return -1;
  abonent.toElement().setAttribute("mail",_on ? "1":"0");
  WriteFile(path);
  return 0;
};

int CXMLReader::SetDescrAbonent(QString &_number, const QString &_descr){
  QDomNode abonent = FindElement(_number);
  if(abonent.isNull()) return -1;
  abonent.toElement().setAttribute("name",_descr);
  WriteFile(path);
  return 0;
};

int CXMLReader::SetValue(int _indxSect, int _indxParam, QString& _value){
  QDomElement dElem = doc.documentElement();

  if(_indxSect > dElem.childNodes().size()) return -1;
  dElem = dElem.childNodes().item(_indxSect).toElement();
  printf("%s",dElem.text().toStdString().c_str());

  QDomElement paramElem = dElem.firstChild().toElement();

  for(int i = 0; i < dElem.childNodes().size(); i++){
    if(paramElem.attribute("visible","0").toInt()){
      _indxParam--;
    };
    if(_indxParam < 0) {
      paramElem.setAttribute("value", _value);
      break;
    }
    paramElem = paramElem.nextSibling().toElement();
  };

  WriteFile(path);

  return 0;
};

void CXMLReader::RemoveAbonent(const QString &_number){
  QDomNode abonent = FindElement(_number);
  if(abonent.isNull()) return;
  abonent = doc.documentElement().removeChild(abonent);
  WriteFile(path);
  return;
};

int CXMLReader::WriteFile(const string&  _path){
  QFile file(QString::fromUtf8(_path.c_str()));
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return -1;

  QTextStream out(&file);
  doc.save(out, 2);
  file.close();
  return 0;
};

void CXMLReader::CreateNewAbonent(QString &_path, QString &_number, const QString &_descr){
  QDomDocument newDoc;

  QDomNode xmlNode = newDoc.createProcessingInstruction("xml",
                            "version='1.0'");
  newDoc.insertBefore(xmlNode, newDoc.firstChild());


  QDomElement root = newDoc.createElement("Base");
  QDomAttr sourceAttr = newDoc.createAttribute("name");
  sourceAttr.setValue(QString::fromUtf8("Mail"));

  root.attributes().setNamedItem(sourceAttr);

  QDomNode new_element = newDoc.createElement("Abonent");

  sourceAttr = newDoc.createAttribute("number");
  sourceAttr.setValue(_number);

  new_element.attributes().setNamedItem(sourceAttr);

  sourceAttr = newDoc.createAttribute("name");
  sourceAttr.setValue(_descr);

  new_element.attributes().setNamedItem(sourceAttr);



  newDoc.appendChild(root);

  root.appendChild(new_element);

  QFile file(_path);
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return;

  QTextStream out(&file);
  newDoc.save(out, 2);
  file.close();
};

void CXMLReader::SetAbonentInfo(const QString &_number, const QString& _descr, bool _checkState){
  QDomNode new_element = doc.createElement("Abonent");

  QDomAttr sourceAttr = doc.createAttribute("number");
  sourceAttr.setValue(_number);
  new_element.attributes().setNamedItem(sourceAttr);

  sourceAttr = doc.createAttribute("name");
  sourceAttr.setValue(_descr);
  new_element.attributes().setNamedItem(sourceAttr);

  sourceAttr = doc.createAttribute("mail");
  sourceAttr.setValue(_checkState ? "1":"0");
  new_element.attributes().setNamedItem(sourceAttr);

  doc.documentElement().appendChild(new_element);

  WriteFile(path);

};
