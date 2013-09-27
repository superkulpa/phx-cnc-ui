#ifndef CXUDPMANAGER_H
#define CXUDPMANAGER_H

#include <QUdpSocket>
#include <QStringList>
#include <QTextCodec>

#include "../../CNC/IMessageConstants.h"
typedef std::string String;

/*!
 Класс для работы с UDP-протоколом.
 */
class CXUdpManager : public QUdpSocket
{
Q_OBJECT

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
  sendCommand(const String& aSection, const String& aCommand, const String& aValue = "");

signals:
  //! Сигнал на получение команды от ядра.
  void
  commandReceived(const QString& aSection, const QString& aCommand, const QString& aValue);

private slots:
  //! Слот на получение порции данных.
  void
  onReadyRead();

private:
  //! Функция анализа комманд строки.
  void
  analyze();

private:
  QString mCommands;
  QTextCodec* mCodec;
};

#endif // CXUDPMANAGER_H
