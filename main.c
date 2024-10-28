#include <stdio.h> 
#include <stdlib.h>
#define SIZE 8
int power_2[7] = {1};
int complement2[SIZE] = {0,0,0,0,0,0,0,1};
void carry(int arr1[],int arr2[], int arr3[]);
void convert_Negative(int arr[SIZE]);
int power_of_2(int power) {
    if(power == 0) return 1;
    if(power_2[power]!=0) return power_2[power];
    else {
        power_2[power] = 2*power_of_2(power-1);
        return power_2[power];
    }

}
void input_num(int num[]) {
    char num_char[SIZE];
    for(int i=0;i<SIZE;i++) {
        num_char[i] = getchar();
        if (num_char[i] == 48) num[i] = 0;
        else num[i] = 1;

        if (i==SIZE-1) getchar(); //개행문자제거
    }
    
}

void change_bit(int arr[]){
    for(int i=0;i<SIZE;i++) {
        if(arr[i]==0) arr[i]=1;
        else arr[i]=0;
    }
    
}

int conversion(int arr[]) {
    int deci = 0;
    for(int i=1;i<SIZE;i++) if(arr[i] == 1) deci += power_of_2(SIZE-1-i);
    return deci;
}

void convert(void) {
    int arr[SIZE];
    int negative = 0;
    printf("8비트 이진수를 입력하세요: ");
    input_num(arr);
    if (arr[0] == 1) {
        negative = 1;
        convert_Negative(arr);
    }

    int deci = conversion(arr);
    if (negative == 1) deci= -deci;              
    printf("십진수로 %d입니다.",deci);
    }
    

void convert_Negative(int arr[SIZE]) {
    change_bit(arr);//비트전환
    int complement_arr[SIZE];
    carry(arr,complement2,complement_arr); //+1하기
    for(int i = 0;i<SIZE;i++) arr[i] = complement_arr[i];
}

void carry(int arr1[],int arr2[], int arr3[]) {
    int carry = 0;
    for(int i = SIZE-1;i>=0;i--) {
        if(carry+arr1[i]+arr2[i] == 0) {
            carry = 0;
            arr3[i]=0;
        }

        else if(carry+arr1[i]+arr2[i] == 1) {
            carry=0;
            arr3[i]=1;
        }
        else {
            arr3[i]=0;
            carry=1; 
        }
    }
}

void add_binary(void) {
    int arr1[SIZE];
    int arr2[SIZE];
    int arr3[SIZE];
    printf("첫번째 8비트 이진수를 입력하세요: ");
    input_num(arr1);
    printf("두번째 8비트 이진수를 입력하세요: ");
    input_num(arr2);
    carry(arr1,arr2,arr3);
    printf("결과는 이진수로 ");
    for(int i=0;i<SIZE;i++) printf("%d",arr3[i]);
    printf("이고, 십진수로 %d입니다",conversion(arr3));
    
}
void minus_binary(void) {
    int arr1[SIZE];
    int arr2[SIZE];
    int arr3[SIZE];
    printf("첫번째 8비트 이진수를 입력하세요: ");
    input_num(arr1);
    printf("두번째 8비트 이진수를 입력하세요: ");
    input_num(arr2);
    if (arr1[0]== 1) convert_Negative(arr1);
    if (arr2[0]==1) convert_Negative(arr2);
    


}

int main (void) {
    short select;
    printf("1. 이진수 변환기 2. 이진수 덧셈기 3. 이진수 뺄셈기\n번호를 선택하세요: ");
    scanf("%hd",&select);
    getchar();
    add_binary();
    
    
    return 0;
}