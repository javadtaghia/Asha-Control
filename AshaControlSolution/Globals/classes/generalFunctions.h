#pragma  once

#include <global.h>

namespace ashacontrol
	{
	class generalFunctions
	{
	public:
		generalFunctions(void);
		~generalFunctions(void);
		int signpn10(double var); // +1 0 -1
		int signpn1(double var); // +1 -1
		const std::string dateTimeFileNameGenerate(void); // create text containing date and time
		double limitIt(double value, double limitud); // threshold value between +-limitud
		double deg2rad(double degval); // degree to radian
		double rad2deg(double radval); // radian to degree
	};

#include <generalFunctions-impl.h>
}
