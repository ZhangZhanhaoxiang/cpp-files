char* str = "Hello World!\n"
void asmprint()
{
    asm (
        "movq $13, %%rdx \n\t"
        "movq %0, %%rsi  \n\t"
        "movq $1, %%rdi  \n\t"
        "movq $1, %%rax  \n\t"
        "syscall      \n\t"
        ::"r"(str));
}

