CC = g++
CCFLAGS = -g -W -Wall

OBJS = Runtime.o InstructionTHROW.o InstructionBTRY.o InstructionFTRY.o NativeFunctions.o InstructionPUSHMEMBER.o InstructionSTOREMEMBER.o InstanceINT.o InstanceCLASS.o InstanceDOUBLE.o InstanceSTRING.o InstructionADD.o InstructionSUB.o InstructionDIV.o InstructionMUL.o InstructionCLT.o InstructionCGT.o InstructionRET.o InstructionCEQ.o InstructionCNEQ.o InstructionCJMP.o InstructionBJMP.o InstructionFJMP.o InstructionNEW.o InstructionPUSHID.o InstructionPUSHINT.o InstructionPUSHDOUBLE.o InstructionPUSHSTRING.o InstructionSTORE.o InstructionCALL.o InstructionMCALL.o Loader.o Instruction.o Heap.o Instance.o Class.o Function.o ConstantPool.o ClassPool.o DataStack.o GarbageCollector.o Frame.o CallStack.o

.PHONY: clean distclean

all: TestRun

clean:
	rm -f *.o TestRun

TestRun: ${OBJS} TestRun.o
	@echo "Linking TestRun..."
	${CC} ${CCFLAGS} ${OBJS} TestRun.o -o TestRun

CallStack.o: CallStack.C CallStack.H Frame.H ClassPool.H Debug.H
	${CC} ${CCFLAGS} -c CallStack.C
		
Frame.o: Frame.C Frame.H Function.H Class.H Debug.H
	${CC} ${CCFLAGS} -c Frame.C
	
Instruction.o: Instruction.C Instruction.H CallStack.H DataStack.H Heap.H Debug.H
	${CC} ${CCFLAGS} -c Instruction.C
	
GarbageCollector.o: GarbageCollector.C GarbageCollector.H Heap.H Debug.H
	${CC} ${CCFLAGS} -c GarbageCollector.C
	
DataStack.o: DataStack.C DataStack.H Debug.H
	${CC} ${CCFLAGS} -c DataStack.C
	
ClassPool.o: ClassPool.C ClassPool.H Class.H Debug.H
	${CC} ${CCFLAGS} -c ClassPool.C
		
ConstantPool.o: ConstantPool.C ConstantPool.H Debug.H
	${CC} ${CCFLAGS} -c ConstantPool.C

Instance.o: Instance.C Instance.H CallStack.H DataStack.H Debug.H
	${CC} ${CCFLAGS} -c Instance.C

Heap.o: Heap.C Heap.H Instance.H InstanceCLASS.H InstanceSTRING.H InstanceDOUBLE.H InstanceINT.H Class.H Debug.H
	${CC} ${CCFLAGS} -c Heap.C
	
Class.o: Class.C Class.H Function.H Debug.H
	${CC} ${CCFLAGS} -c Class.C
	
Function.o: Function.C Function.H Debug.H
	${CC} ${CCFLAGS} -c Function.C

Loader.o: Loader.C Loader.H Debug.H ClassPool.H Class.H Function.H ConstantPool.H Debug.H
	${CC} ${CCFLAGS} -c Loader.C

Runtime.o: Runtime.C Runtime.H Debug.H InstructionTHROW.H InstructionBTRY.H InstructionFTRY.H NativeFunctions.H Loader.H Heap.H ConstantPool.H ClassPool.H CallStack.H DataStack.H GarbageCollector.H Frame.H InstructionADD.H InstructionSUB.H InstructionDIV.H InstructionMUL.H InstructionCLT.H InstructionCGT.H InstructionCEQ.H InstructionCNEQ.H InstructionCJMP.H InstructionBJMP.H InstructionFJMP.H InstructionNEW.H InstructionPUSHID.H InstructionPUSHINT.H InstructionPUSHDOUBLE.H InstructionPUSHSTRING.H InstructionSTORE.H InstructionCALL.H InstructionMCALL.H
	${CC} ${CCFLAGS} -c Runtime.C

TestRun.o: TestRun.C Runtime.H Debug.H
	${CC} ${CCFLAGS} -c TestRun.C
	
InstructionADD.o: InstructionADD.C InstructionADD.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionADD.C
	
InstructionRET.o: InstructionRET.C InstructionRET.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionRET.C
	
InstructionSUB.o: InstructionSUB.C InstructionSUB.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionSUB.C
	
InstructionDIV.o: InstructionDIV.C InstructionDIV.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionDIV.C
	
InstructionMUL.o: InstructionMUL.C InstructionMUL.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionMUL.C
	
