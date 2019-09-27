#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX(a,b) ((a > b) ? a : b)
#define MIN(a,b) ((a < b) ? a : b)
#define TRUE 1
#define FALSE 0

#define NUMBER_OF_DEFINED_FUNCTION_IN_MENU 10


	typedef struct word {
    char name[15];
    unsigned short score;
	}word;


/*	 solutions to problems based on 	https://projecteuler.net        */	

/*						FUNCS THAT WILL BE USED 					*/

/****************************************************************************
 * Function Name  : trim
 * Inputs         : str
 * Outputs        : Currently None
 * Returns        : str
 * Description    : trims spaces
 ****************************************************************************/
char *trim(char *str)
{
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;

    if( str == NULL ) { return NULL; }
    if( str[0] == '\0' ) { return str; }

    len = strlen(str);
    endp = str + len;

    while( isspace((unsigned char) *frontp) ) { ++frontp; }
    if( endp != frontp )
    {
        while( isspace((unsigned char) *(--endp)) && endp != frontp ) {}
    }

    if( str + len - 1 != endp )
            *(endp + 1) = '\0';
    else if( frontp != str &&  endp == frontp )
            *str = '\0';

    endp = str;
    if( frontp != str )
    {
            while( *frontp ) { *endp++ = *frontp++; }
            *endp = '\0';
    }

    return str;
}

/****************************************************************************
 * Function Name  : trim_char
 * Inputs         : string , char
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : to get rid of that exact char from string
 ****************************************************************************/
char *trim_char(char *str,char el)
{
	int len = strlen(str);
	int i = 0,found = 0;

	while(str[i])
	{
		if(str[i] == el)
		{
			found++;
			for (int j = i; j < len-1; ++j)
			{
				str[j] = str[j+1];
				str[j+1] = NULL;
			}
		}

		i++;
	}
	str[len] = '\0';

	return str;
}

/****************************************************************************
 * Function Name  : strrev
 * Inputs         : char* -> string to work with
 * Outputs        : Currently None
 * Returns        : none
 * Description    : reverses given string
 ****************************************************************************/
void strrev(char *str)
{
	
	int i=0,j=0; 
	char temp;
	j=strlen(str)-1; 

	while(i<j)
    {
        temp=str[j];
        str[j]=str[i];
        str[i]=temp;
        i++;
        j--;
    } 
		
}

/****************************************************************************
 * Function Name  : string_value
 * Inputs         : char* -> string to work with
 * Outputs        : Currently None
 * Returns        : i
 * Description    : sum of ascii values of given string
 ****************************************************************************/
int string_value(char *str)
{
	int total = 0,i = 0;
	
	while(str[i] && str[i] != '\0')
	{
		printf("%d\n",str[i] );
		total += str[i];
		i++;
	}

	return i;
}

/****************************************************************************
 * Function Name  : itoa
 * Inputs         : int num   -> number to cast into string
 					char* str -> char pointer to return string
 					int base  -> in what base we need the string
 * Outputs        : Currently None
 * Returns        : char* str
 * Description    : integer to ascii , 
 ****************************************************************************/
char* itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    int isNegative = 0; 
  
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    if (num < 0 && base == 10) 
    { 
        isNegative = 1; 
        num = -num; 
    } 
  
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; 
  
    strrev(str); 
  
    return str; 
} 

/****************************************************************************
 * Function Name  : find_power
 * Inputs         : int number,power
 * Outputs        : Currently None
 * Returns        : power of that number multiplied with power int
 * Description    : 
 ****************************************************************************/
int find_power(const int number,const int power)
{
	if(power == 0)
		return 1;

	int returnval = 1;

	for (int i = 0; i < power; ++i)
	{
		returnval *= number;
	}

	return returnval;
}

/****************************************************************************
 * Function Name  : array_print
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : 
 * Description    : 
 ****************************************************************************/
void array_print(int *str)
{
	printf("PRINTING ARRAY  ->  ");

	for (int i=0; str[i]!= '\0'; i++) 
    { 
        printf("%d ",str[i]);
    } 
    printf("\n");
} 

	

/****************************************************************************
 * Function Name  : number_of_letters_in_String
 * Inputs         : str
 * Outputs        : Currently None
 * Returns        : int returnval
 * Description    : count of letters seperated with spaces
 ****************************************************************************/
int number_of_letters_in_String(char *str)
{
	int returnval = 0;
	int n = strlen(str);

	char *token = malloc(sizeof(char) * (n + 1));

	token = strtok(str, " ");


	while (token != NULL)
    {
    	int m = strlen(token);
    	returnval += m ;
        token = strtok(NULL," ");
	}
	free(token);
	token = NULL;
	return returnval;
}


/****************************************************************************
 * Function Name  : find_factorial
 * Inputs         : u_int64_t n
 * Outputs        : Currently None
 * Returns        : u_int64_t returnval
 * Description    : returns factorial of given number
 ****************************************************************************/
