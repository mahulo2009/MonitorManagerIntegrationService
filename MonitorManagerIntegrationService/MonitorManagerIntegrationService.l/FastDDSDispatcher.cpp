#include "FastDDSDispatcher.h"


#include "DoubleValuePubSubTypes.h"
#include "DoubleArrayValuePubSubTypes.h"
#include "Double2DArrayValuePubSubTypes.h"
#include "EnumValuePubSubTypes.h"
#include "StateValuePubSubTypes.h"

FastDDSDispatcher::FastDDSDispatcher()
{
    DomainParticipantQos participantQos;
    participantQos.name("Participant_publisher");
    participant_ = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);

    //todo all participant register all types?
    TypeSupport type1_ (new DoubleValuePubSubType());
    TypeSupport type2_ (new DoubleArrayValuePubSubType()); 
    TypeSupport type3_ (new Double2DArrayValuePubSubType()); 
    TypeSupport type4_ (new EnumValuePubSubType()); 
    TypeSupport type5_ (new StateValuePubSubType()); 

    //todo
    type1_.register_type(participant_);
    type2_.register_type(participant_); 
    type3_.register_type(participant_); 
    type4_.register_type(participant_); 
    type5_.register_type(participant_); 
}

void FastDDSDispatcher::addMagnitudMonitor(const std::string & monitor_name, 
                                const std::string & monitor_type_name)
{
    FastDDSMagnitudMonitor * monitor 
        = new FastDDSMagnitudMonitor(monitor_name,monitor_type_name,participant_);
    
    std::cout << "monitor_name " << monitor_name << std::endl;

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

void FastDDSDispatcher::publish(const std::string & monitor_name, EnumValue &value)
{
    monitors[monitor_name]->publish(value);
}

void FastDDSDispatcher::publish(const std::string & monitor_name, StateValue &value)
{
    monitors[monitor_name]->publish(value);
}
