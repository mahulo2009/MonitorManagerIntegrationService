#include "FastDDSDispatcher.h"


#include "DoubleValuePubSubTypes.h"
#include "DoubleArrayValuePubSubTypes.h"
#include "Double2DArrayValuePubSubTypes.h"

FastDDSDispatcher::FastDDSDispatcher()
{
    DomainParticipantQos participantQos;
    participantQos.name("Participant_publisher");
    participant_ = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);

    TypeSupport type1_ (new DoubleValuePubSubType());
    TypeSupport type2_ (new DoubleArrayValuePubSubType()); //todo all participant register all types?
    TypeSupport type3_ (new Double2DArrayValuePubSubType()); //todo all participant register all types?
    type1_.register_type(participant_);
    type2_.register_type(participant_); //todo
    type3_.register_type(participant_); //todo
}

void FastDDSDispatcher::addMagnitudMonitor(const std::string & monitor_name, 
                                const std::string & monitor_type_name)
{
    FastDDSMagnitudMonitor * monitor 
        = new FastDDSMagnitudMonitor(monitor_name,monitor_type_name,participant_);

    monitors[monitor_name]=monitor;
}

void FastDDSDispatcher::publish(const std::string & monitor_name, DoubleValue &value)
{
    //todo maybe it is templatizable
    monitors[monitor_name]->publish(value);
}

void FastDDSDispatcher::publish(const std::string & monitor_name, DoubleArrayValue &value)
{
    monitors[monitor_name]->publish(value);
}

void FastDDSDispatcher::publish(const std::string & monitor_name, Double2DArrayValue &value)
{
    monitors[monitor_name]->publish(value);
}