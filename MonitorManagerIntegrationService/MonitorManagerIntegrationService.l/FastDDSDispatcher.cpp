#include "FastDDSDispatcher.h"


#include "DoubleValuePubSubTypes.h"

FastDDSDispatcher::FastDDSDispatcher()
{
    DomainParticipantQos participantQos;
    participantQos.name("Participant_publisher");
    participant_ = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);

    TypeSupport type_ (new DoubleValuePubSubType());
    type_.register_type(participant_);
}

void FastDDSDispatcher::addMagnitudMonitor(const std::string & monitor_name, 
                                const std::string & monitor_type_name)
{
    FastDDSMagnitudMonitor * monitor 
        = new FastDDSMagnitudMonitor(monitor_name,monitor_type_name,participant_);

    monitors[monitor_name]=monitor;
}

void FastDDSDispatcher::publish(const std::string & monitor_name, double value)
{
    monitors[monitor_name]->publish(value);
}
