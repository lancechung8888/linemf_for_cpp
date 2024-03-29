/*======================================
This library is protected by license.
Please check LINCENSE for details.
FILE:linemf/Login.h
AUTHOR:mafusuke
======================================*/
#include "TalkService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

class TalkServiceHandler : virtual public TalkServiceIf {
 public:
  TalkServiceHandler() {
    // Your initialization goes here
  }

  void acceptGroupInvitation(const int32_t reqSeq, const std::string& groupId) {
    // Your implementation goes here
    printf("acceptGroupInvitation\n");
  }

  void createGroup(Group& _return, const int32_t seq, const std::string& name, const std::vector<std::string> & contactIds) {
    // Your implementation goes here
    printf("createGroup\n");
  }

  void createQrcodeBase64Image(std::string& _return, const std::string& url, const std::string& characterSet, const int32_t imageSize, const int32_t x, const int32_t y, const int32_t width, const int32_t height) {
    // Your implementation goes here
    printf("createQrcodeBase64Image\n");
  }

  void createRoom(Room& _return, const int32_t reqSeq, const std::vector<std::string> & contactIds) {
    // Your implementation goes here
    printf("createRoom\n");
  }

  void createSession(std::string& _return) {
    // Your implementation goes here
    printf("createSession\n");
  }

  void fetchOperations(std::vector<Operation> & _return, const int64_t localRev, const int32_t count) {
    // Your implementation goes here
    printf("fetchOperations\n");
  }

  void getProfile(Profile& _return) {
    // Your implementation goes here
    printf("getProfile\n");
  }

  void findAndAddContactsByEmail(std::map<std::string, Contact> & _return, const int32_t reqSeq, const std::set<std::string> & emails) {
    // Your implementation goes here
    printf("findAndAddContactsByEmail\n");
  }

  void findAndAddContactsByMid(std::map<std::string, Contact> & _return, const int32_t reqSeq, const std::string& mid) {
    // Your implementation goes here
    printf("findAndAddContactsByMid\n");
  }

  void findAndAddContactsByPhone(std::map<std::string, Contact> & _return, const int32_t reqSeq, const std::set<std::string> & phones) {
    // Your implementation goes here
    printf("findAndAddContactsByPhone\n");
  }

  void findAndAddContactsByUserid(std::map<std::string, Contact> & _return, const int32_t reqSeq, const std::string& userid) {
    // Your implementation goes here
    printf("findAndAddContactsByUserid\n");
  }

  void findContactByUserid(Contact& _return, const std::string& userid) {
    // Your implementation goes here
    printf("findContactByUserid\n");
  }

  void findContactByUserTicket(Contact& _return, const std::string& ticketId) {
    // Your implementation goes here
    printf("findContactByUserTicket\n");
  }

  void findContactsByEmail(std::map<std::string, Contact> & _return, const std::set<std::string> & emails) {
    // Your implementation goes here
    printf("findContactsByEmail\n");
  }

  void findContactsByPhone(std::map<std::string, Contact> & _return, const std::set<std::string> & phones) {
    // Your implementation goes here
    printf("findContactsByPhone\n");
  }

  void generateUserTicket(Ticket& _return, const int64_t expirationTime, const int32_t maxUseCount) {
    // Your implementation goes here
    printf("generateUserTicket\n");
  }

  void getAllContactIds(std::vector<std::string> & _return) {
    // Your implementation goes here
    printf("getAllContactIds\n");
  }

  void getBlockedContactIds(std::vector<std::string> & _return) {
    // Your implementation goes here
    printf("getBlockedContactIds\n");
  }

  void getBlockedContactIdsByRange(std::vector<std::string> & _return, const int32_t start, const int32_t count) {
    // Your implementation goes here
    printf("getBlockedContactIdsByRange\n");
  }

  void getBlockedRecommendationIds(std::vector<std::string> & _return) {
    // Your implementation goes here
    printf("getBlockedRecommendationIds\n");
  }

  void getContact(Contact& _return, const std::string& id) {
    // Your implementation goes here
    printf("getContact\n");
  }

  void getContacts(std::vector<Contact> & _return, const std::vector<std::string> & ids) {
    // Your implementation goes here
    printf("getContacts\n");
  }

  void getGroup(Group& _return, const std::string& groupId) {
    // Your implementation goes here
    printf("getGroup\n");
  }

  void getGroupIdsInvited(std::vector<std::string> & _return) {
    // Your implementation goes here
    printf("getGroupIdsInvited\n");
  }

  void getGroupIdsJoined(std::vector<std::string> & _return) {
    // Your implementation goes here
    printf("getGroupIdsJoined\n");
  }

  void getGroups(std::vector<Group> & _return, const std::vector<std::string> & groupIds) {
    // Your implementation goes here
    printf("getGroups\n");
  }

  void getFavoriteMids(std::vector<std::string> & _return) {
    // Your implementation goes here
    printf("getFavoriteMids\n");
  }

  void getHiddenContactMids(std::vector<std::string> & _return) {
    // Your implementation goes here
    printf("getHiddenContactMids\n");
  }

  int64_t getLastOpRevision() {
    // Your implementation goes here
    printf("getLastOpRevision\n");
  }

  void getRoom(Room& _return, const std::string& roomId) {
    // Your implementation goes here
    printf("getRoom\n");
  }

  void getRSAKeyInfo(RSAKey& _return, const IdentityProvider::type provider) {
    // Your implementation goes here
    printf("getRSAKeyInfo\n");
  }

  int64_t getServerTime() {
    // Your implementation goes here
    printf("getServerTime\n");
  }

  void getSessions(std::vector<LoginSession> & _return) {
    // Your implementation goes here
    printf("getSessions\n");
  }

  void leaveGroup(const int32_t reqSeq, const std::string& groupId) {
    // Your implementation goes here
    printf("leaveGroup\n");
  }

  void loginZ(LoginResult& _return, const loginRequest& LoginRequest) {
    // Your implementation goes here
    printf("loginZ\n");
  }

  void logout() {
    // Your implementation goes here
    printf("logout\n");
  }

  void logoutSession(const std::string& tokenKey) {
    // Your implementation goes here
    printf("logoutSession\n");
  }

  void sendMessage(Message& _return, const int32_t seq, const Message& message) {
    // Your implementation goes here
    printf("sendMessage\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::apache::thrift::stdcxx::shared_ptr<TalkServiceHandler> handler(new TalkServiceHandler());
  ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new TalkServiceProcessor(handler));
  ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

