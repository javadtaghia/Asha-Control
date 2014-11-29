//////////////////////////////////////////////////////////////////////////
// FILE: Stopwatch.h
// DESC: Implementation of CStopwatch class, to measure C++ code
//       performances.
//////////////////////////////////////////////////////////////////////////
 
 
#pragma once
#include <windows.h>
 
 
 
//========================================================================
// CStopwatch
//
// Class used to measure performances of C++ code.
// (This class uses high-resolution performance counters.)
//
// By Giovanni Dicanio <giovanni.dicanio@gmail.com>
//
// 2010, January 11th
//
// ----------------------------------------------------------------------
//
// To use this class, follow this pattern:
//
// 1. Create an instance of the class nearby the code you want to measure.
//
// 2. Call Start() method immediately before the code to measure.
//
// 3. Call Stop() method immediately after the code to measure.
//
// 4. Call ElapsedTimeSec() or ElapsedTimeMillisec() methods to get the
//    elapsed time (in seconds or milliseconds, respectively).
//
//
//========================================================================
class CStopwatch
{

public:
 
    // Does some initialization to get consistent results for all tests.
    CStopwatch()
        : mstartCount(0), melapsedTimeSec(0.0)
    {
        //
        // Confine the test to run on a single processor,
        // to get consistent results for all tests.
        //
        SetThreadAffinityMask(GetCurrentThread(), 1);
        SetThreadIdealProcessor(GetCurrentThread(), 0);
        Sleep(1);
    }
 
 
    // Starts measuring performance
    // (to be called before the block of code to measure).
    void start()
    {
        // Clear total elapsed time
        // (it is a spurious value until Stop() is called)
        melapsedTimeSec = 0.0;
		    running = true;
        // Start ticking
        mstartCount = Counter();
    }
 
    // Stops measuring performance
    // (to be called after the block of code to measure).
    void stop()
    {
        // Stop ticking
        LONGLONG stopCount = Counter();
		     running = false;
        // Calculate total elapsed time since Start() was called;
        // time is measured in seconds
        melapsedTimeSec = (stopCount - mstartCount) * 1.0 / Frequency();
 
        // Clear start count (it is spurious information)
        mstartCount = 0;
    }
 
    // Returns total elapsed time (in seconds) in Start-Stop interval.
    double elapsedTimeSec() const
    {
        // Total elapsed time was calculated in Stop() method.
        return melapsedTimeSec;
    }
 
    // Returns total elapsed time (in milliseconds) in Start-Stop interval.
		double elapsedTimeMilliSec() const
		{
			// Total elapsed time was calculated in Stop() method.
			return melapsedTimeSec * 1000.0;
		}

		double stopAndRead()
		{
			if (! running)
				return -1;
			else
			{
				stop();
				return   1*((Counter() - mstartCount) * 1.0 / Frequency());
			}

		}
		double currentTime()
		{
			if (! running)
				return -1;
			else
				return  1*((Counter() - mstartCount) * 1.0 / Frequency());
		}
    //--------------------------------------------------------------------
    // IMPLEMENTATION
    //--------------------------------------------------------------------
private:
 
    //
    // *** Data Members ***
    //
 
    // The value of counter on start ticking
    LONGLONG mstartCount;
 
    // The time (in seconds) elapsed in Start-Stop interval
    double melapsedTimeSec;
	  bool running;
 
 
    //
    // *** Helper Methods ***
    //
 
    // Returns current value of high-resolution performance counter.
    LONGLONG Counter() const
    {
        LARGE_INTEGER counter;
        QueryPerformanceCounter(&counter);
        return counter.QuadPart;
    }
 
    // Returns the frequency (in counts per second) of the
    // high-resolution performance counter.
    LONGLONG Frequency() const
    {
        LARGE_INTEGER frequency;
        QueryPerformanceFrequency(&frequency);
        return frequency.QuadPart;
    }
 
 
    //
    // *** Ban copy ***
    //
private:
    CStopwatch(const CStopwatch &);
    CStopwatch & operator=(const CStopwatch &);
};
 
 
/////////////////////////