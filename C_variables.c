//here's the tutorial followed in this code : https://www.youtube.com/watch?v=aIQk1O08zpg&list=PLZPZq0r_RZOOzY_vR4zJM32SqsSInGMwe&index=4
/*
And the one for constants : 
https://www.youtube.com/watch?v=Y17nTXAWBqs&list=PLZPZq0r_RZOOzY_vR4zJM32SqsSInGMwe&index=7
Archives used : 
https://stackoverflow.com/questions/50841881/why-is-the-format-in-printf-marked-as-restrict
https://en.wikipedia.org/wiki/C_data_types
https://www.youtube.com/shorts/6vNMDb316Ck
https://www.geeksforgeeks.org/format-specifiers-in-c/
https://www.geeksforgeeks.org/int_max-int_min-cc-applications/
https://www.geeksforgeeks.org/climits-limits-h-cc/
https://www.w3schools.com/c/c_data_types_characters.php
https://www.spsanderson.com/steveondata/posts/2024-09-18/
https://www.w3schools.com/charsets/ref_html_ascii.asp
https://en.wikipedia.org/wiki/ASCII
https://en.wikipedia.org/wiki/Extended_ASCII#/media/File:Table_ascii_extended.png
https://stackoverflow.com/questions/3200954/what-is-char-bit
https://gustedt.wordpress.com/2010/06/01/how-many-bits-has-a-byte/
https://en.wikipedia.org/wiki/Code_page_850
https://en.wikipedia.org/wiki/UTF-8
https://www.codingeek.com/tutorials/c-programming/2d-character-array-string-array-declaration-and-initialization/
https://www.geeksforgeeks.org/multidimensional-arrays-in-c/
https://en.wikipedia.org/wiki/Single-precision_floating-point_format


*/

//once again, i'll play around with it, and comment the results I get, so, both, me and you, the reader can get a good understanding of what I did. 
#include <stdio.h>
//Added the following header to be able to play with the macros of variables. 
#include <limits.h>
//Added the following header to be able to play with booleans variables. 
#include <stdbool.h>
//Added the following header to be able to play with strings
#include <string.h>
//Added toeh following header to be able to play with long double. double and floats worked great. 
//It doesn't work. 
//#include <float.h>

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

