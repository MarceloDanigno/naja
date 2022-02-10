#include "gtest/gtest.h"
#include <filesystem>

#include "SNLUniverse.h"
#include "SNLDumper.h"
using namespace naja::SNL;

#include "SNLNetlists.h"

#ifndef SNL_DUMP_PATHS
#define SNL_DUMP_PATHS "Undefined"
#endif

namespace {

void createDumpsDir() {
  std::filesystem::path dumpsPath(SNL_DUMP_PATHS);
  if (not std::filesystem::exists(dumpsPath)) {
    std::filesystem::create_directory(dumpsPath);
  } 
}

}

class SNLDumpTest0: public ::testing::Test {
  protected:
    void SetUp() override {
      createDumpsDir();
      auto u = SNLUniverse::create();
      auto db = SNLDB::create(u);
      top_ = SNLNetlists::createNetlist0(db);
    }
    void TearDown() override {
      SNLUniverse::get()->destroy();
    }
    SNLDesign*  top_;
};

TEST_F(SNLDumpTest0, test) {
  std::filesystem::path test0Path(SNL_DUMP_PATHS);
  SNLDumper::dump(top_, test0Path);
}