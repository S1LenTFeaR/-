#ifndef BASE
#define BASE
struct NOTE
{
    char First_Name[9], Second_Name[9];
    int Number;
    int date[3];
    int Date;
}*arr, tmp;
int note(int s, struct NOTE *arr);
int Sort(int s, int i, struct NOTE *arr, struct NOTE tmp);
int pomeshaem(int s, int i, struct NOTE *arr);
int vivod(int s, int i, struct NOTE *arr);





#endif 