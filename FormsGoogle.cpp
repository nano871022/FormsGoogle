#include "Arduino.h"
#include "FormsGoogle.h"
#include <ApiRest.h>

void FormsGoogle::setFingerPrint(const char *fingerPrint){
	fingerprint = fingerPrint;
}

void FormsGoogle::setKeyConnect(String keyConnect){
	this->keyConnect = keyConnect;
}

void FormsGoogle::addParams(String *keyValues){
	fields = keyValues;
}

void FormsGoogle::activeDebugMode(){
	debugMode = true;
}

String FormsGoogle::joinParams(){
	String join = "";
	for(uint i =0; i < sizeof(fields);i++){
		if(join.length()>0){
			join += "&";
		}
		join += fields[i];
	}
	if(join.length()>1){
		join = "?"+join;
	}
	return join;
}

bool FormsGoogle::send(){
	ApiRest rest;
	rest.setFingerPrint(fingerprint);
	if(debugMode){
		rest.activeDebugMode();
	}
	String url = host+keyConnect+page+joinParams();
	rest.get(url);
	if(rest.getStatusConnection() == 200){
		return true;
	}else{
		return false;
	}
}

