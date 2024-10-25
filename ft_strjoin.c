#include "libft.h"
#include <stdlib.h>


char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;
    char *str1;
    char *str2;
    int i;

    str1 = (char *)s1;
    str2 = (char *)s2;
    i = 0;
    str = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
    if (!str)
        return (NULL);
    while (str1[i])
    {
        str[i] = str1[i];
        i++;
    }
    while (*str2)
    {
        str[i++] = *str2;
        str2++;
    }
    str[i] = '\0';
    return (str);
}

int main()
{
    const char *s1 = "ayoub leeet ";
    const char *s2 = "1337 is";

    printf("----> %s\n",ft_strjoin(s1,s2));

}
