#include <iostream>
#include <string>

#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
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
Json::CharReaderBuilder builder;
Json::CharReader * reader = builder.newCharReader();
bool parsingSuccessful=false;
string errorJSON="";
string valueFindXML="";







int main(int argc, char** argv)	{
handle=dlopen("./keysos.dll", RTLD_LAZY);
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
parsingSuccessful = reader->parse(response.c_str(), response.c_str() + response.size(), &root, &errorJSON);
if ( !parsingSuccessful ){
cout << errorJSON << "\n";
}else{
valueFindXML=root["DATA"].asString();
cout << valueFindXML << "\n";
}
//Fin obtention des données XML du resultat

return EXIT_SUCCESS;
}
