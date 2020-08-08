#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
//#include <stdarg.h>

/*
void printNumbers(int args, ...) {
    printf("%d\n", args);

    va_list ap;

    va_start(ap, args);// 가변인자의 메모리 시작점

    for (int i = 0; i < args; i++) {
        int num = va_arg(ap, int);
        printf("%d, ", num);
    }

   // va_arg();// 가변인자를 메모리 크기 기준으로 이동시킨다.

    va_end(ap);// 가변인자의 메모리를 모두 null

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

    printValues("i", 10);                                       // 정수
    printValues("ci", 'a', 10);                                 // 문자, 정수
    printValues("dci", 1.234567, 'a', 10);                      // 실수, 문자, 정수
    printValues("sicd", "Hello, world!", 10, 'a', 1.234567);    // 문자열, 정수, 문자, 실수

   

    return 0;
}
*/

/*
void printValues(char* types, ...)    // 가변 인자의 자료형을 받음, ...로 가변 인자 설정
{
    va_list ap;    // 가변 인자 목록
    int i = 0;

    va_start(ap, types);        // types 문자열에서 문자 개수를 구해서 가변 인자 포인터 설정
    while (types[i] != '\0')    // 가변 인자 자료형이 없을 때까지 반복
    {
        switch (types[i])       // 가변 인자 자료형으로 분기
        {
        case 'i':                                // int형일 때
            printf("%d ", va_arg(ap, int));      // int 크기만큼 값을 가져옴
                                                 // ap를 int 크기만큼 순방향으로 이동
            break;
        case 'd':                                // double형일 때
            printf("%f ", va_arg(ap, double));   // double 크기만큼 값을 가져옴
                                                 // ap를 double 크기만큼 순방향으로 이동
            break;
        case 'c':                                // char형 문자일 때
            printf("%c ", va_arg(ap, char));     // char 크기만큼 값을 가져옴
                                                 // ap를 char 크기만큼 순방향으로 이동
            break;
        case 's':                                // char *형 문자열일 때
            printf("%s ", va_arg(ap, char*));   // char * 크기만큼 값을 가져옴
                                                 // ap를 char * 크기만큼 순방향으로 이동
            break;
        default:
            break;
        }
        i++;
    }
    va_end(ap);    // 가변 인자 포인터를 NULL로 초기화

    printf("\n");    // 줄바꿈
}

int main()
{
    printValues("i", 10);                                       // 정수
    printValues("ci", 'a', 10);                                 // 문자, 정수
    printValues("dci", 1.234567, 'a', 10);                      // 실수, 문자, 정수
    printValues("sicd", "Hello, world!", 10, 'a', 1.234567);    // 문자열, 정수, 문자, 실수

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
        printf("파일 열기 에러\n");
    }

    fputs("_abcde", stream);

    file_state = fclose(stream);
    if (file_state == EOF) {
        printf("파일 닫기 에러\n");
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

    fseek(stream, 0, SEEK_SET);  // 파일의 시작 지점
    fprintf(stdout, "%c\n", fgetc(stream));

    fseek(stream, 2, SEEK_SET);  // 파일의 시작 지점에서 2바이트 떨어진 지점
    fprintf(stdout, "%c\n", fgetc(stream));

    fseek(stream, 0, SEEK_CUR);  // 파일의 현재 지점
    fprintf(stdout, "%c\n", fgetc(stream));

    fseek(stream, 0, SEEK_CUR);  // 파일의 현재 지점
    fprintf(stdout, "%c\n", fgetc(stream));

    fseek(stream, -1, SEEK_END);  // 파일의 끝 지점에서 1바이트 (역으로) 떨어진 지점
    fprintf(stdout, "%c\n", fgetc(stream));

    fseek(stream, -2, SEEK_CUR);  // 파일의 현재 지점에서 2바이트 (역으로) 떨어진 지점
    fprintf(stdout, "%c\n", fgetc(stream));

    fclose(stream);

    return 0;
}