
void os_PutStrLine() = 0x21d30;

int testfunction(int a, int b, int c) {
	return c * a + b;
}

int main() {
	char *str;
	int a, b, c;
	os_PutStrLine(str = "Hello World!");
	a = 123; b = 43; c = 100;
	return str + testfunction(a, b, c);
}
