// Copyright (c) 2021 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

#ifndef _MonitorManagerIntegrationService_h_
#define _MonitorManagerIntegrationService_h_

// Includes
#include "MonitorManagerIntegrationServiceBase.h"
#include "MonitorListYaml.cpp"
#include "FastDDSDispatcher.h"
#include <map>
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

 	virtual void receiveMonitor(const char* componentName,const char* magnitudeName,long time_stamp, double value);
	virtual void receiveMonitor(const char* componentName,const char* magnitudeName,long time_stamp, float value);
	virtual void receiveMonitor(const char* componentName,const char* magnitudeName,long time_stamp, long value);
	virtual void receiveMonitor(const char* componentName,const char* magnitudeName,long time_stamp, short value);
	virtual void receiveMonitor(const char* componentName,const char* magnitudeName,long time_stamp, unsigned char value);
	virtual void receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, DoubleArray1D& value);
	virtual void receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, FloatArray1D& value);
	virtual void receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, LongArray1D& value);
	virtual void receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, ShortArray1D& value);
	virtual void receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, OctetArray1D& value);
	virtual void receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, DoubleArray2D& value);
	virtual void receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, FloatArray2D& value);
	virtual void receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, LongArray2D& value);
	virtual void receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, ShortArray2D& value);
	virtual void receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, OctetArray2D& value);
	virtual void receiveMagnitudeChange(const char* componentName,const char* magnitudeName,long time_stamp, long value);
	virtual void receiveStateChange(const char* componentName, long time_stamp, const char* value);
	
 private:

 	using monitorsMap = std::map<std::string,MonitorListYaml>;
	monitorsMap                         subscribedMonitors_;
	FastDDSDispatcher dispatcher_;

	void LoadYamlConfiguration();
	void SubscribeMonitorList();
};

#endif // _MonitorManagerIntegrationService_h_ 

