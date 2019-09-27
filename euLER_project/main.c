#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <functions.h>

#define one_million 1000000




/*								EULER PROBLEM SOLUTIONS						*/
/****************************************************************************
 * Function Name  : PROB#25
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void thousand_digit_fibonacci_number()
{
	// u_int64_t temp;
	// char result[1000];

}

/****************************************************************************
 * Function Name  : PROB#24
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void Lexicographic_permutations()
{
	int number[10] = {0,1,2,3,4,5,6,7,8,9};

	array_print(number);

	int counter = 0;
	int i = 0;
	u_int64_t nine_fac = find_factorial(9);

	while(counter < one_million)
	{
		counter+=nine_fac;
		swap(&number[i],&number[i++]);
		i++;		
	}


	array_print(number);
	printf("%d\n",counter );

}

/****************************************************************************
 * Function Name  : PROB#23
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void non_abundant_sums()
{
	//max 28123
	int sum = 0;
	int total = 0;
	u_int64_t count;
	int temp_count = 0;
	int *div_array = malloc(sizeof(int) * sqrt(28123) + 8);
	int abundant_array[6961];
	int abundant_sum_array[28123];

	for (int i = 25; i <= 28123; ++i)
	{
		find_div_array(i,div_array,&count);
		sum = sum_of_divisors(div_array,count) - i;

		if(sum >i)
		{
			abundant_array[temp_count] = i;
			temp_count++;
		}
	}

	printf("temp_coutn -> %d\n",temp_count );

	for (int i = 0; i <= 6961; ++i)
	{
		for (int j = i; j <= 6961; ++j)
		{
			if(abundant_array[i] + abundant_array[j] <= 28123)
			{
				abundant_sum_array[abundant_array[i] + abundant_array[j]] = 1;
			}
		}
	}

	for (int i = 1; i <= 28123; ++i)
	{
		if(!abundant_sum_array[i])
		{
			total +=i;
		}
	}

	printf("%d\n",total );
}

/****************************************************************************
 * Function Name  : PROB#22
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void names_scores()
{

	word word_array[5500];
	memset(word_array,0x00,sizeof(word) * 5500);
	char temp[15+1];
	char *file = malloc(sizeof(char)*50000);
	if(!file)
		printf("ERROR\n");

	int i = 0;
	FILE * fp_prob = NULL;
	//READ
	fp_prob = fopen("prob22.txt","r");

	if(fp_prob  != NULL)
	{
		fseek( fp_prob , 0 , SEEK_SET );
		fread(file, sizeof(char)*47448, 1, fp_prob);
	}	
	else	printf("ERROR -> txt file could not found -> %d %s\n",__LINE__,__FUNCTION__ );

	//FILL VARIABLES
	char *token = malloc(sizeof(char) * (16 + 1));

	token = strtok(file, ",");

	while (token != NULL)
    {
    	strcpy(word_array[i].name,token);
        token = strtok(NULL,",");
        i++;
	}

    u_int64_t total = 0;
	int n = i;
	int j = 0;

	//SORT

	for (int j=0; j<n-1; j++) 
    { 
        for (int i=j+1; i<n; i++) 
        { 
            if (strcmp(word_array[j].name, word_array[i].name) > 0) 
            { 
                strcpy(temp, word_array[j].name); 
                strcpy(word_array[j].name, word_array[i].name); 
                strcpy(word_array[i].name, temp); 
            } 
        } 
    }

    for (int i = 0; i < n; ++i)
    {	
    	trim_char(word_array[i].name,'"');
     	while(word_array[i].name[j])
     	{
     		word_array[i].score += (word_array[i].name[j] - 64);
     		j++;
     	}

     	word_array[i].score *= (i+1);     	
     	total += word_array[i].score;

     	j=0;
    }

    for (int i = 0; i < n; ++i)
    {
    	printf("%d-> %s -> %d \n",i,word_array[i].name,word_array[i].score );
    }

    printf("total -> %lu\n",total );

}



/****************************************************************************
 * Function Name  : PROB#21
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void amicable_numbers()
{
	u_int64_t sum = 0;
	u_int64_t temp_sum = 0;
	u_int64_t count = 0;
	u_int64_t temp_count = 0;
	int result = 0;
	int *div_array = malloc(sizeof(int) * 100);
	int *temp_div_array = malloc(sizeof(int) * 100);

	for (int i = 10000-1; i > 20; --i)
	{
		find_div_array(i,div_array,&count);
		sum = sum_of_divisors(div_array,count);
		sum -= i;


		find_div_array(sum,temp_div_array,&temp_count);
		temp_sum = sum_of_divisors(temp_div_array,temp_count);
		temp_sum -= sum;

		printf("i->%d SUM -> %lu TEMPSUM ->%lu\n",i,sum,temp_sum );

		if(i == temp_sum && sum != temp_sum)
		{
			printf("TRUE\n");
			result += (sum + temp_sum);
		}
	}

	result /= 2;
	printf("result -> %d\n",result );
}

/****************************************************************************
 * Function Name  :Lattice_paths PROB#20
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : NOT WORKING PROPERLY
 ****************************************************************************/
