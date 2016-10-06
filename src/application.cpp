#include "application.hpp"

namespace bowlofstew {
void application::fromAdmin(
    const FIX::Message &message,
    const FIX::SessionID &) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat,
                                  FIX::IncorrectTagValue, FIX::RejectLogon) {

}

void application::fromApp(
    const FIX::Message &message,
    const FIX::SessionID &sessionID) throw(FIX::FieldNotFound,
                                           FIX::IncorrectDataFormat,
                                           FIX::IncorrectTagValue,
                                           FIX::UnsupportedMessageType) {

}

void application::onCreate(const FIX::SessionID &sessionID) {}

void application::onLogon(const FIX::SessionID &sessionID) {}

void application::onLogout(const FIX::SessionID &sessionID) {}

void application::toAdmin(FIX::Message &message, const FIX::SessionID &) {}

void application::toApp(FIX::Message &message,
                        const FIX::SessionID &) throw(FIX::DoNotSend) {}
}