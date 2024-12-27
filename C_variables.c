//here's the tutorial followed in this code : https://www.youtube.com/watch?v=aIQk1O08zpg&list=PLZPZq0r_RZOOzY_vR4zJM32SqsSInGMwe&index=4
//once again, i'll play around with it, and comment the results I get, so, both, me and you, the reader can get a good understanding of what I did. 
#include <stdio.h>
//Added the following header to be able to play with the macros of variables. 
#include <limits.h>
//Added the following header to be able to play with booleans variables. 
#include <stdbool.h>
//Added the following header to be able to play with strings
#include <string.h>

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

//============================added Friday the 27th of December 2024============================
printf("\n============================added Friday the 27th of December 2024============================");

printf("\nadded the %%i printing, which stands for signed integers. But since none are signed here, it may broke things.");
printf("\n%i",x);
printf("\n%i",y);
printf("\n%i",icky);
/*
https://www.geeksforgeeks.org/format-specifiers-in-c/
^Link for the data types specifiers. 
Let's now seek more into integers, shall we. 
*/
signed first; 
first = -10; 
signed second = -100; 
printf("\n%d",first );
printf("\n%d",second );
printf("\n%i",first );
printf("\n%i",second );
//works like a charms. show about signed int, now. 

signed int primo; 
primo = -100; 
signed int secondo = -1000; 
printf("\n%d",primo );
printf("\n%d",secondo );
printf("\n%i",primo );
printf("\n%i",secondo );

/*
now let's play a bit with the macros int_min and int_max. 
it's recommended to add the header <limits.h>. 
https://www.geeksforgeeks.org/int_max-int_min-cc-applications/
more on this header and variables limits here : 
https://www.geeksforgeeks.org/climits-limits-h-cc/
*/
int max; 
max = INT_MAX; 
int min = INT_MIN; 
printf("\n%d", max);
printf("\n%d", min);
/*
all working like a pretty charm. Let's continue. 
I noticed, however, that the data specifier didn't seemed to change anything in the way the variable are printed,
at least for the integers. 
Now, let's play with booleans. 
*/
printf("======================================Boolean zone======================================"); 

/*
Be careful. You'll need to add the necessary header, being <stdbool.h> 
*/
bool boole1 ; 
boole1 = true; 
bool boole2 = false ; 
printf("\n%d", boole1); 
printf("\n%d", boole2);

printf("======================================Char Zone======================================"); 
/*
more info on the Char variable type here : 
https://www.w3schools.com/c/c_data_types_characters.php
I'll use this articla as a base for the following code. 
*/
char text; 
text = 'a';
char text2 = 'b';
printf("\n%c\n%c", text, text2);
/*
i think i'll get in about this later in, but here's where i found more about printf, and how to print 2 variables
at the same time : 
https://www.spsanderson.com/steveondata/posts/2024-09-18/
We could do some terribly unpractical things like this: 
*/
char a = 'a'; 
char b = 'b';
char s = 's'; 
printf("\n%c%c%c%c",b,a,s,s);

/*
but that would be terribly unpractical. for culture, we can't do that, cause char, without specification, 
only stocks one character, the last one : 
*/
char text3 = 'bass';
printf("\n%c", text3);

/*
another funny thing to do, is to assign char values directly from the ASCII table. this would also mean you 
understand how ASCII works. I'll try to explain it for you. If you already know how it works, feel free to skip. 
https://www.w3schools.com/charsets/ref_html_ascii.asp
https://en.wikipedia.org/wiki/ASCII
As you can see, the ASCII table run from 0 to 127, meaning there's 128 values. 
Char variables are stocked on 8 bits, which means that there's 256 values. 
ASCII have an extended version, in which the 128-255 values are set : 
https://en.wikipedia.org/wiki/Extended_ASCII#/media/File:Table_ascii_extended.png
Once you've understood that, the only thing left to know is that, you can initiate the char variable, using a number, 
in decimal, or hexadecimal, corresponding to the value of the printable character. 
*/
char at = 64; 
//note that i didn't use the single quotes around here.
printf("\n%c", at); 
char imfrenchhonhonhon = 249; 
printf("\n%c", imfrenchhonhonhon);
//looks like my compiler don't support the frenches. >:( or more realistically extended ascii. I may dig that later. 
//well, next, let's play around with strings. to create a string, you'll simply add [] at the end of your char. 
//I haven't seen this around integers yet, but i know it's possible, so, my best gues is, since integers can create
//a table using [], in char, it's creating a table too, because char are integers type. 
char stringoftext[] = "I am a vampire.";
//note that i'm using double, and not single quotes, when using a string.
printf("\n%c",stringoftext);
/*
the above print will not work. I used the wrong specifier. 
to print string of character using the char variable type, you'll need to use the %s specifier.
but, i won't just let you fly like this. Whenever we make a mistake, not only do we have to know the solution, 
but also how did our code was interpreted. 
turns out to be mostly an undefined behaviour. 
*/ 
printf("\n%s",stringoftext);
/*
we can also displays min and max of char. 
*/
char maxchar = CHAR_MAX;
char minchar = CHAR_MIN;
char bitchar = CHAR_BIT;
printf("\n%c\n%c\n%c", maxchar, minchar, bitchar); 
/*
charmin and charmax not being printable characters, it's understandable that they won't be anything in output.
However, i'll need to dig deeper what charbit is. 
https://stackoverflow.com/questions/3200954/what-is-char-bit
https://gustedt.wordpress.com/2010/06/01/how-many-bits-has-a-byte/
according to those two links, simply put, char_bit is the macro defining the size of a byte, or, put less simply, 
the size of the smallest amount of bits that can be addressed by the computer. Let's try something. 
*/
int charbit = CHAR_BIT;
printf("\n%d",charbit);
//Alllright, interesting. But, no surprise so far. 
int charmax = CHAR_MAX;
int charmin = CHAR_MIN;
printf("\n%d\n%d", charmax,charmin);

