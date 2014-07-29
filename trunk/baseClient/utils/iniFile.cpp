// IniFile.cpp:  Implementation of the CIniFile class.
// Written by:   Adam Clauss
// Email: cabadam@houston.rr.com
// You may use this class/code as you wish in your programs.  Feel free to distribute it, and
// email suggested changes to me.
//
// Rewritten by: Shane Hill
// Date:         21/08/2001
// Email:        Shane.Hill@dsto.defence.gov.au
// Reason:       Remove dependancy on MFC. Code should compile on any
//               platform.
//////////////////////////////////////////////////////////////////////
#if defined(WIN32)
#pragma warning(push) //Отключение предупреждений только для данного заголовочного файла
#pragma warning(disable:4244)
#pragma warning(disable:4800)
#pragma warning(disable:4996)
#endif
// C++ Includes
#include <iostream>
#include <fstream>
#include <sstream>

#include <errno.h>

using namespace std;

#include "iniFile.h"

// C Includes
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

// Local Includes
#include <iosfwd>

#if defined(WIN32)
#define iniEOL endl
#else
#define iniEOL endl
#endif

int
size_of_stream(ifstream& f)
{
  /* Save the current position. */
  long save_pos = f.tellg();
  /* Jump to the end of the file. */
  f.seekg(0, ios::end);
  /* Get the end position. */
  long size_of_file = f.tellg();
  /* Jump back to the original position. */
  f.seekg(save_pos, ios::beg);
  return (size_of_file);
}
;

bool
CheckSize(CString _path, int _minSize, ifstream& _f)
{
  _f.open( _path.c_str());
  if ( _f.fail())
  {
    _f.close();
    return false;
  };
  if((_minSize > 0) && (size_of_stream(_f) < _minSize))
  {
    _f.close();
    return false;
  };
  return true;
};

/*
 ////////////////////////////////////////////////////////////////////////////////
 CString CIniFile::GetValueFromOpts(const CString& _opts, const char* _valueName, const char* _defValue){
 //взять значение из строки опций
 char* start_opts = strdup(( _opts.c_str()) );
 char* opts = start_opts;

 const char *myopts[] = {
 #define OPTION_VALUE_NAME         0
 _valueName
 , NULL};

 char *value;
 while (*opts != '\0')
 switch(getsubopt(&opts, (char* const*)myopts, &value)) {
 case OPTION_VALUE_NAME :
 return (value==NULL)? "1" : value;
 };
 delete start_opts;

 return _defValue;
 }

 //Установить значение в строку запуска
 CString CIniFile::SetValueToOpts(const CString& _opts, const char* _valueName, const CString& _value){
 static const CString def_value= "---";
 CString value_record = CString(_valueName) + CString("=") + _value;

 CString res = _opts;
 CString sect = CIniFile::GetValueFromOpts(res, _valueName, def_value);
 if(sect == def_value){
 //нет такого поля, добавить значение!
 res += CString(",") + value_record;
 }else{
 //уже есть такое поле, заменить значение
 int leftPos = res.find(_valueName);
 int rightPos = res.find(',', leftPos);
 res.replace(leftPos, (rightPos - leftPos), value_record);
 }
 return res;
 }
 */
////////////////////////////////////////////////////////////////////////////////
//
CIniFile::CIniFile(const CString& iniPath, int _minSize, bool _create)
{
  vl = 1;
  minSize = _minSize;
  create = _create;
  Path( iniPath);
  caseInsensitive = true;
}

void
CIniFile::Path(const CString& newPath)
{
//альтернатива basename, dirname
  int lastSlashPos = newPath.rfind('/');

  CString fname = newPath.substr(lastSlashPos+1, CString::npos);

  archive_path = backup_path = newPath.substr(0, lastSlashPos);

  backup_path += "/backup/" + fname;
  archive_path += "/archive/" + fname;
  path = newPath;
};

bool
CIniFile::ReadIniFile()
{
  return ReadFile(path);
}

