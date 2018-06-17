#include <stdio.h>

int rec(){
	int n, m, k, count = 0;
	scanf("%d", &n);
	if (n){
		if (n == 1)
			count++;
		scanf("%d", &m);
		if (m){
			if (m == 1){
				count++;
			}
			return rec() + count;
			
		}
		else {
			scanf("%d", &k);
			if (k){
				if(k == 1){
					count++;
					return rec() + count;
				}
				else
					return rec();
			}
			else
				return count;
			
		}
	}
	else{
		scanf("%d", &m);
		if (m){
			if (m == 1){
				count++;
				return rec() + count;
			}
			else
				return rec();
		}
		else
			return count;
	}

}


int main(){
	printf("%d\n", rec());
	return 0;
}
