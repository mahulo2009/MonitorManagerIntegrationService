#ifndef _MonitorListYaml_h_
#define _MonitorListYaml_h_

// yaml-cpp libraries
#include "yaml-cpp/yaml.h"
#include "yaml-cpp/parser.h"
#include "yaml-cpp/exceptions.h"

struct MonitorListYaml
{ 
public:
	std::string deviceName_;
   	std::string monitorName_;
   	std::string units_;
	std::string type_;
	
	// constructors
	MonitorListYaml()
	{
	};

	MonitorListYaml(const char* Device, const char* Name, const char* Units,const char* Type)
    : deviceName_(Device),
		monitorName_(Name),
    	units_(Units),
		type_(Type)
	{
	};

	//destructors
	~MonitorListYaml()
	{
	};

	//Getters
	const char* GetDeviceName() const { return this->deviceName_.c_str(); };
	const char* GetMonitorName() const { return this->monitorName_.c_str(); };
	const char* GetUnits() const { return this->units_.c_str(); };
	const char* GetType() const { return this->type_.c_str(); };

	//Setters
	void SetUnits(const char* value) { this->units_ = value; };
};

namespace YAML 
{
	template<>
	struct convert<MonitorListYaml> 
	{
		static bool decode(const YAML::Node& node, MonitorListYaml& mon) 
		{
			mon.deviceName_	 = node["device" ].as<std::string>();
			mon.monitorName_ = node["monitor"].as<std::string>();
			mon.units_    	 = node["units"  ].as<std::string>();
			mon.type_    	 = node["type"  ].as<std::string>();

			return true;
		};
	};
};

#endif // _MonitorListYaml_h_