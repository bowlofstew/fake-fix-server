#include <string>
#include <iostream>
#include <fstream>
#include "application.hpp"
#include "quickfix/SocketAcceptor.h"
#include "quickfix/FileStore.h"

int main() {
  auto settings = new FIX::SessionSettings("session_settings.txt");
  bowlofstew::application application;
  FIX::FileStoreFactory factory("store");
  auto pAcceptor = std::auto_ptr<FIX::Acceptor>(new FIX::SocketAcceptor(application, factory, *settings));
  pAcceptor->start();
  while (true) {
    FIX::process_sleep(1);
  }
  return 0;
}