void Factorial_digit_sum()
{
	char * num = calloc(0x00,sizeof(char) * 100000);
	char *array = calloc(0x00,sizeof(char) * 1000);
	int i;
	u_int64_t result;

	num[0] = '1';

	for ( i = 2; i <= 99; ++i)
	{	
		printf("%d x %s\n",i,num );
		array = itoa(i,array,10);	
		num = mup_2_strings(num,array);	
		printf("%d->%s",i,num);	
		printf("\n");
	}

	printf("\n\nFINAL RESULT ->%s\n\n",num);

	result = adding_digits_of_string(num);

	printf("digits ->%lu\n",result );
  	
}

/****************************************************************************
 * Function Name  : PROB#19
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void prob_19()
{

}

/****************************************************************************
 * Function Name  : PROB#18
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void Maximum_path_sum_I()
{
	/* TAKING INPUTS FROM FILE*/
	FILE * fp_prob = NULL;
	int mtx[15][15];
	char line[15*2+15+1];
	int i = 0,j = 0;

	fp_prob = fopen("prob18.txt","r");

	if(fp_prob  != NULL)
	{
		while (fgets ( line, 50+1 , fp_prob  ) != NULL ) 
		{
			j = 0;
			char *token = malloc(sizeof(char) * (strlen(line) + 1));

			token = strtok(line, " ");


			while (token != NULL)
		    {
		    	mtx[i][j] = atoi(token);
		    	printf("matrix[%d][%d] = %d\n",i,j,mtx[i][j] );
		    	j++; 
		        token = strtok(NULL," ");
			}

			i++;
		}
	}	
	else	printf("ERROR -> txt file could not found -> %d %s\n",__LINE__,__FUNCTION__ );

	/*NOW TO SOLUTION SIMILAR TO 15 , STARTING WITH END LEAFS FINDING PATH VALUES TO ROOT*/


	for (int i = 13; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			mtx[i][j] = MAX(mtx[i][j]+mtx[i+1][j],mtx[i][j]+mtx[i+1][j+1]);
		}
	}

	printf("RESULT -> %d\n",mtx[0][0] );

}

/****************************************************************************
 * Function Name  : PROB#17
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void Number_letter_counts()
{	
	int first_ten = 36;						/* 1 - 9 */
	int ten_to_twenty = 70;					/* 11 - 20 */
	
	// twenty one   thirty one  fourty one  fifty one
	// 8 times first ten is gonna be used and 8*10 times thirty fourty ll be used etc

	int twenty_to_hunderd = 10*(6 + 6 + 5 + 5 + 5 + 7 + 6 + 6) + 8*36;
	int hundred_to_thousand = (36*100) + (9*854) + (9*7) + (999*10);
	int total = first_ten + ten_to_twenty + twenty_to_hunderd + hundred_to_thousand;
	printf("%d\n",total );
}
	
/****************************************************************************
 * Function Name  :Lattice_paths PROB#16
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void Power_digit_sum()
{	// can be done with pow() math.h
	u_int64_t sum;

	char * result = malloc(sizeof(char) * 1000);
	memset(result,0x00,sizeof(*result));
	result[0] = '1';

	for (int i = 0; i < 1000; ++i)
	{
		result = mup_string(result , 2);
		printf("%d -> %s\n",i+1,result );
	}
	printf("%s\n",result );
	
	sum = adding_digits_of_string(result);
	printf("%lu\n",sum );
}

/****************************************************************************
 * Function Name  :Lattice_paths PROB#15
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : dynamic programming
 ****************************************************************************/
