
#include <memory>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <sstream>
#include <algorithm>

#include "gamegrid.h"
#include "block.h"


using namespace std;

class ExampleTestCase : public CppUnit::TestCase
{


    CPPUNIT_TEST_SUITE( ExampleTestCase );
    CPPUNIT_TEST( example );
    CPPUNIT_TEST( anotherExample );
    CPPUNIT_TEST( testRotateCCW );
    CPPUNIT_TEST( testhasCollisionOccurred );
    CPPUNIT_TEST( testCollisionOffsides );
    CPPUNIT_TEST_SUITE_END();

    double			m_value1;
    double			m_value2;
    void			example ();
    void			anotherExample ();
    void            testRotateCCW ();

    void            testhasCollisionOccurred ();
    void            testCollisionOffsides ();
public:

    void			setUp ();
};




CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( ExampleTestCase, "ExampleTestCase" );


void ExampleTestCase::setUp ()
{
    m_value1 = 2.0;
    m_value2 = 3.0;
}



void ExampleTestCase::example ()
{
    CPPUNIT_ASSERT (1 == 1);
}


void ExampleTestCase::anotherExample ()
{
    CPPUNIT_ASSERT (2 == 2);
}

void ExampleTestCase::testRotateCCW ()
{
    ostringstream expected;
    expected << "          " << endl;
    expected << "      *   " << endl;
    expected << "  * * *   " << endl;
    expected << "          " << endl;
    expected << "          " << endl;

    Block block(0,0, 0); // Is zero an L?

    block.rotateCCW();

    ostringstream result;
    block.print(result);

    CPPUNIT_ASSERT_EQUAL(expected.str(), result.str());
}

void ExampleTestCase::testhasCollisionOccurred ()
{



    GameGrid grid({
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    });
    Block block1(0,0, 0); // Is zero an L?
    Block block2(0,1, 0); // Is zero an L?

    CPPUNIT_ASSERT(block1.hasCollisionOccurred(grid));

    CPPUNIT_ASSERT(!block2.hasCollisionOccurred(grid));
}

void ExampleTestCase::testCollisionOffsides ()
{
    GameGrid grid({
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    });
    Block block1(0,-2, 0); // dont collide
    Block block2(0,-3, 0); // should collide
    Block block3(-1,3, 0); // dont collisde
    Block block4(-2,3,0); // should collide
    CPPUNIT_ASSERT(!block1.hasCollisionOccurred(grid));
    CPPUNIT_ASSERT(block2.hasCollisionOccurred(grid));
    CPPUNIT_ASSERT(!block3.hasCollisionOccurred(grid));
    CPPUNIT_ASSERT(block4.hasCollisionOccurred(grid));

}

///////////////////////////////////////////////////
// No need to modify anything below this line

CppUnit::Test *suite()
{
    CppUnit::TestFactoryRegistry &registry =
    CppUnit::TestFactoryRegistry::getRegistry();


    registry.registerFactory(&CppUnit::TestFactoryRegistry::getRegistry( "ExampleTestCase" ) );
    return registry.makeTest();
}



int main( int argc, char* argv[] )
{
    // if command line contains "-selftest" then this is the post build check
    // => the output must be in the compiler error format.
    bool selfTest = (argc > 1) && (std::string("-selftest") == argv[1]);


    CppUnit::TextUi::TestRunner runner;
    runner.addTest( suite() );   // Add the top suite to the test runner


    if ( selfTest )
    {
        // Change the default outputter to a compiler error format outputter
        // The test runner owns the new outputter.
        runner.setOutputter( CppUnit::CompilerOutputter::defaultOutputter(&runner.result(),std::cerr ) );
    }


    // Run the test.
    bool wasSucessful = runner.run( "" );


    // Return error code 1 if any tests failed.
    return wasSucessful ? 0 : 1;
}
