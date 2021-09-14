#ifndef _FastDDS_Dispacher_h_
#define _FastDDS_Dispacher_h_

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>

using namespace eprosima::fastdds::dds;

#include "FastDDSMagnitudMonitor.h"
#include <map>
#include "DoubleValue.h"
#include "DoubleArrayValue.h"
#include "Double2DArrayValue.h"
#include "EnumValue.h"
#include "StateValue.h"

	
class FastDDSDispatcher
{ 
public:
    FastDDSDispatcher();

    void addMagnitudMonitor(const std::string & monitor_name, 
                                const std::string & monitor_type_name);

    void publish(const std::string & monitor_name, DoubleValue &value);
    void publish(const std::string & monitor_name, DoubleArrayValue &value);
    void publish(const std::string & monitor_name, Double2DArrayValue &value);
    void publish(const std::string & monitor_name, EnumValue &value);
    void publish(const std::string & monitor_name, StateValue &value);


private:
    DomainParticipant *participant_;   

    std::map<std::string,FastDDSMagnitudMonitor *> monitors;  
};

#endif // _FastDDS_Dispacher_h_
