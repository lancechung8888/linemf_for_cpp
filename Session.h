/*======================================
This library is protected by license.
Please check LINCENSE for details.
FILE:linemf/Session.h
AUTHOR:mafusuke
======================================*/
//https://thrift.apache.org/tutorial/cpp
#include <iostream>
#include <string>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/stdcxx.h>
#include "TalkService.h"
using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
string host;
map<string,string> headers;
class Session{
  Session(string url,string headers,string path=""){
    this->host=url+path;
    this->headers=headers;}
  auto Talk(bool open=true){
    stdcxx::shared_ptr<TTransport> this->socket(new TSocket(this->host, 9090));
    stdcxx::shared_ptr<TTransport> this->transport(new TBufferedTransport(this->socket));
    this->transport->setCustomHeaders(this->headers)
    stdcxx::shared_ptr<TProtocol> this->protocol(new TBinaryProtocol(this->transport));
    auto _talk=Client(this->protocol);
    if (open==true){
      this->transport->open();}
    return _talk;
  }
}
