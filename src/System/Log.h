#ifndef LOG_H

#define LOG_H

#include <stdio.h>
#include <string>


namespace Log {

	typedef enum {
		lmDebug,
		lmInfo,
		lmError
	} LogMessageType;

	void print(std::string msg, LogMessageType type = lmDebug );
	void print(std::string msg, std::string module, LogMessageType type = lmDebug);
	std::string getTypeAsString(LogMessageType type);
}

#endif /* end of include guard: LOG_H */
