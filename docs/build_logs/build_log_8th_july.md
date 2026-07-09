Date: July 8

Duration: 150 minutes

Goal:
Research about hash map ,hash function ,generic hash code ,collision management strategy

Problem Encountered:
collision management strategy - chaining or probing which one to use and how to create hash code from hash function in case of user defined data types.

What I Tried:
- researched about tradeoffs between chaining and probing like probing altough takes less memory but it may make multiple rehashes and more time comsuming 
- researched about different hash function but could not find the one which can be used for user defined data types ,finally selected a variadic template based recurstion based hash function which eventually use primitive data types only


Outcome:
- decided to choose chaining over probing because probing made tables very long over larger number of items and deletion also becomes difficult 
- for hash function i have choosen variadic template function which takes variable inputs and then recursively finds the primitives ones from it and apply hash fucntion.



Date :July 8

Duraction : 150 minutes

Goal :
design proposal for hash map - load factor determination , memory allocation 

Problem Encountered:
choosing appropriate load factor and memory allocation methods

what i tried:
- i was confused between taking load factor 1 or .75  , as 1 is taken as the load factor in unordered_map in stl but then i found out it considers a uniform distribution and also it asumes the hash function is very good 
- but since we are creating things from basic i am assuming my hash function is not that perfect and for better distribution and resizing taking 0.75 here.

- about memory allocation i have 2 options malloc or calloc the same thing which one to use 

outcome:

- for bucket memory i.e type of dynamic array where each pointer needs to be assigned null so i am using calloc and inside bucket for linked list node type memory i am using malloc as it does not needs to have any value ,along with placement new .


