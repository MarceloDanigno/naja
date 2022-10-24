/*
 * Copyright 2022 The Naja Authors.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __SNL_NET_COMPONENT_MACROS_H_
#define __SNL_NET_COMPONENT_MACROS_H_

#define NET_COMPONENT_SET_NET(TYPE) \
void TYPE::setNet(SNLBitNet* net) { \
  if (net and net->getDesign() not_eq getDesign()) { \
    std::string reason = "Impossible setNet call with incompatible designs: "; \
    reason += getString() + " is in " + getDesign()->getString() + " while "; \
    reason += net->getString() + " is in " + net->getDesign()->getString(); \
    throw SNLException(reason); \
  } \
  if (net_ not_eq net) { \
    if (net_) { \
      net_->removeComponent(this); \
    } \
    net_ = net; \
    if (net_) { \
      net->addComponent(this); \
    } \
  } \
}


#endif // __SNL_NET_COMPONENT_MACROS_H_