#include <iostream>
#include <string>

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>
#include <unistd.h>
#include "keysoslib.h"



using namespace std;



void *handle;
KeysOSLib* ps;
typedef KeysOSLib* create_t();
typedef void destroy_t(KeysOSLib*);
create_t* openKeysOS;
destroy_t* closeKeysOS;



Json::Value root;
Json::Reader reader;
bool parsingSuccessful=false;
string valueFindXML="";







int main(int argc, char** argv)	{
handle=dlopen("./keysos.so", RTLD_LAZY);
if(!handle){printf("%s", dlerror());}
openKeysOS=(create_t*)dlsym(handle, "create");
closeKeysOS=(destroy_t*)dlsym(handle, "destroy");
if(!openKeysOS){cout << "%s" << dlerror();}
if(!closeKeysOS){cout << "%s" << dlerror();}
ps=openKeysOS();
string response=ps->CreateSelectKeys("Your request here");
cout << response << "\n";
closeKeysOS(ps);

//Début obtention des données XML du resultat
parsingSuccessful = reader.parse(response.c_str(), root);
if ( !parsingSuccessful ){
cout << reader.getFormattedErrorMessages() << std::endl;
}else{
valueFindXML=root["DATA"].asString();
cout << valueFindXML << "\n";
}
//Fin obtention des données XML du resultat

return EXIT_SUCCESS;
}
