#include "SynMPIComponent.h"
#include "Vehicle.h"

class SynVehComponent : public SynMPIComponent {
  private:
    Vehicle vehicle_;
  public:
    SynVehComponent(std::string name, Vehicle vehicle)
    : SynMPIComponent(name), vehicle_(vehicle) {}

    std::shared_ptr<flatbuffers::Offset<SynMPIMessage>> toFlatBuffer(
      flatbuffers::FlatBufferBuilder& builder_, rank) {

        std::shared_ptr<flatbuffers::Offset<SynMPIComponent::Vector>> posVector = SynMPIMessage::CreateVector(
          builder_, vehicle_.getX(), vehicle_.getY(), vehicle_.getZ()
        );

        std::shared_ptr<flatbuffers::Offset<SynMPIComponent::PositionUpdate>> veh_message = SynMPIMessage::CreateVehiclePosition(
          builder_, vehicle_.getRank(), posVector.union()
        );

        std::shared_ptr<flatbuffers::Offset<SynMPIComponent::Message>> ret_message =
          std::make_shared<flatbuffers::Offset<SynMPIMessage::Message>>(SynMPIMessage::CreateMessage(
            builder_, SynMPIMessage::Type_VehiclePosition, veh_message.Union(), builder_.CreateString("VEH_POS_UPDATE")
          ));
        return ret_message;
      }

    void fromFlatBuffer(const SynMPIMessage::Message* message) {
      const SynMPIMessage::VehiclePosition* veh_pos =
        static_cast<const SynMPIMessage::VehiclePosition*>(message->message());

      const SynMPIMessage::Vector* pos =
        static_cast<const SynMPIMessage::Vector*>(veh_pos->position());

      vehicle_.setPos(pos->x(), pos->y(), pos->z());
    }
}
