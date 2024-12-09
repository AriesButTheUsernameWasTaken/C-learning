#include <stdio.h>
int main(){
    //Tutorial serie used, cause why not, that may interest ya https://www.youtube.com/watch?v=8Vt9k0bh_Q8&list=PLZPZq0r_RZOOzY_vR4zJM32SqsSInGMwe&index=3
    //like in every other language, looks like its the // who does te job 
    /*great. 
    multiline commentaries. 
    beautiful.*/
    /*
    and let's indent things correctly.
    */

   //Now, about esacapes sequences 
   //New lines with "\n" 
   printf("New line\nNew line\nTheory\nPractice\nRepeat \n");
   printf("This one if for tabs, as it seems. \tEvenly distributed tabs\t cleans and nice.\t let's try it out");
   printf("And now, we can mess around.\n\t and even indent our displayed things.\n\t\tJust like this.\nThis\tis\tso\tpractical");
   
   //At this point, tutorial shows many other esacapes sequences i was unaware of, and i've decided to play with. 

   //list of escapes sequences : \a, \b, \e , \f \n (we arlready learnt this one) \r \t (same) \v \\ \', \" \? \nnn \ xhh... \uhhh (4digits) \uhhhhhhhh (8digits)"
   // wikipedia article about the escapes sequences : https://en.wikipedia.org/wiki/Escape_sequences_in_C#Escape_sequences

   //let's mes up with \a : https://en.wikipedia.org/wiki/Bell_character

   printf("\nlets play with ring bell : \a");
   printf("another bell, please ? \a \a \a \a \a \a ");
  
  //kay, it's funny, next one : \b

    printf("\n let's now play with the 123\b123");
    printf("\n\b this shouldbe fun ");
    printf("\n123456789\b");
    printf("\nSeems to work only if there's a character behind 12345\b6789");
   
   //not that fun, can't see so far what it could be useful for
   //Now onto the next section : \e : 
   printf("\n start 12345\e6789 let's see what it does\n");
   printf("\e 123456789 \n");
   printf("123456789\e\n");
   printf("\e12 \n");

   //okay, weird, but not that useful too, as itseems so far.Now, the \f. 
    printf("Now onto the \\f sequence\n ");
   printf("123456789\f \n");
   printf("1234\f56789 \n");
   printf("\f123456789 \n");
   
   //so far, seems to work as a \n

   printf("\\r sequence, as far as i know, it's same as \\n \n");
   printf("123456789\r \n");
   printf("\r123456789 \n");
   printf("12345\r6789 \n");

//okay, that was more interesting that expected
printf("Now onto the vertical tab section \\v\n");
printf("\v123456789\n");
printf("123456789\v\n");
printf("1234\v56789\n");

//interesting. Now let's do sports, i still haven't fully grasped the concept, so, i hope i will while practicing. 
printf("octal and hexadecimal byte number section\n");
printf("octal displays\n \1 \n \11 \n \121 \n");
printf("\n hexadecimal displays\n \x1 \n \xB \n \x51 \n \x79 \n");
//notes : these are used to displays bytes referring to the memory address corresponding to the number entered. 
//in base 8 for octal, and hexadecimal, is hexadecimal. 
//i thought octal was in base 10, so, 121 in base 10, converted into hexadecimal gives us \x79, which is absolutely not the same address. 
//you can try it yourself, if you want. 


printf("\n now, onto the unicode code poitn aka \\uhhhh and \\uhhhhhhhh");
//printf("\u0010");
//printf("\u008F");
//Those ones can't be displayed. Since they're part of the plan 0 of unicode, called the BMP, from 0000 to 000F
//if you check hre : https://en.wikibooks.org/wiki/Unicode/Character_reference/0000-0FFF 
//you can see that thoses caracters are not displayable, or at least, i don't know how to yet. 
printf("\n \u00AE ");
// seems like \uhhhh only displays plane 0 of unicode, according to this article : 
// https://en.wikipedia.org/wiki/Plane_(Unicode)
//Also, you may need to check if the terminal you're using is running with the correct encoding
//or instead of the r in a circle, you'll end up with something else. 
printf("\n \uFFFF \n \uFD66 \n \u00B6 \n \u00d8");
//you can use small and big letter cases, it works anyway. 

//\uhhhhhhhh is used for codes above FFFF. planes greater than 0. 
printf("\n \u11000 \n \u20000");
//once again, check the encoding of your output tool. 

   return 0 ;
} 