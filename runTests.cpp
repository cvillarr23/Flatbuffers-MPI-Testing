#include "messages_generated.h"
#include <iostream>

#define HEARTBEAT 5.0

uint32_t getSize(flatbuffers::Offset<AgentFlatbuf::State> buf, flatbuffers::FlatBufferBuilder &_fbb) {
  _fbb.Finish(buf);
  _fbb.GetBufferPointer();
  uint32_t size = _fbb.GetSize();
  return size;
}

int main(int argc, char* argv[]) {
  flatbuffers::FlatBufferBuilder _fbb;

  flatbuffers::Offset<AgentFlatbuf::Vector> vec = AgentFlatbuf::CreateVector(_fbb, 0, 1, 2);
  // std::cout << vec.getSize() << std::endl;

  flatbuffers::Offset<AgentFlatbuf::Quaternion> rot = AgentFlatbuf::CreateQuaternion(_fbb, 1.0, 2.0, 3.0, 4.0);
  // std::cout << rot.getSize() << std::endl;

  flatbuffers::Offset<AgentFlatbuf::Orientation> ori = AgentFlatbuf::CreateOrientation(_fbb, vec, rot);
  // std::cout << ori.getSize() << std::endl;

  flatbuffers::Offset<AgentFlatbuf::State> state = AgentFlatbuf::CreateState(_fbb, 2.1, ori, ori, ori, ori, ori);

  // AgentFlatbuf::StateBuilder builder_(_fbb);
  // std::cout << getSize(state, _fbb) << std::endl;
  //size is 160

  return 0;
}
