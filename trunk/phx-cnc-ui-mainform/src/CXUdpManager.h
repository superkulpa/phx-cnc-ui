#ifndef CXUDPMANAGER_H
#define CXUDPMANAGER_H

#include <QUdpSocket>
#include <QStringList>
#include <QTextCodec>

#include "IMessageConstants.h"
//typedef std::string String;

/*!
 Класс для работы с UDP-протоколом.
 */
class CXUdpManager : public QUdpSocket
{
Q_OBJECT
public:
  void postEchoCmd(const QString& _cmd);

protected:
  QHostAddress host;
  int port;
public:
  //! Конструктор.
  CXUdpManager(QObject* parent);

  //! Деструктор.
  virtual ~CXUdpManager();

  //! Функция отправки команды.
  void
  sendCommand(const QString& aSection, const QString& aCommand, const QString& aValue = "");

//  void
//  sendCommand(const QString& aSection, const QString& aCommand, const QString& aValue = "");

signals:
  //! Сигнал на получение команды от ядра.
  void
  commandReceived(const QString& aSection, const QString& aCommand, const QString& aValue);

private slots:
  //! Слот на получение порции данных.
  void
  onReadyRead();
  ///
  void
  onEchoCmd(const QString& _cmd);

private:
  //! Функция анализа комманд строки.
  void
  analyze();

private:
  QString mCommands;
  QTextCodec* mCodec;
};

#endif // CXUDPMANAGER_H
