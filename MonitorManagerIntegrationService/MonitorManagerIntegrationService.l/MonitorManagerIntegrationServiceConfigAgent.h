// Copyright (c) 2021 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _MonitorManagerIntegrationServiceConfigAgent_h_
#define _MonitorManagerIntegrationServiceConfigAgent_h_

// Includes
#include "MonitorManagerIntegrationServiceBase.h"
#include "Trace.h"
#include "ConfigAgent.h"

class MonitorManagerIntegrationService;

// Class used to configure MonitorManagerIntegrationServiceConfigAgent objects
class MonitorManagerIntegrationServiceConfigAgent : public ConfigAgent
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	// Constructor
	MonitorManagerIntegrationServiceConfigAgent(MonitorManagerIntegrationServiceBase* device, const int mode, TimerEngine* timer);

	// Destructor
	virtual ~MonitorManagerIntegrationServiceConfigAgent();

	// This method applies the stored configuration to the Device
	void applyProperties();
	
	// This method obtains the properties from the Device
	int readProperties();
	
	// Converts the Device properties to a Configuration
	void toConfiguration(CONFIG::Configuration& c);
	
	// Converts a Configuration to the Device format
	void fromConfiguration(const CONFIG::Configuration& c);
	

 //-----------------------------------------------------------------
 // protected section 
 //-----------------------------------------------------------------
 protected:
	
	Trace trace_;
	
	

 //--------------------------------------------------
 // private section 
 //--------------------------------------------------
 private:

	MonitorManagerIntegrationServiceBase* device_;
};

#endif // _MonitorManagerIntegrationServiceConfigAgent_h_ 

