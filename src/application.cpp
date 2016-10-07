#include "Application.hpp"

namespace bowlofstew {
void Application::fromAdmin(
    const FIX::Message &message,
    const FIX::SessionID &) throw(FIX::FieldNotFound, FIX::IncorrectDataFormat,
FIX::IncorrectTagValue, FIX::RejectLogon) {
  if (!message.isAdmin()) return;
}

void Application::fromApp(
    const FIX::Message &message,
    const FIX::SessionID &sessionID) throw(FIX::FieldNotFound,
FIX::IncorrectDataFormat,
FIX::IncorrectTagValue,
FIX::UnsupportedMessageType) {

}

void Application::onCreate(const FIX::SessionID &sessionID) {

}

void Application::onLogon(const FIX::SessionID &sessionID) {

}

void Application::onLogout(const FIX::SessionID &sessionID) {

}

void Application::toAdmin(FIX::Message &message, const FIX::SessionID &) {

}

void Application::toApp(FIX::Message &message,
                        const FIX::SessionID &) throw(FIX::DoNotSend) {
  if (message.isEmpty()) return;
}

void Application::onMessage(const FIX40::NewOrderSingle &message,
                            const FIX::SessionID &sessionID) {
  FIX::Symbol symbol;
  FIX::Side side;
  FIX::OrdType ordType;
  FIX::OrderQty orderQty;
  FIX::Price price;
  FIX::ClOrdID clOrdID;
  FIX::Account account;
  message.get(ordType);
  if (ordType != FIX::OrdType_LIMIT) {
    throw FIX::IncorrectTagValue(ordType.getField());
  }
  message.get(symbol);
  message.get(side);
  message.get(orderQty);
  message.get(price);
  message.get(clOrdID);
  auto executionReport = FIX40::ExecutionReport
      (FIX::OrderID(generateOrderId()),
       FIX::ExecID(generateExecutionId()),
       FIX::ExecTransType(FIX::ExecTransType_NEW),
       FIX::OrdStatus(FIX::OrdStatus_FILLED),
       symbol,
       side,
       orderQty,
       FIX::LastShares(orderQty),
       FIX::LastPx(price),
       FIX::CumQty(orderQty),
       FIX::AvgPx(price));
  executionReport.set(clOrdID);
  if (message.isSet(account)) {
    executionReport.setField(message.get(account));
  }
  sendToTarget(executionReport, sessionID);
}

void Application::onMessage(const FIX41::NewOrderSingle &message,
                            const FIX::SessionID &sessionID) {
  FIX::Symbol symbol;
  FIX::Side side;
  FIX::OrdType ordType;
  FIX::OrderQty orderQty;
  FIX::Price price;
  FIX::ClOrdID clOrdID;
  FIX::Account account;
  message.get(ordType);
  if (ordType != FIX::OrdType_LIMIT) {
    throw FIX::IncorrectTagValue(ordType.getField());
  }
  message.get(symbol);
  message.get(side);
  message.get(orderQty);
  message.get(price);
  message.get(clOrdID);
  auto executionReport = FIX41::ExecutionReport
      (FIX::OrderID(generateOrderId()),
       FIX::ExecID(generateExecutionId()),
       FIX::ExecTransType(FIX::ExecTransType_NEW),
       FIX::ExecType(FIX::ExecType_FILL),
       FIX::OrdStatus(FIX::OrdStatus_FILLED),
       symbol,
       side,
       orderQty,
       FIX::LastShares(orderQty),
       FIX::LastPx(price),
       FIX::LeavesQty(0),
       FIX::CumQty(orderQty),
       FIX::AvgPx(price));
  executionReport.set(clOrdID);
  if (message.isSet(account)) {
    executionReport.setField(message.get(account));
  }
  sendToTarget(executionReport, sessionID);
}

void Application::onMessage(const FIX42::NewOrderSingle &message,
                            const FIX::SessionID &sessionID) {
  FIX::Symbol symbol;
  FIX::Side side;
  FIX::OrdType ordType;
  FIX::OrderQty orderQty;
  FIX::Price price;
  FIX::ClOrdID clOrdID;
  FIX::Account account;
  message.get(ordType);
  if (ordType != FIX::OrdType_LIMIT) {
    throw FIX::IncorrectTagValue(ordType.getField());
  }
  message.get(symbol);
  message.get(side);
  message.get(orderQty);
  message.get(price);
  message.get(clOrdID);
  auto executionReport = FIX42::ExecutionReport
      (FIX::OrderID(generateOrderId()),
       FIX::ExecID(generateExecutionId()),
       FIX::ExecTransType(FIX::ExecTransType_NEW),
       FIX::ExecType(FIX::ExecType_FILL),
       FIX::OrdStatus(FIX::OrdStatus_FILLED),
       symbol,
       side,
       FIX::LeavesQty(0),
       FIX::CumQty(orderQty),
       FIX::AvgPx(price));
  executionReport.set(clOrdID);
  executionReport.set(orderQty);
  executionReport.set(FIX::LastShares(orderQty));
  executionReport.set(FIX::LastPx(price));
  if (message.isSet(account)) {
    executionReport.setField(message.get(account));
  }
  sendToTarget(executionReport, sessionID);
}

void Application::onMessage(const FIX43::NewOrderSingle &message,
                            const FIX::SessionID &sessionID) {
  FIX::Symbol symbol;
  FIX::Side side;
  FIX::OrdType ordType;
  FIX::OrderQty orderQty;
  FIX::Price price;
  FIX::ClOrdID clOrdID;
  FIX::Account account;
  message.get(ordType);
  if (ordType != FIX::OrdType_LIMIT) {
    throw FIX::IncorrectTagValue(ordType.getField());
  }
  message.get(symbol);
  message.get(side);
  message.get(orderQty);
  message.get(price);
  message.get(clOrdID);
  auto executionReport = FIX43::ExecutionReport
      (FIX::OrderID(generateOrderId()),
       FIX::ExecID(generateExecutionId()),
       FIX::ExecType(FIX::ExecType_FILL),
       FIX::OrdStatus(FIX::OrdStatus_FILLED),
       side,
       FIX::LeavesQty(0),
       FIX::CumQty(orderQty),
       FIX::AvgPx(price));
  executionReport.set(clOrdID);
  executionReport.set(symbol);
  executionReport.set(orderQty);
  executionReport.set(FIX::LastQty(orderQty));
  executionReport.set(FIX::LastPx(price));
  if (message.isSet(account)) {
    executionReport.setField(message.get(account));
  }
  sendToTarget(executionReport, sessionID);
}

void Application::onMessage(const FIX44::NewOrderSingle &message,
                            const FIX::SessionID &sessionID) {
  FIX::Symbol symbol;
  FIX::Side side;
  FIX::OrdType ordType;
  FIX::OrderQty orderQty;
  FIX::Price price;
  FIX::ClOrdID clOrdID;
  FIX::Account account;
  message.get(ordType);
  if (ordType != FIX::OrdType_LIMIT) {
    throw FIX::IncorrectTagValue(ordType.getField());
  }
  message.get(symbol);
  message.get(side);
  message.get(orderQty);
  message.get(price);
  message.get(clOrdID);
  auto executionReport = FIX44::ExecutionReport
      (FIX::OrderID(generateOrderId()),
       FIX::ExecID(generateExecutionId()),
       FIX::ExecType(FIX::ExecType_FILL),
       FIX::OrdStatus(FIX::OrdStatus_FILLED),
       side,
       FIX::LeavesQty(0),
       FIX::CumQty(orderQty),
       FIX::AvgPx(price)
      );
  executionReport.set(clOrdID);
  executionReport.set(symbol);
  executionReport.set(orderQty);
  executionReport.set(FIX::LastQty(orderQty));
  executionReport.set(FIX::LastPx(price));
  if (message.isSet(account)) {
    executionReport.setField(message.get(account));
  }
  sendToTarget(executionReport, sessionID);
}

void Application::onMessage(const FIX50::NewOrderSingle &message,
                            const FIX::SessionID &sessionID) {
  FIX::Symbol symbol;
  FIX::Side side;
  FIX::OrdType ordType;
  FIX::OrderQty orderQty;
  FIX::Price price;
  FIX::ClOrdID clOrdID;
  FIX::Account account;
  message.get(ordType);
  if (ordType != FIX::OrdType_LIMIT) {
    throw FIX::IncorrectTagValue(ordType.getField());
  }
  message.get(symbol);
  message.get(side);
  message.get(orderQty);
  message.get(price);
  message.get(clOrdID);
  auto executionReport = FIX50::ExecutionReport
      (FIX::OrderID(generateOrderId()),
       FIX::ExecID(generateExecutionId()),
       FIX::ExecType(FIX::ExecType_FILL),
       FIX::OrdStatus(FIX::OrdStatus_FILLED),
       side,
       FIX::LeavesQty(0),
       FIX::CumQty(orderQty));
  executionReport.set(clOrdID);
  executionReport.set(symbol);
  executionReport.set(orderQty);
  executionReport.set(FIX::LastQty(orderQty));
  executionReport.set(FIX::LastPx(price));
  executionReport.set(FIX::AvgPx(price));
  if (message.isSet(account)) {
    executionReport.setField(message.get(account));
  }
  sendToTarget(executionReport, sessionID);
}

void Application::sendToTarget(FIX::Message &message, const FIX::SessionID &sessionID) {
  try {
    FIX::Session::sendToTarget(message, sessionID);
  }
  catch (FIX::SessionNotFound &) {}
}

std::string Application::generateOrderId(void) {
  std::stringstream stream;
  stream << ++orderIdM;
  return stream.str();
}

std::string Application::generateExecutionId(void) {
  std::stringstream stream;
  stream << ++executionIdM;
  return stream.str();
}
}