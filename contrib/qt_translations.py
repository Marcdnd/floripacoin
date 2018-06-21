#!/usr/bin/env python

# Helpful little script that spits out a comma-separated list of
# language codes for Qt icons that should be included
<<<<<<< HEAD
# in binary bitcoin distributions
=======
# in binary floripacoin distributions
>>>>>>> upstream/master

import glob
import os
import re
import sys

if len(sys.argv) != 3:
<<<<<<< HEAD
  sys.exit("Usage: %s $QTDIR/translations $BITCOINDIR/src/qt/locale"%sys.argv[0])
=======
  sys.exit("Usage: %s $QTDIR/translations $FLORIPACOINDIR/src/qt/locale"%sys.argv[0])
>>>>>>> upstream/master

d1 = sys.argv[1]
d2 = sys.argv[2]

l1 = set([ re.search(r'qt_(.*).qm', f).group(1) for f in glob.glob(os.path.join(d1, 'qt_*.qm')) ])
<<<<<<< HEAD
l2 = set([ re.search(r'bitcoin_(.*).qm', f).group(1) for f in glob.glob(os.path.join(d2, 'bitcoin_*.qm')) ])
=======
l2 = set([ re.search(r'floripacoin_(.*).qm', f).group(1) for f in glob.glob(os.path.join(d2, 'floripacoin_*.qm')) ])
>>>>>>> upstream/master

print ",".join(sorted(l1.intersection(l2)))

