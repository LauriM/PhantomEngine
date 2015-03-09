#pragma once

#ifdef _DEBUG
	#ifdef OS_WINDOWS
		#define DEBUG_BREAK __debugbreak();
		#define DEBUG_PRINT(p_msg)do{\
			std::stringstream __stringStream__;\
			__stringStream__ << p_msg;\
			phantom::debugPrint(__stringStream__.str());}\
				while(false);
	#else
		#define DEBUG_PRINT(p_msg) printf("%s", p_msg);
		#define DEBUG_BREAK
	#endif
#else
	#define DEBUG_PRINT(p_msg)
	#define DEBUG_BREAK
#endif

namespace phantom {

	void debugPrint(const std::string &p_msg);
	void debugBreakpoint();

}
