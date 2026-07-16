**date:15th july**

duration:45 minutes

goal: complete the design proposal for redis lite 

what i tried:
wrote the design proposal considering that redis lite is not a template but a cli so design proposal should be according to that it does not explicitely have rule of three neither memory allocation or deallocation explicitely rather it uses hashmap internally so these things are maanaged by hash map .
so i mainly focused on public api i.e set,get ,clear,count,del & exists.

problem :
in design decisions i have to take certain decisions like there was one to choose string ,string key value pair as its a cli although it came to my mind why not make it template but again when i researched i got to know Cli only takes string inputs so its better suitable with string,string .


**date:15th july**

duration: 80 minutes 

goal:write the test cases for hash map 

what i tried :
wrote test cases for different methods included in my hash named insert ,remove,clear,size,get,etc.
There were test cases like for isempty ,load factor where i dont need fixture but in other like insert ,remove i needed fixture to provide some inputs even before tests.

problem:
in cases where i have written fixture ,there i got to know i have to use Test_F but i have also used Test only which later while testing gave me an error like i have not used fixture in some and didn't keep it consistent so i have to change that .

outcome :

wrote and tested the test cases for hash map using gtest,cmake and valgrind 

**date:15th july**

duration:60 minutes 

goal: implement redis_lite both redis_lite.h and redis_lite.cpp file 

what i tried:
firstly i used redis_lite.cpp in place of tpp in redislite as its not a template rather an application or more accurately cli .
also in redis_lite.h i have kept only run() and redislite() constructor to be public and kept all the handle command methods private .
plus i didn't explicetely include EXIT() in .h as its handled in while loop to break .

then in implementation of redislite.cpp i used a while loop to trigger each command like SET ,GET ,COUNT,CLEAR ,DEL,EXIST
 and more importantly in checking of comands i hardcoded them to be in uppercase only .

problem:
i initially thought why not manage the commands myself and convert them to uppercase invarient of input but then i figured that for now it may be inconsistent in cases where key or value may also has something like set ,get or related to commands which me cause it to behave differently so i had gone with uppercase only .

outcome :
implemented the first version of redis lite .

**date:15th july**

durartion: 150 minutes 

goal: write and verify the test cases for redis_lite 

what i did:

wrote test cases for different methods of redis lite which didn't cause any problem initially and it took me around 1 hours to do so.

problem:
i faced the problem while runnind those test cases ,and the main problem i encountered was that methods of redislite in .h file are private and i cannot access them for testing ,so i tried first for creating a friend method to access those private members but that didn't work i never fully understood why so for testing i finally have to keep them public for this phase and will make them private after testing .
also i have usually encountered an error of method redefinition which i never fully understood why but when i remove build and recreate it worked.