InstructionCLT.o: InstructionCLT.C InstructionCLT.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionCLT.C
	
InstructionCGT.o: InstructionCGT.C InstructionCGT.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionCGT.C
	
InstructionCEQ.o: InstructionCEQ.C InstructionCEQ.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionCEQ.C
	
InstructionCNEQ.o: InstructionCNEQ.C InstructionCNEQ.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionCNEQ.C
	
InstructionCJMP.o: InstructionCJMP.C InstructionCJMP.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionCJMP.C
	
InstructionBJMP.o: InstructionBJMP.C InstructionBJMP.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionBJMP.C
	
InstructionFJMP.o: InstructionFJMP.C InstructionFJMP.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionFJMP.C
	
InstructionNEW.o: InstructionNEW.C InstructionNEW.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H ConstantPool.H ClassPool.H InstanceCLASS.H
	${CC} ${CCFLAGS} -c InstructionNEW.C
	
InstructionPUSHID.o: InstructionPUSHID.C InstructionPUSHID.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionPUSHID.C
	
InstructionPUSHINT.o: InstructionPUSHINT.C InstructionPUSHINT.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H InstanceINT.H
	${CC} ${CCFLAGS} -c InstructionPUSHINT.C
	
InstructionPUSHDOUBLE.o: InstructionPUSHDOUBLE.C InstructionPUSHDOUBLE.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H InstanceDOUBLE.H ConstantPool.H
	${CC} ${CCFLAGS} -c InstructionPUSHDOUBLE.C
	
InstructionPUSHSTRING.o: InstructionPUSHSTRING.C InstructionPUSHSTRING.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H InstanceSTRING.H ConstantPool.H
	${CC} ${CCFLAGS} -c InstructionPUSHSTRING.C
	
InstructionSTORE.o: InstructionSTORE.C InstructionSTORE.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H
	${CC} ${CCFLAGS} -c InstructionSTORE.C
	
InstructionSTOREMEMBER.o: InstructionSTOREMEMBER.C InstructionSTOREMEMBER.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H ConstantPool.H
	${CC} ${CCFLAGS} -c InstructionSTOREMEMBER.C
	
InstructionPUSHMEMBER.o: InstructionPUSHMEMBER.C InstructionPUSHMEMBER.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H ConstantPool.H
	${CC} ${CCFLAGS} -c InstructionPUSHMEMBER.C
	
InstructionCALL.o: InstructionCALL.C InstructionCALL.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H ClassPool.H ConstantPool.H NativeFunctions.H
	${CC} ${CCFLAGS} -c InstructionCALL.C
	
InstructionMCALL.o: InstructionMCALL.C InstructionMCALL.H Instruction.H Instance.H Heap.H CallStack.H DataStack.H ClassPool.H ConstantPool.H NativeFunctions.H InstanceCLASS.H
	${CC} ${CCFLAGS} -c InstructionMCALL.C

InstanceINT.o: InstanceINT.C InstanceINT.H Instance.H InstanceDOUBLE.H Heap.H
	${CC} ${CCFLAGS} -c InstanceINT.C

InstanceCLASS.o: InstanceCLASS.C InstanceCLASS.H Instance.H Class.H InstanceINT.H
	${CC} ${CCFLAGS} -c InstanceCLASS.C

InstanceDOUBLE.o: InstanceDOUBLE.C InstanceDOUBLE.H Instance.H InstanceINT.H Heap.H
	${CC} ${CCFLAGS} -c InstanceDOUBLE.C

InstanceSTRING.o: InstanceSTRING.C InstanceSTRING.H Instance.H
	${CC} ${CCFLAGS} -c InstanceSTRING.C
	
NativeFunctions.o: NativeFunctions.C NativeFunctions.H Heap.H DataStack.H InstanceSTRING.H InstanceINT.H InstanceDOUBLE.H
	${CC} ${CCFLAGS} -c NativeFunctions.C
	
InstructionBTRY.o: InstructionBTRY.C InstructionBTRY.H Heap.H DataStack.H CallStack.H
	${CC} ${CCFLAGS} -c InstructionBTRY.C
	
InstructionFTRY.o: InstructionFTRY.C InstructionFTRY.H Heap.H DataStack.H CallStack.H
	${CC} ${CCFLAGS} -c InstructionFTRY.C
	
InstructionTHROW.o: InstructionTHROW.C InstructionTHROW.H Heap.H DataStack.H CallStack.H
	${CC} ${CCFLAGS} -c InstructionTHROW.C