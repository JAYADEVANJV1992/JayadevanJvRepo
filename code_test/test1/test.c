#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** invalidTransactions(char** transactions, int transactionsSize, int* returnSize);
#ifdef TEST12
int main() {
    int a[] = {1,67};
    int b[] = {24,12,5};
    int size_a = sizeof(a) / sizeof(a[0]);
    int size_b = sizeof(b) / sizeof(b[0]);
    int total_size = size_a + size_b;
    
    int *c = (int *)malloc(total_size * sizeof(int)); // Allocate enough space for the merged array
    if (c == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }

    int i = 0, j = 0, k = 0; // Initialize indices for a, b, and c

    // Merge the two arrays
    while (i < size_a && j < size_b) {
        if (a[i] < b[j]) {
            c[k++] = a[i++]; // Add from array a and increment
        } else {
            c[k++] = b[j++]; // Add from array b and increment
        }
    }

    // Add remaining elements from array a
    while (i < size_a) {
        c[k++] = a[i++];
    }

    // Add remaining elements from array b
    while (j < size_b) {
        c[k++] = b[j++];
    }

    // Print the merged array
    printf("Merged array:\n");
    for (int m = 0; m < total_size; m++) {
        printf("val = %d\n", c[m]);
    }

    // Free the allocated memory
    free(c);

    return 0;
}
#endif
#ifdef STR
int main() {
	int a[]= {1,3,2,6};
	int b[]= {7,4,5};
	int t1=0;
	int a_s = sizeof(a) / sizeof(a[0]);
	int b_s = sizeof(b) / sizeof(b[0]);
	int si = a_s+b_s;
	int m = 0,n=0;
	int arr[si];
	int i=0,j=0,k=0,f_s =0, s_s =0;
	int *f,*s;
	int *p = (int *)malloc(si * sizeof(int));
	    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }
	
	if(a_s>=b_s)
	{
		f_s = a_s;
		s_s = b_s;
		f = a;
		s = b;
		
	}
	else
	{
		f_s = b_s;
		s_s = a_s;
		f = b;
		s = a;
	}
	
    // for(i=0;i<f_s;i++)
	// {
		// printf("f_s= %d\n", f_s);
	// }
	
	 // for(i=0;i<f_s,k<s_s;i++)
		for(i=0;i<f_s;i++)
	{
			
		//if(j<f_s)
		{
			for(j=i+1;j<f_s;j++)
			{
				if(f[i] <= f[j])
				{
					/// p[n++] = f[i];
					
					// arr[m] = f[i];
					// printf("arr[%d] = %d\n",m, arr[m]);
					// printf("no\n");
					
				
				}
					
				else
				{
					//*(p++) = f[j];
					
					// arr[m] = f[j];
					// printf("yes\n");
					// printf("f_i[%d] = %d\n", i,f[i]);
					// printf("f_j[%d] = %d\n", j,f[j]);
					t1 = f[j];
					f[j] = f[i];
					f[i] = t1;
					// printf("swap\n");
					// printf("f_i[%d] = %d\n", i,f[i]);
					// printf("f_j[%d] = %d\n", j,f[j]);
				}
				
			}
		printf("f[%d] = %d\n", i,f[i]);
			// m++;
			
		}
		//else
		{
				   
		}
	}
		for(i=0;i<s_s;i++)
		{
	
	         if(f[f_s-1] <= s[i])
				{
					//*(p++) = f[i];
					// arr[m++]= f[i];
					
				}	
                else
				{
					//*(p++) = s[k];
					// arr[m++]= s[k];
					t1 = s[i];
					s[i] = f[f_s-1];
					f[f_s-1] = t1;
				}	
               // m++;	
              		
		}
   
	for(i=0;i<f_s;i++)
	{
		printf("f[%d] = %d\n",i, f[i]);
	}
	for(i=0;i<s_s;i++)
	{
		printf("s[%d] = %d\n",i, s[i]);
	}
	for(i=0;i<s_s;i++)
	{
			for(j=i+1;j<s_s;j++)
			{
				if(s[i] <= s[j])
				{				
				}
					
				else
				{
					t1 = s[j];
					s[j] = s[i];
					s[i] = t1;
				}
				
			}
			
	}
	printf("after\n");
		for(i=0;i<f_s;i++)
	{
		printf("f[%d] = %d\n",i, f[i]);
	}
	for(i=0;i<s_s;i++)
	{
		printf("s[%d] = %d\n",i, s[i]);
	}
	for(i=0;i<si;i++)
	{
		if(i<f_s)
		p[i] = f[i];
	    else
	    p[i] = s[(i-1)-s_s];
		
	}
	for(i=0;i<si;i++)
	{
		printf("p[%d] = %d\n",i, p[i]);
	}
	 free(p);
	return 0;
}
#endif
#ifdef TEST3
int main() {
	
	char *transactions[]= {
        "alice,20,1800,mtv",
        "alice,50,1200,beijing"
    };
	char **ret;
	  int returnSize;
	int num_transactions = sizeof(transactions) / sizeof(transactions[0]);
	ret = invalidTransactions(transactions,num_transactions,&returnSize);
	printf("returnSize =%d\n",returnSize);
	for(int i=0;i<returnSize;i++)
	{
	 printf("ret =%s\n",  ret[i]);
	
	}
	
	return 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** invalidTransactions(char** transactions, int transactionsSize, int* returnSize) {
    int i=0,j=0;
    char *s;
    char name[100];
    
    typedef struct{
        char name[10];
        char time[10];
        char amt[10];
        char city[10];
    } trans;
    
    trans tr[transactionsSize];
	int k=0,k2=0,k3 =0,k4 = 0;
	int m=0;
	char** invalidList = malloc(transactionsSize * sizeof(char*));
	printf("val =%c\n",  invalidList[0][0]);
    for(i=0;i<transactionsSize;i++)
    {
        
       s = transactions[i];
        while(s[j] != ',') 
        {           
            tr[i].name[k] =  s[j];
            k++;
            j++;
        }
        tr[i].name[k] =  '\0';
        j++;
        while(s[j] != ',') 
        {           
            tr[i].time[k2] =  s[j];
            j++;
            k2++;
            
         
        }
        tr[i].time[k2] =  '\0';
        j++;
        while(s[j] != ',') 
        {           
            tr[i].amt[k3] =  s[j];
            j++;
            k3++;
            
         
        }
        tr[i].amt[k3] =  '\0';
        j++;
        while(s[j] != '\0') 
        {           
            tr[i].city[k4] =  s[j];
            j++;
            k4++;
            
         
        }
          tr[i].city[k4]  =  '\0';
             printf("name =%s\n",  tr[i].name);
             printf("time =%s\n",  tr[i].time);
         printf("amt =%s\n",  tr[i].amt);
         printf("city =%s\n",  tr[i].city);
        k=0;
        j=0;
        k2=0;
        k3=0;
        k4=0;
		printf("val =%c\n",  invalidList[0][0]);
		if(atoi(tr[i].amt) > 1000)
		{
			invalidList[m] = malloc(10 * sizeof(char));
			
			strcat(invalidList[m],tr[i].name);
			strcat(invalidList[m],tr[i].time);
			strcat(invalidList[m],tr[i].amt);
			strcat(invalidList[m],tr[i].city);
			// sprintf(invalidList[m], "%s,%s,%s,%s", tr[i].name, tr[i].time, tr[i].amt, tr[i].city);
			m++;
		}
		
    }
	
	printf("val =%c\n",  invalidList[0][0]);
	
	*returnSize = m;
  return invalidList;  
}
#endif



// Function to calculate Fibonacci number using recursion

#ifdef TEST4
int fib(int n){
int k=0;
    while(n>0)
    {
       k=n+k;
	   n--;
    }
    return k;
}
int f(int n)
{
	static k=0;
	k=k+n+f(n-1);
}
int main() {
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fib: %d",fib(n));

    
    return 0;
}
#endif


struct ls{
	int data;
	struct ls *next;
};

void insert_beg(int val);
void insert_last(struct ls *node, int val);
void display(struct ls *ptr);
void create(int firstVal);
void delete(struct ls *head,int val);
void insert_loc(int loc,int val);
struct ls *head;
struct ls *fir;
struct ls *sec;
struct ls *thi;


void insert_beg(int val)
{
	struct ls *ptr;
	ptr = (struct ls *) malloc(sizeof(struct ls));
	if(NULL == ptr)
	{
		printf("Memory allocation failed\n");
	}
	else
	{
		ptr->data = val;
		ptr->next = head;

    head = ptr;	
	}
}

void insert_loc(int loc,int val)
{
	
	
	struct ls *tmp1;
	struct ls *ptr = (struct ls *) malloc(sizeof(struct ls));;
	tmp1 = head;
	ptr->data = val;
	if(NULL == ptr)
	{
		printf("Memory allocation failed\n");
	}
	else
	{
		
		for(int i=0;i<loc;i++)
		{
			tmp1 = tmp1->next;
			//tmp2= ptr->next;
			
		}

		ptr->next = tmp1->next;
		tmp1->next = ptr;
		// printf("\nddd = %d",tmp1->data);
		// ptr->data = val;
		// ptr->next = tmp1->next;

    
	}
}
void insert_last(struct ls *node, int val)
{
	struct ls *ptr;
	ptr = (struct ls *) malloc(sizeof(struct ls));
	if(NULL == ptr)
	{
		printf("Memory allocation failed\n");
	}
	else
	{
	ptr->data = val;
    ptr->next = NULL;
    head = ptr;	
	}	
}
void display(struct ls *ptr)
{
			printf("Data is below-----\n");
	while(ptr!=NULL)
	{

		printf("%d  %u\n",ptr->data,ptr->next);
		ptr = ptr -> next;
		
	}
	
}

void create(int firstVal)
{
	head = (struct ls *) malloc(sizeof(struct ls));
	head -> data = firstVal;
	head -> next = NULL;
}
void delete(struct ls *head,int val)
{
	struct ls * ptr;
	struct ls * tmp;
	struct ls * tmp2;
	int j=0;
	//ptr = (struct ls *) malloc(sizeof(struct ls));
	ptr = head;
int m=0,n=0,k=0;
	for(ptr=head;ptr->next !=NULL; ptr=ptr->next)
	
	{
		j++;
		if(ptr->data == val)
		{
			tmp = ptr;
		}
	}
	//ptr = head;
	/*for(int k=0;k<(j-1);k++)
	{	
      // printf("\n j = %d\n",j);
      if(ptr->data == val)
	  {
		  m=k;
		  // printf("\nhere");
		  tmp = ptr;
		    free(ptr);
		  ptr=tmp->next;
		   return;
		 
	  }	
      ptr = ptr -> next;  
	}*/
    /*ptr=head;	
    while(n<k-1)
	{
      ptr = ptr -> next; 
	}
tmp2=	ptr;
ptr=tmp2->next;*/
	
}
void main()
{
	/*head = (struct ls *) malloc(sizeof(struct ls));
	fir = (struct ls *) malloc(sizeof(struct ls));
	sec = (struct ls *) malloc(sizeof(struct ls));
	thi = (struct ls *) malloc(sizeof(struct ls));
	
	head -> data = 34;
	head -> next = fir;
	fir -> data = 5;
	fir -> next = sec;
	sec -> data = 8;
	sec -> next = thi;
	thi -> data = 45;
	thi -> next = NULL;*/
   create(97);
   insert_beg(66);
   display(head);	
   
   insert_loc(0,3);
    display(head);	
	 insert_loc(0,6);
	  insert_loc(0,9);
	   insert_loc(0,12);
	   display(head);
	   delete(head,12);
	   display(head);
	
}


