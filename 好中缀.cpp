#include<stdio.h>
#include<string.h>
int *searchfail(char*p);
int main() {
	char p[100010];
	int longest,MAX;
	scanf("%s",p);
	int p_length = strlen(p);
	int* fail = searchfail(p);
	longest = fail[0];
	for (int i = 0; i < p_length; i++) {
		if (fail[i] > longest)
			longest = fail[i];
	}
	MAX = longest + 1;
	p[MAX] = '\0';
	int * fail2 = searchfail(p);
	longest = fail2[0];
	for (int i = 0; i < strlen(p); i++) {
		if (fail2[i] > longest)
			longest = fail2[i];
	}
	int MAX2 = longest + 1;
	printf("%d", p_length - (2 * MAX2));
	return 0;
}
int *searchfail(char*p) {
	int p_length, i, j;
	p_length = (int)strlen(p);
	int* f = new int[p_length];
	f[0] = -1;
	for (j = 1; j < p_length; j++) {
		i = f[j - 1];
		while (p[j] != p[i + 1] && i >= 0) {
			i = f[i];
		}
		if (p[j] == p[i + 1]) {
			f[j] = i + 1;
		}
		else { f[j] = -1; }
	}
	return f;
}