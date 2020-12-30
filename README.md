# simple_atm_controller
This is a C++ implementation of a simple ATM controller.<br/>
The Bank (Bank.cpp) generates and contains the complete data about each account.<br/>
Bank shares only relevant data with the ATM (atmController.cpp) to allow the user to<br/>
perform certain functions such as "See Balance", "Deposit Cash" , "Withdraw Cash".<br/>
<br/>
The Bank doesn't share details like PIN number but let's the ATM know if entered PIN<br/>
is correct or not. 
<br/>

You can Clone the repository using this link https://github.com/AnimeshNema/simple_atm_controller.git <br/>
After that Build it using the intructions below.
# Build Instructions
	cd simple_atm_controller
	mkdir build
	cd build
	cmake ..
	make
	./simple_atm_controller
  

