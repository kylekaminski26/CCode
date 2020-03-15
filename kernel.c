#include "console.h"

/*
 * "You will then alter your kernel_early function to perform the initialization tasks
 * of the variable in console.h"
 */
void kernel_early(void) {
	// This function is empty because the variables are initialized in console.h
}

/*
 * "Following that, use your functions in the main function in kernel.c to make sure they work.
 * How this is done is up to you. 
 * What you want to do is just provide some output that tests your functions."
 */
int main(void) {
	print("abcdefghijklmnopqrstuvwxyz01234567890123456789012345678901234567890hiprofessormckee!!!");
	print("thisisanormallengthstring");
	println("thisisanotveryjustkiddingveryveryverylongstringtotestmyprintlnmethodthankyouandgoodbye");
	println("tinystring");
	return 0;
}
