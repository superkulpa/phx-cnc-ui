// IniFile.cpp:  Implementation of the CIniFile class.
// Written by:   Adam Clauss
// Email: cabadam@tamu.edu
// You may use this class/code as you wish in your programs.  Feel free to distribute it, and
// email suggested changes to me.
//
// Rewritten by: Shane Hill
// Date:         21/08/2001
// Email:        Shane.Hill@dsto.defence.gov.au
// Reason:       Remove dependancy on MFC. Code should compile on any
//               platform. Tested on Windows/Linux/Irix
//////////////////////////////////////////////////////////////////////

#ifndef CIniFile_H
#define CIniFile_H

#define CString std::string

using namespace std;

// C++ Includes
#include <string>
#include <vector>

// C Includes
#include <stdlib.h>

#define MAX_KEYNAME    128
#define MAX_VALUENAME  128
#define MAX_VALUEDATA 2048

class CIniFile
{
private:
  bool   caseInsensitive;
  CString path;
  CString backup_path;
  CString archive_path;

  struct key {
    vector<CString> names;
    vector<CString> values;
    vector<CString> comments;
  };
  vector<key>    keys;
  vector<CString> names;
  vector<CString> comments;
  const CString& CheckCase( const CString& s) const;
public:
  int vl;
  int minSize;
  bool create;

public:
  void SetCreate(bool _create){create = _create;};
public:

  enum errors{ noID = -1};

  CIniFile( const CString& iniPath = " ", int _minSize = 10, bool _create = false);

  virtual ~CIniFile()                            {}

  // Sets whether or not keynames and valuenames should be case sensitive.
  // The default is case insensitive.
  void CaseSensitive()                           {caseInsensitive = false;}
  void CaseInsensitive()                         {caseInsensitive = true;}

  // Sets path of ini file to read and write from.
  void Path(const CString& newPath);
  CString Path() const                            {return path;}
  void SetPath(const CString& newPath)             {Path( newPath);}

  //
  void BackupPath(const CString& newPath)					 {backup_path = newPath;};

  void ArchivePath(const CString& newPath)         {archive_path = newPath;};
  // Reads ini file specified using path.
  // Returns true if successful, false otherwise.
  bool ReadFile(const CString&  _path);
  bool ReadIniFile();
  bool ReadString(const char* ini_str);

  // Writes data stored in class to ini file.
  bool WriteFile(const CString& _path);
  bool WriteIniFile();

  bool CheckFile();
//  bool WriteFile(string &ini_str);

  // Deletes all stored ini data.
  void Erase();
  void Clear()                                   {Erase();}
  void Reset()                                   {Erase();}

  // Returns index of specified key, or noID if not found.
  long FindKey( const CString& keyname) const;

  // Returns index of specified value, in the specified key, or noID if not found.
  long FindValue( unsigned const keyID, const CString& valuename) const;

  // Returns number of keys currently in the ini.
  unsigned NumKeys() const                       {return names.size();}
  unsigned GetNumKeys() const                    {return NumKeys();}

  // Add a key name.
  unsigned AddKeyName( const CString& keyname);

  // Returns key names by index.
  CString KeyName( unsigned const keyID) const;
  CString GetKeyName( unsigned const keyID) const {return KeyName(keyID);}

  // Returns number of values stored for specified key.
  unsigned NumValues( unsigned const keyID);
  unsigned GetNumValues( unsigned const keyID)   {return NumValues( keyID);}
  unsigned NumValues( const CString& keyname);
  unsigned GetNumValues( const CString& keyname)   {return NumValues( keyname);}

  // Returns value name by index for a given keyname or keyID.
  CString ValueName( unsigned const keyID, unsigned const valueID) const;
  CString GetValueName( unsigned const keyID, unsigned const valueID) const {
    return ValueName( keyID, valueID);
  }
  CString ValueName( const CString& keyname, unsigned const valueID) const;
  CString GetValueName( const CString& keyname, unsigned const valueID) const {
    return ValueName( keyname, valueID);
  }

  // Gets value of [keyname] valuename =.
  // Overloaded to return string, int, and double.
  // Returns defValue if key/value not found.
  CString GetValue( unsigned const keyID, unsigned const valueID, const CString& defValue = "");// const;
  CString GetValue(const CString& keyname, const CString& valuename, const CString& defValue = "");// const;
  int    GetValueI(const CString& keyname, const CString& valuename, int const defValue = 0);
  bool   GetValueB(const CString& keyname, const CString& valuename, bool const defValue = false){
    return bool( GetValueI( keyname, valuename, int( defValue)));
  }
  double   GetValueF(const CString& keyname, const CString& valuename, double const defValue = 0.0);

