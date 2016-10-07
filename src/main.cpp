#include <string>
#include <iostream>
#include <fstream>

#include "application.hpp"

#include "quickfix/FileStore.h"
#include "quickfix/FileLog.h"
#include "quickfix/SocketAcceptor.h"

void wait() {
  std::cout << "press ctrl-c to exit" << std::endl;
  while (true) {
    FIX::process_sleep(1);
  }
}

int main() {
  std::string settingsFile = "session_settings.txt";
  try {
    FIX::SessionSettings settings(settingsFile);
    bowlofstew::Application application;
    FIX::ScreenLogFactory logFactory(settings);
    FIX::FileStoreFactory factory("store");

    auto acceptor = std::auto_ptr<FIX::Acceptor>(new FIX::SocketAcceptor(application,
                                                                         factory,
                                                                         settings,
                                                                         logFactory
    ));
    acceptor->start();
    wait();
  } catch (std::exception &exception) {
    std::cout << exception.what() << std::endl;
    return 1;
  }
  return 0;
}
