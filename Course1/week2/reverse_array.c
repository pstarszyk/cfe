# include <stdio.h>

int main(void)
{
    int list[] = {1, 2, 3, 4};
    int l = 0, r = 3;
    int lv, rv;

    while (l < r) {
        lv = list[l];
        rv = list[r];
        list[l] = rv;
        list[r] = lv;
        l++;
        r--;
    }

    return 0;
}