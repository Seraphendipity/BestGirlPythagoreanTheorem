// Random Thing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <setjmp.h>

jmp_buf buf;

int DummyFunction(void);

int main(int argc, char const *argv[])
{
    int a;
    int b;
    int c;
    int answer;
    char side;
start:
    printf("\nSelect side: ");
    scanf("%c", &side);
    printf("Enter the two side values \n");
    scanf("%d%d",&a,&b);
    answer = (side=='a') ? printf("b=%d c=%d a=%0.2lf\n",a,b,sqrt(b*b-a*a)) : (side=='b') ? printf("a=%d c=%d b=%0.2lf\n",a,b,sqrt(b*b-a*a)) : (side=='c') ?  printf("a=%d b=%d c=%0.2lf\n",a,b,sqrt(b*b+a*a)) : (fprintf(stderr, "Error Invalid %d Side\n", DummyFunction()));
    /* code */
    scanf("%*c");
    goto start;
    setjmp(buf);
end:
    return 0;
}

int DummyFunction(void) {
    longjmp(buf, 1);
    return 2;
}