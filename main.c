#include <stdio.h>
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVINE 32
#define MULTIPLY 33
#define BRUNCH 40
#define BRANCHNEG 41
#define BRUNCHZERO 42
#define HALT 43
void printDump(int,short,int,short,short,int *);
int main(int argc, char const *argv[])
{
    int accumulator=+0000;
    short instructionCounter=00;
    int instructionRegister=+0000;
    short operationCode=00;
    short operand = 00;
    int memory[100];
    printf("Добро пожаловать в симулятор машинного кода\nВводите вашу программу по одной команде\nСлева будет выводиться текущий адрес команды\nДля окончания ввода введите -99999\n");
    // for (short i = 0; i < 10; i++)
    // {
    //     printf("%8d",i);
    // }
    // puts("0");
printDump(accumulator,instructionCounter,instructionRegister,operationCode,operand,memory);
    for (short i = 0; i < 100-1; i++)
    {
        printf("\n%0d?",i);
        scanf("%d",&memory[i]);
        if (memory[i]==(-99999))
        {
            break;
        }
        
    }
    for (short i = 0; i < 100; i++)
    {
        /* code */
    }
    


    return 0;
}
void printDump(int accumulator,short instructionCounter,int instructionRegister,short operationCode,short operand,int *memory){
    printf("РЕГИСТРЫ\n%d\n%d\n%d\n%d\n%d\n",accumulator,instructionCounter,instructionRegister,operationCode,operand);
    for (short i = 0; i < 10; i++)
    {
        printf("%8d",i);
    }
    for (short i = 0,j=0; i < 100; i++)
    {
        if (i%10==0)
        {
            printf("\n");
            printf("%d",i);
        }
        // if (j%10==0)
        // {
        //     printf("%d",j);
        //     j+=10;
        // }
        printf("%+8d",&memory[i]);
        
        
                 
        
    }
    
}
void chooseOperation(int operationCode,int operand,int *memory,int accumulator,short instructionCounter){
        switch (operationCode)
    {
    case READ:
        scanf("%d",&memory[operand]);
        
        break;
    case WRITE:
    printf("%s",operand);
        break;
        case LOAD:
        accumulator = memory[operand];
        break;
    case STORE:
    memory[operand]=accumulator;
        break;
    case ADD:
accumulator=accumulator+memory[operand] ;
        break;
    case SUBTRACT:
    accumulator=accumulator-memory[operand];
        break;
        case DIVINE:
    accumulator=accumulator/memory[operand];
        break;
        case MULTIPLY:
accumulator=accumulator*memory[operand];
        break;
        case BRUNCH:
    instructionCounter=operand;
        break;
        case BRANCHNEG:
    if (accumulator<0)
    {
        instructionCounter=operand;
    }
    
        break;
        case BRUNCHZERO:
    if (accumulator==0)
    {
        instructionCounter=operand;
    }
        break;
    case HALT:
    
    default:
        break;
    }
}