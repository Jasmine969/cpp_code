#include <stdio.h>
int array[5] = {0};
int *get_array(void) { return array; }
int *(*get_pointer(void))(void) { return get_array; }
int main()
{
    int *(*fp)(void) = get_pointer();
    printf("%d\n", (*fp)()[0]);
    return 0;
}