//до проверка на первый и последний параметр
bool
CIniFile::CheckFile()
{
  if (minSize <= 0)
    return true;

  CString tmp_data = "";

  int lastSlashPos = Path().rfind('/');
  CString fname = Path().substr(lastSlashPos+1, CString::npos);
  bool tmp_create = create;
  bool res = true;
  create = false;
  if ((tmp_data = GetValue(GetKeyName(0), "CRC", "noname")) != fname)
  {
    res = false;
  }
  if ((tmp_data = GetValue(GetKeyName(GetNumKeys() - 1), "CRC", "noname")) != fname)
  {
    res = false;
  }
  create = tmp_create;
  return res;
}

bool
CIniFile::WriteIniFile()
{
  return WriteFile(path);
}

bool
CIniFile::ReadFile(const CString& _path)
{
  // Normally you would use ifstream, but the SGI CC compiler has
  // a few bugs with ifstream. So ... fstream used.
  ifstream f;
  CString line;
  CString keyname, valuename, value;
  CString::size_type pLeft, pRight;

  f.open( _path.c_str());

  try
  {
    Clear();
    while( getline( f, line))
    {
      // To be compatible with Win32, check for existence of '\r'.
      // Win32 files have the '\r' and Unix files don't at the end of a line.
      // Note that the '\r' will be written to INI files from
      // Unix so that the created INI file can be read under Win32
      // without change.
      //printf("str=%s \n line=%s\n",_str.c_str(),line.c_str());

      if (line.size() <= 0) continue;

      if ( line[line.length() - 1] == '\r')
      line = line.substr( 0, line.length() - 1);

      if ( line.length())
      {
        // Check that the user hasn't openned a binary file by checking the first
        // character of each line!
//      if ( !isprint( line[0])) {
//       printf( "Failing on char %d\n", line[0]);
//       f.close();
//        return false;
//      };
        if (( pLeft = line.find_first_of(";#[=:")) != CString::npos)
        {
          switch ( line[pLeft])
          {
            case '[':
            if ((pRight = line.find_last_of("]")) != CString::npos &&
            pRight > pLeft)
            {
              keyname = line.substr( pLeft + 1, pRight - pLeft - 1);
              AddKeyName( keyname);
              //printf("Section: %s\n",keyname.c_str());
            }
            break;

            case '=':
            valuename = line.substr( 0, pLeft);
            value = line.substr( pLeft + 1);
            SetValue( keyname, valuename, value);
            break;
//
//       case ':':
//         valuename = line.substr( 0, pLeft);
//         value = line.substr( pLeft + 1);
//         AddValue( keyname, valuename, value);
//       break;

            case ';':
            case '#':
            if ( !names.size())
            HeaderComment( line.substr( pLeft + 1));
            else
            KeyComment( keyname, line.substr( pLeft + 1));
            break;
          };      //switch()
        }      //if(( pLeft = line.find_first_of(";#[=")) != CString::npos)
      };      //if ( line.length())
    };      //while( getline( ini_str, line))
  }
  catch(...)
  {

  };
  f.close();

  if(0 == names.size())
  {
    printf("Warning: ini file:'%s' is NOT contain any names\n", _path.c_str());
    return false;
  };

  return (CheckFile());
}

bool
getline(CString&_str, CString &line)
{
  if(_str.size()==0) return false;
  CString::size_type pLeft=0, pRight = _str.find('\n');
  line = _str.substr( pLeft, pRight );
  _str = _str.erase(0,pRight+1);
  return true;
};

