// Copyright (c) 2021 Gran Telescopio Canarias, S.A. (GRANTECAN)
// All Rights Reserved

// Includes
#include "MonitorManagerIntegrationService.h"

#include "DoubleValue.h"
#include "DoubleArrayValue.h"
#include "Double2DArrayValue.h"
#include "EnumValue.h"
#include "StateValue.h"

//----------------------------------------------------------------------
// Device Constructor
//----------------------------------------------------------------------
MonitorManagerIntegrationService::MonitorManagerIntegrationService(string name)
: MonitorManagerIntegrationServiceBase(name)
{
	trace_.out("MonitorManagerIntegrationService constructor\n");
	className_ = "MonitorManagerIntegrationService";
}

//----------------------------------------------------------------------
// Device destructor
//----------------------------------------------------------------------
MonitorManagerIntegrationService::~MonitorManagerIntegrationService()
{
  trace_.out("destructor\n");
}

/************************************************************************
*************************************************************************
**                                                                     **
**       Virtual methods inherited from Device interface               **
**                                                                     **
*************************************************************************
************************************************************************/
	
//----------------------------------------------------------------------
// Connects device with GCS services
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::connect(string orbname, bool corbaDebug, unsigned threads, long priority, bool mode, bool update)
{
	trace_.out("MonitorManagerIntegrationService::connect()\n");
	MonitorManagerIntegrationServiceBase::connect(orbname, corbaDebug, threads, priority, mode, update);
	
	//## Add code as required
	
}

