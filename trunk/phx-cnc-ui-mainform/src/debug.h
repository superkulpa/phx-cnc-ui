/*
 * debug.h
 *
 *  Created on: Jan 21, 2014
 *      Author: kulpanov
 */

#ifndef DEBUG_H_
#define DEBUG_H_
#include <stdint.h>
//#include <glog/logging.h>
#include <QDebug>

#define LOGS            this <<":"<<__func__
#define LOGP(p)         ","#p"=" << p
#define LOGPqs(p)       ","#p"=" << qPrintable(p)
#define LOGN            " "//std::endl
#define LOGE            ",catch:" << e.what()
#define LOG_E(lev)      VLOG(lev) << LOGS << LOGE << LOGN
#define VLOG(Level)     qDebug()

enum {
  D4=1,D3, D2, D1, INFO, WARN, ERRR, FAULT
};

#endif /* DEBUG_H_ */