bool
CIniFile::ReadString(const char* ini_str)
{
  CString line;
  CString keyname, valuename, value;
  CString::size_type pLeft, pRight;

  Clear();
  CString _str = ini_str;
  while( getline( _str, line))
  {
    // To be compatible with Win32, check for existence of '\r'.
    // Win32 files have the '\r' and Unix files don't at the end of a line.
    // Note that the '\r' will be written to INI files from
    // Unix so that the created INI file can be read under Win32
    // without change.
    //printf("str=%s \n line=%s\n",_str.c_str(),line.c_str());
    if ( line[line.length() - 1] == '\r')
    line = line.substr( 0, line.length() - 1);

    if ( line.length())
    {
      // Check that the user hasn't openned a binary file by checking the first
      // character of each line!
      if ( !isprint( line[0]))
      {
//       printf( "Failing on char %d\n", line[0]);
//       f.close();
//        return false;
      };
      if (( pLeft = line.find_first_of(";#[=:")) != CString::npos)
      {
        switch ( line[pLeft])
        {
          case '[':
          if ((pRight = line.find_last_of("]")) != CString::npos &&
              pRight > pLeft)
          {
            keyname = line.substr( pLeft + 1, pRight - pLeft - 1);
            AddKeyName( keyname);
//           printf("Section: %s\n",keyname.c_str());
          }
          break;

          case '=':
//       case ':':
          valuename = line.substr( 0, pLeft);
          value = line.substr( pLeft + 1);
          AddValue( keyname, valuename, value);
//         printf("%s=%s\n",valuename.c_str(),value.c_str());
          break;

          case ';':
          case '#':
          if ( !names.size())
          HeaderComment( line.substr( pLeft + 1));
          else
          KeyComment( keyname, line.substr( pLeft + 1));
          break;
        };      //switch()
      }      //if(( pLeft = line.find_first_of(";#[=")) != CString::npos)
    };      //if ( line.length())
  };      //while( getline( ini_str, line))

  if(minSize <= 0)
  return true;

  if ( names.size())
  return true;

  return false;
};

bool
CIniFile::WriteFile(const CString& _path)
{
  unsigned commentID, keyID, valueID;
  int wasException = 0;
  // Normally you would use ofstream, but the SGI CC compiler has
  // a few bugs with ofstream. So ... fstream used.
  ofstream f( _path.c_str());
  if ( f.fail())
  {
    printf("Warning:w ini file:'%s' is NOT OPENED\n", _path.c_str());
    f.close();
    return false;
  };

//  //вписать CRC
//  char buf[10];
//  itoa(names.size() + keys.size(), buf, 10);
//  SetValue("General", "CRC", buf, true);

  try
  {
    // Write header comments.
    for ( commentID = 0; commentID < comments.size(); ++commentID)
    f << ';' << comments[commentID] << iniEOL;
    if ( comments.size())
    f << iniEOL;

    // Write keys and values.
    for ( keyID = 0; keyID < keys.size(); ++keyID)
    {
      f << '[' << names[keyID] << ']' << iniEOL;
      // Comments.
      for ( commentID = 0; commentID < keys[keyID].comments.size(); ++commentID)
      f << ';' << keys[keyID].comments[commentID] << iniEOL;
      // Values.
      for ( valueID = 0; valueID < keys[keyID].names.size(); ++valueID)
      f << keys[keyID].names[valueID] << '=' << keys[keyID].values[valueID] << iniEOL;
      f << iniEOL;
    }
  }
  catch(exception* e)
  {
    printf("Warning:w ini file:'%s' is NOT WRITTEN, reason: %s\n", _path.c_str(), e->what());
    wasException = 1;
  }
  catch(int e)
  {
    printf("Warning:w ini file:'%s' is NOT WRITTEN, reason: %d\n", _path.c_str(), e);
    wasException = 1;
  }
  catch(...)
  {
    printf("Warning:w ini file:'%s' is NOT WRITTEN, reason: %s\n", _path.c_str(), "unknown exception");
    wasException = 1;
  };

  f.flush();
  f.close();

  if(wasException)
  return false;

  //проверка испорченности файла: тест записанного
  if(minSize<=0)
  return true;

  CIniFile tmpIni(_path, minSize);
  if( (! tmpIni.ReadFile(_path))
  ||(tmpIni.names.size() != names.size())
  ||(tmpIni.keys.size() != keys.size()) )
  {
    printf("Warning:w ini file:'%s' is NOT CHECKED\n", _path.c_str());
    return false;
  }

  return true;
}

long
CIniFile::FindKey(const CString& keyname) const
{
  for ( unsigned keyID = 0; keyID < names.size(); ++keyID)
  if ( CheckCase( names[keyID]) == CheckCase( keyname))
  return long(keyID);
  return noID;
}

