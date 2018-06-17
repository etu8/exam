#include <stdio.h>

int HowMany1() {
    int count = 0;

    int cur;
    scanf("%d", &cur);
    if(cur) {
        if(cur == 1)
            count++;
        return HowMany1() + count;
    }
    else {
        scanf("%d", &cur);
        if(!cur)
            return 0;
        else {
            if(cur == 1)
                count++;
            return HowMany1() + count;
        }
    }
    return count;
}

int main()
{
    printf("%d\n", HowMany1());
    return 0;
}
