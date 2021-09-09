// Copyright (c) 2021 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _VxLCU_h_
#define _VxLCU_h_

// GCS Includes
#include "LCU.h"
#include "CommandLine.h"

// Forward declarations
class monitorManagerIntegrationServiceApp;

/** Implements the LCU interface */
class VxLCU : public LCU
{

 //--------------------------------------------------
 // public section 
 //--------------------------------------------------
 public:

	/** Constructor */
	VxLCU(char* name);

	/** Destructor */
	virtual ~VxLCU();

	/** Start LCU services and applications */
	int start(int update=0); //Only for reasons of compatibility with DCF LCU interface class
	int start(int update=0, int corbaDebug=0);

	/** Stop LCU services and applications */
	int stop();


 //--------------------------------------------------
 // private section 
 //--------------------------------------------------
 private:

	monitorManagerIntegrationServiceApp* monitorManagerIntegrationServiceApp_;
};

#endif  // _VxLCU_h_