u_int64_t find_factorial(u_int64_t n)
{
	u_int64_t returnval = 1;

	for (u_int64_t  i = n; i > 1; i--)
	{
		returnval = returnval * i;	
	}

	return returnval;
}	

/****************************************************************************
 * Function Name  : find_digit_array
 * Inputs         : u_int64_t n, u_int64_t *array_count
 * Outputs        : Fills array_count pointer based on array count
 * Returns        : pointer to int array
 * Description    : how many digits does given number has , also fills array_count
 ****************************************************************************/
unsigned char find_dig_array(u_int64_t n, u_int64_t *digit_array, u_int64_t *array_count)
{
	u_int64_t remainder = 0;
	int i = 0;

	if(!digit_array || !array_count || n == 0)
		return FALSE;

	while(n!=0)
  	{
  		remainder = n % 10;
  		digit_array[i] = remainder;
    	n = n/10;
    	i++;
  	}

  	*array_count = i;

  	return TRUE;
}


/****************************************************************************
 * Function Name  : find_div_array
 * Inputs         : int n
 * Outputs        : Currently None
 * Returns        : pointer to div array
 * Description    : To find divisors of given nubmer
 ****************************************************************************/
unsigned char find_div_array(u_int64_t n,int * div_array, u_int64_t *div_count)
{
	if(!div_array || !div_count)
		return FALSE;

	int j = 0;

	   for (int i=1;i*i<=n;i++) 
        if (n%i==0)
        {
        	if (n / i == i)
        	{
        		div_array[j] = i;
        		j++; 
        	} 
            else
            {
        	div_array[j] = i;
        	div_array[j+1] = n/i;
        	j += 2;
        	}
        } 
        
        *div_count = j ;

    return TRUE;
}

/****************************************************************************
 * Function Name  : find_div_array
 * Inputs         : int n
 * Outputs        : Currently None
 * Returns        : pointer to div array
 * Description    : To find divisors of given nubmer
 ****************************************************************************/
int sum_of_divisors(int *div_array,u_int64_t div_count)
{
	// printf("IN SUM OF DIV count -> %lu\n",div_count);
	u_int64_t returnval = 0;

	for (int i = 0; i < div_count; ++i)
	{
		returnval += div_array[i];
	}

	return returnval;
}


/****************************************************************************
 * Function Name  : is_Prime
 * Inputs         : int n
 * Outputs        : Currently None
 * Returns        : 1/0
 * Description    : To check if given number is prime or not
 ****************************************************************************/
int is_Prime(int n)
{
	int return_value  = 1;

	if(n == 1) return 0;
	if(n == 2) return 1;

    for (int i = 3; i*i <= n ; i = i+2) 
    { 
		if (n % i == 0)
		{ 
			return return_value = 0; 
	    } 
    } 
return return_value;
}


/****************************************************************************
 * Function Name  : is_Palindrome
 * Inputs         : int n
 * Outputs        : Currently None
 * Returns        : 1/0
 * Description    : To check if given number is palindrome or not
 ****************************************************************************/
int is_Palindrome(int n)
{
	int t;
	int reverse = 0;
	
	t = n;
 
   while (t != 0)
   {
      reverse = reverse * 10;
      reverse = reverse + t%10;
      t = t/10;
   }

	if( n == reverse)
	{
		printf("%d IS PALINDROME \n",n );
		return 1;
	}
	else
	{
		return 0;
	}
}



void swapstr(char *str1, char *str2) 
{ 
  char *temp = str1; 
  str1 = str2; 
  str2 = temp; 
  free(temp);
}   

/****************************************************************************
 * Function Name  : array_shift_left
 * Inputs         : str1,n
 * Outputs        : Currently None
 * Returns        : Char pointer to result
 * Description    : append with '0' s to end of string
 ****************************************************************************/
void array_shift_left(char * str,int n)
{
	int slen = strlen(str);

	for (int i = slen; i < slen+n; ++i)
	{
		str[i] = '0';
	}

	// printf("IN ARRAY SHITFT LEFT RESULT-> %s\n",result );

}

/****************************************************************************
 * Function Name  : adding_digits_of_string
 * Inputs         : str
 * Outputs        : Currently None
 * Returns        : u_int64_t return_val
 * Description    : finding sum of all digits of given large number
 ****************************************************************************/
u_int64_t adding_digits_of_string(char *str)
{
	u_int64_t n1 = strlen(str);
	u_int64_t return_val = 0;

	for (int i = 0; i < n1; ++i)
	{
		return_val += ( str[i] - '0' ); 		
	}

	return return_val;
}

/****************************************************************************
 * Function Name  : add_of_string
 * Inputs         : str1,str2
 * Outputs        : Currently None
 * Returns        : Char pointer to result
 * Description    : adds two large numbers that taken as char pointers
 ****************************************************************************/