/*============================Added Saturday the 28th, of December 2024============================*/
printf("============================Added Saturday the 28th, of December 2024============================");
/*
today I'll like to dive deeper into the arrays, or at least their declaration and basics.
Since I consider them as variables, or, more exactly, variations of variable, i consider it is equally important
to learn them at an early stage. Escpecially common traps, like I've seen the last day, with char arrays 
and the Null terminator byte, leading to a memory overflow.
I'll like to see 2d arrays, in char, and then in integers. then we we'll see if i don't want to do somethin else. 
like finding a job. Heh. 

Anyways. 
Here's how to declare and initialize a 2d char array.
https://www.codingeek.com/tutorials/c-programming/2d-character-array-string-array-declaration-and-initialization/
*/
char dimensions2[5][3]={"flow","mall","pit"};
/*
As you can see, since it is a char array, we need to take in consideration that the length of our strings will
be less to one byte of the declared array. Seen as a table, the array in 2 dimensions will be declared as 
follows : 
-First, the lenght of the words ==> 5 here, minus one for the null terminator, leaving us with 4. 
-Second, how many rows will be declared. ==> 3. There's no other (as far as i'm aware) parameters that would 
lead to have one row dedicated to a whole technical detail, so, the rows will be as many as declared. 
Now, how do we print that out ? 
First, let's try a simple idea.
*/
printf("\n%s",dimensions2);
/*
This doesn't looks that good. And, it isn't because of the null terminator thing. but just for the sake or if,
let's do this : 
*/
char dimensions21[5][3]={"abc","def","ghi"};
printf("\n%s",dimensions21);
/*
Guess what. I was wrong. the first one is for how many rows will our array contain, and the second one for 
how many characters will be used. 
*/
char dimensions22[5][3]={"io","nb","gt","er","bl"};
printf("\n%s",dimensions22);
/*
What's interesting in here, is that, this the two previous attempt didn't contained null terminators, 
printing the array didn't stop the code to just print the first array element, but the whole array. 
This would also mean, that, the array as a whole, since not having null terminator, would respond in an 
undefined behaviour, being, as seen above, merging altogether the array elements into one. 
Here, in the last attempt, we only have the first array element. 

Doing errors is important. 

So now, let's try to access any single one of our array element. Usually, this is where we take the famous tool, 
known as the for loop, but since i haven't learned them in this language, i'll keep doinf things the old, 
and, mostly, unpractical way. 
*/
printf("\n%s",dimensions22[0]);
/*
I have already the chance to work with others types of arrays before learning this language, 
so i already know that arrays indexes starts at 0. and end at arrays size, minus one. in our case, being 4. 
*/
printf("\n%s",dimensions22[1]);
printf("\n%s",dimensions22[2]);
printf("\n%s",dimensions22[3]);
printf("\n%s",dimensions22[4]);
/*
i could also print it like this : 
*/
printf("\n%s\n%s\n%s\n%s\n%s",dimensions22[0],dimensions22[1],dimensions22[2],dimensions22[3],dimensions22[4]);
/*
but that means i can't use my favorite tool as efficiently as above. (ctrlc+ctrlv). I mean, both method are doing
pretty good, but, i think the matter of which one to choose depends on how tight we are on the hardware we're 
working with. 
Now, the question everyon wants to seen answered :  We already know what happens when we have too many characters
in our arrays, not enough characters (not fully filled string of characters), not fully filled rows, but, 
what happen when we fill too many rows ? 
I'll also use the other method of 2d array declaration/initialization in the following example.
*/
char dimensions23[5][3]={
{"aa"},
{"bb"},
{"cc"},
{"dd"},
{"ee"},
//now, we have all our rows fully loaded, and we will add one more, just for the fun.
//{"ff"}
};
printf("\n%s",dimensions23);
/*
Althought i can run this properly without proble SO FAR, i still get a notification in the problems tab of the
console : 
[{
	"resource": "mypath",
	"owner": "cpptools",
	"severity": 4,
	"message": "excess elements in array initializer",
	"source": "gcc",
	"startLineNumber": 514,
	"startColumn": 1,
	"endLineNumber": 514,
	"endColumn": 1
}]
which falls into the expectable behaviours. I expected an error making the compilation and running impossible.
This is a really interesting behaviour, it could be useful. Since we're here for the fun of it, let's try to 
actually access this array element. 
*/
printf("\nsupposedly index 6 of dimensions23 : %s",dimensions23[5]);
/*
What's interesting is that i do not get any errors, while trying to access a data that isn't supposed to exists. 
But, since i've initialized it, without declaring it, i guess we're into undefined behaviour territory. 
Maybe, since the memory space is initialized but not declared, the computer know that there is a space for 
the index[5] of dimensiosn23, but since it isn't declared, it doens't know where, and print something out of 
the blue. 
That's really interesting, i wonder how it could be exploited. 
one thing that could also be done os to access one specific slot in the array, in the 2d array.
i'm gonna take back our simple strings of text here, then go back to our 2d arrays. 
*/
//printf("\nfirst character of the text6 array : %s",text6[0]);
/*
weird, if got the following error : 
Exception has occurred.
Segmentation fault
tried again, but didn't encoutered this error anymore. However, now i'm having a problem 
with the sixth and undeclared row of dimensions23. 
back with the segmentation fault. I have to seek knowledge. 
okay, rookie mistake, as it appears. Since I'm trying to access a single characters, it may be from a string, 
but the type of data required is a single character, therefore, the specifier i'll need to use will be the 
one for the single character. Hence : 
*/
printf("\nfirst character of the text6 array, using the correct specifier: %c", text6[0]);

