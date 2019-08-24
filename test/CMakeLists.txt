project(tests)
IF(CMAKE_BUILD_TYPE MATCHES COVERAGE)
#coverage build options
add_definitions(-Wall -Wextra  -fprofile-arcs -ftest-coverage)
#//else(CMAKE_BUILD_TYPE MATCHES COVERAGE)
else()
add_definitions(-g )
#//ENDIF(CMAKE_BUILD_TYPE MATCHES COVERAGE)
ENDIF()
add_definitions(-g )
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
#checking the object dbo functionality CRUD are ok

ADD_DEFINITIONS( -fno-access-control -DBOOST_TEST_DYN_LINK -DBOOST_TEST_MAIN ) # So tests load the test lib dynamically
add_executable(allinOneTest ../apps/allTests.cpp  )
target_link_libraries(allinOneTest    ${gcov} dl m ${ZLIB_LIBRARY} ${X11_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}  ${Boost_FILESYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
add_test(memorycheck_allinOneTest valgrind -q --tool=memcheck --leak-check=yes --track-origins=yes --show-reachable=yes --workaround-gcc296-bugs=yes --error-exitcode=1 ./allinOneTest --run_test=*/*)
add_test(checkdbo  ./allinOneTest --run_test=UserdboTestSuite/*)
add_test(allinOneTest  ./allinOneTest --run_test=*/*)
