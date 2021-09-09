// Copyright (c) 2021 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _MonitorManagerIntegrationService_h_
#define _MonitorManagerIntegrationService_h_

// Includes
#include "MonitorManagerIntegrationServiceBase.h"

/**
* 
*/
class MonitorManagerIntegrationService : public MonitorManagerIntegrationServiceBase
{
 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	//####################### CONSTRUCTOR & DESTRUCTOR #####################
	
	/** Device Constructor */
	MonitorManagerIntegrationService(string name);

	/** Destructor */
	virtual ~MonitorManagerIntegrationService();

	//########################## DEVICE METHODS ############################
	
	/** Connects the device with a CORBA and other GCS Services*/
	void  connect(string orbname, bool corbaDebug, unsigned threads,long priority,
	              bool mode  =Device::INTEGRATED,
	              bool update=Device::DO_NOT_UPDATE);
	
	/** Starting procedure */
	void  start();
	
	/** Initialization procedure */
	void  init();
	
	/** Halting procedure */
	void  halt();
	
	/** Shutdown procedure */
	void  shutdown();
	
	/** Reset procedure */
	void  reset();
	
	/** Test procedure */
	void  test();
	
	/** Stops all commands and goes to fault */
	void  abort();
	
	/** Report device info */
	char* report(short level);
	
	//####################### SPECIFIC METHODS #############################
	

 //-----------------------------------------------------------------
 // protected section 
 //-----------------------------------------------------------------
 protected:
};

#endif // _MonitorManagerIntegrationService_h_ 

