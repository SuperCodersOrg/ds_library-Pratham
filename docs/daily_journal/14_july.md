## Specific Issue

While setting up the testing environment, I faced configuration issues because CMake, Google Test, and Valgrind were installed inside WSL while VS Code was using the Windows toolchain. During testing, some Dynamic Array test cases also failed due to incorrect test fixture usage and implementation issues.

---

## Failed Attempt

I repeatedly rebuilt the project, reconfigured CMake, and even modified include paths, assuming the problem was with the project configuration. Later, I realized the red errors were caused by the mismatch between the Windows compiler and the WSL-installed tools. I also fixed the failing Google Test cases by using the correct `TEST_F` fixture consistently.


---

## Section 4 – Code Reference

Installed and configured CMake, Google Test, and Valgrind in WSL.
Wrote unit tests for `constructor`, `push()`, `insert()`, `remove()`, `get()`, `size()`, `isEmpty()`, and `clear()`. Verified all tests passed successfully and confirmed memory safety using Valgrind.


---

## Section 5 – Learning Reflection

ok so I learned the configuring of the development environment correctly when using WSL with VS Code. I also learned how to write unit tests with Google Test suite, debugging failed test cases, using test fixtures correctly, and validating memory management with Valgrind.
specifically i also saw one mistake i made changes in constructors but forgot to make the initialization in copy constructor and assignment overloading which leaded to errors and failed test cases which i will remember that altering a consturctor should be followed by altering the copy constructor as well the assignment operator in the same way .


