#ifndef _OBFUSCATION_H_
#define _OBFUSCATION_H_

#include "llvm/Support/Timer.h"
#include "AntiClassDump.h"
#include "AntiDebugging.h"
#include "AntiHook.h"
#include "BogusControlFlow.h"
#include "ConstantEncryption.h"
#include "CryptoUtils.h"
#include "Flattening.h"
#include "FunctionCallObfuscate.h"
#include "FunctionWrapper.h"
#include "IndirectBranch.h"
#include "Split.h"
#include "StringEncryption.h"
#include "Substitution.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Transforms/Utils/ModuleUtils.h"

namespace llvm {

class ObfuscationPass : public PassInfoMixin<ObfuscationPass> {
public:
  ObfuscationPass() {}
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &MAM);
  static bool isRequired() { return true; }
};

ModulePass *createObfuscationLegacyPass();
void initializeObfuscationPass(PassRegistry &Registry);

} // namespace llvm

#endif
