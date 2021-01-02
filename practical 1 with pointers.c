/*
Assignment no- 1
Title of program-Write a C program to perform following string operations with and without pointers
to arrays (without using library functions):
a)  Substring   b)  Palindrome   c) Compare   d) Copy   e)Reverse
(With Pointers)
*/

#include <stdio.h>
//#include <conio.h>

void substr (char *str1, char *str2);
int palindrome (char *str);
int compare (char *str1, char *str2);
void copy (char *str1, char *str2);
void reverse (char *str);

int main () {
  char str1[100], str2[100];
  char *strptr1, *strptr2;
  strptr1 = str1;
  strptr2 = str2;
  int result, option;
  do {
    option = 0; //reset option
    printf ("\n1.Substring Searching");
    printf ("\n2.Check for Palindrome");
    printf ("\n3.String Comparison");
    printf ("\n4.Copy string");
    printf ("\n5.Reverse String");
    printf ("\n6.Quit");
    printf ("\n\nEnter Your Choice:");
    scanf ("%d", &option);
    switch (option)	{
	  case 1:
	    printf ("\nEnter 1st string:");
	    scanf ("%s", strptr1);
	    printf ("\nEnter 2nd string:");
	    scanf ("%s", strptr2);
	    substr (strptr1, strptr2);

	    printf ("\nPress a Character");
	    getch ();
	    break;

	  case 2:
	    printf ("\n Enter a String:");
	    scanf ("%s", strptr1);
	    result = palindrome (strptr1);

	    if (result == 0)
	      printf ("\nNot a palindrome");
	    else
	      printf ("\nA palindrome");

	    printf ("\nPress a Character");
	    getch ();
	    break;

	  case 3:
	    printf ("\nEnter 1st string:");
	    scanf ("%s", strptr1);
	    printf ("\nEnter 2nd string:");
	    scanf ("%s", strptr2);
	    result = compare (strptr1, strptr2);

	    if (result == 0)
	      printf ("\nboth are same");
	    else if (result > 0)
	      printf ("\n1st>2nd");
	    else
	      printf ("\n1st<2nd");

	    printf ("\nPress a Character");
	    getch ();
	    break;

	  case 4:
	    printf ("\nEnter a String:");
	    scanf ("%s", strptr1);
	    copy (strptr2, strptr1);

	    printf ("\nResult=%s", strptr2);

	    printf ("\nPress a Character");
	    getch ();
	    break;

	  case 5:
	    printf ("\nEnter a String:");
	    scanf ("%s", strptr1);
	    reverse (strptr1);

	    printf ("\nResult=%s", strptr1);
	    printf ("\nPress a Character");
	    getch ();
	    break;

	  case 6:
	    printf ("\nBye!");
	    break;

	  default:
	    printf ("\nInvalid Choice:");
	    break;
    }
  } while (option != 6);

  return 0;
}

void substr (char *str1, char *str2) {
  int i, j, lena, lenb;
  for (lena = 0; str1[lena] != '\0'; lena++);
  for (lenb = 0; str2[lenb] != '\0'; lenb++);
  for (i = 0; i <= lena - lenb + 1; i++) {
    for (j = 0; str1[i + j] == str2[j] && str2[j] != '\0'; j++);

    if (str2[j] == '\0')
	  printf ("\nString found at location : %d", i + 1);
    else{
        printf("Substring not found");
	}
  }
}

int palindrome (char *str) {
  int i, j;
  i = j = 0;

  while (str[j] != '\0')
    j++;

  while (i < j) {
    if (str[i] != str[j - 1])
	  return (0);
    i++;
    j--;
  }

  return (1);
}

int compare (char *str1, char *str2) {
  int i;
  i = 0;

  while (str1[i] != '\0') {
    if (str1[i] > str2[i])
	  return (1);

    if (str1[i] < str2[i])
	  return (-1);
    i++;
  }

  return (0);
}

void copy (char *str2, char *str1) {
  int i = 0;

  while (str1[i] != '\0') {
    str2[i] = str1[i];
    i++;
  }

  str2[i] = '\0';
}

void reverse (char *str) {
  int i, j;
  char temp;
  i = j = 0;

  while (str[j] != '\0')
    j++;
  j--;

  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}
