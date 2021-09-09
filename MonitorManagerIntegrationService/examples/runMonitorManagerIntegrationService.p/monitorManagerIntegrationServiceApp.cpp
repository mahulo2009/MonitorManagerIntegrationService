// Copyright (c) 2021 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// GCS Includes
#include "monitorManagerIntegrationServiceApp.h"
#include "MonitorManagerIntegrationService.h"

// Constructor
monitorManagerIntegrationServiceApp::monitorManagerIntegrationServiceApp(char* name)
:Application(name)
{
}

// Destructor
monitorManagerIntegrationServiceApp::~monitorManagerIntegrationServiceApp()
{
}

// Create the Devices of the application
int monitorManagerIntegrationServiceApp::run(int update)  //Only for compatibility reasons with DCF Application interface class
{
	return 0;
}

int monitorManagerIntegrationServiceApp::run(int update, int corbaDebug)
{
	// Create Devices
	try
	{

	}
	catch(GCSException& ex)
	{
		ex.addToTrace("monitorManagerIntegrationServiceApp:run");
		cerr << "Error creating Device for this application" << endl;
		throw;
	}
	// Start Devices (if required)
	try
	{
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("monitorManagerIntegrationServiceApp:run");
		cerr << "Error starting Device" << endl;
		throw;
	}
	// Init Devices (if required)
	try
	{
	}
	catch(GCSException& ex)
	{
		ex.addToTrace("monitorManagerIntegrationServiceApp:run");
		cerr << "Error initialising Device" << endl;
		throw;
	}
	return(0);
}

// Delete the Devices of the family 
int monitorManagerIntegrationServiceApp::quit()
{
	try
	{

	}
	catch(GCSException& ex)
	{
		ex.addToTrace("monitorManagerIntegrationServiceApp:quit");
		cerr << ex;
	}
	return(0);
}

#ifdef VXWORKS
//---------------------------------------------------------------------------
// These functions can be called from the VxWorks shell or VxWorks scripts
//---------------------------------------------------------------------------
monitorManagerIntegrationServiceApp* _monitorManagerIntegrationServiceApp_;

extern "C" void run_monitorManagerIntegrationServiceApp(int update=0, int corbaDebug=0)
{
	_monitorManagerIntegrationServiceApp_ = new monitorManagerIntegrationServiceApp(const_cast<char *>("monitorManagerIntegrationServiceApp"));
	_monitorManagerIntegrationServiceApp_->run(update, corbaDebug); 
}

extern "C" void quit_monitorManagerIntegrationServiceApp(void)
{
	_monitorManagerIntegrationServiceApp_->quit(); 
	delete _monitorManagerIntegrationServiceApp_;
}
#endif
