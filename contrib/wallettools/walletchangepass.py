from jsonrpc import ServiceProxy
<<<<<<< HEAD
access = ServiceProxy("http://127.0.0.1:9332")
pwd = raw_input("Enter old wallet passphrase: ")
pwd2 = raw_input("Enter new wallet passphrase: ")
access.walletpassphrasechange(pwd, pwd2)
=======
access = ServiceProxy("http://127.0.0.1:7950")
pwd = raw_input("Enter old wallet passphrase: ")
pwd2 = raw_input("Enter new wallet passphrase: ")
access.walletpassphrasechange(pwd, pwd2)
>>>>>>> upstream/master