/*
I am encountering quite another problem. Quite ironic. 
The permission for opening the output file on my own computer is denied. 
It looks like i need to shut down VSC, delete the application files, and restart VSC to be able to access 
the output file. 
I have one track about this. Maybe the sixth row of dimensions23 is messing with the executable file. 
As far as I'm aware, that's the only thing that could produce such behaviour. 
looks like it was it. 
But i'm not THAT sure of it. However, we're accessing our desired data correctly. 
*/
printf("\nThe first character of the second row of dimensions22 : %c",dimensions22[1][0]);
/*
That wrap it up about the 2d arrays. Let's now seek what are the 3d arrays. 
https://www.geeksforgeeks.org/multidimensional-arrays-in-c/
I don't know i i put it down already, but here's how the 3d array works : 
char dimensions3 [Depth of the 3d arrays, or how many 2d arrays will be stack uponeach others][row][colums, or number of characters]
so, for something around 
char dimensions3[9][6][3]
that's gonna be 9 tables of 6 rows and 3 columns. Or characters. but let's do something a bit more light. 
Once again, there's 2 syntaxes :  
*/
char dimensions3[2][3][5]={
	//first depth
	{
		// 3 rows from there
		{"plop"},
		{"flop"},
		{"dire"}
	},
	//second depth
	{
		{"fire"},
		{"sit"},
		{"dog"},
	}
};
printf("\n%s",dimensions3[0][2]);
printf("\n%s",dimensions3[0][3]);
/*
the interesting behaviour of how the data are printed is once again not disappointing. 
There's no row that should answer to the index 3, yet, when looking for the fourth row of the first depth, 
the data printed instead of an error is the first one of the second depth, as if the counting was reported on
the second layer of our 3d array. 
*/
printf("\n%s",dimensions3[1][3]);
/*
as expected, since there's nothing else after our 3d array, when asking to get somehting out of the bounds of the
arrays while referencing the array, nothing's printed. 
but, we can, with mutiples go from one layer to another, while referencing another one. 
*/
printf("\n%s",dimensions3[0][5]);
printf("\n%c",dimensions3[0][2][2]);

char dimensions31[3][4][6]={"first","layer","end","now","2nd","depth","stops","here","this","is","level","three"};
//and i hope i know how to count. so let's retry our funny thing. 
printf("\nprintfs of dimensions31: %s",dimensions31[0][5]);
printf("\n%s",dimensions31[0][9]);
printf("\n%s",dimensions31[1][4]);
printf("\n%s",dimensions31[0][0]);
printf("\n%s",dimensions31[1][0]);
printf("\n%s",dimensions31[2][0]);
/*
looks like it works. only things left now is to do it for integers too. 
*/
int array1d1[5]={1,2,3,4,5};
printf("\n%d",array1d1[2]);

int array2d1[2][5]={1,2,3,4,5,6,7,8,9,0};
printf("\n%d\n%d",array2d1[0][0],array2d1[1][4]);
int array2d2[3][5]={
	{10,20,30,40},
	{50,60,70,80},
	{90,100,200,300}
};
printf("\n%d\n%d\n%d",array2d2[0][3],array2d2[1][2],array2d2[2][1]);

int array3d1[2][2][2]={1,2,3,4,5,6,7,8};
printf("\n%d\n%d\n%d\n%d",array3d1[0][0][1],array3d1[0][1][0],array3d1[1][0][0],array3d1[1][1][0]);

int array3d2[3][2][3]={
	{
		{1,2},
		{}
	},
	{
		{10,20,30},
		{40,50}
	},
	{
		{100,200,300},
		{400,500,600}
	}
};
printf("\n%d\n%d\n%d\n%d",array3d2[2][1][2],array3d2[0][1][0],array3d2[1][0][1],array3d2[1][1][2]);

/*
seems correct to me. There are uninitialized slots, and it seems that uninitialized integers are on 0 by default. 
so, that's all for today. See you in a bit.g
*/

