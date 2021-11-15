#include "SNLBitNet.h"

namespace SNL {

void SNLBitNet::preCreate() {
  super::preCreate();
}

void SNLBitNet::postCreate() {
  super::postCreate();
}

void SNLBitNet::preDestroy() {
  super::preDestroy();
}

void SNLBitNet::addComponent(SNLNetComponent* component) {
  //FIXME: should assert that component is not in bitNet ? not connected hook ?
  components_.insert(*component);
}

void SNLBitNet::removeComponent(SNLNetComponent* component) {
  components_.erase(*component);
}

}
