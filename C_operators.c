/*
In this file, I'll see operators, and how the differents variables types reacts to them, and to operations. 
This will also lead to maybe the creation of another file in which I'll dig variables conversions.
Or i'll dig it on this file, we'll see. But it will be learnt. 
Anyway. here's the base tutorial followed here : 
https://www.youtube.com/watch?v=9E3I1URu6fc&list=PLZPZq0r_RZOOzY_vR4zJM32SqsSInGMwe&index=9
And this is the wikipedia article that we will also follow and dig, and the Archives for this lesson : 
https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
https://www.geeksforgeeks.org/lvalue-and-rvalue-in-c-language/

And yes, i'll like to see every one of them, try to break them, but mostly understand how they interact. 
With erery type of variable. we're in for a long ride. 
We may learn quite a few things within it. Will it be fun ? Well, for me, surely. 
*/


#include <stdio.h>
//Added the following header to be able to play with booleans variables. 
#include <stdbool.h>
//Added the following header to be able to play with strings
#include <string.h>
int main(){
printf("======================Arithmetic operators zone======================");


/*
let's first see additions. With ints. 
*/

int a = 10;
int b = 12;
int c = 7;
int d = 800;
int e = 401; 
float float_d=d;
float float_e=e;
float f = 1.3;
float g = 2.7;
bool shambles = true; 
bool stable = false;
char text[] = "maybe i'm more than a vampire.";
char dextre[] = "something completely else.";
int results;  
float results_float;
char results_char[100];

printf("\n======================Changing value without operations zone======================");
/*
We can already start with a simple thing :  
changing the value of our variable without operations. 
*/
printf("\n%d",a);
a = 2;
printf("\n%d",a);
a = 10; 
printf("\n%d",a);
/*
It might seems obvious, but i'll rather clarify too much thing than no enough.
*/

printf("\n======================Additions zone======================");

results = a + b ; 
printf("\n%d",results);
results = a + c ; 
printf("\n%d",results);
/*
First thing we can see, is that the right side of the = sign, will be stocked into the left side of the =. 
Aditionnally, we can see that, the variable is only equal to what we input. Making a variable changing it's value throught
an operation doesn't retain the initial value of the variable. if results was 10000, or -556, the result of the
a+b operations would be the same. 
Unless : 
*/
results = results + d; 
/*
here, we add results to itself, plus the d variable. So, results is already equal to 17, at this point, 
shat's gonna be done will be results (17) + d (800). 
So, what's interesting to add, is that the operations is completed, THEN, and only THEN stored into the variable.
But for the sake of entertainment, let's try to break it : 
*/
printf("\n%d",results);
results = 0 ; 

//results + d = a + b ; 
/*
As Expected, this won't work. Not because the compiler can't compute results + d, or a+b. 
This has to do with values types. when throwing a = there's two sides. 
Left side. It is, as already mentionned, the variable, or more specifically, the location where the value will
be stocked, and it's addressed by it's name. 
This is a Location, or Left value, also abbreviated Lvalue, as seen in the generated error :  

error: lvalue required as left operand of assignment 

Since L values are a memory location referred to by their names, in order to allocated thed a value, 
putting 2 or more value on the left side, as Lvalues, will trigger unpredictable behaviour. 
Basically, I'm trying to allocate a value (here the result of my operation), to more than one memory space. 
While this can be done in many other way, I think, trying to pass an operation as a memory location, using 
variables names will, first results in the left operation not being computed, but also, trying to allocate 
two memory spaces at the same time, while only one is expected. 

R values are the right side of the =7.
It's whatever will be put into the variable.    

The following article may explain this better than me, so, feel free to check it out : 
https://www.geeksforgeeks.org/lvalue-and-rvalue-in-c-language/

Additionnally, consider the following :  
*/

//a + b = c ; 

/*
It also create the same error, for the same reasons. 
*/


/*
we can add many variables to this. even twice the same. 
*/
results = a+b+b; 
printf("\n%d",results);
/*
now, this was pretty simple, so, let's just continue.
*/
printf("\n=======================================Added Tuesday the 4th of February 2025=======================================");
/*
let's forget simplicity. let's try floats. 
*/
results_float = f+g+g;
printf("\n%f",results_float);

/*
still, pretty simple. Now.
let's try cross types addition. 
*/
results = a + g; 
printf("\n%d",results);

/*
as we can see, and will see again below, it may not be calculated as an integer, but, since it is stored as one, 
it is also displayed as one, truncating the floating part. So, let's try something else. 
*/
results_float = a + g;
printf("\n%f",results_float);
/*
and now, as we can see, the floating part is not truncated. we made a cross types calculation, and stored it 
in the correct data type, so that we can actually have the result correctly displayed. 
*/

printf("\n==========================Added Tuesday the 11th of February 2025==========================");
/*
still on the path of testing the additions and complementarities between différent types of variables, let's
mess with booleans. 
*/

results = stable + shambles; 
printf("\n%d",results);
/*
Booleans are stored on either 1 or 0, in regard if their value are true, ergo 1, on our case, it's the variable 
shambles, or 0, which is the statment false, and which is, here, our stable variable. 
But, since our result is an integer, and, booleans are stored as integer, with just the limitation of range, 
0 to 1, we can actually add them together, and get the expected result, as if it was a simple integers addition. 
We can also try other things, to get a better understanding of this. 
*/
results = stable + stable + stable; 
printf("\n%d",results);
results = shambles + shambles ;
printf("\n%d",results);

printf("\n============================Added Wednesday the 12th of February 2025============================");
/*
we already have added floats, and booleans. Playing with the macros won't be that much more interesting,
however, maybe playing with char can be funny. 
*/
//results  = text + dextre;
printf("\n%d",results);

/*
    error: invalid operands to binary + (have 'char *' and 'char *')
This error is, once again, totally expectable, since we're adding two char variable into a integer one. 
*/
printf("=========================Added Thursday the 13th of January 2025=========================");
//results_char = text + dextre;
printf("\n%s",results_char);

/*
We see, that, even when trying to store two char in another char, it still doesn't works.
I am now, about to seek knowledge. 
It apprears that there's two reasons, happenning at the same time here. 
The first being that, since char arrays devays into pointers, and that, since pointers are designating a 
data address, or memory address, they can't be additionned together. (cause, adding one memory address to 
another one would lead to undefined behaviour). Or at least, that's how i understand it, since i still don't 
know what pointers are. 
The other thing happening is that, arithmetics operators are designed only for arithmetics values, hence int, 
floats, longs, and booleans ( since they're stored as integers). char, however, do not correspond to any of 
those types, and can't be "added" throught arithmetic operators. 
to "add" one string to another, one would need to use strcpy. 
*/
strcpy(results_char, text);
printf("\n%s",results_char);
strcpy(results_char, dextre);
printf("\n%s",results_char);

/*
 error: array size missing in 'results_char'

 yeah. remember to initialize your arrays kids. Or at least define their size. Otherwise the puter won't be happy.
*/


printf("\n======================Substractions zone======================");
/*
same operating logic. 
*/
results = a-b;

printf("\n==========================Added Wednesday the 29th of January 2025==========================");
printf("\n%d",results);
results = 0 ;
/*
since it's all signed integers, they can go negative. 
*/

printf("\n===============================Multiplication zone===============================");
/*
still the same logic.
*/
results = a*b;
printf("\n%d",results);
results = 0 ;

printf("\n=======================================Added Tuesday the 4th of February 2025=======================================");

/*
buuuuuuuut. We also have FLOATS. 
let's try. 
trying to store a floating point in an integer would only results in the truncation of the floating value.
And, as explained in the division zone, trying to calculate integers between themselves and the storing 
the result in a float will also truncate the floating part. Because it is calculated as integers. 
*/
results_float =f*g;
printf("\n%f",results_float);





printf("\n===============================Division zone===============================");
/*
Here lies some traps (are they gays ? who knows). Let's see them :  
First, let's try a simple division. 
*/
results = d/a;
printf("\n%d",results);

/*
I purposefully choose numbers that would not end up in a floating result after the division, so it can stay
in the scope of an integer. However, let's now try one that doesn't end up like this. 
*/
results = a/c;
/*
10 on 7, will give a result of 1.4285714285714285714285714285714. 
Far from the scope of an integer. 
*/
printf("\n%d",results);
/*
so, what happens here, is that, since my results is an integer, i can't store floating points. 
So it just round it to just the integer part. 
What i'll like to see, is that what happens if our floating point is above 1.5, to see if it rounds it up to 
the superior value. 
*/
results = d/e;

printf("\n%d",results);
printf("\n=======================================Added Tuesday the 4th of February 2025=======================================");
/*
as we can see, the value of the division isn't actually rounded neither up or down. It's just the integer part 
that's taken as the actual value. 
let's now try to concatenate the result of a division into a float. 
up there, where i've declared my variables, i'll declare a result variable but as a float. (results_floats)
and we will try the same division. 
*/
results_float = d/e;
printf("\n%f",results_float);

/*
as we can also realize here, the division, while being stored in a float, does not contain a significant 
floating value. Or, at least, not the one expected. 
that is because, divisions are operated following the rules of the declared variables types. 
here, we have only integers. We can store our data in a float, the value stored, since we only have integers
will be calculated as an integer, then stored as a float. 
According to this, to have a divisions calculated as floats, we will first need to store our integers as floats. 
*/
float_d = d;
float_e = e;
results_float = float_d/float_e;
printf("\n%f",results_float);
/*
we finally have our floating result. 
*/

return 0; 
}