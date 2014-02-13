/*
 * debug.h
 *
 *  Created on: Jan 21, 2014
 *      Author: kulpanov
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include <glog/logging.h>

#define LOGS            this <<":"<<__func__
#define LOGP(p)         ","#p"=" << p
#define LOGPqs(p)       ","#p"=" << qPrintable(p)
#define LOGN            std::endl
#define LOGE            ",catch:" << e.what()
#define LOG_E(lev)      LOG(lev) << LOGS << LOGE << LOGN


enum {
  D1=1,D2, D3, D4
};

#endif /* DEBUG_H_ */