void Lattice_paths()
{
	unsigned long int matrix[21][21];

	for (int i = 0; i < 21; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < 21; ++i)
	{
		matrix[i][20] = 1;
		matrix[20][i] = 1;
	}

	for (int i = 19; i >= 0; --i)
	{
		for (int j = 19; j >= 0; --j)
		{
			matrix[i][j] = matrix[i][j+1] + matrix[i+1][j];
		}
	}
	
	for (int i = 0; i < 21; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			printf("%lu ",matrix[i][j] );
		}
		printf("\n");
	}
}


/****************************************************************************
 * Function Name  :Longest_Collatz_sequence PROB#14
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void Longest_Collatz_sequence()
{
	int it = 0;
	unsigned long int temp;
	int max = 0,max_num = 0;

	for (int num = 999999; num > 1; num--)
	{	
		it = 0;
		temp = num;
		while(temp != 1 && it < 5000)
		{
			if( temp % 2 == 0)
			{
				temp = temp / 2;
			}
			else
			{
				temp = 3 * temp + 1;
			}
			it ++;
		}
		if (max != MAX(max,it))
		{
			max = MAX(max,it);
			max_num = num;
		}
		printf("num -> %d temp -> %lu it -> %d\n",num,temp,it );
	}	
	printf("num -> %d max -> %d\n",max_num,max );
}


/****************************************************************************
 * Function Name  : PROB#13
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
 void prob13()
 {

 }

/****************************************************************************
 * Function Name  :Highly_divisible_triangular_number PROB#12
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void Highly_divisible_triangular_number()
{
	u_int64_t sum = 0;
	u_int64_t count = 0;
	int i = 1;
	int *div_array = malloc(sizeof(int) * 100);
	

	while(count < 500)
	{
		sum = sum + (i);
		find_div_array(sum,div_array,&count);
		printf("%lu number -> divisors %lu\n",sum,count );
		i++;
	}
}

/****************************************************************************
 * Function Name  :Summation_of_primes PROB#11
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void Largest_product_in_a_grid()
{	
	char line[100];
	int matrix[20][20];
	unsigned long int sum = 1;
	unsigned long int temp_sum = 1;
	unsigned long int temp_sum2 = 1;
	unsigned long int temp_sum3 = 1;	
	unsigned long int temp_sum4 = 1;
	unsigned long int temp_sum5 = 1;
	unsigned long int temp_sum6 = 1;
	int i = 0,j = 0;

	for (int i = 0; i < 20; ++i)
	{
		for (int i = 0; i < 20; ++i)
		{
			 matrix[i][j] = 0;
		}	
	}
	i = 0;
	j = 0;

	FILE * fp_prob = NULL;

	fp_prob = fopen("prob11.txt","r");

	if(fp_prob  != NULL)
	{
		while (fgets ( line, 100+1 , fp_prob  ) != NULL && i<20) 
		{
			// scaning matrix
			sscanf(line,"%d%d%d%d%d%d%d %d %d %d %d %d %d %d %d %d %d %d %d %d "
				,&matrix[i][j],&matrix[i][j+1],&matrix[i][j+2],&matrix[i][j+3],&matrix[i][j+4]
				,&matrix[i][j+5],&matrix[i][j+6],&matrix[i][j+7],&matrix[i][j+8],&matrix[i][j+9]
				,&matrix[i][j+10],&matrix[i][j+11],&matrix[i][j+12],&matrix[i][j+13],&matrix[i][j+14]				
				,&matrix[i][j+15],&matrix[i][j+16],&matrix[i][j+17],&matrix[i][j+18],&matrix[i][j+19]);
			i++;
		}
	}	
	else	printf("ERROR -> Kelimeler.txt not found -> %d %s\n",__LINE__,__FUNCTION__ );

	for (int i = 3; i < 20-4; ++i)
	{
		for (int j = 3; j < 20-4; ++j)
		{	
			temp_sum = matrix[i][j]*matrix[i][j+1]*matrix[i][j+2]*matrix[i][j+3];	//sag
			temp_sum2 = matrix[i][j]*matrix[i+1][j]*matrix[i+2][j]*matrix[i+3][j];	//asa
			temp_sum3 = matrix[i][j]*matrix[i+1][j+1]*matrix[i+2][j+2]*matrix[i+3][j+3];	//sag as
			temp_sum4 = matrix[i][j]*matrix[i-1][j+1]*matrix[i-2][j+2]*matrix[i-3][j+3];	//sag ust
			temp_sum5 = matrix[i][j]*matrix[i+1][j-1]*matrix[i+2][j-2]*matrix[i+3][j-3];	//sol as
			temp_sum6 = matrix[i][j]*matrix[i-1][j-1]*matrix[i-2][j-2]*matrix[i-3][j-3];	//sol ust
			// printf("%ld ,%ld ,%ld \n",temp_sum,temp_sum2,temp_sum3 );
			sum = MAX(sum,MAX(temp_sum,MAX(temp_sum2,MAX(temp_sum3,MAX(temp_sum4,MAX(temp_sum5,temp_sum6))))));
		}	
	}

	printf("SUM -> %ld\n",sum );

} 

/****************************************************************************
 * Function Name  :Summation_of_primes PROB#10
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void Summation_of_primes()
{
	unsigned long int sum = 2;

	for (int i = 3  ; i < 2000000 ; i = i + 2)
	{
		if(is_Prime(i))
		{
			sum = sum + i;	
		} 
	}
	printf("%ld\n", sum  );
}

/****************************************************************************
 * Function Name  :Special_Pythagorean_triplet PROB#9
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void Special_Pythagorean_triplet()
{
	int k;
	for (int i = 0; i < 1000/2; ++i)
	{
		for (int j = 0; j < 1000/2; ++j)
		{
			k = 1000-(i+j);
		
			if((i*i+j*j == k*k) && (i<j<k))
			{
				/* DO IT MORE EFFICIENT*/
				printf("a = %d ,b = %d , c = %d\n",i,j,k );
			}			
		}
	}
}

