
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
    CPPUNIT_TEST( testhasCollisionOccurred );
    CPPUNIT_TEST( testCollisionOffsides );
    CPPUNIT_TEST( testlineCompleteNone );
    CPPUNIT_TEST( testShift );

    CPPUNIT_TEST_SUITE_END();

    double			m_value1;
    double			m_value2;
    void			example ();
    void			anotherExample ();
    void            testRotateCCW ();
    void            testlineCompleteTwoRows();
    void            testlineCompleteOffsetline();
    void            testlineCompleteNone();
    void            testhasCollisionOccurred ();
    void            testCollisionOffsides ();
    void            testShift ();

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

        // {' ', ' ', ' ', ' ', ' '},
        // {' ', ' ', '*', ' ', ' '},
        // {' ', ' ', '*', ' ', ' '},
        // {' ', ' ', '*', '*', ' '},
        // {' ', ' ', ' ', ' ', ' '}


    Block block1(0,-2, 0); // dont collide
    Block block2(0,-3, 0); // should collide
    Block block3(-1,3, 0); // dont collisde
    Block block4(-2,3,0); // should collide
    Block block5(16,6, 0); // dont collisde
    Block block6(16,7,0); // should collide
    Block block7(17,6,0); // should collide

        CPPUNIT_ASSERT(!block1.hasCollisionOccurred(grid));
    //cppunit alwasys wants true, ! makes it want False
    CPPUNIT_ASSERT(block2.hasCollisionOccurred(grid));
    CPPUNIT_ASSERT(!block3.hasCollisionOccurred(grid));
    CPPUNIT_ASSERT(block4.hasCollisionOccurred(grid));
    CPPUNIT_ASSERT(!block5.hasCollisionOccurred(grid));
    CPPUNIT_ASSERT(block6.hasCollisionOccurred(grid));
    CPPUNIT_ASSERT(block7.hasCollisionOccurred(grid));

}

void ExampleTestCase::testlineCompleteOffsetline ()
{
    GameGrid grid({
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
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}
    });

    CPPUNIT_ASSERT(grid.lineComplete() == 16);

}
void ExampleTestCase::testlineCompleteNone ()
{
    GameGrid grid({
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
        {' ', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}
    });

    CPPUNIT_ASSERT(grid.lineComplete() == -1);

}

void ExampleTestCase::testlineCompleteTwoRows ()
{
    GameGrid grid({
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
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    });

    CPPUNIT_ASSERT(grid.lineComplete() == 19);

}


void ExampleTestCase::testShift ()
{
    GameGrid grid({
        //0    1    2    3    4    5    6    7    8    9
        {' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' '}, // 0
        {' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' '}, // 1
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 2
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 3
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 4
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 7
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 8
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' '}, // 9
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, //10
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, //11
        {' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' '}, //12
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, //13
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, //14
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, //15
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}, //16
        {' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'}, //17
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //18
        {'*', '*', ' ', '*', '*', '*', '*', '*', '*', '*'}  //19
    });

    grid.shift(16);

    CPPUNIT_ASSERT(grid.getData(16,2) == ' ');
    CPPUNIT_ASSERT(grid.getData(13,6) == '*');
    CPPUNIT_ASSERT(grid.getData(10,7) == '*');
    CPPUNIT_ASSERT(grid.getData(9,7) == ' ');
    CPPUNIT_ASSERT(grid.getData(1,7) == '*');
    CPPUNIT_ASSERT(grid.getData(2,3) == '*');
    CPPUNIT_ASSERT(grid.getData(1,4) == '*');
    CPPUNIT_ASSERT_EQUAL(' ', grid.getData(0,1));
    CPPUNIT_ASSERT_EQUAL(' ', grid.getData(0,4));
    CPPUNIT_ASSERT_EQUAL(' ', grid.getData(0,7));
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
