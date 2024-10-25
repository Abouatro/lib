#include "libft.h"

int is_include(char const *set,char c)
{
    int i;

    i = 0;
    while (set[i])
    {
        if(set[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int SkiipSet_atBeg(char const *set,char const *s1)
{
    int i;

    i = 0;
    while (is_include(set,s1[i]))
        i++;
    return (i);
}

int SkiipSet_atEnd(char const *set,char const *s1)
{
    int i;
    int counter;

    i = ft_strlen((char *)s1) - 1;
    counter = 0;
    while (is_include(set,s1[i]))
    {
        i--;
        counter++;
    }
    return (counter);
}

char *ft_strtrim(char const *s1, char const *set)
{
    int skiip_beg;
    int skiip_end;
    char *str;
    char *s;
    int i;

    skiip_beg = SkiipSet_atBeg(set,s1);
    skiip_end = SkiipSet_atEnd(set,s1);
    s = (char *)s1;
    str = (char *)malloc(((ft_strlen(s) - (skiip_beg + skiip_end))  + 1) * sizeof(char));
    if (!str)
        return (str);
    while ((unsigned int)(i + skiip_beg) < (unsigned int)(ft_strlen(s) - skiip_end))
    {
        str[i] = s[skiip_beg + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

int main()
{
    char const* s1 = "assssaasMy name is ayoubasassasass";
    char const* set = "as";

    printf("------>%s\n",ft_strtrim(s1,set));
}