printf("=========================================Added Tuesday, the Seventh of January 2025=========================================");
/*
Today, i'll like to see shorts ints.and maybe long ints too.  
*/
printf("======================short zone(put one on, even if its freezing)======================");
short billy;
billy = 16;
short shortmin = SHRT_MIN;
short shortmax = SHRT_MAX;
short lämp = 11111;

printf("\n%hd\n%hd\n%hd\n%hd",billy,shortmin,shortmax,lämp);

short int billy_the_second = 1; 
signed short billy_the_third = -1;
signed short int billy_the_kid = -3000;

printf("\n%hd\n%hd\n%hd",billy_the_second,billy_the_third,billy_the_kid);

unsigned short billy_the_one_too_many = 10;
unsigned short int billy_the_two_too_many = -1;
printf("\n%u\n%u",billy_the_one_too_many,billy_the_two_too_many);
/*
here, we can see the famous bug, in billy_the_two_too_many, that turn an unsigned variable into it's max 
value, whenever it hit a negative value. however, there's something else i'll like to try with this bug. 
*/
unsigned short int billy_the_two_two_many = -5535;
printf("\n%u",billy_the_two_two_many);
/*
hehe, it works. you can "substract" your desired number from the variable once it hits a negative value. 
here, even thought we substracted 5535, we still start at 0, so, it will actually not be 60 000, but 60 001.
*/
short yul[]={0,1,2,3};
printf("\n%hd",yul[2]);
/*
we can of course declare an initialize arrays into those types of variable too. not specifying the size
of the array, declare and initializes it still. It's just that it's not of a fixed sized. 
but i thinks we'll learn about that later. 
*/

printf("======================long zone(i promise it won't be THAT long)======================");

long g;
g = 2021489752;
long ng = -3;
long ong = LONG_MIN;
long Long = LONG_MAX;
unsigned long llong = 4000000123;
unsigned long int lllong = -1; 
long llllong [2][3]={
	{1,2,3,},
	{3,2,1}
};
printf("\n%li\n%ld\n%li\n%ld\n%ld\n%lu\n%lu",g,ng,ong,Long,llong,lllong,llllong[1][2]);

printf("======================long long zone======================");

long long long_long ; 
long_long = 1;
long long int long_loong = -1;
signed long long long_looong = 60065;
signed long long int long_loooong = -351983773;
long long long_looooong = LLONG_MAX;
long long long_loooooong = LLONG_MIN;
unsigned long long long_looooooong= -1;
unsigned long long int long_loooooooong = ULLONG_MAX;

printf("\n%lli\n%lld\n%lli\n%lld\n%lli\n%lld\n%llu\n%llu",long_long,long_loong,long_looong,long_loooong,long_looooong,long_loooooong,long_looooooong,long_loooooooong);

long long long_matriiiiiix[2][2]={8,7,5,4};
printf("\n%lli",long_matriiiiiix[1][0]);

/*
looks like we still got time to float. 
this artcile will help you to understand into more details how the calculation of a float works. 
https://en.wikipedia.org/wiki/Single-precision_floating-point_format
It's a bit hard to understand, but you'll get it, i'm convinced. 
1 : signed part (1) ==> + or -. 
2 : exponent (8) ==> value from -126 to 127, with a +127 biais to  fit it in the 0 to 255 range. 
 -126 are number under 0, and +127 are number above 0. 
3 : fraction (23) : when number converted in binary, then into scientific notation, is the precision,
meaning every number (in binary scientific notation of entered number) after the coma. 1.1 ==> 1 is stored. 
1.010101010101010101 ==> 010101010101010101 is stored. 
end result is fraction, exponent exponent, and the sign. 
was not as easy as expected. 
*/

printf("====================================float zone====================================");
printf("===============================Added the 15th of January 2025===============================");

float flottant = 1.2;
float bateau;
bateau = 30000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
float barque = 1.123456789123456789123456789123456787896565235889658967569879532589856985659123456789123456789;
float navire = 78987879878978.5555555; 

printf("\n%f\n%f\n%f\n%f",flottant,barque,bateau,navire);

/*
here, we can see that bateau is waaaay ahead of the limit of declaration, and is hence, not initialized. 
However, barque is under the limit, being rounded up to 1.123457.
now, let's play with doubles, being the double of a 32 bits float, being a 64 bits float. 
BUT. before. Let's play with the other format specifiers of floats.  
*/

printf("\n%f\n%g\n%a\n%e",navire,navire,navire,navire);

printf("=============================Double Zone=============================");
double gros_bateau; 
gros_bateau = 5.89; 
double gros_navire = 30000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 ; 
double grosse_barque = 789456123.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001 ;  
double grosse_flottante = 777777777777777777777777777777.8888888888888888888888888888888888 ;

printf("\n%lf\n%lf\n%lf\n%lf",gros_bateau,gros_navire,grosse_flottante,grosse_barque); 
printf("\n%lf\n%la\n%e\n%g",gros_bateau,gros_bateau,gros_bateau,gros_bateau);

/*
interestingly, the gros navire doesn't create an error, it display anyway, but not the seemingly correct, 
or expected thing. 
After seeking knowledge, (aka chatgpt, lol), i can safely tell you that, the behaviour, is expected,
and i was frankly trying to get to it : Overflow of the value. Meaning that gros_navire variable is too big
for the 32 bits assigned to one (or 64 for a double) variable. 
Now, let's play with long double. supposedly, it's along 96, or 128 bits. let's seek knowledge. 
apparently, since the variable is overflowed, it's assigning an infinity value to the variable, and, 
when asking to displays it, since it can't diplsays an infonite value, it displays the 0.00000... 
*/
printf("\n==================================long double zone==================================");
long double spaceship; 
spaceship = 127892.1565; 
long double mothership = 30000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
long double pursuit_spacecraft = 12.2;
long double stealth_ship = 1.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001 ; 
 printf("\n%Lf\n%Lf\n%Lf\n%Lf\v",spaceship,mothership,pursuit_spacecraft,stealth_ship); 
 printf("\n%Lf\n%La\n%Le\n%Lg",spaceship,spaceship,spaceship,spaceship);
 printf("====================================Added Friday the 17th of January 2025====================================");
 /*
 As you can see, mothership is expectedly too large, creating an error where the compiler can't displays it 
 correctly. However, other long doubles aren't correctly displayed here. But. Since we have many format 
 specifiers for floats, and its variants (double and long double), I've actually been able to realize that the 
 varaible is indeed initialized. What seems to be the origin of the problem is the %Lf format specifier. 
 After seeking knowledge on our dear friend chatgpt, it seems that that the central problem is running around 
 the compiler not being able to process the desired precision. 
 Which leaves us with quite a few question. 
 -I'm using GCC, what's the default long double precision ? 
 -Can I modify it ? 
 -How do I specify it ? 
 To the last, our firend already provided an answer, and I'll test it right away : 
 */
printf("\n%.20Lf",spaceship);
/*
that doesn't seems to work. 
Maybe we'll try to reduce it.
*/
printf("\n%.2Lf",spaceship);
/*
Doesn't work either. 
our dear friends gifted me more knowledge. There is, apparently macros not recorded in the wikipedia article
above. I'll first check if the knowledge given to me is correct. 
*/
long double long_double_max = __LDBL_MAX__;
printf("\nLong double max : %Lf\n%Lg",long_double_max,long_double_max);

/*
there IS some macro for our floating variable types, which onyl leave me with even MORE questions. 
- what are float and doubles macros ? 
- Why aren't they recorded in the wikipedia article ? 
So. let's try first what are our float and double macros. 
*/
float float_max = __FLT32_MAX__;
double double_max = __DBL_MAX__; 
printf("\n%Lg\n%Lg",float_max,double_max);
/*
surprisingly, it also appear, in the tab deployed by VSC using the above header file (<limits.h>) that there's
more than just maximum value of variables as macros. But that's not something i'll like to see right now.
Right now, once i've actually corrected my knowledge about wether or not floating variables have macros,
I just want to know why i can't print them correctly. 
*/

