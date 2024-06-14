// copied from
// https://stackoverflow.com/a/21235556/2278742

void all_combinations(char *x, const int len) {
	for (char c = '!'; c <= '~'; ++c) {
		x[len] = c;
		if (len > 0) {
			all_combinations(x, len - 1);
		} else {
			printf("%s\n", x);
		}
	}
}

int main() {
	const int maxlen = 3;
	char x[maxlen + 1];
	for (int thislen = 1; thislen <= maxlen; thislen++) {
		x[thislen] = 0;
		all_combinations(x, thislen - 1);
	}
}