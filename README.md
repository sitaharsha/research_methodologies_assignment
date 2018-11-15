# research_methodologies_assignment

Implementation of Paillier cryptosystem

I implememted the three algorithms provided in the following research paper

http://www.cs.tau.ac.il/~fiat/crypt07/papers/Pai99pai.pdf


For compilation :

g++ -I$HOME/sw/include <file_name.cpp> -o <object_file_name> -L$HOME/sw/lib -lntl -lm

Example : g++ -I$HOME/sw/include basicpailler.cpp -o basicpailler -L$HOME/sw/lib -lntl -lm
