// Copyright (c) 2021 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include <IDL_Adapters_DGT.h>

#include "MonitorManagerIntegrationServiceAdapter.h"
//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
MonitorManagerIntegrationServiceAdapter::MonitorManagerIntegrationServiceAdapter(MonitorManagerIntegrationServiceBase* device)
: DeviceAdapter(device)
{
	device_=device;
}

//----------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------
MonitorManagerIntegrationServiceAdapter::~MonitorManagerIntegrationServiceAdapter()
{
}


//----------------------------------------------------------------------
// Device specific operations
//----------------------------------------------------------------------


//----------------------------------------------------------------------
// Monitorable attributes (device magnitudes) 
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Configurable attributes (device properties) 
//----------------------------------------------------------------------


/**************************************************************
 *                private methods                             *
 **************************************************************/

