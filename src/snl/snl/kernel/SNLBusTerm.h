// SPDX-FileCopyrightText: 2023 The Naja authors <https://github.com/xtofalex/naja/blob/main/AUTHORS>
//
// SPDX-License-Identifier: Apache-2.0

#ifndef __SNL_BUS_TERM_H_
#define __SNL_BUS_TERM_H_

#include <vector>

#include "SNLTerm.h"
#include "NajaCollection.h"

namespace naja { namespace SNL {

class SNLNet;
class SNLBusTermBit;

class SNLBusTerm final: public SNLTerm {
  public:
    friend class SNLDesign;
    using super = SNLTerm;

    static SNLBusTerm* create(
        SNLDesign* design,
        Direction direction,
        SNLID::Bit msb,
        SNLID::Bit lsb,
        const SNLName& name=SNLName());
    static SNLBusTerm* create(
        SNLDesign* design,
        SNLID::DesignObjectID id,
        Direction direction,
        SNLID::Bit msb,
        SNLID::Bit lsb,
        const SNLName& name=SNLName());

    SNLBitNet* getNet() const override { return nullptr; }
    void setNet(SNLNet* net) override;

    SNLDesign* getDesign() const override { return design_; }
    
    ///\return MSB (Most Significant Bit) or left hand side of the bus range.
    SNLID::Bit getMSB() const { return msb_; }
    ///\return LSB (Most Significant Bit) or right hand side of the bus range.
    SNLID::Bit getLSB() const { return lsb_; }
    SNLID::Bit getSize() const override;
    SNLBusTermBit* getBit(SNLID::Bit bit) const;
    SNLBusTermBit* getBitAtPosition(size_t position) const;
    NajaCollection<SNLBitTerm*> getBits() const override;
    NajaCollection<SNLBusTermBit*> getBusBits() const;

    SNLID::DesignObjectID getID() const override { return id_; }
    SNLID getSNLID() const override;
    size_t getFlatID() const override { return flatID_; }
    SNLName getName() const override { return name_; }
    bool isAnonymous() const override { return name_.empty(); }
    void setName(const SNLName& name) override;
    const char* getTypeName() const override;
    SNLTerm::Direction getDirection() const override { return direction_; }
    std::string getString() const override;
    std::string getDescription() const override;
    void debugDump(size_t indent, bool recursive=true, std::ostream& stream=std::cerr) const override;

  private:
    SNLBusTerm(
        SNLDesign* design,
        Direction direction,
        SNLID::Bit msb,
        SNLID::Bit lsb,
        const SNLName& name);
    SNLBusTerm(
        SNLDesign* design,
        SNLID::DesignObjectID id,
        Direction direction,
        SNLID::Bit msb,
        SNLID::Bit lsb,
        const SNLName& name);
    static void preCreate(const SNLDesign* design, const SNLName& name);
    static void preCreate(const SNLDesign* design, SNLID::DesignObjectID id, const SNLName& name);
    void createBits();
    void postCreate();
    void postCreateAndSetID();
    void destroyFromDesign() override;
    void commonPreDestroy();
    void preDestroy() override;

    void setID(SNLID::DesignObjectID id) override { id_ = id; }
    void setFlatID(size_t flatID) override { flatID_ = flatID; }

    using Bits = std::vector<SNLBusTermBit*>;

    SNLDesign*              design_;
    SNLID::DesignObjectID   id_;
    size_t                  flatID_   {0};
    SNLName                 name_     {};
    SNLTerm::Direction      direction_;
    SNLID::Bit              msb_;
    SNLID::Bit              lsb_;
    Bits                    bits_     {};
};

}} // namespace SNL // namespace naja

#endif // __SNL_BUS_TERM_H_