/*
while trying to get the size of a long double on my configuration, i also happenned to learn one more thing.
the %zu format specifier is used as a universal format specifiers to get the size of variables, 
no matter the configuration. 
*/
printf("\n%zu",sizeof(long double));
printf("\n=====================================Added Saturday the 18th of January 2025=====================================");

/*
It appears that since i'm running on a 64 bits long double system, instead of the usually used 128, or 80, 
the long double is misinterpredted by the compiler, and then nullified to 0. But this is something that, 
to my opinion, should also be done using the other format specifiers. And we see it actually works, when using
the other format specifier. So, that's not a size problem. It could be part of it, but there is also something 
else. The problem seems to be more with the library who's handling the %Lf format specifier. Which, since it's 
a 64 bits system, could be messed up, maybe because it's expecting a 128 or 80 bits format. 
apparently snprintf is also a thing, but i'll have to dig on it later. 
howerver, since i'm using MinGW, Apparently, it's why my long doubles are interpreted as floats. 
While this doens't answer why only %Lf don't work while other long double specifics format specifiers (Le,La,Lg)
do works, it gives me clues on why %Lf don't work : It's the wrong format specifier. 
*/
printf("\n%f",spaceship);
/*
which doesn't seems to work either. Guess we won't work with long double. -_-
Just to confirm, I'll also like to, dig arrays over floats and doubles. 
*/
float barge[] ={1.2,0.003,789456123,444.412385670};
double big_barge[] = {1.2,1.3,0.000001};
printf("\n%f\n%lf",barge[2],big_barge[0]); 

/*
Just for the fun, I'll also want to try something else. more than 3 dimensionnal array. Let's try 5. 
*/
int five_d_chess[2][2][2][3][4]={
/*
so, two instances, of 2 copy of 2 dimensionnal 3 rows, 4 column array. 
*/
//first instance : 
	{
		//first copy : 
		{
			//first dimension : 
			{
				{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12}
			},
			//second dimension : 
			{
				{13,14,15,16},
				{17,18,19,20},
				{21,22,23,24}
			}
		},
		//second copy
		{
			//second copy first dimension 
			{
				{25,26,27,28},
				{29,30,31,32},
				{33,34,35,36}
			},
			//second copy second dimension
			{
				{37,38,39,40},
				{41,42,43,44},
				{45,46,47,48}
			}
		}
	},
	//second instance
	{
		//second instance first copy
		{
			//second instance first copy first dimension
			{
				{49,50,51,52},
				{53,54,55,56},
				{57,58,59,60}
			},
			//second instance first copy second dimension
			{
				{61,62,63,64},
				{65,66,67,68},
				{69,70,71,72}
			}
		},
		//second instance second copy
		{
			//second instance second copy first dimension
			{
				{73,74,75,76},
				{77,78,79,80},
				{81,82,83,84}
			},
			//second instance second copy second dimension
			{
				{85,86,87,88},
				{89,90,91,92},
				{93,94,95,96}
			}
		}
	}

};
printf("\n%d",five_d_chess[1][0][0][2][3]);
/*
it works. We can do above 3d arrays. 
I thinks that settles it for variables in C. At least for now. 
*/

printf("========================Added Sunday, the 19th of January 2025========================");
/*
Guess what, we still had something to dig. It's gonna be quick. 
Constants. in a variable focused lesson. using the following video. 
https://www.youtube.com/watch?v=Y17nTXAWBqs&list=PLZPZq0r_RZOOzY_vR4zJM32SqsSInGMwe&index=7
*/
const int const_earth_rotation_speed = 1600; 
//const_earth_rotation_speed = 1500 ;  
/*
this, when decommented, produce the following error :  
error: assignment of read-only variable 'const_earth_rotation_speed'
Which guard us from changing the value of a constant. 
*/

return 0;
}