#pragma once
#ifndef __APPLICATION__
#define __APPLICATION__

#include "quickfix/Application.h"
#include "message_cracker.hpp"

namespace bowlofstew {
class application : public FIX::Application {
 public:
  void onCreate(const FIX::SessionID& sessionID);

  void onLogon(const FIX::SessionID& sessionID);

  void onLogout(const FIX::SessionID& sessionID);

  void toAdmin(FIX::Message& message, const FIX::SessionID&);

  void toApp(FIX::Message& message,
             const FIX::SessionID&) throw(FIX::DoNotSend);
  void fromAdmin(const FIX::Message& message,
                 const FIX::SessionID&) throw(FIX::FieldNotFound,
                                              FIX::IncorrectDataFormat,
                                              FIX::IncorrectTagValue,
                                              FIX::RejectLogon);

  void fromApp(
      const FIX::Message& message,
      const FIX::SessionID& sessionID) throw(FIX::FieldNotFound,
                                             FIX::IncorrectDataFormat,
                                             FIX::IncorrectTagValue,
                                             FIX::UnsupportedMessageType);

 private:
  message_cracker m_cracker;
};
}

#endif