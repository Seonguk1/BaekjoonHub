#include<stdio.h>
int main(){
	int n;
	int i=1;
	int k=1;
	scanf("%d", &n);
	while(i<n){
		i += k+1;
		k++;
	}
	int a = i-n;
	(k%2)?printf("%d/%d", 1+a, k-a):printf("%d/%d", k-a, 1+a);
}