#pragma once

#include "base_event_data.h"
#include "../actors/actor.h"

class EvtData_Modified_Render_Component : public BaseEventData {
    ActorId m_id;

public:
    static const EventTypeId sk_EventType = 0x80fe9766;
    static const std::string sk_EventName;

    EvtData_Modified_Render_Component();
    EvtData_Modified_Render_Component(ActorId id);

    virtual EventTypeId VGetEventType() const override;
    virtual void VSerialize(std::ostream& out) const override;
    virtual void VDeserialize(std::istream& in) override;
    virtual IEventDataPtr VCopy() const override;
    virtual const std::string& GetName() const override;

    ActorId GetActorId() const;

    friend std::ostream& operator<<(std::ostream& os, const EvtData_Modified_Render_Component& evt);
};