#include <stdio.h>

/* swap_nums() works, but swap_pointers() doesn't.  Try using the
 debugger to understand what's going wrong, and then fix it. */

void swap_nums(int *x, int *y)
{
	int tmp;

	/* Use a debugger to step into this function and compare the addresses and values
	 * of 'x' and 'y' with 'a' and 'b'. */
	tmp = *x;
	*x = *y;
	*y = tmp;
}

swap_pointers(char **x, char **y)
{
	char *tmp;

	/* Use a debugger to step into this function and compare the addresses and values
	 * of 'x' and 'y' with 's1' and 's2'. HINT: does x point to the address of s1? */
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	int a, b; /* Declare two integers */
	char *s1, *s2; /* Declare two character arrays to hold strings */
	/* In C, "char *" is more often thought of as a string (or array of chars) than
	 * a "char pointer". For a pointer to a string, use "char **". */
    char *string1 = "I should print second", *string2 = "I should print first";
	a = 3;
	b = 4;
	printf("Before swap_nums(), a=%d and b=%d\n", a, b);
	swap_nums(&a, &b);
	printf("After swap_nums(), a=%d and b=%d\n", a, b);
	s1 = NULL;
	s2 = NULL;
	s1 = (char *)malloc(sizeof(*string1));
	s2 = (char *)malloc(sizeof(*string2));
	s1 = string1;
	s2 = string2;
	swap_pointers(&s1, &s2);
	printf("s1 is \"%s\"\n", s1);
	printf("s2 is \"%s\"\n", s2);

	return 0;
}
