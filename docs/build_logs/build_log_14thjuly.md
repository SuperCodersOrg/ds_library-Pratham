**date : 14th july**

Duration: 1.5 hr 

goal: install & configure cmake + gtest to support build and test cases 

problem :
As i was using wsl so i installed gtest ,cmake and valgribd using wsl terminal ,which caused my codes to appear in red 
and i was wondering what went wrong here

what i tried:
tried to reconfigure cmake , build using rm -rf build and then again made it using mkdir build tried this many times .
then bad cmake executable popup is continuosly poping so i thought maybe the problem is in path somewhere so i changed the include paths in each header files .
and then finally i understood that my cmake and gtest and valgrind are installed using swl i.e. in ubuntu space so my compiler can't configure them in local space of vs code 

outcome:
i left those red lines as it is and continued to implement my test cases for dyanmic arrays which were running smoothly using wsl its just that i have not configured cmake in my global windows space.


**date:14 july**

duration:3 hours

what i did:
written test cases for different dynamic arrays methods like constructor,get ,insert,isempty,push,remove,size,clear .

problem encountered:

got some test cases failed while running them using gtest while implementing them which lead me to correcting the method & modifying them .

**before :**
[  FAILED  ] DynamicArrayTest.ClearDefaultCapacity (0 ms)
[ RUN      ] DynamicArrayTest.ClearCustomCapacity
/mnt/n/cq/Project 1/collections-library/build/_deps/googletest-src/googletest/src/gtest.cc:2622: Failure
Failed
All tests in the same test suite must use the same test fixture
class, so mixing TEST_F and TEST in the same test suite is
illegal.  In test suite DynamicArrayTest,
test ClearArray is defined using TEST_F but
test ClearCustomCapacity is defined using TEST.  You probably
want to change the TEST to TEST_F or move it to another test
case.

[  FAILED  ] DynamicArrayTest.ClearCustomCapacity (0 ms)
[----------] 7 tests from DynamicArrayTest (2 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test suite ran. (2 ms total)
[  PASSED  ] 3 tests.
[  FAILED  ] 4 tests, listed below:
[  FAILED  ] DynamicArrayTest.ClearChar
[  FAILED  ] DynamicArrayTest.ClearString
[  FAILED  ] DynamicArrayTest.ClearDefaultCapacity
[  FAILED  ] DynamicArrayTest.ClearCustomCapacity

 4 FAILED TESTS

 **After:**
 pratham@PC-Niklaus:/mnt/n/cq/Project 1/collections-library/build$ ./runTests
Running main() from /mnt/n/cq/Project 1/collections-library/build/_deps/googletest-src/googletest/src/gtest_main.cc
[==========] Running 7 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 7 tests from DynamicArrayTest
[ RUN      ] DynamicArrayTest.ClearArray
[       OK ] DynamicArrayTest.ClearArray (0 ms)
[ RUN      ] DynamicArrayTest.ClearTwice
[       OK ] DynamicArrayTest.ClearTwice (0 ms)
[ RUN      ] DynamicArrayTest.PushAfterClear
[       OK ] DynamicArrayTest.PushAfterClear (0 ms)
[ RUN      ] DynamicArrayTest.ClearChar
[       OK ] DynamicArrayTest.ClearChar (0 ms)
[ RUN      ] DynamicArrayTest.ClearString
[       OK ] DynamicArrayTest.ClearString (0 ms)
[ RUN      ] DynamicArrayTest.ClearDefaultCapacity
[       OK ] DynamicArrayTest.ClearDefaultCapacity (0 ms)
[ RUN      ] DynamicArrayTest.ClearCustomCapacity
[       OK ] DynamicArrayTest.ClearCustomCapacity (0 ms)
[----------] 7 tests from DynamicArrayTest (0 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 7 tests.
pratham@PC-Niklaus:/mnt/n/cq/Project 1/collections-library/build$ valgrind --leak-check=full ./runTests
==700== Memcheck, a memory error detector
==700== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==700== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==700== Command: ./runTests
==700== 
Running main() from /mnt/n/cq/Project 1/collections-library/build/_deps/googletest-src/googletest/src/gtest_main.cc
[==========] Running 7 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 7 tests from DynamicArrayTest
[ RUN      ] DynamicArrayTest.ClearArray
[       OK ] DynamicArrayTest.ClearArray (37 ms)
[ RUN      ] DynamicArrayTest.ClearTwice
[       OK ] DynamicArrayTest.ClearTwice (3 ms)
[ RUN      ] DynamicArrayTest.PushAfterClear
[       OK ] DynamicArrayTest.PushAfterClear (5 ms)
[ RUN      ] DynamicArrayTest.ClearChar
[       OK ] DynamicArrayTest.ClearChar (7 ms)
[ RUN      ] DynamicArrayTest.ClearString
[       OK ] DynamicArrayTest.ClearString (11 ms)
[ RUN      ] DynamicArrayTest.ClearDefaultCapacity
[       OK ] DynamicArrayTest.ClearDefaultCapacity (7 ms)
[ RUN      ] DynamicArrayTest.ClearCustomCapacity
[       OK ] DynamicArrayTest.ClearCustomCapacity (8 ms)
[----------] 7 tests from DynamicArrayTest (104 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test suite ran. (221 ms total)
[  PASSED  ] 7 tests.
==700== 
==700== HEAP SUMMARY:
==700==     in use at exit: 0 bytes in 0 blocks
==700==   total heap usage: 299 allocs, 299 frees, 126,405 bytes allocated
==700== 
==700== All heap blocks were freed -- no leaks are possible
==700== 
==700== For lists of detected and suppressed errors, rerun with: -s
==700== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
pratham@PC-Niklaus:/mnt/n/cq/Project 1/collections-library/build$ 

**outcome**
completed the test cases for dynamic array 's methods successfully and tested them against gtest and valgrind.







