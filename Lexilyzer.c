// Michael Said
// Liam May
// COP 3402
// Spring 2020

#include <stdio.h>
#include <string.h>
#include <stdbool.h> // for booleans
#include <ctype.h> // for isalpha/isdigit
#include <stdlib.h> // for malloc

#define MAX_IDENT_LENGTH 11
#define MAX_NUM_LENGTH 5
#define MAX_CODE_LENGTH 550

typedef enum
{
  nulsym = 1, identsym = 2, numbersym = 3, plussym = 4, minussym = 5, multsym = 6,
  slashsym = 7, oddsym = 8, eqlsym = 9, neqsym = 10, lessym = 11, leqsym = 12,
  gtrsym = 13, geqsym = 14, lparentsym = 15, rparentsym = 16, commasym = 17,
  semicolonsym = 18, periodsym = 19, becomessym = 20, beginsym = 21, endsym = 22,
  ifsym = 23, thensym = 24, whilesym = 25, dosym = 26, callsym = 27, constsym = 28,
  varsym = 29, procsym = 30, writesym = 31, readsym = 32 , elsesym = 33
} token_type;

typedef struct lexemes
{
  token_type type;
  char *lexeme;
}lexeme;

void trim(char *str);
void parse(char *code);
bool isReserved(char *str);

void trim(char *str)
{
  int lp = 0, rp, diff, i, len = strlen(str);
  i=0;
  char trimmed[MAX_CODE_LENGTH];

  while (str[lp] != '\0')
  {

    if (str[lp] == '/' && str[lp + 1] == '*')
    {
      rp = lp + 2;
      while (str[rp] != '*' && str[rp + 1] != '/')
      {
        rp++;
      }
      //rp += 2; // rp = rp + 2
      lp= rp+2;
    }
    trimmed[i] = str[lp];
    i++;
    lp++;
  }
  printf("\nTrimmed input:\n*%s*\n", trimmed);
  return;
}

void parse(char *code)
{
  lexeme list[MAX_CODE_LENGTH];
  lexeme *lptr;
  int lp = 0, rp, length, i;
  char buffer[MAX_CODE_LENGTH];

  while (code[lp] != '\0')
  {
    if (isalpha(code[lp]))
    {
      rp = lp;
      // capturing length of substring
      while (isalpha(code[lp]) || isdigit(code[lp]))
      {
        rp++;
      }
      length = rp - lp;

      // checking for ident length error
      if (length > MAX_IDENT_LENGTH)
      {
        printf("Err: ident length too long\n");
        return;
      }

      // creating substring
      for (i = 0; i < length; i++)
      {
        buffer[i] = code[lp + i];
      }

      if (isReserved(buffer))
      {
        
      }
    }
    else
    {
      // err
    }
  }

}

// return true if the string is a reserved keyword and false otherwise
bool isReserved(char *str)
{
  // Table of reserved word names
  char reserved[14][9] = { "const", "var", "procedure", "call", "begin", "end",
                           "if", "then", "else", "while", "do", "read", "write",
                           "odd" };

  if (str[0] == 'b')
  {
    if (strcmp(reserved[4], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'c')
  {
    if (strcmp(reserved[0], str) == 0)
    {
      return true;
    }
    else if (strcmp(reserved[3], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'd')
  {
    if (strcmp(reserved[10], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'e')
  {
    if (strcmp(reserved[5], str) == 0)
    {
      return true;
    }
    else if (strcmp(reserved[8], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'i')
  {
    if (strcmp(reserved[6], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'o')
  {
    if (strcmp(reserved[13], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'p')
  {
    if (strcmp(reserved[2], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'r')
  {
    if (strcmp(reserved[11], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 't')
  {
    if (strcmp(reserved[7], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'v')
  {
    if (strcmp(reserved[1], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'w')
  {
    if (strcmp(reserved[9], str) == 0)
    {
      return true;
    }
    else if (strcmp(reserved[12], str) == 0)
    {
      return true;
    }
  }
  return false;
}

int main(int argc, char **argv)
{
  FILE *fp;
  fp = fopen(argv[1], "r");
  char aSingleLine[MAX_CODE_LENGTH], code[MAX_CODE_LENGTH] = {'\0'};

  while(!feof(fp))
  {
    fgets(aSingleLine, MAX_CODE_LENGTH, fp);
    strcat(code, aSingleLine);
  }
  printf("Input:\n%s\n", code);

  trim(code);

  fclose(fp);
  return 0;
}
