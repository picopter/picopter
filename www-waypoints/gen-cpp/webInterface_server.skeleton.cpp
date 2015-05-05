// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "webInterface.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::picopter;

class webInterfaceHandler : virtual public webInterfaceIf {
 public:
  webInterfaceHandler() {
    // Your initialization goes here
  }

  bool beginWaypointsThread() {
    // Your implementation goes here
    printf("beginWaypointsThread\n");
  }

  bool beginLawnmowerThread() {
    // Your implementation goes here
    printf("beginLawnmowerThread\n");
  }

  bool beginUserTrackingThread() {
    // Your implementation goes here
    printf("beginUserTrackingThread\n");
  }

  bool beginObjectTrackingThread(const int32_t method) {
    // Your implementation goes here
    printf("beginObjectTrackingThread\n");
  }

  bool allStop() {
    // Your implementation goes here
    printf("allStop\n");
  }

  void requestStatus(std::string& _return) {
    // Your implementation goes here
    printf("requestStatus\n");
  }

  void requestCoords(coordDeg& _return) {
    // Your implementation goes here
    printf("requestCoords\n");
  }

  double requestBearing() {
    // Your implementation goes here
    printf("requestBearing\n");
  }

  void requestNextWaypoint(coordDeg& _return) {
    // Your implementation goes here
    printf("requestNextWaypoint\n");
  }

  bool updateUserPosition(const coordDeg& wpt) {
    // Your implementation goes here
    printf("updateUserPosition\n");
  }

  bool updateWaypoints(const std::vector<coordDeg> & wpts) {
    // Your implementation goes here
    printf("updateWaypoints\n");
  }

  bool resetWaypoints() {
    // Your implementation goes here
    printf("resetWaypoints\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<webInterfaceHandler> handler(new webInterfaceHandler());
  shared_ptr<TProcessor> processor(new webInterfaceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

