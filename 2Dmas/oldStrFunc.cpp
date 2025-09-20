#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 50

int myputs (const char *s);
const char* mystrchr (const char * s, int c);
size_t mystrlen (const char * s);
char *mystrcat (char * s1, const char * s2);
char *mystrncat (char * s1, const char * s2, size_t n);
int myatoi(const char * nptr);
char *myfgets(char *str, int num, FILE *stream);
char *mystrdup(char *str);
int mygetline(char **lineptr, size_t *n, FILE *stream);           

int main(int argc, char * argv[])
{
    char s[] = "123I am a string!";
    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "--puts"))
        {
            myputs(s);
        }
        else if (!strcmp(argv[i], "--strchr"))
        {
            char c = ' ';
            printf("What element do you want to find?\n");
            c = getchar();
            printf("Poiter to wanted element: %p\n", mystrchr(s, c));
        }
        else if (!strcmp(argv[i], "--strlen"))
        {
            printf("The length of your string: %d, %d\n", mystrlen(s), sizeof(s) - 1);
        }
        else if (!strcmp(argv[i], "--strcat"))
        {
            char s1[MAXSIZE] = "Hello,";
            const char s2[] = " World!";
            myputs(mystrcat(s1, s2));
        }
        else if (!strcmp(argv[i], "--strncat"))
        {
            char s1[MAXSIZE] = "Hello,";
            const char s2[] = " World!";
            myputs(mystrncat(s1, s2, 3));
        }
        else if (!strcmp(argv[i], "--atoi"))
        {
            printf("%d\n", myatoi(s));
        }
        else if (!strcmp(argv[i], "--fgets"))
        {
            FILE *fp = fopen("myfile.txt", "rb");
            if (!fp) 
                printf("!fp\n");
            char mas[MAXSIZE] = {};
            char *str = mas;
            myfgets(str, MAXSIZE, fp);
            myputs(str);
        }
        else if (!strcmp(argv[i], "--strdup"))
        {
            myputs(mystrdup(s));
        }
        else if (!strcmp(argv[i], "--getline"))
        {
            size_t n = 3;
            char *lineptr = (char *) calloc(sizeof (char), n);
            free(lineptr);
            FILE *fp = fopen("myfile.txt", "rb");
            printf("%c\n", mygetline(&lineptr, &n, fp));
        }
        else
        {
            printf("Try --puts, --strchr, --strlen, --strcat, --strncat, --atoi, --fgets, --strdup, --getline flags.\n");
        }
               
    }
}

//TODO: use function simpiler that writes one char to stdout
//TODO: EVERY STD FUNCTION MUST BE CHECKED FOR RETURNED VALUE
//const char *save_ptr = s; //TODO:
//TODO: --*s *--s (*s)++ *(s++) *s++ 

int myputs (const char *s)
{
    if (!s)
        return EOF;
    
    const char *save_ptr = s;
    while (*s != '\0') {
        putchar(*(s++));
    }
    putchar('\n'); 
    return '\n';
}

const char* mystrchr (const char * s, int c)
{
    const char *save_ptr = s;
    while (*s != '\0') {
        if (*s == c)
        {
            return s;
        }
        *(s++);
    }
    if (!c) {
        return s;
    }
    return NULL;
}

size_t mystrlen (const char * s)
{
    const char *save_ptr = s;
    size_t cnt = 0;
    while (*(s++) != '\0') {
        cnt++;
    }
    return cnt;
}

char* mystrcat (char * s1, const char * s2)
{
    char *save_ptr1 = s1; 
    const char *save_ptr2 = s2; 

    while (*s1 != '\0') {
        *s1++;
    }
    while (*s2 != '\0') {
        *(s1++) = *(s2++);
    }
    *s1 = '\0';
    return save_ptr1;
}

char *mystrncat (char * s1, const char * s2, size_t n)
{
    char *save_ptr1 = s1;
    const char *save_ptr2 = s2;

    size_t i = 0;
    while (*s1 != '\0') {
        *s1++;
    }
    
    while (*s2 != '\0' && i++ != n) {
        *s1++ = *s2++;
    }

    *s1 = '\0';

    return save_ptr1;
}

int myatoi(const char * s)
{
    const char * save_ptr = s;
    int ans = 0;
    while (isspace(*s)) {
        *s++;
    }
    while (isdigit(*s)) {
        ans = ans * 10 + (*s++ - '0');
    }
    return ans;
}

char *myfgets(char *s, int n, FILE *fp)
{
    char *save_ptr = s;
    for (int i = 0; i < n; i++) {
        if ((*s = fgetc(fp)) == EOF || *s == '\n') {
            --*s = '\0';
            return s;
        }
        *s++;
    }
    return save_ptr;
}

char *mystrdup(char *s)
{
    char * save_ptr1 = s;
    char * ptr = (char *) calloc(sizeof (char), mystrlen(s) + 1);
    char * save_ptr2 = ptr;
    while (*s != '\0') {
        *ptr++ = *s++;
    }
    *ptr = '\0';
    return save_ptr2;
}

int mygetline(char **lineptr, size_t *n, FILE *fp)
{
    char *save_ptr = *lineptr;
    
    if (!(*lineptr))
        *lineptr = (char *) calloc(sizeof (char), *n);
    size_t cnt = 0;
    while ((**lineptr = (char) fgetc(fp)) != '\0') 
    {    
        if (**lineptr == '\n')
        {
            return (int)**lineptr;
            break;
        }
        cnt++;
        printf("%p\n", *lineptr);    
        if (cnt > *n)
        {
            printf("1\n");
            char *lineptr_new = (char *) realloc(*lineptr, MAXSIZE * sizeof(char));
            printf("%p\n", lineptr_new);
            //(*lineptr)++;
            *lineptr = lineptr_new;
            printf("%p\n", *lineptr);
            // if (!lineptr_new)
            // {
            //     printf("error\n");
            //     return EOF;
            // }
            // else
            // {
                
            // }
        }
        
        putchar((int)**lineptr);
        (*lineptr)++;
        printf("%p\n", *lineptr);
    }
    printf("%p\n", *lineptr);
    if ((**lineptr == '\0'))
    {
        *lineptr--;
        return (int)**lineptr;
    }
    return EOF;
}