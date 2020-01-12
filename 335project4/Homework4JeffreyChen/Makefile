########################################
##
## Makefile
## LINUX compilation 
##
##############################################





#FLAGS
C++FLAG = -g -std=c++11 -Wall

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.





#Rule for .cpp files
# .SUFFIXES : .cc.o 

.cc.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@




#Including
INCLUDES=  -I. 


LIBS_ALL =  -L/usr/lib -L/usr/local/lib $(MATH_LIBS) 


#ZEROTH PROGRAM
ALL_OBJ0=CreateGraphandTest.o
PROGRAM_0=CreateGraphandTest
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

ALL_OBJ1=Findpaths.o 
PROGRAM_1=Findpaths
$(PROGRAM_1): $(ALL_OBJ1)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)

ALL_OBJ2=test_random_graph.o disjoint_sets.o
PROGRAM_2=test_random_graph 
$(PROGRAM_2): $(ALL_OBJ2)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ2) $(INCLUDES) $(LIBS_ALL)


#Compiling all

all: 	
		make $(PROGRAM_0)
		make $(PROGRAM_1)
		make $(PROGRAM_2)


runquery1: 	
		./$(PROGRAM_0) Graph1.txt AdjacencyQueries1.txt

runquery2: 	
		./$(PROGRAM_0) Graph1.txt AdjacencyQueries2.txt

runfindpaths1: 	
		./$(PROGRAM_1) Graph1.txt 1

runfindpaths2: 	
		./$(PROGRAM_1) Graph2.txt 1

runrandomgraph:
		./$(PROGRAM_2) 6




#Clean obj files

clean:
	(rm -f *.o; rm -f $(PROGRAM_0); rm -f $(PROGRAM_1); rm -f $(PROGRAM_2))



(:
