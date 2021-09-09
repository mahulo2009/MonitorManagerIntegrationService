// Copyright (c) 2021 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// GCS Includes
#include "VxLCU.h"
#include "monitorManagerIntegrationServiceApp.h"
#include "TimeService.h"
#include "ace/ACE.h"
#ifdef VXWORKS
#include "DDFactory.h"
#endif
#include <string>

// Constructor
VxLCU::VxLCU(char* name)
:LCU(name)
{
}

// Destructor
VxLCU::~VxLCU()
{
}

// Create the Devices of the lcu
int VxLCU::start(int update)  //Only for compatibility reasons with DCF LCU interface class
{
	return 0;
}

int VxLCU::start(int update, int corbaDebug)
{
	printf("-------------------------------------------------------------------------------\n");
	printf("Starting %s services...\n",name_);
	printf("-------------------------------------------------------------------------------\n");
#ifdef VXWORKS
	try
	{
		driverFactory_ = DDFactory::instance();
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("VxLCU::start");
		ex.addToTrace("Error initialising DDFactory");
		cerr << ex;
	}
	cerr << driverFactory_->report();
#endif

	//-------------------
	// Start ACE services
	//-------------------
	ACE::init();

	//---------------------------------------
	// Initialising Time Service for this LCU
	//---------------------------------------
	try
	{
		timeService_ = TimeService::instance();
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("VxLCU::start");
		ex.addToTrace("Error initialising TimeService");
		cerr << ex;
	}

	// Start your Applications and Devices here
	printf("-------------------------------------------------------------\n");
	printf("Starting %s Applications...\n",name_);
	printf("-------------------------------------------------------------\n");
	try
	{
		monitorManagerIntegrationServiceApp_ = new monitorManagerIntegrationServiceApp(const_cast<char *>("monitorManagerIntegrationServiceApp"));
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("VxLCU::start");
		ex.addToTrace("Error creating application");
		cerr << ex;
	}
	try
	{
		monitorManagerIntegrationServiceApp_->run(update, corbaDebug);
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("VxLCU::start");
		ex.addToTrace("Error running application");
		cerr << ex;
	}

	return 0;
}

// Stop services and applications
int VxLCU::stop()
{
	printf("-------------------------------------------------------------------------------\n");
	printf("Stopping %s...\n",name_);
	printf("-------------------------------------------------------------------------------\n");

	monitorManagerIntegrationServiceApp_->quit();
	delete monitorManagerIntegrationServiceApp_;

	// Stop services here
	//timeService_->fini();
	//delete timeService_;
	// ACE, DDFactory...
	return 0;
}

#ifdef VXWORKS
//---------------------------------------------------------------------------
// These functions can be called from the VxWorks shell or VxWorks scripts
//---------------------------------------------------------------------------
VxLCU* _monitorManagerIntegrationService_lcu_;

extern "C" void start_LCU(int update=0, int corbaDebug=0)
{
	_monitorManagerIntegrationService_lcu_ = new VxLCU(const_cast<char *>("VxLCU"));
	_monitorManagerIntegrationService_lcu_->start(update, corbaDebug); 
}

extern "C" void stop_LCU()
{
	_monitorManagerIntegrationService_lcu_->stop(); 
	delete _monitorManagerIntegrationService_lcu_;
}

extern "C" void reboot_LCU()
{
	_monitorManagerIntegrationService_lcu_->reBoot(); 
}
#else
int main(int argc, char** argv)
{
	VxLCU* _monitorManagerIntegrationService_lcu_;
	int update=0;
	int corbaDebug=0;

	printf("\n-------------------------------------------------------------------------------\n");
	printf("Usage: runMonitorManagerIntegrationService[-update] [-corbaDebug]\n");
	printf("\n-------------------------------------------------------------------------------\n");

	CommandLine::current(argc, argv);
	CommandLine cl(argc, argv);

	update = cl.getFlag("-update");
	corbaDebug = cl.getFlag("-corbaDebug");

	_monitorManagerIntegrationService_lcu_ = new VxLCU(const_cast<char *>("VxLCU"));
	_monitorManagerIntegrationService_lcu_->start(update, corbaDebug); 

	// Leave the program running
	while(true)
	{
		sleep(2);
	};
}
#endif

