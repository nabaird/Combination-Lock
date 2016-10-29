# Combination-Lock
My arduino code for a combination lock keypad

When the yellow light is turned on a combination must be set. Once set, a red or green LED lights up depending on whether or not the correct combination has been entered into the keypad. 

The combination is stored in an array when it is initially set. After each correct button is pressed (the entered value is compared to the corrisponding index in the array) the green light is turned on. When an incorrect button is pressed, we return to the begining of the array to start again. 

The code guarentees that only one button can be pressed at a time (a scan through all the button-states returns only one possible candidate) and ensures that buttons cannot be pressed too quickly by mistake (using a delay). 