long
CIniFile::FindValue(unsigned const keyID, const CString& valuename) const
{
  if ( !keys.size() || keyID >= keys.size())
  return noID;

  for ( unsigned valueID = 0; valueID < keys[keyID].names.size(); ++valueID)
  if ( CheckCase( keys[keyID].names[valueID]) == CheckCase( valuename))
  return long(valueID);
  return noID;
}

unsigned
CIniFile::AddKeyName(const CString& keyname)
{
  names.resize( names.size() + 1, keyname);
  keys.resize( keys.size() + 1);
  return names.size() - 1;
}

CString CIniFile::KeyName( unsigned const keyID) const
{
  if ( keyID < names.size())
  return names[keyID];
  else
  return "";
}

unsigned
CIniFile::NumValues(unsigned const keyID)
{
  if (keyID < keys.size())
    return keys[keyID].names.size();
  return 0;
}

unsigned
CIniFile::NumValues(const CString& keyname)
{
  long keyID = FindKey( keyname);
  if ( keyID == noID)
  return 0;
  return keys[keyID].names.size();
}

CString CIniFile::ValueName( unsigned const keyID, unsigned const valueID) const
{
  if ( keyID < keys.size() && valueID < keys[keyID].names.size())
  return keys[keyID].names[valueID];
  return "";
}

CString CIniFile::ValueName( const CString& keyname, unsigned const valueID) const
{
  long keyID = FindKey( keyname);
  if ( keyID == noID)
  return "";
  return ValueName( keyID, valueID);
}

bool
CIniFile::SetValue(unsigned const keyID, unsigned const valueID, const CString& value)
{
  if ( keyID < keys.size() && valueID < keys[keyID].names.size())
  keys[keyID].values[valueID] = value;

  return false;
}

bool
CIniFile::SetValue(const CString& keyname, const CString& valuename, const CString& value, bool const create)
{
  long keyID = FindKey( keyname);
  if ( keyID == noID)
  {
    if ( create)
    keyID = long( AddKeyName( keyname));
    else
    return false;
  }

  long valueID = FindValue( unsigned(keyID), valuename);
  if ( valueID == noID)
  {
    if ( !create)
    return false;
    keys[keyID].names.resize( keys[keyID].names.size() + 1, valuename);
    keys[keyID].values.resize( keys[keyID].values.size() + 1, value);
  }
  else
  keys[keyID].values[valueID] = value;

  return true;
}

bool
CIniFile::AddValue(const CString& keyname, const CString& valuename, const CString& value)
{
  long keyID = FindKey( keyname);
  if ( keyID == noID) return false;

  keys[keyID].names.resize( keys[keyID].names.size() + 1, valuename);
  keys[keyID].values.resize( keys[keyID].values.size() + 1, value);
  return true;
};

bool
CIniFile::SetValueI(const CString& keyname, const CString& valuename, int const value, bool const create)
{
  char svalue[MAX_VALUEDATA];

  sprintf( svalue, "%d", value);
  return SetValue( keyname, valuename, svalue);
}

bool
CIniFile::SetValueF(const CString& keyname, const CString& valuename, double const value, bool const create)
{
  char svalue[MAX_VALUEDATA];

  sprintf( svalue, "%f", value);
  return SetValue( keyname, valuename, svalue);
}

bool
CIniFile::SetValueV(const CString& keyname, const CString& valuename, char *format, ...)
{
  va_list args;
  char value[MAX_VALUEDATA];

  va_start( args, format);
  vsprintf( value, format, args);
  va_end( args);
  return SetValue( keyname, valuename, value);
}
/*
 void CIniFile::CreateSection( const CString& keyname, const CString& valuename, const CString& value){
 //проверяем есть ли в последней секции CRC и удаляем если есть
 DeleteValue(KeyName(keys.size() - 1),"CRC");

 //создаем CRC
 char* tmp = strdup(path.c_str());
 SetValue(keyname,"CRC",basename(tmp),true);
 delete tmp;
 //создаем и записываем значение
 CreateValue(keyname,valuename,value);
 }
 */

