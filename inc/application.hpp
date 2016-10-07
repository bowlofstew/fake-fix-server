#pragma once
#ifndef __APPLICATION__
#define __APPLICATION__

#include <string>
#include "quickfix/Application.h"
#include "quickfix/MessageCracker.h"

#include "quickfix/fix40/NewOrderSingle.h"
#include "quickfix/fix41/NewOrderSingle.h"
#include "quickfix/fix42/NewOrderSingle.h"
#include "quickfix/fix43/NewOrderSingle.h"
#include "quickfix/fix44/NewOrderSingle.h"
#include "quickfix/fix50/NewOrderSingle.h"

#include "quickfix/fix40/ExecutionReport.h"
#include "quickfix/fix41/ExecutionReport.h"
#include "quickfix/fix42/ExecutionReport.h"
#include "quickfix/fix43/ExecutionReport.h"
#include "quickfix/fix44/ExecutionReport.h"
#include "quickfix/fix50/ExecutionReport.h"

namespace bowlofstew {
class Application : public FIX::Application,
                    public FIX::MessageCracker {
 public:
  void onCreate(const FIX::SessionID &sessionID);

  void onLogon(const FIX::SessionID &sessionID);

  void onLogout(const FIX::SessionID &sessionID);

  void toAdmin(FIX::Message &message, const FIX::SessionID &);

  void toApp(FIX::Message &message,
             const FIX::SessionID &) throw(FIX::DoNotSend);
  void fromAdmin(const FIX::Message &message,
                 const FIX::SessionID &) throw(FIX::FieldNotFound,
  FIX::IncorrectDataFormat,
  FIX::IncorrectTagValue,
  FIX::RejectLogon);

  void fromApp(
      const FIX::Message &message,
      const FIX::SessionID &sessionID) throw(FIX::FieldNotFound,
  FIX::IncorrectDataFormat,
  FIX::IncorrectTagValue,
  FIX::UnsupportedMessageType);

  void onMessage(const FIX40::NewOrderSingle &, const FIX::SessionID &);

  void onMessage(const FIX41::NewOrderSingle &, const FIX::SessionID &);

  void onMessage(const FIX42::NewOrderSingle &, const FIX::SessionID &);

  void onMessage(const FIX43::NewOrderSingle &, const FIX::SessionID &);

  void onMessage(const FIX44::NewOrderSingle &, const FIX::SessionID &);

  void onMessage(const FIX50::NewOrderSingle &, const FIX::SessionID &);

  void sendToTarget(FIX::Message &message, const FIX::SessionID &sessionID);

  std::string generateOrderId(void);

  std::string generateExecutionId(void);

 private:
  int orderIdM;
  int executionIdM;
};
}

#endif