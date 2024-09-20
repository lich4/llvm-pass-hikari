CC := xcrun clang
CFLAGS := -I../llvm/include -I../Build/include -std=c++17 -fno-rtti -DGIT_COMMIT_HASH=20240825210000 #-O3
LDFLAGS := -L../Build/lib -lstdc++ -lz -lzstd -lLLVMAsmParser -lLLVMCodeGenTypes -lLLVMDemangle -lLLVMHipStdPar -lLLVMLinker -lLLVMTargetParser -lLLVMBitstreamReader -lLLVMRemarks -lLLVMFrontendOffloading -lLLVMSupport -lLLVMBinaryFormat -lLLVMIRReader -lLLVMScalarOpts -lLLVMTarget -lLLVMIRPrinter -lLLVMMC -lLLVMBitReader -lLLVMProfileData -lLLVMInstCombine -lLLVMBitWriter -lLLVMObject -lLLVMVectorize -lLLVMTransformUtils -lLLVMipo -lLLVMObjCARCOpts -lLLVMMCParser -lLLVMAnalysis -lLLVMCodeGen -lLLVMInstrumentation -lLLVMFrontendOpenMP -lLLVMCoroutines -lLLVMCFGuard -lLLVMDebugInfoDWARF -lLLVMTextAPI -lLLVMAggressiveInstCombine -lLLVMCore -lLLVMPasses
TARGET := hikari.dylib

$(shell sed -i '' "s/llvm\/Transforms\/Obfuscation\///g" *.cpp *.h)

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -shared $(LDFLAGS) -o $@ $^
	#strip -S -X -x $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(TARGET) *.o
	
.PHONY: all clean

