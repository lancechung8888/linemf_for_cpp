/*======================================
*This library is protected by license.
*Please check LINCENSE for details.
*@file:linemf/main.cpp
*@author=mafusuke
*@copyright=Copyright 2018 by mafusuke
*@license=BSD-3-Clause
*@version=1.0.0
#======================================*/
#include "login.h"
int main(void){
  Login mf0=new Login("1")//URL
  Login mf1=new Login("2","e-mail","password")//Email
  Login mf2=new Login("3","AuthToken")//authToken
  delete mf0,mf1,mf2
}
