// Copyright (c) 2021 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _monitorManagerIntegrationServiceApp_h_
#define _monitorManagerIntegrationServiceApp_h_

// GCS Includes
#include "Application.h"

// Forward declarations
class MonitorManagerIntegrationService;

/** This class manages a group of related Device instances */
class monitorManagerIntegrationServiceApp : public Application
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	/** Constructor */
	monitorManagerIntegrationServiceApp(char* name);

	/** Destructor */
	virtual ~monitorManagerIntegrationServiceApp();

	/** Creates devices */
	int run(int update=0); //Only for compatibility reasons with DCF Application interface class
	int run(int update=0, int corbaDebug=0);

	/** Destroy devices */
	int quit();


 //--------------------------------------------------
 // private section 
 //--------------------------------------------------
 private:

};

#endif  // _monitorManagerIntegrationServiceApp_h_
