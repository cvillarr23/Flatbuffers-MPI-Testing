
#include <string>
#include "messages_generated.h"

class SynMPIComponent {
  public:
    SynMPIComponent(std::string name)
    : name_(name) {}

    // = 0 to define it as a pure virtual function
    virtual std::shared_ptr<flatbuffers::Offset<MessageTest::Message>> toFlatBuffer(flatbuffers::FlatBufferBuilder) = 0;
    virtual std::shared_ptr<flatbuffers::Offset<MessageTest::Message>> fromFlatBuffer(const MessageTest::Message* message) = 0;
  private:
    std::string name_;
    unsigned int num_updates_ = 0;

}
