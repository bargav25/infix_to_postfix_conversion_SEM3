#include<iostream>
using namespace std;

int top1 = -1;
int top2 = -1;
char helper[20];
char postfix[20];


void pushhelper (char x)
{
  helper[++top1] = x;
}

void pushpostfix (char x)
{
  postfix[++top2] = x;
}

char pophelper ()
{
  char element = helper[top1];
  top1--;
  return element;
}

char peek ()
{
  char element = helper[top1];
  return element;
}

int order (char x)
{
  switch (x)
    {
    case '(':
      return 0;
      break;
    case '+':
    case '-':
      return 1;
      break;
    case '*':
    case '/':
      return 2;
      break;
    case '^':
      return 3;
      break;

    }
}

int main ()
{
  char shire[20];
  char element;
  scanf ("%s", shire);
  char buffer;

  int m;

  int i = 0;
  element = shire[0];
  while (element != '\0')

    {

      element = shire[i];
      m = element;
      if (m == 40)
	{
	  pushhelper (element);

	}

      else if (m == 43 || m == 45 || m == 47 || m == 42)
	{



	  buffer = peek ();
	  while (order (element) <= order (buffer))
	    {
	      buffer = pophelper ();
	      pushpostfix (buffer);
	      buffer = peek ();

	    }






	  pushhelper (element);



	}



      else if (m == 41)
	{

	  while (helper[top1] != '(')
	    {
	      buffer = pophelper ();
	      pushpostfix (buffer);

	    }
	  pophelper ();

	}
      else
	{
	  pushpostfix (element);

	}


      i++;

    }

 


  while (top1 != -1)
    {
      element = pophelper ();

      pushpostfix (element);
    }

  for (i = 0; i <= top2; i++)
    {
      element = postfix[i];
      cout << element;
    }
}
