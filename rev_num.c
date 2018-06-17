#include <stdio.h>

long long int num_rev(long long int num, long long int ans){
	if (num < 10)
		return (ans*10 + num);
	return num_rev (num/10, ans*10 + num%10);
}


int main(){
	long long int num;
	scanf("%lld", &num);
	num = num_rev(num, 0);
	printf("%lld\n", num);
}