void
CIniFile::CreateValue(const CString& keyname, const CString& valuename, const CString& value)
{

  SetValue(keyname,valuename,value,true);
  SetValue(keyname,"descr","",true);
  //записываем
  WriteIniFile();
}

CString CIniFile::GetValue( unsigned const keyID, unsigned const valueID, const CString& defValue)
{
  if ( keyID < keys.size() && valueID < keys[keyID].names.size())
  return keys[keyID].values[valueID];

  if(vl) printf("ini::GetValue: '%s':'%d':'%d' initialized by default\n", path.c_str(), keyID, valueID);
  return defValue;
}

CString CIniFile::GetValue( const CString& keyname, const CString& valuename, const CString& defValue)
{
  long keyID = FindKey( keyname);
  if ( keyID == noID)
  {
    if(vl) printf("ini::GetValue: '%s':'%s':'%s' initialized by default\n", path.c_str(), keyname.c_str(), valuename.c_str());
    //сохраняем секцию проверяем наличие CRC и сохраняем файл
//    if(create)
//      CreateSection(keyname,valuename,defValue);
    return defValue;
  };
  long valueID = FindValue( unsigned(keyID), valuename);
  if ( valueID == noID)
  {
    if(vl) printf("ini::GetValue: '%s':'%s':'%s' initialized by default\n", path.c_str(), keyname.c_str(), valuename.c_str());
    //сохраняем параметр и файл и сохраняем файл
    if(create)
    CreateValue(keyname,valuename,defValue);
    return defValue;
  }
  return keys[keyID].values[valueID];
}

int
CIniFile::GetValueI(const CString& keyname, const CString& valuename, int const defValue)
{
  char svalue[MAX_VALUEDATA];

  sprintf( svalue, "%d", defValue);
  return atoi( GetValue( keyname, valuename, svalue).c_str());
}

double
CIniFile::GetValueF(const CString& keyname, const CString& valuename, double const defValue)
{
  char svalue[MAX_VALUEDATA];

  sprintf( svalue, "%f", defValue);
  return atof( GetValue( keyname, valuename, svalue).c_str());
}

// 16 variables may be a bit of over kill, but hey, it's only code.
unsigned
CIniFile::GetValueV(const CString& keyname, const CString& valuename, char *format,
void *v1, void *v2, void *v3, void *v4,
void *v5, void *v6, void *v7, void *v8,
void *v9, void *v10, void *v11, void *v12,
void *v13, void *v14, void *v15, void *v16)
{
  CString value;
  // va_list  args;
  unsigned nVals;

  value = GetValue( keyname, valuename);
  if ( !value.length())
  return false;
  // Why is there not vsscanf() function. Linux man pages say that there is
  // but no compiler I've seen has it defined. Bummer!
  //
  // va_start( args, format);
  // nVals = vsscanf( value.c_str(), format, args);
  // va_end( args);

  nVals = sscanf( value.c_str(), format,
  v1, v2, v3, v4, v5, v6, v7, v8,
  v9, v10, v11, v12, v13, v14, v15, v16);

  return nVals;
}

bool
CIniFile::DeleteValue(const CString& keyname, const CString& valuename)
{
  long keyID = FindKey( keyname);
  if ( keyID == noID)
  return false;

  long valueID = FindValue( unsigned(keyID), valuename);
  if ( valueID == noID)
  return false;

  // This looks strange, but is neccessary.
  vector<CString>::iterator npos = keys[keyID].names.begin() + valueID;
  vector<CString>::iterator vpos = keys[keyID].values.begin() + valueID;
  keys[keyID].names.erase( npos, npos + 1);
  keys[keyID].values.erase( vpos, vpos + 1);

  return true;
}

