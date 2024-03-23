#include <stdio.h>
float add(float num1, float num2){
  return num1+num2;
}
float sub(float num1, float num2){
  return num1-num2;
}
float mul(float num1, float num2){
  return num1*num2;
}
float div(float num1, float num2){
  if (num2 == 0.0){
    printf("Error!");
    return 0;
  }
  else{
    return num1/num2;
  }
}

int main(){
  float num1, num2;
  int pos;
  while(1){
    printf("Input first num: ");
    scanf("%f", &num1);
    printf("Input second num: ");
    scanf("%f", &num2);
    printf("\nInput Operation:\n1) ADD\n2) SUB\n3) MUL \n4) DIV\n5) EXIT\n");
    scanf("%d", &pos);
    if (pos==5){
      printf("Exit.\n");
      break;
    }
    if (pos == 1){
      printf("Result add: %.2f\n", add(num1,num2));
    }
    else if (pos==2){
      printf("Result sub: %.2f\n", sub(num1,num2));
    }
    else if (pos==3){
      printf("Result mul: %.2f\n", mul(num1,num2));
    }
    else if (pos==4){
      printf("Result div: %.2f\n", div(num1,num2));
    }
    else{
      printf("Error input\n");
    }
  }
}
