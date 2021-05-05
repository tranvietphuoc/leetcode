#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// in C, like normal pointers, we can have pointer to functions too.

// a normal function with an int parameter
// and void return type
void func(int a) {
    printf("Value of a is %d\n", a);
}

void add(int a, int b){
    printf("Addition is: %d\n", a + b);
}

void sub(int a, int b){
    printf("Subtraction is: %d\n", a - b);
}

void mul(int a, int b){
    printf("Multiplication is: %d\n", a * b);
}

void func1(){
    printf("Func1\n");
}

void func2(){
    printf("Func2\n");
}

void wrapper(void (*func)()){
    func();
}


int main() {
    // func_ptr is a pointer to function func
    void (*func_ptr)(int) = &func;
    /*
     * the above line equivalent of following
     * two
     * void (*func_ptr)(int);
     * func_ptr = &func;
     */
    // ivoking func() using func_ptr
    (*func_ptr)(10);
    //
    // 1. unlike normal pointers, function pointers point to code, not data.
    // 2. unlike normal pointers, we don't allocate de-allocate memory using function pointers
    // 3. a function's name can also be used to get function's address.
    // for example:
    /*
     * void (*func_ptr)(int) = func;  // removed &
     * and then, we call func using func_ptr
     * func_ptr(10);  // removed *
     * */
    // 4. like normal pointers, we can have an array to function pointers
    void (*func_ptrs[])(int, int) = {add, sub, mul};
    unsigned int ch, a = 15, b = 10;
    printf("Enter choice: 0 for add, 1 for sub, 2 for mul\n");
    scanf("%d", &ch);
    if(ch > 2) return 0;
    (*func_ptrs[ch])(a, b);

    // 5. like normal data pointers, a function pointer can be passed as an argument
    // and can also be returned from a function
    // for example:
    wrapper(func1);
    wrapper(func2);
    // *. we can use function pointers to avoid code redundancy.
    // let's look at the qsort() example:
    /*
     * int compare(const void *a, const void *b){
     *  return (*(int*)a - *(int*)b);
     * }
     * int arr[] = {.....};
     * int n = sizeof(arr)/sizeof(arr[0]);
     * qsort(arr, n, sizeof(int), compare);
     * */

    // 6. many object oriented features can be implemented using function pointers
    return 0;
}
