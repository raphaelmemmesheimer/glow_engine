#include "Log.h"

//Log::Log() {
//}

//Log::~Log() {

//}
using namespace Log;

std::string Log::getTypeAsString(LogMessageType type) {
	switch (type) {
		case lmDebug:
			return "Debug";
			break;
		case lmInfo:
			return "Info";
			break;
		case lmError:
			return "Error";
			break;
	}
}

void Log::print(std::string msg, LogMessageType type) 
{
	printf("[%s] \t %s\n", getTypeAsString(type).c_str(), msg.c_str());
}

void Log::print(std::string msg, std::string module, LogMessageType type) {
	printf("[%s] [%s] \t %s\n", getTypeAsString(type).c_str(), module.c_str(), msg.c_str());
}

