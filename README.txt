In the makefile, I had gotten an error that said "g++: error: unrecognized command line option ‘-Wnoc++11-narrowing’; did you mean ‘-Wno-narrowing’?"

I was developing on windows so i made the change.

Line 15 in the make file was changed from:

CFLAGS   = -w $(OPTFLAGS) -std=c++11 -pthread -Wnoc++11-narrowing
TO:
CFLAGS   = -w $(OPTFLAGS) -std=c++11 -pthread -Wno-narrowing


IF TESTING ON MAC PLEASE CHANGE LINE 15 TO THIS--> 	"CFLAGS   = -w $(OPTFLAGS) -std=c++11 -pthread -Wnoc++11-narrowing"
else it should run fine


-----------------------------------------------------
ALSO SOMETIMES THE GAME DOESNT LOAD PROPERLY, SO I HAVE TO RESTART MY COMPUTER TO FIX IT. IF ALL YOU SEE IS THE CITY BACKGROUND JUST RESTART.