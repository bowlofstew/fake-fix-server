#pragma once
#ifndef __MESSAGE_CRACKER__
#define __MESSAGE_CRACKER__

#include "quickfix/MessageCracker.h"

namespace bowlofstew {
class message_cracker : public FIX::MessageCracker {
 public:
  void onMessage(const FIX44::MarketDataRequest&, const FIX::SessionID&);
};
}

#endif