from distutils.core import setup
<<<<<<< HEAD
setup(name='btcspendfrom',
      version='1.0',
      description='Command-line utility for bitcoin "coin control"',
      author='Gavin Andresen',
      author_email='gavin@bitcoinfoundation.org',
=======
setup(name='mgcspendfrom',
      version='1.0',
      description='Command-line utility for floripacoin "coin control"',
      author='Gavin Andresen',
      author_email='team@floripacoin.org',
>>>>>>> upstream/master
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
