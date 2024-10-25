#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

short Count_Word(const char *str,char c)
{
    int i;
    short counter;

    i = 0;
    counter = 0;
    while (str[i])
    {
        while (str[i] && str[i] == c)
            i++;

        if(str[i] && str[i] != c)
            counter++;
    
        while (str[i] && str[i] != c)
            i++; 
    }

    return (counter);

}

char *get_word(const char *str,char c)
{
    char *Word;
    int len_Word;
    int i = 0;

    while (str[len_Word] && str[len_Word] != c)
        len_Word++;
    
    Word = malloc((len_Word + 1) * sizeof(char));
    if (!Word)
        return (NULL);
    while (str[i] && str[i] != c)
    {
        Word[i] = str[i];
        i++;
    }

    Word[i] = '\0';
    return (Word);

}

char	**ft_split(char const *str, char c)
{
    short nbr_word;
    char **sWord;
    int i;
    int indexWord;


    i = 0;
    indexWord = 0;
    nbr_word = Count_Word(str,c);
    sWord = (char **)malloc((nbr_word + 1) * sizeof(char *));
    if(!sWord)
        return (NULL);
    
    while (str[i])
    {
        while (str[i] && str[i] == c)
            i++;
        if(str[i] && str[i] != c)
        {
            sWord[indexWord] = get_word(&str[i],c);

            while (str[i] && str[i] != c)
                i++;  
        }
        indexWord++;
    }
    sWord[indexWord] = NULL;
    
    return (sWord);
}

int main()
{
    const char *buff = "   Ayoub   student   at   ump6   this   years  ";
    char **Word = ft_split(buff,' ');
    int i = 0;
    while (Word[i] != NULL)
    {
        printf("this word [%d] : %s\n",i,Word[i++]);
    }
    
}