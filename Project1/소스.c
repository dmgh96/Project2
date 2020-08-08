#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
//#include <stdarg.h>

/*
void printNumbers(int args, ...) {
    printf("%d\n", args);

    va_list ap;

    va_start(ap, args);// ���������� �޸� ������

    for (int i = 0; i < args; i++) {
        int num = va_arg(ap, int);
        printf("%d, ", num);
    }

   // va_arg();// �������ڸ� �޸� ũ�� �������� �̵���Ų��.

    va_end(ap);// ���������� �޸𸮸� ��� null

}

int main()
{
    printNumbers(6, 10, 11, 12, 13, 14, 15);
  

    return 0;
}
*/

/*
void printValues( char* types, ... ) {
    va_list ap;
    int i = 0;

    va_start(ap, types);
    while (types[i] != '\0') {

        switch (types[i]) {

            case 'i' :
                printf("%d, ", va_arg(ap, int));
                break;
                
            case 'd' :
                printf("%f, ", va_arg(ap, double));
                break;

            case 'c' :
                printf("%c, ", va_arg(ap, char));
                break;

            case 's' :
                printf("%s, ", va_arg(ap, char *));
                break;
              
            default:
                break;

        }

        i++;
    }

    va_end(ap);

    printf("\n");
}

int main() {

    printValues("i", 10);                                       // ����
    printValues("ci", 'a', 10);                                 // ����, ����
    printValues("dci", 1.234567, 'a', 10);                      // �Ǽ�, ����, ����
    printValues("sicd", "Hello, world!", 10, 'a', 1.234567);    // ���ڿ�, ����, ����, �Ǽ�

   

    return 0;
}
*/

/*
void printValues(char* types, ...)    // ���� ������ �ڷ����� ����, ...�� ���� ���� ����
{
    va_list ap;    // ���� ���� ���
    int i = 0;

    va_start(ap, types);        // types ���ڿ����� ���� ������ ���ؼ� ���� ���� ������ ����
    while (types[i] != '\0')    // ���� ���� �ڷ����� ���� ������ �ݺ�
    {
        switch (types[i])       // ���� ���� �ڷ������� �б�
        {
        case 'i':                                // int���� ��
            printf("%d ", va_arg(ap, int));      // int ũ�⸸ŭ ���� ������
                                                 // ap�� int ũ�⸸ŭ ���������� �̵�
            break;
        case 'd':                                // double���� ��
            printf("%f ", va_arg(ap, double));   // double ũ�⸸ŭ ���� ������
                                                 // ap�� double ũ�⸸ŭ ���������� �̵�
            break;
        case 'c':                                // char�� ������ ��
            printf("%c ", va_arg(ap, char));     // char ũ�⸸ŭ ���� ������
                                                 // ap�� char ũ�⸸ŭ ���������� �̵�
            break;
        case 's':                                // char *�� ���ڿ��� ��
            printf("%s ", va_arg(ap, char*));   // char * ũ�⸸ŭ ���� ������
                                                 // ap�� char * ũ�⸸ŭ ���������� �̵�
            break;
        default:
            break;
        }
        i++;
    }
    va_end(ap);    // ���� ���� �����͸� NULL�� �ʱ�ȭ

    printf("\n");    // �ٹٲ�
}

int main()
{
    printValues("i", 10);                                       // ����
    printValues("ci", 'a', 10);                                 // ����, ����
    printValues("dci", 1.234567, 'a', 10);                      // �Ǽ�, ����, ����
    printValues("sicd", "Hello, world!", 10, 'a', 1.234567);    // ���ڿ�, ����, ����, �Ǽ�

    return 0;
}

*/
/*
void hello(int count)
{
    if (count == 0)
        return;

    printf("Hello, world! %d\n", count);

    hello(--count);
}

int main()
{
    hello(100);
    return 0;
}
*/
/*
int main()
{
    FILE* stream;
    int file_state;

    stream = fopen("data.txt", "w");
    if (stream == NULL) {
        printf("���� ���� ����\n");
    }

    fputs("_abcde", stream);

    file_state = fclose(stream);
    if (file_state == EOF) {
        printf("���� �ݱ� ����\n");
    }

    return 0;
}
*/
int main(void)
{
    FILE* stream;
    stream = fopen("fseek.dat", "w");
    fputs("ABCDEFGHIJ", stream);
    fclose(stream);

    stream = fopen("fseek.dat", "r");

    fseek(stream, 0, SEEK_SET);  // ������ ���� ����
    fprintf(stdout, "%c\n", fgetc(stream));

    fseek(stream, 2, SEEK_SET);  // ������ ���� �������� 2����Ʈ ������ ����
    fprintf(stdout, "%c\n", fgetc(stream));

    fseek(stream, 0, SEEK_CUR);  // ������ ���� ����
    fprintf(stdout, "%c\n", fgetc(stream));

    fseek(stream, 0, SEEK_CUR);  // ������ ���� ����
    fprintf(stdout, "%c\n", fgetc(stream));

    fseek(stream, -1, SEEK_END);  // ������ �� �������� 1����Ʈ (������) ������ ����
    fprintf(stdout, "%c\n", fgetc(stream));

    fseek(stream, -2, SEEK_CUR);  // ������ ���� �������� 2����Ʈ (������) ������ ����
    fprintf(stdout, "%c\n", fgetc(stream));

    fclose(stream);

    return 0;
}