//----------------------------------------------------------------------
// Performs starting procedure: OFF-->STARTING-->ON
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::start()
{
	trace_.out("start()\n");
	
	try
	{
		goStarting_();
	
		// Configure device
		try
		{
			configure("Default");
		}
		catch(GCSException& ex)
		{
			//logError_("unable to configure device");
			throw;
		}
		
		createMonitors_();
		
		// ## Create other classes required for this Device		
		LoadYamlConfiguration();
		
		// ## Create other threads required for this Device
		
		goOn_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("MonitorManagerIntegrationService::start()"); 
		trace_.err("MonitorManagerIntegrationService::start() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs initialization procedure: ON-->INITIALISING-->READY
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::init()
{
	trace_.out("init()\n");
	
	try
	{
		goInitialising_();
		
		// ## Initialization procedure
		SubscribeMonitorList();
		
		cout << endl << "MonitorManagerIntegrationService READY!!!" << endl << endl;
		
		goIdle_();  // or goRunning_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("MonitorManagerIntegrationService::init()"); 
		trace_.err("MonitorManagerIntegrationService::init() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs halting procedure: READY-->HALTING-->ON
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::halt()
{
	trace_.out("halt()\n");
	
	try
	{
		goHalting_();
		
		// ## Halting procedure
		
		goOn_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("MonitorManagerIntegrationService::halt()"); 
		trace_.err("MonitorManagerIntegrationService::halt() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs shutdown procedure: ON-->SHUTTING_DOWN-->OFF
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::shutdown()
{
	trace_.out("shutdown()\n");
	
	try
	{
		goShuttingDown_();
		
		// ## Shutdown procedure
		
		goOff_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("MonitorManagerIntegrationService::shutdown()"); 
		trace_.err("MonitorManagerIntegrationService::shutdown() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs reset procedure: FAULT-->RESETTING-->ON
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::reset()
{
	trace_.out("reset()\n");
	
	try
	{
		goResetting_();
		
		// ## Resetting procedure
		
		goOn_();
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("MonitorManagerIntegrationService::reset()"); 
		trace_.err("MonitorManagerIntegrationService::reset() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs test procedure: only possible in ON state
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::test()
{
	trace_.out("test()\n");
	
	try
	{
		if (isOn()==FALSE)
		{
			//logError_("Test is only posible in ON state");
			throw WrongState(name_.c_str(),"Not in ON state. Unable to test");
		}
		
		// ## Test procedure
		
	}
	catch(GCSException& ex)
	{
		goFault_();
		ex.addToTrace("MonitorManagerIntegrationService::test()"); 
		trace_.err("MonitorManagerIntegrationService::test() exception - %s\n", ex.toString());
		throw;
	}
}

//----------------------------------------------------------------------
// Performs abort: interrupt any current operation and goes to FAULT
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::abort()
{
	trace_.out("abort()\n");
	
	// ## Abort procedure
	
	goFault_();
}

//----------------------------------------------------------------------
// Report device status: returns static memory, do not delete! 
//----------------------------------------------------------------------
char* MonitorManagerIntegrationService::report(short level)
{
	trace_.out("report(%d)\n",level);
	char* dev_reply = new char[DEVICE_REPORT_SIZE_];
	ostrstream ost(dev_reply, DEVICE_REPORT_SIZE_);
	memset(dev_reply,0,DEVICE_REPORT_SIZE_);
	
	// Generic Device info
	ost << MonitorManagerIntegrationServiceBase::report(level);
	
	// ## Add here your other monitors
	
	// ## Add more information if required
	
	return(dev_reply);
}

/************************************************************************
*************************************************************************
**                                                                     **
**                 Specific methods of this Device                     **
**                                                                     **
*************************************************************************
*************************************************************************
* All specific methods:                                                 *
* - Shall make a transition to RUNNING (even when is already running)   *
* - Shall make a transition to IDLE when the Device in really idle      *
* - Use ACE_Guard only for thread safe operations                       *
* - If an error is detected use logError_() & throw GCSException        *
* - If an alarm is detected use sendAlarm_()                            *
* - If a failure is detected use goFault_(method)                       *
* - Access to a DeviceDriver or aggregated Device can be required       *
************************************************************************/
	
/************************************************************************
*************************************************************************
**                                                                     **
**                        Specific private methods                     **
**                                                                     **
*************************************************************************
************************************************************************/
	
//----------------------------------------------------------------------
// LoadYamlConfiguration
//----------------------------------------------------------------------
void MonitorManagerIntegrationService::LoadYamlConfiguration()
{
	std::string configFile = monitorsConfigurationPath_;
	trace_.out("Loading yaml config file -> %s\n", configFile.c_str());
	
	try
	{
		YAML::Node myNode = YAML::LoadFile(configFile);
		YAML::Node monitors = myNode["Telemetry"];

		for(auto monitor : monitors)
		{

			std::string     key	= monitor.first.as<std::string>();
			MonitorListYaml m	= monitor.second.as<MonitorListYaml>();
						
			//Loading the unordered map
			subscribedMonitors_[key] = m;			
		}	

		trace_.out("Loading yaml config file -> %s\n", configFile.c_str());

	}
	catch(const YAML::ParserException& ex)
	{
		std::cout << "YAML parser file exception >> " << ex.what() << std::endl;
		throw;
	}
}

void MonitorManagerIntegrationService::SubscribeMonitorList()
{
	for (auto monitor : subscribedMonitors_)
	{
		auto&       key   = monitor.first;
		auto&       m     = monitor.second;
		const char* dev   = m.GetDeviceName();
		const char* mon   = m.GetMonitorName();
		const char* units = m.GetUnits();
		const char* type = m.GetType();

		try
		{
			trace_.out("[*] SUBSCRIBED MONITOR >> %s { %s, %s } \n\n", key.c_str(), dev, mon);

            //todo check if the type is correct
			dispatcher_.addMagnitudMonitor(key,type); 

			if ( type == std::string("EnumValue") ) {				
				subscribeToMagnitudeChanges(dev,mon);	
			} else if ( type == std::string("StateValue") ) {
				subscribeToStateChanges(dev);	
			} else {
				subscribeToDataBlocks(dev,mon);	
			}			
		}
		catch(GCSException& e)
		{
			e.addToTrace("TelemetryModuleNRT::SubscribeMonitorList()");
			//logError_("TelemetryModuleNRT::SubscribeMonitorList() exception - %s\n", e.toString());
			trace_.err("TelemetryModuleNRT::SubscribeMonitorList() exception - %s\n", e.toString());
			std::cout << "TelemetryModuleNRT::SubscribeMonitorList()" << endl;
			throw;
		}
		catch (CORBA::Exception& ex)
		{
			TimeValue now = TimeService::getTAI(); // get time of the system

			GCSException gcsex = DException::mapCORBAException(const_cast<CORBA::Exception&>(ex));
		}
	}
}

void MonitorManagerIntegrationService::receiveMonitorScalar_(const char* componentName,const char* magnitudeName,long time_stamp, double value)
{
    trace_.out("receiveMonitorScalar [%s,%s,%ld,%f]\n",componentName,magnitudeName,time_stamp,value);

	DoubleValue doubleSample;
	doubleSample.componentName(componentName);
	doubleSample.magnitudeName(magnitudeName);
	doubleSample.time_stamp(time_stamp);
	doubleSample.value(value);
	
	std::string key = std::string(componentName)+"/"+std::string(magnitudeName);
	std::replace(key.begin(),key.end(),'/','.');

	dispatcher_.publish(key,doubleSample);
}

void MonitorManagerIntegrationService::receiveMonitorArray_(const char* componentName,const char* magnitudeName,long time_stamp, const std::vector<double> & value)
{
    trace_.out("receiveMonitorArray [%s,%s,%ld]\n",componentName,magnitudeName,time_stamp);

	DoubleArrayValue doubleArraySample;
	doubleArraySample.componentName(componentName);
	doubleArraySample.magnitudeName(magnitudeName);
	doubleArraySample.time_stamp(time_stamp);
	doubleArraySample.value(value);
	
	std::string key = std::string(componentName)+"/"+std::string(magnitudeName);
	std::replace(key.begin(),key.end(),'/','.');

	dispatcher_.publish(key,doubleArraySample);	
}

void MonitorManagerIntegrationService::receiveMonitor2DArray_(const char* componentName,const char* magnitudeName,long time_stamp, const std::vector< std::vector<double> > & value)
{
    trace_.out("receiveMonitor2DArray [%s,%s,%ld]\n",componentName,magnitudeName,time_stamp);

	Double2DArrayValue doubleArraySample;
	
	doubleArraySample.componentName(componentName);
	doubleArraySample.magnitudeName(magnitudeName);
	doubleArraySample.time_stamp(time_stamp);
	doubleArraySample.value(value);
	
	std::string key = std::string(componentName)+"/"+std::string(magnitudeName);
	std::replace(key.begin(),key.end(),'/','.');

	dispatcher_.publish(key,doubleArraySample);	
}

void MonitorManagerIntegrationService::receiveMonitor(const char* componentName,const char* magnitudeName,long time_stamp, double value)
{
	receiveMonitorScalar_(componentName,magnitudeName,time_stamp, value);
}
void MonitorManagerIntegrationService::receiveMonitor(const char* componentName,const char* magnitudeName,long time_stamp, float value)
{	
	receiveMonitorScalar_(componentName,magnitudeName,time_stamp, value);
}
void MonitorManagerIntegrationService::receiveMonitor(const char* componentName,const char* magnitudeName,long time_stamp, long value)
{
	receiveMonitorScalar_(componentName,magnitudeName,time_stamp, value);
}
void MonitorManagerIntegrationService::receiveMonitor(const char* componentName,const char* magnitudeName,long time_stamp, short value)
{
	receiveMonitorScalar_(componentName,magnitudeName,time_stamp, value);
}
void MonitorManagerIntegrationService::receiveMonitor(const char* componentName,const char* magnitudeName,long time_stamp, unsigned char value)
{
	receiveMonitorScalar_(componentName,magnitudeName,time_stamp, value);
}
void MonitorManagerIntegrationService::receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, DoubleArray1D& value)
{
	std::vector<double> values;
	for (auto v : value) 	
		values.push_back(v);
	
	receiveMonitorArray_(componentName,magnitudeName,time_stamp, values);
}
void MonitorManagerIntegrationService::receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, FloatArray1D& value)
{
	std::vector<double> values;
	for (auto v : value) 	
		values.push_back(v);
	
	receiveMonitorArray_(componentName,magnitudeName,time_stamp, values);

}
void MonitorManagerIntegrationService::receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, LongArray1D& value)
{
	std::vector<double> values;
	for (auto v : value) 	
		values.push_back(v);
	
	receiveMonitorArray_(componentName,magnitudeName,time_stamp, values);

}
void MonitorManagerIntegrationService::receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, ShortArray1D& value)
{
	std::vector<double> values;
	for (auto v : value) 	
		values.push_back(v);
	
	receiveMonitorArray_(componentName,magnitudeName,time_stamp, values);

}
void MonitorManagerIntegrationService::receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, OctetArray1D& value)
{
	std::vector<double> values;
	for (auto v : value) 	
		values.push_back(v);
	
	receiveMonitorArray_(componentName,magnitudeName,time_stamp, values);
}

void MonitorManagerIntegrationService::receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, DoubleArray2D& value)
{
	//todo due a bug in DCF this method is not called.
	std::vector< std::vector<double> > values;
	for(int i =0;i< value.height();i++)
	{
		std::vector<double> innerValues;
		for(int j =0;j< value.width();j++)
		{
			innerValues.push_back(value[i][j]);
		}
		values.push_back(innerValues);
	}
	receiveMonitor2DArray_(componentName,magnitudeName,time_stamp, values);
}

void MonitorManagerIntegrationService::receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, FloatArray2D& value)
{
	//todo due a bug in DCF this method is not called.
	std::vector< std::vector<double> > values;
	for(int i =0;i< value.height();i++)
	{
		std::vector<double> innerValues;
		for(int j =0;j< value.width();j++)
		{
			innerValues.push_back(value[i][j]);
		}
		values.push_back(innerValues);
	}
	receiveMonitor2DArray_(componentName,magnitudeName,time_stamp, values);
}

void MonitorManagerIntegrationService::receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, LongArray2D& value)
{
	//todo due a bug in DCF this method is not called.
	std::vector< std::vector<double> > values;
	for(int i =0;i< value.height();i++)
	{
		std::vector<double> innerValues;
		for(int j =0;j< value.width();j++)
		{
			innerValues.push_back(value[i][j]);
		}
		values.push_back(innerValues);
	}
	receiveMonitor2DArray_(componentName,magnitudeName,time_stamp, values);
}

void MonitorManagerIntegrationService::receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, ShortArray2D& value)
{
	//todo due a bug in DCF this method is not called.
	std::vector< std::vector<double> > values;
	for(int i =0;i< value.height();i++)
	{
		std::vector<double> innerValues;
		for(int j =0;j< value.width();j++)
		{
			innerValues.push_back(value[i][j]);
		}
		values.push_back(innerValues);
	}
	receiveMonitor2DArray_(componentName,magnitudeName,time_stamp, values);

}

void MonitorManagerIntegrationService::receiveArrayMonitor(const char* componentName,const char* magnitudeName,long time_stamp, OctetArray2D& value)
{
	//todo due a bug in DCF this method is not called.
	std::vector< std::vector<double> > values;
	for(int i =0;i< value.height();i++)
	{
		std::vector<double> innerValues;
		for(int j =0;j< value.width();j++)
		{
			innerValues.push_back(value[i][j]);
		}
		values.push_back(innerValues);
	}
	receiveMonitor2DArray_(componentName,magnitudeName,time_stamp, values);
}

void MonitorManagerIntegrationService::receiveMagnitudeChange(const char* componentName,const char* magnitudeName,long time_stamp, long value)
{
	EnumValue sample;	//todo change statue for enum
	sample.componentName(componentName);
	sample.magnitudeName(magnitudeName);
	sample.time_stamp(time_stamp);
	sample.value(value);
	
	std::string key = std::string(componentName)+"/"+std::string(magnitudeName);
	std::replace(key.begin(),key.end(),'/','.');

	dispatcher_.publish(key,sample);		
}

void MonitorManagerIntegrationService::receiveStateChange(const char* componentName, long time_stamp, const char* value)
{
	StateValue sample;	//todo change statue for enum
	sample.componentName(componentName);
	sample.time_stamp(time_stamp);
	sample.value(value);
	
	std::string key = std::string(componentName);
	dispatcher_.publish(key,sample);	
}