bool
CIniFile::DeleteKey(const CString& keyname)
{
  long keyID = FindKey( keyname);
  if ( keyID == noID)
  return false;

  // Now hopefully this destroys the vector lists within keys.
  // Looking at <vector> source, this should be the case using the destructor.
  // If not, I may have to do it explicitly. Memory leak check should tell.
  // memleak_test.cpp shows that the following not required.
  //keys[keyID].names.clear();
  //keys[keyID].values.clear();

  vector<CString>::iterator npos = names.begin() + keyID;
  vector<key>::iterator kpos = keys.begin() + keyID;
  names.erase( npos, npos + 1);
  keys.erase( kpos, kpos + 1);

  return true;
}

void
CIniFile::Erase()
{
  // This loop not needed. The vector<> destructor seems to do
  // all the work itself. memleak_test.cpp shows this.
  for (unsigned i = 0; i < keys.size(); ++i)
  {
    keys[i].names.clear();
    keys[i].values.clear();
  }
  names.clear();
  keys.clear();
  comments.clear();
}

void
CIniFile::HeaderComment(const CString& comment)
{
  comments.resize( comments.size() + 1, comment);
}

CString CIniFile::HeaderComment( unsigned const commentID) const
{
  if ( commentID < comments.size())
  return comments[commentID];
  return "";
}

bool
CIniFile::DeleteHeaderComment(unsigned commentID)
{
  if (commentID < comments.size())
  {
    vector<CString>::iterator cpos = comments.begin() + commentID;
    comments.erase( cpos, cpos + 1);
    return true;
  }
  return false;
}

unsigned
CIniFile::NumKeyComments(unsigned const keyID) const
    {
  if (keyID < keys.size())
    return keys[keyID].comments.size();
  return 0;
}

unsigned
CIniFile::NumKeyComments(const CString& keyname) const
{
  long keyID = FindKey( keyname);
  if ( keyID == noID)
  return 0;
  return keys[keyID].comments.size();
}

bool
CIniFile::KeyComment(unsigned const keyID, const CString& comment)
{
  if ( keyID < keys.size())
  {
    keys[keyID].comments.resize( keys[keyID].comments.size() + 1, comment);
    return true;
  }
  return false;
}

bool
CIniFile::KeyComment(const CString& keyname, const CString& comment)
{
  long keyID = FindKey( keyname);
  if ( keyID == noID)
  return false;
  return KeyComment( unsigned(keyID), comment);
}

CString CIniFile::KeyComment( unsigned const keyID, unsigned const commentID) const
{
  if ( keyID < keys.size() && commentID < keys[keyID].comments.size())
  return keys[keyID].comments[commentID];
  return "";
}

CString CIniFile::KeyComment( const CString& keyname, unsigned const commentID) const
{
  long keyID = FindKey( keyname);
  if ( keyID == noID)
  return "";
  return KeyComment( unsigned(keyID), commentID);
}

bool
CIniFile::DeleteKeyComment(unsigned const keyID, unsigned const commentID)
{
  if (keyID < keys.size() && commentID < keys[keyID].comments.size())
  {
    vector<CString>::iterator cpos = keys[keyID].comments.begin() + commentID;
    keys[keyID].comments.erase( cpos, cpos + 1);
    return true;
  }
  return false;
}

bool
CIniFile::DeleteKeyComment(const CString& keyname, unsigned const commentID)
{
  long keyID = FindKey( keyname);
  if ( keyID == noID)
  return false;
  return DeleteKeyComment( unsigned(keyID), commentID);
}

bool
CIniFile::DeleteKeyComments(unsigned const keyID)
{
  if (keyID < keys.size())
  {
    keys[keyID].comments.clear();
    return true;
  }
  return false;
}

bool
CIniFile::DeleteKeyComments(const CString& keyname)
{
  long keyID = FindKey( keyname);
  if ( keyID == noID)
  return false;
  return DeleteKeyComments( unsigned(keyID));
}

const CString& CIniFile::CheckCase( const CString& s) const
{
//  if ( caseInsensitive)
//    for ( CString::size_type i = 0; i < s.length(); ++i)
//      s[i] = tolower(s[i]);
  return s;
}
#if defined(WIN32)
#pragma warning(pop) //Восстанавливаем исходный уровень вывода предупреждений
#endif
