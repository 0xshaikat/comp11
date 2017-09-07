#CHAPTER 1 NOTES - CS11
##1.1
- **main memory (RAM)**
	- program being executed is stored in main memory and is most imp.
	- consists of long list of memory locations which consist of strings of 0s and 1s
	- all memory locations contain the same number of 0s and 1s (usually 8 bits to a byte)
	- number that identifies a byte in its location is the ADDRESS
	- if computer needs to use more memory than can fit in a byte, other adjacent bytes are used as chunks 
	and are still referred to as memory locations
	- can think of main memory as long list of memory locations of various sizes
	- address of first byte in group of a chunk is the address of the larger memory location
	- different code used for each different type of item stored in a computer's memory
	- eight bits in a byte becayse it is a power of 2 and is convenient in computing

- **secondary memory (HDD)**
	- memory used for permanent storage (i.e. HDD and SSD)
	- flash drives use flash memory which are solid state and do not require power to maintain information

- **processor (CPU)**
	- simple brain of the computer that can only follow instructions
	- has primitive ability to rearrange orders of instructions to seemingly "multitask"

- **OS**
	- your chief servant program
	- program is a set of instructions for a computer to follow
	- data is conceptualized as input to a program
	- Program + Data --> Computer --> Output (where --> means "goes to")

- **High Level Languages**
	- C++, C, C#, Java, Python, PHP, Pascal, Visual Basic, FORTRAN, COBOL, Lisp, Scheme, Ada
	- resemble human languages
	- much more complicated than simple instructions for a CPU
	- a computer can understand LOW LEVEL LANGUAGES
	- an example includes ASSEMBLY LANGUAGE, which, however, must be translated into binary for a CPU 
	to process
	- programs written in binary are MACHINE LANGUAGE 

- **Compilers**
	- program that translates high-level language to machine language
	- input program called source code, and translated version produced by the compiler is the object code
	- some stuff like input and output routines are already compiled and their object code is waiting to be 
	combined w/ your object codee
	- a linker combines object code of stuff already defined with your object code 
	- don't really need to worry about linking
	
##1.2
- **algorithms**
	- hardest part is not translating into a programming language, but coming up with a method of solution
	- concentrate on the steps of solution and writing them down first
	- A SEQUENCE OF PRECISE INSTRUCTIONS WHICH LEAD TO A SOLUTION --- AN ALGORITHM
	- algorithm more general than the term program
	- most algorithms are assumed to be carried out in order they are given but more interesting ones usually
	have a change of order (i.e. repetition)
	- word 'algorithm' comes from Al-Khwarizmi, a Persian mathematican from the 9th century (Rules for Reuniting and Reducing)
	- an algorithm MUST be PRECISE

- **program design**
	- often difficult and is a CREATIVE process
	- divided into the problem-solving phase and the implementation phase
	- result of the problem-solving phase is an algorithm; producing the final program from the algorithm is
	the implementation
	- first step: be sure your task is completely and precisely specified
		- be certain of input and output
	- NOT DESIGNING AN ALGORITHM FIRST IN THE PROBLEM-SOLVING PHASE WASTES TIME
	- the two-phase process produces a correctly working program faster
	- not doing the first phrase leads to shitty, inefficient code
	- implementation is not trivial either, but as you get used to a language, it becomes routine
	- testing takes place in both phases
	- inefficient algorithms are redesigned and mistakes in steps lead to better implementations later
	- good to do it on paper 

- **OOP**
	- modern programs usually designed using a method called OOP
	- in OOP, a program is a collection of interacting objects 
	- each object has algorithms that describe how it should behave in diff. situations
	- **MAIN CHARACTERISTICS OF OOP**
		- encapsulation - information hiding/abstraction (form of simplification of descriptions of objects)
		- inheritance - has to do with writing reusable program code
		- polymorphism - refers to how a single name can have different meanings in the context of inheritance
	- C++ implements OOP using classes

- **the software life cycle**
	1. analysis and specification of the task (problem definition)
	2. design of the software (object and algorithm design)
	3. implementation
	4. testing
	5. maintenance and evolution of the system
	6. obsolescence

##1.3

 - **origins of the c++ language**
	- BCPL -> B -> C -> C++
	- C developed by Dennis Ritchie of AT&T Bell in 1970, used for writing and maintaining UNIX (usually written in B or assembly)
	- Ken Thompson invented UNIX
	- C is peculiar bc it is a high lvl lang with the features of a low-level lang
		- can directly manipulate computer's memory
		- also really good at writing systems programs
	- to overcome shortcomings of C, Bjarne Strosoup (AT&T Bell) developed C++ which was OOP.

- **a sample c++ program**

		//program starts here
		//is called an include directive, which asks the compiler to use the 'iostream' library 
		//the linker from the combiner adds object code from 'iostream' to your source code
		//directives always begin with '#'
		#include <iostream>
	
		//says that names defined in iostream are to be interpreted in the 'standard way' 
 		using namespace std;
	
		//main function starts here
 		int main( )
 		{
			//variable declaration
 			int number_of_pods, peas_per_pod, total_peas; 
	
			//executable statements
			//cout is used for output
 			cout << "Press return after entering a number.\n";
 			cout << "Enter the number of pods:\n";

			//cin is used for input
 			cin >> number_of_pods;
 			cout << "Enter the number of peas in a pod:\n";
 			cin >> peas_per_pod;
 			total_peas = number_of_pods * peas_per_pod;
 			cout << "If you have ";
 			cout << number_of_pods;
 			cout << " pea pods\n";
 			cout << "and ";
 			cout << peas_per_pod;
 			cout << " peas in each pod, then\n";
 			cout << "you have ";
 			cout << total_peas;
 			cout << " peas in all the pods.\n";
		
			//program ends here bc no more statements to compile
			//return statement
 			return 0; 
		}

>cout '<<' insert/put to (can be thought of as a screen)
>cin '>>' extract/ get from (can be thought of as a keyboard)

- **compiling**
	- somewhat different for various systems
	- C++11 is the most recent version of the standard C++ prog lang
	- C++11 compilers include stuff that wouldn't be accessible to old compilers
	- if code works with '#include <iostream.h>', then ya got an old compiler
	- HOW TO COMPILE ON OUR SETUPS:
	>uh
		
		
##1.4
- **testing and debugging**
	- eliminating bugs is debugging
	- Rear Admiral Grace Murray Hopper was the third programmer on the world's first largescale digital computer
	- Hopper was working on HARVARD MARK I and a moth caused a relay to fail, which is the first computer bug
	- logbook with the detailed report is available in the Naval Museum in Dahlgren, Viriginia

- **kind of program errors**
	- syntax errors
	- by and large the most common	
		- compiler better at finding the location of the error than actually describing it
	- error message/warning message
		- you've done something unusual enough to indicate a likely mistake
	- run-time errors
		- only detected when a program is run
		- most deal with numeric calculations, and compilers detect certain run-time erroes
	- a compiler will not tell you if you have succeeded in the task you set out for, only if the grammar
	of the program works and it runs
	- logic errors are hard to find, because they are not found by the compiler, but are made by you 
		
	




	
	

	




 