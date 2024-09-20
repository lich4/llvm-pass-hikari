llvm/include/llvm/InitializePasses.h:
    void initializeObfuscationPass(PassRegistry&);
llvm/include/llvm/LinkAllPasses.h:
    (void)llvm::createObfuscationLegacyPass()
llvm/lib/Passes/PassBuilderPipelines.cpp
    if (!LTOPreLink)
    MPM.addPass(ObfuscationPass());
    MPM.addPass(ObfuscationPass());
    MPM.addPass(ObfuscationPass());
    MPM.addPass(ObfuscationPass());
    MPM.addPass(ObfuscationPass());
    MPM.addPass(ObfuscationPass());
    if (!LTOPreLink)
    MPM.addPass(ObfuscationPass());
llvm/lib/Passes/CMakeLists.txt:
    Obfuscation
llvm/lib/Transforms/CMakeLists.txt:
    add_subdirectory(Obfuscation)

