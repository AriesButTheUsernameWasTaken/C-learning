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
int main(){
printf("======================Arithmetic operators zone======================");


/*
let's first see additions. With ints. 
*/

int a = 10;
int b = 12;
int c = 7;
int d = 800;
int results; 
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

results + d = a + b ; 
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

R values are the right side of the =.   

The following article may explain this better than me, so, feel free to check it out : 
https://www.geeksforgeeks.org/lvalue-and-rvalue-in-c-language/
*/



/*
we can add many variables to this. even twice the same. 
*/
results = a+b+b; 
printf("\n%d",results);
/*
now, this was pretty simple, so, let's just continue.
*/
printf("\n======================Substractions zone======================");
/*
same operating logic. 
*/


return 0; 
}