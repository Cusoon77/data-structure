#include<stdio.h>
int main() {
int array[100],n,pos,i;
printf("enter number of element \n array: ");
scanf("%d", &n);
printf("enter %d eletment:\n:", n);
for(i =0;i<n; i++) {
scanf("%d", &array[i]);
}
printf("enter the position to delete (0 to %d): ", n - 1);
scanf("%d", &pos);
if (pos < 0 || pos>= n) {
printf("invalid position:\n");
} else {
  for (i = pos;i < n - 1; i++) {
  array[i] = array[i + 1];
  }
  n--;
  printf("array after deletion:\n");
  for (i = 0; i<n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
return 0;
}

