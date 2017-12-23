#ifndef PRINT_H_
#define PRINT_H_

/* print_body_parts()
 * Purpose: Prints the hangman board with a certain number of body parts
 *          printed.
 * Parameters: int (number of body parts printed with 0-based indices)
 * Return Type: void
 * Errors Thrown: Exit if a number is given that is greater than the number of
 *                body parts available to be printed.
 */
void print_body_parts(int n);

#endif
