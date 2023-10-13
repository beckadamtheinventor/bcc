
void os_PutStrLine(char *s) = 0x21d30;
void os_NewLine() = 0x207F0;

int testfunction(int a, int b, int c) {
	return c * a + b;
}

int main() {
	char *str;
	int a, b, c;
	os_PutStrLine(str = "Hello World!");
	os_NewLine();
	a = 123; b = 43; c = 100;
	return str + testfunction(a, b, c);
}
