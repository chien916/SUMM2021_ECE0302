# CMake generated Testfile for 
# Source directory: E:/SM2021/ece0302/Projects/pj4/Starter Code
# Build directory: E:/SM2021/ece0302/Projects/pj4/Starter Code/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(student-tests "student-tests")
set_tests_properties(student-tests PROPERTIES  _BACKTRACE_TRIPLES "E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;36;add_test;E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;0;")
add_test(test00 "pathfinder" "E:/SM2021/ece0302/Projects/pj4/Starter Code/tests/maze00.png" "output00.png")
set_tests_properties(test00 PROPERTIES  _BACKTRACE_TRIPLES "E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;37;add_test;E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;0;")
add_test(test00-compare "compare" "E:/SM2021/ece0302/Projects/pj4/Starter Code/tests/output00.png" "output00.png")
set_tests_properties(test00-compare PROPERTIES  _BACKTRACE_TRIPLES "E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;38;add_test;E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;0;")
add_test(test01 "pathfinder" "E:/SM2021/ece0302/Projects/pj4/Starter Code/tests/maze01.png" "output01.png")
set_tests_properties(test01 PROPERTIES  _BACKTRACE_TRIPLES "E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;39;add_test;E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;0;")
add_test(test01-compare "compare" "E:/SM2021/ece0302/Projects/pj4/Starter Code/tests/output01.png" "output01.png")
set_tests_properties(test01-compare PROPERTIES  _BACKTRACE_TRIPLES "E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;40;add_test;E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;0;")
add_test(test02 "pathfinder" "E:/SM2021/ece0302/Projects/pj4/Starter Code/tests/maze02.png" "output02.png")
set_tests_properties(test02 PROPERTIES  _BACKTRACE_TRIPLES "E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;41;add_test;E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;0;")
add_test(test02-compare "compare" "E:/SM2021/ece0302/Projects/pj4/Starter Code/tests/output02.png" "output02.png")
set_tests_properties(test02-compare PROPERTIES  _BACKTRACE_TRIPLES "E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;42;add_test;E:/SM2021/ece0302/Projects/pj4/Starter Code/CMakeLists.txt;0;")
subdirs("lib")
