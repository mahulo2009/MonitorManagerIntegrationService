// Copyright (c) 2021 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _MonitorManagerIntegrationServiceAdapter_h_
#define _MonitorManagerIntegrationServiceAdapter_h_

// Includes
#include <DeviceAdapter.h>
#include "MONITORMANAGERINTEGRATIONSERVICES.h"
#include "MonitorManagerIntegrationServiceBase.h"

class MonitorManagerIntegrationService;

//This class implements the IDL interface MonitorManagerIntegrationService_ifce
class MonitorManagerIntegrationServiceAdapter : public virtual POA_MONITORMANAGERINTEGRATIONSERVICE::MonitorManagerIntegrationService_ifce,  public DeviceAdapter
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	// Constructor
	MonitorManagerIntegrationServiceAdapter(MonitorManagerIntegrationServiceBase* device);

	// Destructor
	~MonitorManagerIntegrationServiceAdapter();


	//----------------------------------------------------------------------
	// Device specific operations
	//----------------------------------------------------------------------

	//----------------------------------------------------------------------
	// Monitorable attributes (device magnitudes) 
	//----------------------------------------------------------------------

	//----------------------------------------------------------------------
	// Configurable attributes (device properties) 
	//----------------------------------------------------------------------
	char* monitorsConfigurationPath();
	void  monitorsConfigurationPath(const char* value); 


	//--------------------------------------------------
	// private section 
	//--------------------------------------------------
	private:

	MonitorManagerIntegrationServiceBase* device_;
};

#endif // _MonitorManagerIntegrationServiceAdapter_h_ 