/****************************************************************************
 * Function Name  :Largest_product_in_a_series PROB#8
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void Largest_product_in_a_series()
{
	unsigned long int sum = 1;
	unsigned long int temp_sum = 1;
	const char num[1000+1] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	// unsigned long int num2 = 7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450;

	for (int i = 0; i < 1000-13; ++i)
	{
		temp_sum = 1;
		for (int j = 0; j < 13; ++j)
		{
			temp_sum = temp_sum * ( num[i+j] - '0' );
			if( temp_sum > sum ) sum = temp_sum;
		}
	}
	printf("%lu\n",sum );
}

/****************************************************************************
 * Function Name  :prime_10001 PROB#7
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void prime_10001()
{
	int count = 1,i = 1;

	while(count != 10001)
	{
		if(is_Prime(i))
		{
			count++;
		}

		i += 2;
	}

	printf("10001st prime = %d\n",i-2 );
}

/****************************************************************************
 * Function Name  : Sum_square_difference PROB#6
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 ****************************************************************************/
void Sum_square_difference()
{
	int sum = 0,sum2 = 0;

	for (int i = 1; i < 101; ++i)
	{
		sum += i;
		sum2 += i*i;
	}
	sum *= sum;

	printf("difference is %d \n",sum - sum2 );
}

/****************************************************************************
 * Function Name  : smallest_multiple PROB#5
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 ****************************************************************************/
void smallest_multiple()
{
	printf("2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n");
	int i = 20;
	
	while (i %  2 != 0 || i %  3 != 0 || i %  4 != 0 || i %  5 != 0 ||
         i %  6 != 0 || i %  7 != 0 || i %  8 != 0 || i %  9 != 0 ||
         i % 10 != 0 || i % 11 != 0 || i % 12 != 0 || i % 13 != 0 ||
         i % 14 != 0 || i % 15 != 0 || i % 16 != 0 || i % 17 != 0 ||
         i % 18 != 0 || i % 19 != 0 || i % 20 != 0) 
	{
    	i += 20;
	}
	printf("TOTAL = %d\n",i );
}

/****************************************************************************
 * Function Name  : Largest_Palindrome_Product PROB#4
 * Inputs         : int
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : Find the largest palindrome made from the product of two 3-digit numbers
 ****************************************************************************/
void Largest_Palindrome_Product()
{
	printf("Find the largest palindrome made from the product of two 3-digit numbers.\n");
	int a = 999;
	int b = 999;
	int found = 0;

	while (a>900 && !found)
	{
		for ( b = 999; b > 900; b--)
		{
			if(is_Palindrome(a*b))
			{
				found = 1;
				break;
			}
		}
		a--;
	}
}


