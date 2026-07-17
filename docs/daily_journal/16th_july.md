## Specific Issue

Today's work focused on understanding the Web Crawler project and resolving failing Dynamic Array test cases. I studied the crawler architecture, component interactions, and the role of different data structures. While testing, I investigated why multiple Dynamic Array tests were failing when built together.

---

## Failed Attempt

Initially, I suspected the failing tests were caused by incorrect test cases. After running them individually, I found they all passed, indicating the issue was with the build configuration. Following my evaluation instructor's advice, I created a separate `CMakeLists.txt` for the test directory, which significantly reduced the number of failing tests.


---

## Code Reference

Completed the Web Crawler documentation review and understood its workflow, component interfaces, and design decisions. Created a dedicated `CMakeLists.txt` for the test directory and rebuilt the project, reducing the failing Dynamic Array tests from **14 to just 1** out of **251** total tests.

99% tests passed, 1 tests failed out of 251

Total Test time (real) =   8.31 sec

The following tests FAILED:
          7 - DynamicArrayTest.Default (Failed)
Errors while running CTest
Output from these tests are in: /mnt/n/cq/Project 1/collections-library/build/Testing/Temporary/LastTest.log
Use "--rerun-failed --output-on-failure" to re-run the failed cases verbosely.

---

## Learning Reflection

so i learned how software architecture influences the choice of data structures in real-world applications such as a Web Crawler. I also realized that not every failing test indicates an implementation bug—sometimes the build configuration itself is the root cause. Separating the test build greatly simplified debugging and improved the reliability of the testing process.
