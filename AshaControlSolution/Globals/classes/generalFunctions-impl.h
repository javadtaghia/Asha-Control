#pragma  once
generalFunctions::generalFunctions  (void) 
{
};
generalFunctions::~generalFunctions  (void) 
{
};

inline int generalFunctions ::signpn10(double var)
{
	if (var == 0)
		return 0;
	else if (var >=0)
		return 1;
	else if (var <=0)
		return -1;
	else
		return 2;
};

inline int generalFunctions ::signpn1(double var)
{
	if (var == 0)
		return 1;
	else if (var >=0)
		return 1;
	else if (var <=0)
		return -1;
	else
		return 2;
};

inline const std::string generalFunctions ::dateTimeFileNameGenerate(void)
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y_%m_%d_%H_%M_recData.m", &tstruct);
	return buf;
};

inline double generalFunctions ::limitIt(double value, double limitud)
{
	if (abs(value) >= limitud)
		value = signpn10(value) * limitud;
	else
		value = value ;

	return value;
};

inline double generalFunctions ::deg2rad(double degval) 
{
	return degval * PI / 180.0;
};

inline double generalFunctions ::rad2deg(double radval) 
{
	return radval * 180.0 / PI;
};
