/** \file  allTests.cpp
 *    \brief : concrete  Test suite
* run with \code ./allinOneTest --run_test=TestSuite/TestName --log_level=test_suite --report_level=short \endcode
* to get xml result We run our tests with \code ./test --report_format=xml --report_level=detailed --log_level=test_suite --log_format=xml \endcode .
* You need both stderr and stdout, then we replace \<TestLog\> with \<xml\>\<TestLog\> and replace \<TestResult\> with \<TestResult\>\<xml\>. After that we run it though tidy and finally run that though this xslt.
\code
./tests --log_format=XML --report_level=detailed \endcode
* or see http://www.boost.org/doc/libs/1_35_0/libs/test/doc/components/utf/parameters/index.html for more options
 *\version:  1.0
 *\date  12/08/13 18:05:21
 *       Revision:  none
 *       Compiler:  gcc
 *
*\author:  Matthew Sherborne (), msherborne@gmail.com & lyase.d, lyase.d@gmail.com
 *        Company:
 *
 * =====================================================================================
 */
#include <boost/test/test_tools.hpp>
#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream> // Pour std::cerr, etc.
#include <stdexcept>
#include <string>
#include <typeinfo> // Pour std::bad_cast
#include <vector>
struct MyFixture {
    MyFixture ()
    {
        std::cout << "MyFixture c'tor" << std::endl;
    }
    ~MyFixture ()
    {
        std::cout << "MyFixture d'tor" << std::endl;
    }
};
//
////  The fixtures initiates and destructs
////  the definable MyFixture for every test
////  case below (BOOST_AUTO_TEST_CASE)
//BOOST_FIXTURE_TEST_SUITE( MVC_modelTestSuite, LiveAppFixture );
BOOST_AUTO_TEST_SUITE( MVC_modelTestSuite);
BOOST_AUTO_TEST_CASE(test_scenario1_on_MinimalBeatModel_WatchDogView)
{
    BOOST_CHECK_EQUAL(true, true);
}
BOOST_AUTO_TEST_CASE(test__scenario1_on_MinimalBe_defaultView)
{
    BOOST_CHECK_EQUAL(true, true);
}
BOOST_AUTO_TEST_CASE(test__scenario1_on_NonThreadableModel_defaultView)
{
    BOOST_CHECK_EQUAL(true, true);
}
BOOST_AUTO_TEST_CASE(Test_Scenario2execution_speeatModel_defaultView)
{
    BOOST_CHECK_EQUAL(true, true);
}
BOOST_AUTO_TEST_CASE(test__scenario1_on_BeatModeld60bpm)
{
    BOOST_CHECK_EQUAL(true, true);
}
BOOST_AUTO_TEST_CASE(Test_Scenario2execution_speed120bpm)
{
    BOOST_CHECK_EQUAL(true, true);
}
BOOST_AUTO_TEST_CASE(Test_AccountEntryLineRead)
{
    BOOST_CHECK_EQUAL(true, true);
}
BOOST_AUTO_TEST_CASE(Test_AccountEntryLineExport)
{
    BOOST_CHECK_EQUAL(true, true);
}
BOOST_AUTO_TEST_SUITE_END();
BOOST_AUTO_TEST_SUITE( WebAppTestSuite );
BOOST_AUTO_TEST_CASE( testAppStart )
{
    BOOST_CHECK_EQUAL(true, true);
}
BOOST_AUTO_TEST_CASE( testRegisterUser )
{
    BOOST_CHECK_EQUAL(true, true);
}
BOOST_AUTO_TEST_CASE(testUserPersistenceAcrossRestartingApp)
{
    BOOST_CHECK_EQUAL(true, true);
}
BOOST_AUTO_TEST_SUITE_END();
BOOST_FIXTURE_TEST_SUITE(UserdboTestSuite,MyFixture);
BOOST_AUTO_TEST_CASE(readdefaultUserKarma)
{
    BOOST_CHECK_EQUAL(true, true);
}
/*!
* check user model's name setter
* explample name setter & name getter
*/
BOOST_AUTO_TEST_CASE(SettingUserName)
{
    BOOST_CHECK_EQUAL(true, true);
}
/*!
* check crud functionality of the model
* actually no testing here
* this is for usage documenation only
* how to access data from the database
*/
BOOST_AUTO_TEST_CASE(checkUserCRUD)
{
    BOOST_CHECK_EQUAL(true, true);
}
BOOST_AUTO_TEST_SUITE_END();
BOOST_AUTO_TEST_SUITE( PrimeNumber);
BOOST_AUTO_TEST_CASE(TestbasicPrimeListSanityCheck)
{
    BOOST_CHECK_EQUAL(true, true);
}
BOOST_AUTO_TEST_SUITE_END();
