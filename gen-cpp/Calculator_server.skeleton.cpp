// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Calculator.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::tutorial;
using namespace  ::shared;

class CalculatorHandler : public CalculatorIf {
 public:
  CalculatorHandler() {}

  void ping() {
    printf("ping()\n");
  }

  int32_t add(const int32_t n1, const int32_t n2) {
    printf("add(%d,%d)\n", n1, n2);
    return n1 + n2;
  }

  int32_t calculate(const int32_t logid, const Work &work) {
    printf("calculate(%d,{%d,%d,%d})\n", logid, work.op, work.num1, work.num2);
    int32_t val;

    switch (work.op) {
    case Operation::ADD:
      val = work.num1 + work.num2;
      break;
    case Operation::SUBTRACT:
      val = work.num1 - work.num2;
      break;
    case Operation::MULTIPLY:
      val = work.num1 * work.num2;
      break;
    case Operation::DIVIDE:
      if (work.num2 == 0) {
        InvalidOperation io;
        io.what = work.op;
        io.why = "Cannot divide by 0";
        throw io;
      }
      val = work.num1 / work.num2;
      break;
    default:
      InvalidOperation io;
      io.what = work.op;
      io.why = "Invalid Operation";
      throw io;
    }

    SharedStruct ss;
    ss.key = logid;
    char buffer[12];
    snprintf(buffer, sizeof(buffer), "%d", val);
    ss.value = buffer;

    log[logid] = ss;

    return val;
  }

  void getStruct(SharedStruct &ret, const int32_t logid) {
    printf("getStruct(%d)\n", logid);
    ret = log[logid];
  }

  void zip() {
    printf("zip()\n");
  }

protected:
  map log;

};

int main(int argc, char **argv) {
  shared_ptr protocolFactory(new TBinaryProtocolFactory());
  shared_ptr handler(new CalculatorHandler());
  shared_ptr processor(new CalculatorProcessor(handler));
  shared_ptr serverTransport(new TServerSocket(9090));
  shared_ptr transportFactory(new TBufferedTransportFactory());
  
  TSimpleServer server(processor, 
                       serverTransport, 
                       transportFactory, 
                       protocolFactory);

  printf("Starting the server...\n");
  server.serve();
}

