Compiling/running floripacoind unit tests
------------------------------------

floripacoind unit tests are in the `src/test/` directory; they
use the Boost::Test unit-testing framework.

To compile and run the tests:

	cd src
	make -f makefile.unix test_floripacoin  # Replace makefile.unix if you're not on unix
	./test_floripacoin   # Runs the unit tests

If all tests succeed the last line of output will be:
`*** No errors detected`

To add more tests, add `BOOST_AUTO_TEST_CASE` functions to the existing
.cpp files in the test/ directory or add new .cpp files that
implement new BOOST_AUTO_TEST_SUITE sections (the makefiles are
set up to add test/*.cpp to test_floripacoin automatically).


Compiling/running Floripacoin-Qt unit tests
---------------------------------------

<<<<<<< HEAD
Bitcoin-Qt unit tests are in the src/qt/test/ directory; they
=======
Floripacoin-Qt unit tests are in the src/qt/test/ directory; they
>>>>>>> upstream/master
use the Qt unit-testing framework.

To compile and run the tests:

<<<<<<< HEAD
	qmake bitcoin-qt.pro BITCOIN_QT_TEST=1
=======
	qmake floripacoin-qt.pro FLORIPACOIN_QT_TEST=1
>>>>>>> upstream/master
	make
	./floripacoin-qt_test

To add more tests, add them to the `src/qt/test/` directory,
<<<<<<< HEAD
the `src/qt/test/test_main.cpp` file, and bitcoin-qt.pro.
=======
the `src/qt/test/test_main.cpp` file, and floripacoin-qt.pro.
>>>>>>> upstream/master
