/*
												Avery Jacobson
													csci 1111
													James Polzin
														2/13/14

Assignment 5:                Given: 02/06/14     Due: 02/13/14
------------                                  Points: 10
Purpose: Use loops, rand( ) and do some analysis of the 
         randomness of rand( ).

Description:

  Write a program that will simulate the following random 
  events using the rand( ) function in the C standard 
  libraries. We are interested in determining if rand( ) 
  really seems to produce a random set of values. To do this
  we will repeat the event a certain number of times and see
  how often we get each of the possible results. If rand( ) 
  is truly random, and our mapping to the possible results is
  uniform, our results should be equally likely and therefore
  evenly distributed across all possible results.
  
  The two events will be:
      1) Flipping a coin
      2) Rolling a six-sided die
      
  Repeat each event:
        1) 10
        2) 100
        3) 1000
        4) 10,000
        5) 100,000  times
        
  Within each set of repetitions, count how often each result 
  occurs. Then compute the percentage of the total events 
  were represented by each result.
  
  Ex:
    Coin:
    ----
      Flips: 10       Heads: 40%
                      Tails: 60%
    
    Die:
    ----
      Rolls: 10       1: 10%
                      2:  0%
                      3: 20%
                      4: 30%
                      5: 30%
                      6: 10%
                  
              ...
                  
    Coin:
    ----
      Flips: 100000   Heads: 49%
                      Tails: 51%
    
    Die:
    ----
      Rolls: 100000   1: 17%
                      2: 18%
                      3: 17%
                      4: 17%
                      5: 17%
                      6: 16%
    
    

  Notes:
  -----
  - Do not "randomly" seed the rand( ) function, we are 
    interested in repeatability.
  - No inputs are necessary.
  - Gradually develop your program in steps
  
  - There is a "Supplement" posted on Otto that discusses
    the rand( ) function and there are "Random_.c examples
    in the examples directory.
      

*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	int i, value, input, r;
	int counth, countt, count1, count2, count3, count4, count5, count6;
		
	int n;
	int l;

	FILE *inptr;
	inptr=fopen ("RANDOM.DATA","r"); 
    FILE *myfile; 
    myfile = fopen("RANDOM.OUT","w"); 

	

	n = 0;

	while( (r=fscanf(inptr,"%i",&input)) == 1) 
	{
		

		counth=0;
		countt=0;
		count1=0;
		count2=0;
		count3=0;
		count4=0;
		count5=0;
		count6=0;

		if (n == 0)
			l = input;
		if (n == 1)
			l = input;
		if (n == 2)
			l = input;
		if (n == 3)
			l = input;
		if (n == 4)
			l = input;


		for(i=0; i < l; i++)
		{
			value = rand( )%2;

			if(value == 0)
				counth++;
			else if(value == 1)
				countt++;
		}

		fprintf(myfile,"\n\n");
		
		
		for(i=0; i < l; i++)
		{
			value = rand( )%6;

			switch(value +1)
			{
				case 1:
					count1++;
					break;
				case 2:
					count2++;
					break;
				case 3:
					count3++;
					break;
				case 4:
					count4++;
					break;
				case 5:
					count5++;
					break;
				case 6:
					count6++;
					break;
			}
		
		}
	
		fprintf(myfile,"\nNumber of iterations %i\n", l);
		fprintf(myfile,"\nHeads occured: %.3lf percent of the time\n", ( (float)counth / (float)l) * 100);
		fprintf(myfile,"\nTails occured: %.3lf percent of the time\n", ( (float)countt / (float)l) * 100);
		fprintf(myfile,"\nA one occured: %9.2lf percent of the time\n", ((float)count1/l)*100);
		fprintf(myfile,"A two occured: %9.2lf percent of the time\n", ((float)count2/l)*100);
		fprintf(myfile,"A three occured: %7.2lf percent of the time\n", ((float)count3/l)*100);
		fprintf(myfile,"A four occured: %8.2lf percent of the time\n", ((float)count4/l)*100);
		fprintf(myfile,"A five occured: %8.2lf percent of the time\n", ((float)count5/l)*100);
		fprintf(myfile,"A six occured: %9.2lf percent of the time\n", ((float)count6/l)*100);

		n++;
	}

	fprintf(myfile,"\n");

	fclose(inptr);
    fclose(myfile);

	return 0;
}




