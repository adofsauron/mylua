#include "../src/luaaux.h"
#include "test.h"

int main(int argc, char** argv) 
{
    printf("\n--------------------test case 1--------------------------\n");
    test_result01();
    printf("\n--------------------test case 2--------------------------\n");
    test_result02();
    printf("\n--------------------test case 3--------------------------\n");
    test_result03();
    printf("\n--------------------test case 4--------------------------\n");
    test_result04();
    printf("\n--------------------test case 5--------------------------\n");
    test_result05();
    printf("\n--------------------test case 6--------------------------\n");
    test_result06();
    printf("\n--------------------test case 7--------------------------\n");
    test_result07();
    printf("\n--------------------test case 8--------------------------\n");
    test_result08();
    printf("\n--------------------test case 9--------------------------\n");
    test_result09();
    printf("\n--------------------test case 10-------------------------\n");
    test_result10();
    printf("\n--------------------test case 11-------------------------\n");
    test_nestcall01();

    return 0;
}
