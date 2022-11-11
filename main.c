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
void printHelp();
int main(int argc, char const *argv[])
{

    printHelp();

    
    int accumulator=+0000;
    short instructionCounter=00;
    int instructionRegister=+0000;
    short operationCode=00;
    short operand = 00;
    int memory[100]={0000};
    printf("Добро пожаловать в симулятор машинного кода\nВводите вашу программу по одной команде\nСлева будет выводиться текущий адрес команды\nДля окончания ввода введите -99999\n");
//Цикл ввода команд
    for (short i = 0; i < 99; i++)
    {
        
        printf("\n%0d?",i);
        scanf("%d",&memory[i]);
        if (memory[i]==(-99999))
        {
            break;
        }
        
    }
//цикл исполнения программ
    while (instructionCounter!=HALT)
    {
        instructionRegister=memory[instructionCounter];
        operationCode=instructionRegister/100;
        operand=instructionRegister%100;
        switch (operationCode)
        {
        case READ:
            scanf("%d",&memory[operand]);
            ++instructionCounter;
            break;
        case WRITE:
        printf("%d\n",memory[operand]);
        ++instructionCounter;
            break;
        case LOAD:
            accumulator = memory[operand];
            ++instructionCounter;
            break;
        case STORE:
        memory[operand]=accumulator;
            ++instructionCounter;
            break;
        case ADD:
    accumulator=accumulator+memory[operand] ;
        ++instructionCounter;
            break;
        case SUBTRACT:
        accumulator=accumulator-memory[operand];
            ++instructionCounter;
            break;
            case DIVINE:
        accumulator=accumulator/memory[operand];
            ++instructionCounter;
            break;
            case MULTIPLY:
    accumulator=accumulator*memory[operand];
        ++instructionCounter;
            break;
            case BRUNCH:
        instructionCounter=operand;//безусловный переход

            break;
            case BRANCHNEG:
        if (accumulator<0)//если в аккумуляторе отрицательное число
        {
            instructionCounter=operand;
        }
        
            break;
            case BRUNCHZERO:
        if (accumulator==0)//если в аккумуляторе 0
        {
            instructionCounter=operand;
        }
            break;
        case HALT:
        //останова
instructionCounter=HALT;
            break;
        default:
        puts("Такой команды не существует");
        instructionCounter=HALT;
            break;
        }
    }
    

printDump(accumulator,instructionCounter,instructionRegister,operationCode,operand,memory);

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
            printf("%#d",i);
        }
        // if (j%10==0)
        // {
        //     printf("%d",j);
        //     j+=10;
        // }
        printf("%+8d",memory[i]);  
    }
}
void chooseOperation(int operationCode,int operand,int *memory,int accumulator,short instructionCounter){
        switch (operationCode)
    {
    case READ:
        scanf("%d",&memory[operand]);
        
        break;
    case WRITE:
    printf("%s\n",&memory[operand]);
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
    puts("Такой команды не существует");
        break;
    }
}
void printHelp(){
puts("У вас в распоряжении 100 ячеек памяти");
puts("Каждая команда начинается с номера команды и ячейки памяти");
printf("%d - Вводит слово из терминала в память\n",READ);
printf("%d - Ввыводит слово из памяти в терминала\n",WRITE);
printf("%d - Помещает в аккумулятор слово из указанного адреса памяти\n",LOAD);
printf("%d - Выгружает слово из аккумулятора по указанному адресу памяти\n",STORE);
printf("%d - Сложение слова в аккумуляторе и слова по адресу памяти(слово остается в аккумулятор)\n",ADD);
printf("%d - Вычитает из слова в аккумуляторе на слово из указанного места в памяти\n",SUBTRACT);
printf("%d - Деление слова в аккумуляторе на слово из указанного места в памяти\n",DIVINE);
printf("%d - Умножение слова в аккумуляторе на слово из указанного места в памяти\n",MULTIPLY);
printf("%d - Переход к указанному адресу памяти\n",BRUNCH);
printf("%d - Переход к указанному адресу памяти, если в аккумуляторе находится отрицательное число\n",BRANCHNEG);
printf("%d - Переход к указанному адресу памяти, если в аккумуляторе находится ноль\n",BRUNCHZERO);
printf("%d - Остонова, выполняется при заверщении программой своей работы\n",HALT);
puts("");
}