/****************************************************************************
 * Function Name  : smallest_multiple PROB#3
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void Largest_Prime_Factor()
{
	int i;
	printf("The prime factors of 13195 are 5, 7, 13 and 29.What is the largest prime factor of the number 600851475143 ?\n");

	for (i =1000000; i >= 0 ; i-- )
	{
		if(600851475143 % i == 0)
		{
			if(is_Prime(i))
			{
				printf("LARGEST PRIME FACTOR %d\n",i );
			}
		}
	}

}

/****************************************************************************
 * Function Name  : even fibonnacci numbers PROB#2
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void evenfib()
{
	int temp;
	int first = 1;
	int second = 2;
	int total = 0;
	printf("Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.");
	printf("\n");

	while(second < 4000000)
	{
		if(second % 2 == 0)  
			total += second;
		
		temp = second;
		second = first + second ;
		first  = temp;
	}

	printf("TOTAL = %d\n",total );

}

/****************************************************************************
 * Function Name  :multiples of 3 and 5 PROB#1
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : 
 ****************************************************************************/
void mup35()
{
	int mupofthree = 0,mupoffifteen = 0,total = 0;
	int mupoffive = 0;
	printf("If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.	Find the sum of all the multiples of 3 or 5 below 1000. \n");

	for (int i = 0; i < 1000; ++i)
	{
		if(i%3 == 0)
		{
			mupofthree += i;
		}
		if(i%5 == 0)
		{
			mupoffive += i;
		}
		if(i%15 == 0)
		{
			mupoffifteen += i;
		}
	}
	total = mupofthree + mupoffive - mupoffifteen;
	// printf("3 = %d 5=%d 15=%d\n",mupofthree,mupoffive,mupoffifteen );
	printf("TOTAL = %d\n",total );
}

void intro_page()
{
	printf ("\n\n");
	printf("###############################\n");
	printf("######## PROJECT EULER ########\n");
	printf("###############################\n\n\n");
}

void welcome_screen(unsigned int *p_menu_selection)
{

	printf("\n--------------------------------\n");
	printf("Select Operation to Continue\n");
	printf("1 - multiples of 3 and 5\n");
	printf("2 - even fibonacci numbers\n");
	printf("3 - Largest Prime Factor\n");
	printf("4 - Largest Palindrome Product\n");
	printf("5 - TEST	\n");
	printf("6 - 	\n");
	printf("7 - 	\n");
	printf("0 - 	\n\n");
	printf("Seçilen işlem:");
	scanf("%d",p_menu_selection);	
	printf("--------------------------------\n");
	printf ("\n");

	if (*p_menu_selection >= NUMBER_OF_DEFINED_FUNCTION_IN_MENU || *p_menu_selection == 0)
				printf("Program has been terminated!\n\n");
}


/****************************************************************************
 * Function Name  : test
 * Inputs         : 
 * Outputs        : Currently None
 * Returns        : Currently None
 * Description    : To unit test functions
 ****************************************************************************/
void unit_test()
{
	Lexicographic_permutations();
	// printf("%lu\n",fibonacci_sequence(12));
}

/****************************************************************************
 * Function Name  : main_page
 * Inputs         : word struck array
 * Outputs        : Currently None
 * Returns        : 1
 * Description    : A Basic UI
 ****************************************************************************/
int main_page(){

		unsigned int menu_selection 	= 0;
		unsigned int * p_menu_selection = &menu_selection;

	do{
		welcome_screen(p_menu_selection);
		switch (menu_selection) {
			case 1:
				printf("MULTIPLES\n");
				mup35();
				break;
			case 2:
				printf("Print adjacency matrix -> its absurd\n\n");
				evenfib();
				break;
			case 3:
				printf("Largest Prime Factor\n\n");			
				Largest_Prime_Factor();				
				break;
			case 4:
				Factorial_digit_sum();
				break;
			case 5:
				unit_test();
				break;
			case 6:
				// printf("GUessing\n\n");			
				// guessing_menu(pst_AllTeam);
				break;
			case 7:
				// printf("Reset Scenario\n");
				// reset_scenario(pst_AllTeam);
			default:
				break;
		}

	}while(menu_selection < NUMBER_OF_DEFINED_FUNCTION_IN_MENU && menu_selection != 0);
return 1;
}

int main(void)
{
	
	intro_page();
	main_page();

	return 0;	
}
