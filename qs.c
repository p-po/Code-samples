#include<stdio.h>
#include<stdlib.h>

void qs(int *a, size_t n)
{
	if(n<2) return;

	int p = a[n/2];
	size_t i = 0;
	size_t j = n - 1;

	while(i<j) {
		while (a[i]<p) i++;
		while (a[j]>p) j--;
		if(i>=j) break;
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

	qs(a+i, i);
	qs(a+i, n-i);

}

int main()
{
int a[] = {5,9,1,45,37,99,54,61,17};
size_t i;

for(i=0; i<sizeof a/sizeof a[0]; i++)
printf("%d ", a[i]);

qs(a, sizeof a/sizeof a[0]);
puts("");
for(i=0; i<sizeof a/sizeof a[0]; i++)
printf("%d ", a[i]);


return 0;
}
