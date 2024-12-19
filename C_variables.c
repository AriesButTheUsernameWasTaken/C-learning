//here's the tutorial followed in this code : https://www.youtube.com/watch?v=aIQk1O08zpg&list=PLZPZq0r_RZOOzY_vR4zJM32SqsSInGMwe&index=4
//once again, i'll play around with it, and comment the results I get, so, both, me and you, the reader can get a good understanding of what I did. 
#include <stdio.h>

int main(){
//declaration of the variable
int x ; 
//initialization
x = 10 ; 
//declaration and initialization combined
int icky = 100 ; 
int y = 1000; 
/*
printf(x);
printf(y);
*/
/*
seems you can't print variables, or at least integer, the way i did above. I you do, you'll certainly get the following errors : 

error: passing argument 1 of 'printf' makes pointer from integer without a cast [-Wint-conversion]
I haven't learnt pointers yet, I'll leave it like this, and come back to it later. (I won't)

note: expected 'const char * restrict' but argument is of type 'int' 

int __cdecl printf(const char * __restrict__ _Format,...);
The above error is explained here : https://stackoverflow.com/questions/50841881/why-is-the-format-in-printf-marked-as-restrict
the printf function is restricted to only the format const char, if I understand well. 

Let's try something else. 
*/

/*
I was curious, and decided to dive deeper, so, here comes the wikipedia article : 
https://en.wikipedia.org/wiki/C_data_types
looks like we have a lot to see.
I'll like to first, learn to display a integer correctly, let's try. 
*/
printf("\n %x\n");
printf("%y\n");
printf("%icky\n");
/*
okay, so, i think it's normal, but, on console from windows cmd, and from vsc, i geet two different things. 
Which, as seen in the precedent code, is expectable, since they're not displaying things using the same encrytpion. 
but which is helping us understand more accuratly what we're facing here. 

return from windows console : 
 ffadd130
y
-2111305344cky

running the code a second time gives us this : 
 ededd1b0
y
-2111305344cky

My best guest so far, is that, since I haven't cleaned the memory, the variable displayed, instead of x, is the memory address. 

and from VSC : 
 7addc0
y
-2111305344cky 

as already mentionned, the VSC and the windows cmd terminal aren't using the same encoding system. 
that settles it. But, we still don't know the following : 
- why doesn't it displays the value of x ? 
- why can't i display y ? It seems that it's not even understanding that y declared and initialized the variable. 
- What is displayed instead of my icky variable ? 

at least, I know it isn't the memory address. (or what i think is the memrry address), since it's stable throught runs. 


*/
/*
with bit of research, it looks like % designate the type of displays we want our variable to be displayed like. 
so, by doing %x, then, nothing, I think it's expectable to get nothing back.
https://www.youtube.com/shorts/6vNMDb316Ck
with this video, and chatgpt (we're using the bests tools here, we ant to understand fast and right), 
it appears that the type of displays wanted needs to be in a litteral string. so, let's try, once again. 
*/
printf("\n%d",x);
/*
this, above, works. 
It also clarify some things. Looks like : 
printf("%x");
create an undefined behaviour. Since we're expecting a value, but never tells which one, the code (or compiler, I still don't know)
need to displays SOME things, no matter what. undefined behaviour can throw, as far as I'm aware, 
crash
random value from the stack
garbage data, interpreted as unsigned int. 

So far, this also clarify the 
printf("%y"); 
error. Since y isn't a form to diplay data, it looks like ots cancelling the % sign, or ignoring it, 
and then follow the instructions, by just displaying the letter y. as if i just wrote : 
printf("y");
the same behaviour occurs on the : 
printf("%icky");
or, almost similar. the %i, exist in the types of data displays, and then, the rest is interpreted as if :  
printf("cky");
since i don't know what %i does, i'll dig it deeper. It doesn't change the value throught runs, tho. 
*/
printf("\n=========%%i experimentation=========");
printf("\n%i");
printf("\n%i",x);

/*
it appears that print("%i") also create undefined behaviour. which is expectable. undefined behaviour,
could also generates the reading of an uninitialized memory. 
so, i i were to print all my previous integers, i would have to do it like this : 
*/
printf("\v\n=======this is supposed to work correctly=======");
printf("\n%d",x);
printf("\n%d",y);
printf("\n%d",icky);

/*
That was it. Just for one type of variable. But we learned quite some things. the rest should be easier, now.
let's continue on the path of ints, and try ourself at signed, and signed int. 
but not today folks, i have to wake up at like 4:30 am, cause i was funny in school. 
*/


return 0;
}