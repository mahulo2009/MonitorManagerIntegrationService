#include "FastDDSMagnitudMonitor.h"

#include "DoubleValuePubSubTypes.h"

FastDDSMagnitudMonitor::FastDDSMagnitudMonitor(const std::string & monitor_name, 
                                                const std::string & monitor_type_name,
                                                DomainParticipant *participant) : participant_(participant)
{
    Topic*  topic_ = participant_->create_topic(monitor_name, monitor_type_name, TOPIC_QOS_DEFAULT);
    Publisher* publisher_ = participant_->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr); //todo register matches
    writer_ = publisher_->create_datawriter(topic_, DATAWRITER_QOS_DEFAULT, nullptr);
}

void FastDDSMagnitudMonitor::publish(DoubleValue &value)
{
    writer_->write(&value);
}

void FastDDSMagnitudMonitor::publish(DoubleArrayValue &value)
{
    writer_->write(&value);
}

void FastDDSMagnitudMonitor::publish(Double2DArrayValue &value)
{
    writer_->write(&value);
}

void FastDDSMagnitudMonitor::publish(EnumValue &value)
{
    writer_->write(&value);
}    
void FastDDSMagnitudMonitor::publish(StateValue &value)
{
    writer_->write(&value);
}
