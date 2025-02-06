#include<stdio.h>
#include <stdlib.h>

int main()
{
	int a[] = {1,3};
	int b[] = {2,4,5};
	int i = 0, j = 0;
	int k = 0;
	int *f, *s, *c;
	c = (int *)malloc(5 * sizeof(int));
	if(a[0] < b[0])
	{
      f = a;
	  s = b;
	}
	else
	{
		f = b;
		s = a;
	}
	
			
	//if((a[i] != '\0') &&  (b[i] != '\0'))
		for (int k =0; k< ((sizeof(b)/sizeof(int))+(sizeof(a)/sizeof(int))) ; k++)
		{
		
	if((i < (sizeof(a)/sizeof(int))) &&  (i < (sizeof(b)/sizeof(int))))
	{
	  if(a[i] < b[i])
	  {
		  *(c++) = a[i];
		  *(c++) = b[i];
		  printf("c = %d",c[0]);
	  }	
     else
	 {
		 *(c++) = b[i];
		  *(c++) = a[i];
	 }	
	 
     	 
	}
	else
	{
		
	if(i >= (sizeof(a)/sizeof(int)))
	{
		while (i < (sizeof(b)/sizeof(int)))
		{
			*(c++) = b[i];
			i++;
			k=1;
		}
	}
	else if(i >= (sizeof(b)/sizeof(int)))
	{
		while (i < (sizeof(a)/sizeof(int)))
		{
			*(c++) = a[i];
			i++;
			k=1;
		}
	}
	}
	i++;
	
		}
	printf("i = %d", i);
	printf("size = %d", ((sizeof(b)/sizeof(int))+(sizeof(a)/sizeof(int))));
	if(k == 1)		
		{
			for (int m =0; m < ((sizeof(b)/sizeof(int))+(sizeof(a)/sizeof(int))) ; m++)
			{
				printf("val = %d\n", c[m] );
			}
			
		}
		
	return 0;
}
