#ifndef __SNL_INSTANCE_H_
#define __SNL_INSTANCE_H_

#include <vector>
#include <boost/intrusive/set.hpp>

#include "SNLDesignObject.h"
#include "SNLID.h"
#include "SNLName.h"
#include "SNLCollection.h"

namespace SNL {

class SNLInstTerm;
class SNLSharedPath;

class SNLInstance final: public SNLDesignObject {
  public:
    friend class SNLDesign;
    friend class SNLSharedPath;
    friend class SNLPath;
    using super = SNLDesignObject;
    using SNLInstanceInstTerms = std::vector<SNLInstTerm*>; 

    static SNLInstance* create(SNLDesign* design, SNLDesign* model, const SNLName& name=SNLName());

    SNLDesign* getDesign() const override { return design_; }
    SNLDesign* getModel() const { return model_; }

    SNLID::DesignObjectID getID() const { return id_; }
    SNLID getSNLID() const override;
    SNLName getName() const { return name_; }
    bool isAnonymous() const override { return name_.empty(); }
    constexpr const char* getTypeName() const override;
    std::string getString() const override;
    std::string getDescription() const override;
    Card* getCard() const override;

    SNLCollection<SNLInstTerm*> getInstTerms() const;
  private:
    static void preCreate(SNLDesign* design, const SNLName& name);
    void postCreate();
    void commonPreDestroy();
    void destroyFromDesign();
    void destroyFromModel();
    void preDestroy() override;
    SNLSharedPath* getSharedPath(const SNLSharedPath* sharedPath) const { return nullptr; }

    SNLInstance(SNLDesign* design, SNLDesign* model, const SNLName& name);

    SNLDesign*                          design_                   {nullptr};
    SNLDesign*                          model_                    {nullptr};
    SNLID::InstanceID                   id_;
    SNLName                             name_                     {};
    SNLInstanceInstTerms                instTerms_                {};
    boost::intrusive::set_member_hook<> designInstancesHook_      {};
    boost::intrusive::set_member_hook<> designSlaveInstancesHook_ {};
};

}

#endif /* __SNL_INSTANCE_H_ */ 
