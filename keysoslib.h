#ifndef KEYSOSLIB_H
#define KEYSOSLIB_H

#include <iostream>

using namespace std;

class KeysOSLib{
public:virtual string GetKeysForAdmin(string port, string code, string licencelink, string keys)=0;
public:virtual string SelectKeys(string request, string keys)=0;
public:virtual string CreateSelectKeys(string request)=0;
};

#endif
