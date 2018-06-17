#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Book{
	char name[30];
	char author[30];
	unsigned int pages;
	char isbn[20];
}Book;

int cmp(const void* a, const void* b){
	int cmpname=strcmp(((Book*)b)->name,((Book*)a)->name);
	int cmpauthor=strcmp(((Book*)a)->author,((Book*)b)->author);
	int cmppages=((Book*)b)->pages-((Book*)a)->pages;
	if(cmpname==0)
		return cmpauthor;
	if(cmpname==cmpauthor)
		return cmppages;
}

int main(){
	size_t booksCount;
	scanf("%zd", &booksCount);
	Book* books=(Book*)malloc(booksCount*sizeof(Book));
	for(int i=0;i<booksCount;i++){
		scanf("%s %s %u %s",books[i].name,books[i].author,&books[i].pages, books[i].isbn);
	}
	qsort(books, booksCount, sizeof(Book), cmp);
	for(int i=0;i<booksCount;i++)
		printf("%s %s %u %s",books[i].name, books[i].author, books[i].pages, books[i].isbn );
	return 0;
}

