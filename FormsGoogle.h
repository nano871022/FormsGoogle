/**
this library was created to comunicate with forms by google, 
the forms is save into de sheet file google into drive google
the library only save information into de forms.
The library use lib ApiRest by Alejandro Parra to communicate with google
Additional method necesary to start is it need that you put fingerprint
(it is a certificate in formar SHA1) by docs.google.com.
const fingerprint[] PROGMEM = "00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00";
Since 4 Jun 2020
By ALejandro Parra
*/
#ifndef FormsGoogle_h
#define FormsGoogle_h

#include "Arduino.h"
#include <ApiRest.h>

	class FormsGoogle{
		public:
			void setFingerPrint(const char *fingerPrint);
			void setKeyConnect(String keyConnect);
			/**
			this methos recieve value in format key=value
			key is name field to form 
			value is a value 
			*/
			void addParams(String *keyValues);
			void activeDebugMode();
			bool send();
		private:
			const char *fingerprint;
			String host = "https://docs.google.com/forms/d/e/";
			String page = "/formResponse";
			String *fields;
			String keyConnect;
			bool debugMode = false;
			String joinParams();
	};


#endif