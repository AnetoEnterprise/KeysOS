#include <iostream>
#include <dlfcn.h>
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
if(!openKeysOS){cout << dlerror() << "\n";}
if(!closeKeysOS){cout << dlerror() << "\n";}
ps=openKeysOS();
string response=ps->CreateSelectKeys("CREATE KEYS{SOCIETY{NAME='Test',DOMAINNAME='www.test.com'}SECURITY{LEVEL=1}EXPIRATION{DATE=CURRENT_DATE,TIME='23:50'}FIND{DATA='My data to secure'}};");
closeKeysOS(ps);

//Début obtention des données XML du resultat
parsingSuccessful = reader.parse(response.c_str(), root);
if ( !parsingSuccessful ){
cout << reader.getFormattedErrorMessages() << std::endl;
}else{
size_t foundWORD1=response.find("\"SUCCESS\":");
size_t foundWORD2=response.find("\"PENDING\":");
if(foundWORD1!=string::npos){
valueFindXML=root["SUCCESS"].get("DATA", "NoResponseDATA" ).asString();
cout << valueFindXML << "\n";
}else{
if(foundWORD2!=string::npos){
valueFindXML=root["PENDING"].get("DATA", "NoResponseDATA" ).asString();
cout << valueFindXML << "\n";
}else{
valueFindXML=root["ERROR"].get("DATA", "NoResponseDATA" ).asString();
cout << valueFindXML << "\n";
}}
}
//Fin obtention des données XML du resultat

return EXIT_SUCCESS;
}
