#include <TXLib.h>
int SwitchStr(char ** s1, char ** s2);
int main()
{
    char * s1 = "a";
    char **s11 = &s1;
    char * s2 = "b";
    char **s21 = &s2;
    SwitchStr(s11,s21);
    puts(s1);
    puts(s2);
}
int SwitchStr(char ** s1, char ** s2)
{
    char * temp = *s1;
    *s1 = *s2;
    *s2 = temp;
    return 0;
}