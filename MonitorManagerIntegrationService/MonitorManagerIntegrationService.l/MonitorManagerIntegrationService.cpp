// Copyright (c) 2021 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include "MonitorManagerIntegrationService.h"

//----------------------------------------------------------------------
// Device Constructor
//----------------------------------------------------------------------
MonitorManagerIntegrationService::MonitorManagerIntegrationService(string name)
: MonitorManagerIntegrationServiceBase(name)
{
	trace_.out("MonitorManagerIntegrationService constructor\n");
	className_ = "MonitorManagerIntegrationService";
}

//----------------------------------------------------------------------
// Device destructor
//----------------------------------------------------------------------
MonitorManagerIntegrationService::~MonitorManagerIntegrationService()
{
  trace_.out("destructor\n");
}

/************************************************************************
*************************************************************************
**                                                                     **
**       Virtual methods inherited from Device interface               **
**                                                                     **
*************************************************************************
************************************************************************/
	
//----------------------------------------------------------------------
// Connects device with GCS services
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::connect(string orbname, bool corbaDebug, unsigned threads, long priority, bool mode, bool update)
{
	trace_.out("MonitorManagerIntegrationService::connect()\n");
	MonitorManagerIntegrationServiceBase::connect(orbname, corbaDebug, threads, priority, mode, update);
	
	//## Add code as required
	
}

//----------------------------------------------------------------------
// Performs starting procedure: OFF-->STARTING-->ON
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::start()
{
	trace_.out("start()\n");
	
	try
	{
		goStarting_();
	
		// Configure device
		try
		{
			configure("Default");
		}
		catch(GCSException& ex)
		{
			logError_("unable to configure device");
			throw;
		}
		
		createMonitors_();
		
		// ## Create other classes required for this Device
		
		// ## Create other threads required for this Device
		
		goOn_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("MonitorManagerIntegrationService::start()"); 
		trace_.err("MonitorManagerIntegrationService::start() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs initialization procedure: ON-->INITIALISING-->READY
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::init()
{
	trace_.out("init()\n");
	
	try
	{
		goInitialising_();
		
		// ## Initialization procedure
		
		
		cout << endl << "MonitorManagerIntegrationService READY!!!" << endl << endl;
		
		goIdle_();  // or goRunning_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("MonitorManagerIntegrationService::init()"); 
		trace_.err("MonitorManagerIntegrationService::init() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs halting procedure: READY-->HALTING-->ON
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::halt()
{
	trace_.out("halt()\n");
	
	try
	{
		goHalting_();
		
		// ## Halting procedure
		
		goOn_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("MonitorManagerIntegrationService::halt()"); 
		trace_.err("MonitorManagerIntegrationService::halt() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs shutdown procedure: ON-->SHUTTING_DOWN-->OFF
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::shutdown()
{
	trace_.out("shutdown()\n");
	
	try
	{
		goShuttingDown_();
		
		// ## Shutdown procedure
		
		goOff_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("MonitorManagerIntegrationService::shutdown()"); 
		trace_.err("MonitorManagerIntegrationService::shutdown() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs reset procedure: FAULT-->RESETTING-->ON
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::reset()
{
	trace_.out("reset()\n");
	
	try
	{
		goResetting_();
		
		// ## Resetting procedure
		
		goOn_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("MonitorManagerIntegrationService::reset()"); 
		trace_.err("MonitorManagerIntegrationService::reset() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs test procedure: only possible in ON state
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::test()
{
	trace_.out("test()\n");
	
	try
	{
		if (isOn()==FALSE)
		{
			logError_("Test is only posible in ON state");
			throw WrongState(name_.c_str(),"Not in ON state. Unable to test");
		}
		
		// ## Test procedure
		
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("MonitorManagerIntegrationService::test()"); 
		trace_.err("MonitorManagerIntegrationService::test() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs abort: interrupt any current operation and goes to FAULT
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::abort()
{
	trace_.out("abort()\n");
	
	// ## Abort procedure
	
	goFault_();
}

//----------------------------------------------------------------------
// Report device status: returns static memory, do not delete! 
//----------------------------------------------------------------------
char* MonitorManagerIntegrationService::report(short level)
{
	trace_.out("report(%d)\n",level);
	char* dev_reply = new char[DEVICE_REPORT_SIZE_];
	ostrstream ost(dev_reply, DEVICE_REPORT_SIZE_);
	memset(dev_reply,0,DEVICE_REPORT_SIZE_);
	
	// Generic Device info
	ost << MonitorManagerIntegrationServiceBase::report(level);
	
	// ## Add here your other monitors
	
	// ## Add more information if required
	
	return(dev_reply);
}

/************************************************************************
*************************************************************************
**                                                                     **
**                 Specific methods of this Device                     **
**                                                                     **
*************************************************************************
*************************************************************************
* All specific methods:                                                 *
* - Shall make a transition to RUNNING (even when is already running)   *
* - Shall make a transition to IDLE when the Device in really idle      *
* - Use ACE_Guard only for thread safe operations                       *
* - If an error is detected use logError_() & throw GCSException        *
* - If an alarm is detected use sendAlarm_()                            *
* - If a failure is detected use goFault_(method)                       *
* - Access to a DeviceDriver or aggregated Device can be required       *
************************************************************************/
	
/************************************************************************
*************************************************************************
**                                                                     **
**                        Specific private methods                     **
**                                                                     **
*************************************************************************
************************************************************************/
	
