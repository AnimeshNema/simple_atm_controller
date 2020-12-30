# simple_atm_controller
This is a C++ implementation of a simple ATM controller.<br/>
The Bank (Bank.cpp) generates and contains the complete data about each account.<br/>
Bank shares only relevant data with the ATM (atmController.cpp) to allow the user to<br/>
perform certain functions such as "See Balance", "Deposit Cash" , "Withdraw Cash".<br/>
<br/>
The Bank doesnt share details like PIN number but let's the ATM know if entered PIN<br/>
is correct or not. 
<br/>


# Build Instructions
	cd simple_atm_controller
	mkdir build
	cd build
	cmake ..
	make
	./simple_atm_controller
  

