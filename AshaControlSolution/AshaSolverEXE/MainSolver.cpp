#include <global.h> // global include libs
#include <timing.h>
#include <winTiming.h>
#include <generalFunctions.h>


int main()
{
	splab::Timing timer1_;
	ashacontrol::generalFunctions gfn_;
	//CStopwatch timer1;
	timer1_.start();
	while(true)
	{
		Sleep(1000);
		std:: cout << "Time is: " << timer1_.currentTime() << std::endl;
		std:: cout << "test gfn" << gfn_.limitIt(timer1_.currentTime(),10)
			<< std:: endl;

	}
	std::cout << "Asha Says Hello !" << std::endl;
return 0;
}
