/*
 * CXMLReader.h
 *
 *  Created on: 20.03.2011
 *      Author: tsvet
 */

#ifndef CXMLREADER_H_
#define CXMLREADER_H_
#include <QtXml>
#include <QListWidget>
#include <string.h>
#include <stdio.h>

using namespace std;

class CXMLReader{
protected:
  string path;
  QDomDocument doc;
public:
  void setPath(const string& _path);
  //разбить строку, выбрать подстроку до символа /
  string GetName(string& _path);

  //Получить значение элемента
  QDomElement Get(const char* _elementPath);

  //получить значение атрибута у заданного элемента
  QString GetAttribute(const char* _elementPath, const char* _attributeName, const char* _defValue);

  string GetValue(const char* _elementPath, const char* _defValue);

  //Получить int-значение элемента
  int GetValueI(const char* _elementPath, int _defValue);

  //Получить double-значение элемента
  double GetValueF(const char* _elementPath, double _defValue);

  //задать значение атрибута у заданного элемента
  bool SetAttribute(const char* _elementPath, const char* _attributeName, const QString &_attributeValue);

  //задать значение атрибута value у заданного элемента
  bool SetValue(const char* _elementPath, const char* _attributeValue);

  //задать значение атрибута value у заданного элемента
  bool SetValueI(const char* _elementPath, int _attributeValue);

  //задать значение атрибута value у заданного элемента
  bool SetValueF(const char* _elementPath, double& _attributeValue);

  //������� ������ � �����

  void addElement(const char* _number, const char* _source, const char* _fileName);

  void DeleteFirstElement(QString &_number);

  QDomNode FindElement(const QString &_number);

  string getSource();
  string getFileName();

  QDomElement GetElement(QDomElement _parent, int _nElem);
  
  int GetAbonents(QString* &_numbers, QString* &_names,int* &_checks/*, QString* &_sizes*/);

  int GetParams(int _nSect, QString* &_names, QString* &_values);

  int GetSections(QString* &_sections);

  int GetCountElement(const QString &_sectionName);

  int SetMail(QString &_number, bool _on);

  int SetDescrAbonent(QString &_number, const QString &_descr);

  int SetValue(int _indxSect, int _indxParam, QString& _value);

  void RemoveAbonent(const QString &_number);

  int WriteFile(const string&  _path);

  void CreateNewAbonent(QString &_path, QString &_number, const QString &_descr);

  void SetAbonentInfo(const QString &_number, const QString& _descr, bool _checkState);

public:
  CXMLReader(){};
  CXMLReader(QString _path);
  ~CXMLReader(){};
};

#endif /* CXMLREADER_H_ */