char * add_string(const char* str1,const char* str2)
{
	// free str?
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	char *tempstr1 = malloc((sizeof(str1) * n1 ));
	char *tempstr2 = malloc((sizeof(str2) * n2 ));
	char *str = malloc((sizeof(str1) * n1 ) + (sizeof(str2) * n2  ) + 5*10);
	
	strcpy(tempstr1,str1);
	strcpy(tempstr2,str2);

	int min = MIN(n1,n2);
	int sum;

	if(n1 > n2)
		swapstr(tempstr1,tempstr2);

	strrev(tempstr1);
	strrev(tempstr2);
	

	int carry = 0;


	for (int i=0; i<min; i++) 
    { 
        sum = ((tempstr1[i]-'0')+(tempstr2[i]-'0')+carry); 
        str[i] = (sum%10 + '0'); 
  
        carry = sum/10; 
    }

    for (int i=min; i<n2; i++) 
    { 
        int sum = ((tempstr2[i]-'0')+carry); 
        str[i] = (sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    if (carry) 
    str[n2] = (carry+'0'); 
	
	strrev(str);
	// printf("	ADDING %s w %s Returning result of : %s\n",str1,str2,str );

	free(tempstr1);
	free(tempstr2);
	tempstr1 = NULL;
	tempstr2 = NULL;
	return str;
}

/****************************************************************************
 * Function Name  : mup_of_string
 * Inputs         : char* str1,int num
 * Outputs        : Currently None
 * Returns        : char pointer to result
 * Description    : multiplies one large number with  a number that below 10
 ****************************************************************************/
char* mup_string(const char *str1,int num)
{	
	int n1 = strlen(str1);
	char *result = malloc(sizeof(char) * (n1 * 2) + 4 );


	if(num == 0)
		return itoa(0,result,10);

	// printf("FUNC : %s, array1 -> %s , num -> %d\n",__FUNCTION__,str1,num );

	int j = 0,sum;
	int carry = 0;

	for (int i = n1-1; i >= 0; --i)
	{
		sum = ( str1[i] - '0' ) * num + carry ;
		result[j] = sum % 10 + '0';
		carry = sum /10 ;
		j++;
	}

	if(carry)
		result[j] = carry + '0';

	strrev(result);

	// printf("IN MUP RESULT = %s\n",result );

	return result;
}

/****************************************************************************
 * Function Name  : mup_of_string
 * Inputs         : str1,str2 -> char pointers that stores large numbers 
 * Outputs        : Currently None
 * Returns        : char pointer of result
 * Description    : multiplies two strings that stores large numbers, uses 
					mup_string function 						222
																111 x 
																222
															   2220
															  22200 + 
															  24642
 ****************************************************************************/
char* mup_2_strings(const char * str1,const char * str2) 
{ 

    int n1 = strlen(str1); 
    int n2 = strlen(str2);
    int num = 1;

    if (n1 == 0 || n2 == 0) 
    return "0"; 

    char *result = malloc(sizeof(char)*(n1) * 2 + 4);
    char *mup_result = malloc(sizeof(char)*(n1) * 2 + 4);
    int tenmultiplier = 0;

    if(result == NULL)
    printf("THERE IS A PROBLEM\n");

    for (int i = n1-1; i >= 0; --i)
    {
    	num = str1[i] - '0';

    	// printf("BEFORE str2->%s num->%d\n",str2,num );
    	mup_result = mup_string(str2,num);
    	array_shift_left(mup_result,tenmultiplier);
    	result = add_string(result,mup_result);

    	tenmultiplier++;
    }

    // printf("result of it->%s\n\n ",result);
    return result;
} 

/****************************************************************************
 * Function Name  : swap
 * Inputs         : int xp,int yp
 * Outputs        : Currently None
 * Returns        : 
 * Description    : swap two integers
 ****************************************************************************/
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
/****************************************************************************
 * Function Name  : bubbleSort
 * Inputs         : u_int64_t n
 * Outputs        : Currently None
 * Returns        : 
 * Description    : 
 ****************************************************************************/
void bubbleSort(int arr[], int array_length) 
{ 
   int i, j; 
   for (i = 0; i < array_length-1; i++)       
      
       for (j = 0; j < array_length-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 


/****************************************************************************
 * Function Name  : fibonacci_sequence
 * Inputs         : u_int64_t n
 * Outputs        : Currently None
 * Returns        : 
 * Description    : 
 ****************************************************************************/
u_int64_t fibonacci_sequence(int n)
{
	static int fib_func_called = 0;

	if(n <= 0)
	{
		printf("ERROR");
		return -1;
	}

	if(n == 1 || n == 2)
		return 1;

	u_int64_t returnval = fibonacci_sequence(n-1) + fibonacci_sequence(n-2);
	printf("FIB RESULT = %lu fib_func_called = %d\n",returnval,fib_func_called );

	fib_func_called++;
	return returnval;
}

