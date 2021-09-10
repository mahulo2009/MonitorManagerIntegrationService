#ifndef _FastDDS_MagnitudMonitor_h_
#define _FastDDS_MagnitudMonitor_h_

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>

using namespace eprosima::fastdds::dds;

#include "DoubleValue.h"
	
class FastDDSMagnitudMonitor
{ 
public:
    FastDDSMagnitudMonitor(const std::string & monitor_name, 
                            const std::string & monitor_type_name,
                            DomainParticipant *participant);

    void publish(DoubleValue &value);
    
private:

    DomainParticipant *participant_;
    Topic*      topic_;
    Publisher*  publisher_;
    DataWriter* writer_;
    std::thread th_;  
};

#endif // _FastDDS_Dispacher_h_