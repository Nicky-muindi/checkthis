#include<stdio.h>

#include<stdarg.h>



void Myprintf(char *,...); /* Our printf function*/

char* convert(unsigned int, int); /* Convert integer number into octal, hex, et*/

int main()

{

    Myprintf(" Nicholas Mwanza \n %d",9);
    
    Myprintf(" I love C Programming \n %s",9);


    return 0;
    
}

void Myprintf(char* format,...)

{

    char *traverse;
    
    unsigned int i;
    
    char *s;
    
/* Module 1: Initializing Myprintf's arguments */

    va_list arg;
    
    va_start(arg, format);
    
    for(    traverse = format; *traverse != '\0'; traverse++)
    
    {
    
        while( *traverse != '%' )
	
        {
	
            putchar(*traverse);
	    
            traverse++;
	    
        }
	
        traverse++;
	
/* Module 2: Fetching and executing arguments */

        switch(*traverse)
	
        {
	


        case 'c' :
	
            i = va_arg(arg,int); /* Fetch char argument /Fetch char argument*/
	    
            putchar(i);
	    
            break;
	    
            break;
	    


        case 'd' :
	
            i = va_arg(arg,int); /* Fetch Decimal/Inte /Fetch Decimal/Inte */
	    
            if(i<0) if(i<0)
	    
                { {
		
                        i = -i;
			
                        i = -i;
			
                        putchar('-');
			
                        putchar('-');
			
                    }
		    
                }
		
            puts(convert(i,10));
	    
            puts(convert(i,10));
	    
            break;
	    
            break;
	    
        case 'o':
	
            i = va_arg(arg,unsigned int); /* Fetch Octal representation */
	    
            puts(convert(i,8));
	    
            puts(convert(i,8));
	    
            break;
	    
            break;
	    
        case 's':
	
            s = va_arg(arg,char *); /* Fetch string /Fetch string */
	    
            puts(s);
	    
            puts(s);
	    
            break;
	    
            break;
	    
        case 'x':
	
            i = va_arg(arg,unsigned int); /* Fetch Hexadecimal represent */
	    
            puts(convert(i,16));
	    
            puts(convert(i,16));
	    
            break;
	    
            break;
	    
        }
	
    }
    
/* Module 3: Closing argument list to necessary clean-up */

    va_end(arg);
    
}

char *convert(unsigned int num, int base)

{

    static char Representation[]= "0123456789ABCDEF";
    
    static char buffer[50];
    
    char *ptr;
    
    ptr = &buffer[49];
    
    *ptr = '\0';
    
    do
    
    {
    
        *--ptr = Representation[num%base];
	
        num /= base;
	
    } while(num != 0);
    
    return(ptr);
    
}