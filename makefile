CC = gcc
AR = ar

OBJEKTS_MAIN=main.c
OBJEKTS_MAINO=main.o
OBJECTS_LIBREC=advancedClassificationRecursion.o
OBJECTS_LIBLOOP=advancedClassificationLoop.o
FLAGS= -Wall -g




all: libclassloops.so libclassrec.so libclassrec.a libclassrec.a mains maindrec maindloop

mains: $(OBJEKTS_MAINO) libclassrec.a
	$(CC) -o mains $(OBJEKTS_MAINO) libclassrec.a


maindrec: $(OBJEKTS_MAINO) 
	$(CC) $(FLAGS) -o maindrec $(OBJEKTS_MAINO) ./libclassrec.so


maindloop: $(OBJEKTS_MAINO) libclassloops.so
	$(CC) $(FLAGS)  -o maindloop $(OBJEKTS_MAINO) ./libclassloops.so


loops: libclassloops.a
recursives: libclassrec.a 

recursived:libclassrec.so
loops: libclassloops.so


libclassloops.so: $(OBJECTS_LIBLOOP) basicClassification.o
	$(CC) -shared -o libclassloops.so $(OBJECTS_LIBLOOP) basicClassification.o


libclassrec.so: $(OBJECTS_LIBREC) basicClassification.o
	$(CC) -shared -o libclassrec.so $(OBJECTS_LIBREC) basicClassification.o

libclassloops.a: $(OBJECTS_LIBLOOP) basicClassification.o
	$(AR) -rcs libclassloops.a $(OBJECTS_LIBLOOP) basicClassification.o 

libclassrec.a: $(OBJECTS_LIBREC) basicClassification.o 
	$(AR) -rcs libclassrec.a $(OBJECTS_LIBREC) basicClassification.o 




main.o: $(OBJEKTS_MAIN) NumClass.h
	$(CC) $(FLAGS) -c $(OBJEKTS_MAIN) 


advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c


advancedClassificationRecursion.o: advancedClassificationRecursion.c  NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c 


basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c






clean: 
	rm -f *.o  *.a *.so 