  CString GetAttribute(const CString& keyname, const CString& valuename, const CString& defValue){
  	return GetValue(keyname, valuename, defValue);
  };

  // This is a variable length formatted GetValue routine. All these voids
  // are required because there is no vsscanf() like there is a vsprintf().
  // Only a maximum of 8 variable can be read.
  unsigned GetValueV( const CString& keyname, const CString& valuename, char *format,
		      void *v1 = 0, void *v2 = 0, void *v3 = 0, void *v4 = 0,
  		      void *v5 = 0, void *v6 = 0, void *v7 = 0, void *v8 = 0,
  		      void *v9 = 0, void *v10 = 0, void *v11 = 0, void *v12 = 0,
  		      void *v13 = 0, void *v14 = 0, void *v15 = 0, void *v16 = 0);

  // Sets value of [keyname] valuename =.
  // Specify the optional paramter as false (0) if you do not want it to create
  // the key if it doesn't exist. Returns true if data entered, false otherwise.
  // Overloaded to accept CString, int, and double.
  bool SetValue( unsigned const keyID, unsigned const valueID, const CString& value);
  bool SetValue( const CString& keyname, const CString& valuename, const CString& value, bool const create = true);
  bool SetValueI( const CString& keyname, const CString& valuename, int const value, bool const create = true);
  bool SetValueB( const CString& keyname, const CString& valuename, bool const value, bool const create = true) {
    return SetValueI( keyname, valuename, int(value), create);
  }
  bool SetValueF( const CString& keyname, const CString& valuename, double const value, bool const create = true);
  bool SetValueV( const CString& keyname, const CString& valuename, char *format, ...);

  void CreateSection( const CString& keyname, const CString& valuename, const CString& defValue);

  void CreateValue( const CString& keyname, const CString& valuename, const CString& defValue);

  bool AddValue(const CString& keyname, const CString& valuename, const CString& value);
  //////////////////////////////////////////////////////////////////////////////
  //мои функции
  bool SetAttribute(const CString& keyname, const CString& valuename, const CString& value){
  	return SetValue(keyname, valuename, value);
  };
  // Deletes specified value.
  // Returns true if value existed and deleted, false otherwise.
  bool DeleteValue( const CString& keyname, const CString& valuename);

  // Deletes specified key and all values contained within.
  // Returns true if key existed and deleted, false otherwise.
  bool DeleteKey(const CString& keyname);

  // Header comment functions.
  // Header comments are those comments before the first key.
  //
  // Number of header comments.
  unsigned NumHeaderComments()                  {return comments.size();}
  // Add a header comment.
  void     HeaderComment( const CString& comment);
  // Return a header comment.
  CString   HeaderComment( unsigned const commentID) const;
  // Delete a header comment.
  bool     DeleteHeaderComment( unsigned commentID);
  // Delete all header comments.
  void     DeleteHeaderComments()               {comments.clear();}

  // Key comment functions.
  // Key comments are those comments within a key. Any comments
  // defined within value names will be added to this list. Therefore,
  // these comments will be moved to the top of the key definition when
  // the CIniFile::WriteFile() is called.
  //
  // Number of key comments.
  unsigned NumKeyComments( unsigned const keyID) const;
  unsigned NumKeyComments( const CString& keyname) const;
  // Add a key comment.
  bool     KeyComment( unsigned const keyID, const CString& comment);
  bool     KeyComment( const CString& keyname, const CString& comment);
  // Return a key comment.
  CString   KeyComment( unsigned const keyID, unsigned const commentID) const;
  CString   KeyComment( const CString& keyname, unsigned const commentID) const;
  // Delete a key comment.
  bool     DeleteKeyComment( unsigned const keyID, unsigned const commentID);
  bool     DeleteKeyComment( const CString& keyname, unsigned const commentID);
  // Delete all comments for a key.
  bool     DeleteKeyComments( unsigned const keyID);
  bool     DeleteKeyComments( const CString& keyname);

public:
  //static CString GetValueFromOpts(const CString& _opts, const char* _valueName, const char* _defValue);
  ///Задать/заменить значение из строки запуска
  static CString SetValueToOpts(const CString& _opts, const char* _valueName, const CString& _value);
};

#endif
