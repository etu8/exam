#include<stdio.h>

int main()
{
	int c[26];
	char alp[26];
	char str[8];
	int i, f = 0, g = 0;
	for(i=0; i<26; i++)
		scanf("%d %c\n", &c[i], &alp[i]);
	for(g = 0; g<7; g++)
	{
		scanf("%d", &i);
		for(int j=0; j<26;j++)
		{
			if( i == c[j])
			{
				str[g] = alp[j];
				f++;
				break;
			}
		}
		if(f == 0)
		{
			printf("Error\n");
			return 0;
		}
		f=0;

	}
	printf("%s\n", str);
	return 0;
}
		
