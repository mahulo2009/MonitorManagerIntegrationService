// Copyright (c) 2021 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _MonitorManagerIntegrationServiceBase_h_
#define _MonitorManagerIntegrationServiceBase_h_

// Includes
#include <Device.h>
#include <ConcreteArrays.h>

/**
* This class is automaticaly regenerated when devBuilder-gev is invoked,
* and therefore it should not be edited by the developer.
*/
class MonitorManagerIntegrationServiceBase : public Device
{
//-----------------------------------------------------------------
// public section 
//-----------------------------------------------------------------
 public:

	//######################## SPECIFIC TYPES ##############################
	
	//####################### CONSTRUCTOR & DESTRUCTOR #####################
	
	/** Device Constructor */
	MonitorManagerIntegrationServiceBase(string name);

	/** Destructor */
	virtual ~MonitorManagerIntegrationServiceBase();

	//########################## DEVICE METHODS ############################
	
	/** Connects the device with a CORBA and other GCS Services*/
	virtual void  connect(string orbname, bool corbaDebug, unsigned threads, long priority,
	                      bool mode      =Device::INTEGRATED,
	                      bool update    =Device::DO_NOT_UPDATE);
	
	/** Starting procedure */
	virtual void  start();
	
	/** Initialization procedure */
	virtual void  init();
	
	/** Halting procedure */
	virtual void  halt();
	
	/** Shutdown procedure */
	virtual void  shutdown();
	
	/** Reset procedure */
	virtual void  reset();
	
	/** Restore procedure */
	virtual void  restore();
	
	/** Test procedure */
	virtual void  test();
	
	/** Stops all commands and goes to fault */
	virtual void  abort();
	
	/** Report device info */
	virtual char* report(short level);
	
	/** Reports device version */
	const char* version();
	
	//####################### SPECIFIC METHODS #############################
	
	//####################### MONITORS #####################################
	
	//####################### PROPERTIES ##################################

	/**
	* String property
	*
	* @property:
	* @description:Monitor Configuration Path
	* @default:CARD1
	* @maximum:""
	* @minimum:""
	* @units:None
	*/
	virtual const char* monitorsConfigurationPath();
	virtual void monitorsConfigurationPath(const char* new_value); 
	
	
//-----------------------------------------------------------------
// protected section 
//-----------------------------------------------------------------
protected:

	bool corbaDebug_; ///<Activate/deactivate corba debugging
	bool update_    ; ///<Activate/deactivate profile updating
	
	/// Method to create monitors
	void createMonitors_();

//-----------------------------------------------------------------
// private section 
//-----------------------------------------------------------------
 private:
	
	// Modifiable attributes (device properties)
	std::string monitorsConfigurationPath_; ///<String property
};

#endif // _MonitorManagerIntegrationServiceBase_h_ 

