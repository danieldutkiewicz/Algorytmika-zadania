/*
Program wykrywa najmniejsze możliwe palindromy w zdaniu do 200 znaków.
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    const int t_size = 256;
    
    char input[t_size];
    gets(input);
    
    char palindrom[t_size];
    char niepalindrom[t_size];
    
    int dl = strlen(input);
    
    bool znaleziono = true;
    bool pisz_palindrom = true;
    
    char zapisz[4];
    
    for(int i = 0; i < dl; i+=2)
    {
        //printf(" %d ", i);
        
        if(input[i] == input[i+1] && znaleziono == true)
        {
            pisz_palindrom = true;
            
            palindrom[i] = input[i];
            palindrom[i+1] = input[i+1];
        }
        else
        {
            pisz_palindrom = false;
            
            niepalindrom[i] = input[i];
            niepalindrom[i+1] = input[i+1];
            
            if(znaleziono == true)
            {
                zapisz[0] = niepalindrom[i+1];
                zapisz[1] = niepalindrom[i];
                //printf(" | Zapisano: %c%c | ", zapisz[0], zapisz[1]);
            }
            
            znaleziono = false;
        
            if(niepalindrom[i] == zapisz[0] && niepalindrom[i+1] == zapisz[1])
            {
                znaleziono = true;
                //printf(" Znaleziono! ");
            }
           
            if(znaleziono == true)
            {
                printf("%c%c ", niepalindrom[i], niepalindrom[i+1]);
            }
            else
            {
                printf("%c%c", niepalindrom[i], niepalindrom[i+1]);
            }
        }
        
        if(pisz_palindrom == true)
        {
            printf("%c%c ", palindrom[i], palindrom[i+1]);
        }
    }

    return 0;
}
