//....Subhashis PAUL

#include<stdio.h>
#include<stdlib.h>
struct array 
{
	int *arr; int size;
};
int Max(struct array *elements);  //Declaring Max() function to calculate max from the array
int Digits(int);     //Declaring Digits() function to calculate the number of digits of the max value
int do_ridix_sort(struct array *elements,int*);  //This is the main procedure function
int main()
{
	struct array elements;
	int i,max,digits;
	printf("\n\t\t\t\t\t- : RADIX SORT : -");
	printf("\n\n\n Enter the number of elements in array : "); //Taking Number of elements in the array
	scanf("%d",&elements.size);
	elements.arr = (int*)malloc(elements.size*sizeof(int));  // Allocating memory for the array
	printf("\n Enter the elements : ");  // Entering the elements in array
	for(i=0; i<elements.size; i++)
	scanf("%d",elements.arr+i);
	max = Max(&elements);             // Calling Max() to calculate the max value in the array
	digits = Digits(max);       //  Calling Digits() to calculate no of digits od the max value 
	// No of pass = no of digits in the max value
	// for that using loop  for "No of pass" value time
	for(i=1; i<=digits; i++)
	do_ridix_sort(&elements,&i);    // Passing structure and 'i' value
	                                // Passing 'i' to denote the position like 1s position, 10s position etc. 
	printf("\n\n After sorting the elements are : ");  // Printing the the sorted elements
	for(i=0; i<elements.size; i++)
	printf("%d\t",*(elements.arr+i));
return 0;
}

int Max(struct array *elements)    // Max() ....Here I am accepting the structue elements
{
	int i,m;
	m = *(elements->arr);
	for(i=1;i<elements->size;i++)
		if(*(elements->arr+i) > m)
			m = *(elements->arr+i);
return m;                               // And returning the max value
}

int Digits(int val)         // Digits() ....Here I am accepting the max value
{
	int digits = 0, rem;
	while(val > 0)
	{
		rem = val % 10;
		val = val - rem;
		val = val / 10;
		digits++;
	}
return digits;              // And returning the no of digits
}

int do_ridix_sort(struct array *elements, int *loop)  // This is the main procedure
{                                                     // Here I am accepting the Structure elements as a pointer
	int i,j,rem,temp;                     //  And also accepting the 'i' value as a pointer named '*loop'
	int **temp_arr;                   // Declaring a temporary 2D array of pointers 
	int check[10];   // Declaring a normal array to calculate the frequency of elements in 'temp_arr' array
	temp_arr = (int**)malloc(10*sizeof(int*)); // Allocating memeory of row in 'temp_arr' array
	for(i=0;i<10;i++)
	check[i]=0;              // Initially considering the value of each elements in 'check[10]' array as '0'
	/*   check ->      0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  
	                   0  |  0  |  0  |  0  |  0  |  1  |  0  |  0  |  0  |  0    */
	                   
	for(i=0; i<elements->size; i++)   // If we consider a array   { 15 ,  115 , 111 }     here,  *loop = 1
	{                                                      
		temp = *(elements->arr+i);   // for i=0,  temp = 15
		for(j=0; j<*loop; j++)                                 // if we rotate loop 1 time
		{                                                    //  it will take the 1s position value
		rem = temp % 10;                                     // if we rotate loop 2 times
		temp = temp - rem;          						//  it will take the 10s position value
		temp = temp / 10;                                       // And so on
		}
	if(check[rem] == 0)     
	*(temp_arr+rem) = (int*)calloc(1,1*sizeof(int)); 
	
	else  // if check[5] > 0, then memeory is already allocated, for that we have to reallocate memory
	*(temp_arr+rem) = (int*)realloc(*(temp_arr+rem),(check[rem]+1)*sizeof(int));  //realloc function
	
	// After allocating memory, temp_arr[5][0] will be 15
	*(*(temp_arr+rem)+check[rem]) = *(elements->arr+i);
	check[rem]++;   // 'check[5] = 0' will be 'check[5] = 1' ... It is denoting that a value is stored in
	}                                                       //                               temp_arr[5] position
int k=0;
for(i=0;i<10;i++)
{
	if(check[i] > 0) // If check[i] > 0, then 'temp_arr' value will be stored in 'structure array elements'
	for(j=0;j<check[i];j++)
	{
		elements->arr[k]=*(*(temp_arr+i)+j);
		k++;
	}
}
free(temp_arr);
return 0;
}









