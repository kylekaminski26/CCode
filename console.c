#include "console.h"
// Include the console header file so we can use the variable declarations and function headers from it in this file.

/*
 * A variable is needed to track the address of the last call to the print function.
 * This is needed so we can accurately store where we are in memory.
 */
unsigned int PREV_ADDR = 0; // Address of where I left off the last time I made a call to the print function.

/* 
 * A video buffer operates like an array starting at address 0xb8000 
 * where every pair of index bytes is a character and a style byte.
 * The video buffer is 80x25, therefore we start at...
 */
char* const MEM_BUF = (char*) 0xb8000; // Starting point of the video buffer.

/*  
 * And now we define the width and the height that is needed for the video buffer to display properly.
 * The video buffer is 80 characters across and 25 characters down, so...
 */
const int WIDTH = 80; // final value of 25
const int HEIGHT = 25; // final value of 25

/*
 * "Will print the String denoted by the char* parameter, starting it at the current address held by the variable in console.h and updating the pointer as I finish with characters."
 * Now we need a for loop to print the String.
 * The buffer is loaded with the Strings and the length and wrapping is handled for readability.
 */
void print(char* str) { // Takes in a string.
	unsigned int i = 0; // Increment for the following for loop.	
	for (i = 0; str[i] != '/0'; i++) { // While the String is not terminated ('/0' means end of String in this case).
		MEM_BUF[PREV_ADDR] = str[i]; // Load String character into buffer, starting at current address. 
		MEM_BUF[PREV_ADDR + 1] = 0x07; // Default style byte.
		PREV_ADDR = PREV_ADDR + 2; // Move 2 places because of the addition to the buffer plus the default style byte.
		if (PREV_ADDR >= (WIDTH * HEIGHT * 2)) { // if the address where we left off is outside the scope of the video buffer.
			unsigned int ind = 0; // Inner for loop's incrementer.
			for (ind = 0; ind < WIDTH * HEIGHT * 2; ind++) { // For every index in the buffer that is out of scope.
				MEM_BUF[ind] = MEM_BUF[ind + (WIDTH * 2)]; // Bring it back into the scope of the buffer.
			} // End for
			PREV_ADDR = PREV_ADDR - (WIDTH * 2); // Move the address where we left off to be within the width of the video buffer (in scope).
		} // End if
	} // End for
} // End print

/*
 * "Will do the same as print but will move the output pointer to the beginning of the next line (note - \n will not work here because \n does not exist in your OS)."
 * This method will function the same as the print function but will move the cursor to the next line (same as S.O.println() in Java vs S.O.print())
 */
void println(char* str) { // Also takes in a String.
	while ((PREV_ADDR % (WIDTH * 2)) != 0) { // While there is leftover data in the line (that we want to move to the next line).
		PREV_ADDR = PREV_ADDR + 2; // Move the address of where I left off lower down.
	} // End while
	print(str); // Call the print function again (continue the rest of the String data on the next line).
} // End println
