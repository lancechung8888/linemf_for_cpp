/*======================================
This library is protected by license.
Please check LINCENSE for details.
FILE:linemf/Login.h
AUTHOR:mafusuke
======================================*/
#include <iostream>
#include <string>
#include <exception>
#include "Session.h"
using namespace std;

class Login(){
public:
  /*setting*/
  //Auth
  bool isLogin=false;
  string authToken("");
  string certificate("");
  //Config
  string LINE_HOST_DOMAIN("https://gd2.line.naver.jp");
  string LINE_LOGIN_QUERY_PATH("/api/v4p/rs");
  string LINE_AUTH_QUERY_PATH("/api/v4/TalkService.do");
  string LINE_API_QUERY_PATH_FIR("/S4");
  string LINE_API_QUERY_PATH_FIR("/P4");
  string LINE_CERTIFICATE_PATH("/Q");
  string APP_TYPE("CHROMEOS");
  string APP_VER("8.9.1");
  string CARRIER("51089, 1-0");
  string SYSTEM_NAME("_mafusuke_");
  string SYSTEM_VER("12.1.1");
  string IP_ADDR("8.8.8.8");
  string USER_AGENT;
  string APP_NAME;
  //Server
  map<string,string> Headers;
  /*method*/
  Login(string lt,string iot="",string pswd="",string cert="",string sn="",string *an="",bool kl=true){
    this->USER_AGENT="Line/"+this->APP_VER;
    this->APP_NAME=this->APP_TYPE+"\t"+this->APP_VER+"\t"+this->SYSTEM_NAME+"\t"+this->SYSTEM_VER;
    this->Headers["USER_AGENT"]=this->USER_AGENT;
    this->Headers["X-Line-Application"]=this->APP_NAME;
    this->Headers["X-Line-Carrier"]=this->CARRIER;
    if (lt=="1"||lt=="url"){
      this->QrCodeLogin(keepLoggedIn=kl,systemName=sn,appName=an);}
    else if (lt=="2"||lt=="mail"){
      this->MailLogin(_id=iot,passwd=pswd,certificate=cert,systemName=sn,appName=an,keepLoggedIn=kl);}
    else if (lt=="3"||lt=="token"){
      this->TokenLogin(authToken=iot,appName=an);}
    else{
      throw exception("not found type");}
    if (this->isLogin==true){
      cout << "LoginSuccess!!\n[" << this->talk->getProfile()->displayName << "]" << endl;}
  }
  auto QrCodeLogin(bool keepLoggedIn=true,string systemName="",string appName=""){
    if (systemName==""){systemName=this->SYSTEM_NAME;}
    if (appName==""){appName=this->APP_NAME;}
    this->Headers["X-Line-Application"]=appName;
    Session this->tauth=new Session(this->LINE_HOST_DOMAIN,this->Headers,this->LINE_AUTH_QUERY_PATH).Talk(open=false);
    auto qr=this->tauth->getAuthQrcode(keepLoggedIn,systemName);
    cout << "有効期限:2分\n" << "line://au/q/"+qr.verifier << endl;
    delete tauth;
    this->Headers["X-Line-Access"]=appName;
    //auto accessKey=;
    Session this->talk=new Session(this->LINE_HOST_DOMAIN,this->Headers,this->LINE_LOGIN_QUERY_PATH).Talk(open=false);
    try{
      LoginRequest lr=this->loginRequest("1");
      result=this->talk->loginZ(lr);
    }
    catch(...){
      return false;
    }
    if (result->type==1){
      if (result->authToken!=NULL){
        this->loginWithAuthToken(result.authToken,appName);
      }
      else{
        return false;
      }
    }
    else{
      throw Exception("ログイン失敗");
    }
  }
  auto loginWithAuthToken(string* authToken=NULL,string* appName){
    if (authToken==NULL){
      throw Exception("authTokenを設定してください");
    }
    if (appName==NULL){
      appName=this->APP_NAME;
    }
    this->Headers["X-Line-Application"]=*appName;
    this->Headers["X-Line-Access"]=*authToken;
    this->authToken=*authToken;
    Session this->poll=new session(this->LINE_HOST_DOMAIN,this->Headers,this->LINE_POLL_QUERY_PATH_FIR).Talk();
    this->isLogin=true;
  }
}
