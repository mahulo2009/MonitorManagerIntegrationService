// Copyright (c) 2021 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include "MonitorManagerIntegrationServiceConfigAgent.h"

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
MonitorManagerIntegrationServiceConfigAgent::MonitorManagerIntegrationServiceConfigAgent(MonitorManagerIntegrationServiceBase* device, const int mode, TimerEngine* timer)
: ConfigAgent(device->name(),device->className(),mode,timer),trace_(device->name())
{
	device_ = device;

	// Assign default values to properties so they never contain garbage
	monitorsConfigurationPath_ = "CARD1";
}

//----------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------
MonitorManagerIntegrationServiceConfigAgent::~MonitorManagerIntegrationServiceConfigAgent()
{
}

//----------------------------------------------------------------------
// applyProperties: applies the stored configuration to the Device
//----------------------------------------------------------------------
void MonitorManagerIntegrationServiceConfigAgent::applyProperties()
{
	trace_.out("MonitorManagerIntegrationServiceConfigAgent::applyProperties()");
	
	try
	{
	
		// Apply properties one by one
		device_->monitorsConfigurationPath(this->monitorsConfigurationPath_);
	}
	catch (GCSException& ex)
	{
		ex.addToTrace("MonitorManagerIntegrationServiceConfigAgent::applyProperties");
		throw;
	}
}

//----------------------------------------------------------------------
// readProperties: obtains the property values from the Device
//----------------------------------------------------------------------
int MonitorManagerIntegrationServiceConfigAgent::readProperties()
{
	trace_.out("MonitorManagerIntegrationServiceConfigAgent::readProperties()");
	
	try
	{
	
		// Read properties one by one
		this->monitorsConfigurationPath_  = device_->monitorsConfigurationPath();
	}
	catch (GCSException& ex)
	{
		ex.addToTrace("MonitorManagerIntegrationServiceConfigAgent::readProperties");
		throw;
	}
	return(0);
}

//----------------------------------------------------------------------
// toConfiguration: Converts the Device properties to a Configuration
//----------------------------------------------------------------------
void MonitorManagerIntegrationServiceConfigAgent::toConfiguration(CONFIG::Configuration& c)
{
	trace_.out("MonitorManagerIntegrationServiceConfigAgent::toConfiguration()");
	
	try
	{
	
		// Let ConfigAgent base class do the common stuff
		this->ConfigAgent::toConfiguration(c);

		addProperty(c, "monitorsConfigurationPath", monitorsConfigurationPath_);
	}
	catch (GCSException& ex)
	{
		ex.addToTrace("MonitorManagerIntegrationServiceConfigAgent::toConfiguration");
		throw;
	}
}

//----------------------------------------------------------------------
// fromConfiguration: Converts the configuration to the Device format
//----------------------------------------------------------------------
void MonitorManagerIntegrationServiceConfigAgent::fromConfiguration(const CONFIG::Configuration& c)
{
	trace_.out("MonitorManagerIntegrationServiceConfigAgent::fromConfiguration()");
	
	try
	{
	
		// Let ConfigAgent base class do the common stuff
		this->ConfigAgent::fromConfiguration(c);

		extractProperty(c, "monitorsConfigurationPath", monitorsConfigurationPath_);
	}
	catch (GCSException& ex)
	{
		ex.addToTrace("MonitorManagerIntegrationServiceConfigAgent::fromConfiguration");
		throw;
	}
}

