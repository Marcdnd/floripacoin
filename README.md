<<<<<<< HEAD
Floripacoin integration/staging tree
================================

http://www.floripacoin.org

Copyright (c) 2009-2013 Bitcoin Developers
Copyright (c) 2011-2013 Floripacoin Developers

What is Floripacoin?
----------------

Floripacoin is a lite version of Bitcoin using scrypt as a proof-of-work algorithm.
 - 2.5 minute block targets
 - subsidy halves in 840k blocks (~4 years)
 - ~84 million total coins

The rest is the same as Bitcoin.
 - 50 coins per block
 - 2016 blocks to retarget difficulty

For more information, as well as an immediately useable, binary version of
the Floripacoin client sofware, see http://www.floripacoin.org.

License
-------

Floripacoin is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.

Development process
-------------------

Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

If it is a simple/trivial/non-controversial change, then one of the Floripacoin
development team members simply pulls it.

If it is a *more complicated or potentially controversial* change, then the patch
submitter will be asked to start a discussion (if they haven't already) on the
[mailing list](http://sourceforge.net/mailarchive/forum.php?forum_name=bitcoin-development).

The patch will be accepted if there is broad consensus that it is a good thing.
Developers should expect to rework and resubmit patches if the code doesn't
match the project's coding conventions (see `doc/coding.txt`) or are
controversial.

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/bitcoin/bitcoin/tags) are created
regularly to indicate new official, stable release versions of Floripacoin.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test. Please be patient and help out, and
remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write unit tests for new code, and to
submit new unit tests for old code.

Unit tests for the core code are in `src/test/`. To compile and run them:

    cd src; make -f makefile.unix test

Unit tests for the GUI code are in `src/qt/test/`. To compile and run them:

    qmake BITCOIN_QT_TEST=1 -o Makefile.test bitcoin-qt.pro
    make -f Makefile.test
    ./floripacoin-qt_test
=======
"# FloripaCoin-Master" 
Launch Date-Time: Since 03/21/2014 08:00 PM (UTC-0).

Principal features:

Algorithm: Scrypt
Maximum coins: over 17.000.000.000,00 FLN
Block time: 43 seconds (aprox. 2009/day)
Difficulty Re-target Time: Kimoto Gravity Well
Full mining: 5 years

Coins awarded per block: this is the big difference in Floripacoin:
  - In the first 999,999 blocks (approx. 500 days) coins awarded per block is 10,000 FLN
  - However, every 1000 blocks (2 times a day) starts a sequence of 21 special blocks, and the first 20 coins will randomly between 500 and 50,000, and block 21 will give fixed value of 50,000
  - Between blocks 1,000,000 and 2,999,999 a block reward is 10,000, and will be halved every 733,394 blocks (approx 1 year)
  - And from the block 3,000,000 will give fixed value of 600 FLN
>>>>>>> upstream/master

