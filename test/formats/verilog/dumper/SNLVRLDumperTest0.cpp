#include "gtest/gtest.h"

#include <filesystem>
#include <fstream>

#include "SNLVRLDumper.h"

#include "SNLUniverse.h"
#include "SNLDB.h"
#include "SNLScalarTerm.h"
#include "SNLBusTerm.h"

using namespace SNL;

class SNLVRLDumperTest0: public ::testing::Test {
  protected:
    void SetUp() override {
      SNLUniverse* universe = SNLUniverse::create();
      db_ = SNLDB::create(universe);
      SNLLibrary* library = SNLLibrary::create(db_, SNLName("MYLIB"));
      SNLDesign* design = SNLDesign::create(library, SNLName("design"));
      SNLScalarTerm::create(design, SNLTerm::Direction::Input, SNLName("i0"));
      SNLBusTerm::create(design, SNLTerm::Direction::Input, 31, 0, SNLName("i1"));
      SNLScalarTerm::create(design, SNLTerm::Direction::Output, SNLName("o"));
      SNLDesign* model = SNLDesign::create(library, "model");
      SNLInstance* instance1 = SNLInstance::create(design, model, "instance1");
      SNLInstance* instance2 = SNLInstance::create(design, model, "instance2");
    }
    void TearDown() override {
      SNLUniverse::get()->destroy();
    }
  protected:
    SNLDB*      db_;
};

TEST_F(SNLVRLDumperTest0, test0) {
  auto lib = db_->getLibrary("MYLIB");  
  ASSERT_TRUE(lib);
  auto top = lib->getDesign("design");
  ASSERT_TRUE(top);
  std::filesystem::path outPath("test.v");
  std::ofstream ofs(outPath, std::ofstream::out);
  SNLVRLDumper dumper;
  dumper.dumpDesign(top, ofs);
  ofs.close();
}