/*
interesting. since char only range from 127 to -128, there's no surprise in numbers above 127 not being supported.
so, maybe my encoder does supports french peoples >:) 
However, there's something else i'll like to try. 
*/
char negative = -127;
char negative2 = -66;
char negative3 = -17;
printf("\n%c\n%c\n%c",negative,negative2,negative3);
//expectable. There's no negative ASCII characters. 

//signed chars, now. I don't know why you would need negative chars to be certainly signed, but here we are.
//maybe to do operation between characters. 
signed char schar1 = 66; 
signed char schar2 = 'a';
signed char schar3 = -66;
printf("\n%c\n%c\n%c",schar1,schar2,schar3);

int scharmax = SCHAR_MAX; 
int scharmin = SCHAR_MIN;
printf("\n%d\n%d",scharmax,scharmin);

/*
And now the unsigned char. Have the same range as the signed char, but, is only positive. 
Range from 0 to 255. It can be seen as a long char, and it gives us access to 128-255 characters : 
*/
unsigned char uschar1 = 66;
unsigned char uschar2 = 'a';
unsigned char uschar3 = 224;
printf("\n%c\n%c\n%c",uschar1,uschar2,uschar3);

int uscharmax = UCHAR_MAX; 
printf("\n%d",uscharmax);
/*
what's interesting is that, i tried to run the code on my VSC, and on my windows cmd only now, since the 224
unsigned char didn't showed me the expected symbol, it didn't showed me anything, in fact. However, in win cmd : 

0======================================Char Zone======================================
a
b
bass
s
@
¨
É
I am a vampire.

Ç

8
127
-128
ü
¥
´
B
a
¥
127
-128
B
a
Ó
255

the above values aren't the ones espected, so, for the sake of it, i'll go and find how to get which encoding
is my cmd using, and my VSC too. 

right, my windows cmd is using the page code 850, also known as OEM Multilingual :  
https://en.wikipedia.org/wiki/Code_page_850
given the above article, the output i'm getting is correct, and expectable. 
And, I'm on UTF-8 on VSC. 
https://en.wikipedia.org/wiki/UTF-8
Which, once again, given the above information, won't show me anything above 127, or 0xFF. 
Depending on your enconding, it'll surely change. 
I have some last things i want to try before leaving the char types variables : 
*/
signed char text4[] = "Am I a vampire ?";
unsigned char text5[] = "Surely not. So, it may be something else. But what ?";
printf("\n%s\n%s",text4,text5 );

/*
i also know that you can put thing between the [] brackets. I wanna try what, and how. we may be gone for more
than a 20 minutes adventure. 
*/

//char text6[6]; 

/*
It appears that this define a char of only 6 bytes (which ares 8 bits long), nothing more.It also appears, 
according to our dear friend chatgpt, to be uninitialized, which mean undefined behaviour. variables using 
[] brackets also appears to be called arrays. 
It appears that in the series of tutorials i'm currently following, arrays are a whole other chapter. 
I don't think we should treat it like that. I think it is among the basics, so i'll treat it here. 
It's not gonna be a 20 minutes adventure, Oh no. 
to initialize such array, i'll have to do the following : 
*/

//text6 = "12345";

/*
here, i've initialized the array with only 5 charcters, while it requires 6. Let's see how it is doing :
*/
//printf("\n%s",text6);

/*
do not initialize the array without specifiying it is an array.
here, above, my text6 get interpreted as an integer. 
*/

//text6[6] = "12345";

/*
the above also doesn't works. 6 is out of the bounds of the 0-5 addresses of the array. 
I'm trying to access an address in the array that doesn't exists. 

*/

//text6[] = "12345"; 

/*
this too appears to be invalid. Arrays, in C can't be redefined as whole in C. That's what i'm trying to do here.
what i need to do is to either use the header <string.h>, or initialize it when i declared it.
note that i've decided to move the initialization of text6 down here, for readability. it's still up there,
at line 356.
*/

/*
char text6[6]; 
char text7[6] = "123456"; 
strcpy(text6, "helloo");
printf("\n%s\n%s",text6,text7);
*/

/*
this result in an interesting behaviour, being memory overwrite. i don't know the full extend of it yet,
but here's what I understood. 
Since neither text6 or text7 have a bit left for the null terminator (i learnt about its existence just now),
meaning a memory overwrites happen between text6 and text7 : 

output : 

helloo
123456helloo

that would mean that i'll need to left a byte free for the Null-termination. 
*/
char text6[6]; 
char text7[6] = "12345"; 
strcpy(text6, "hello");
printf("\n%s\n%s",text6,text7);

/*
which does works.
we've almost covered all the things my curiosity is asking me to cover. We saw what happen when we overwrite, 
but what happen when we underwrite, and don't declare enough characters to fully fill the array ? 
*/
char text8[6] = "1234";
printf("\n%s",text8);

/*
Nothing particular. That's all for today. See you in a bit, i hope. 
*/
return 0;
}