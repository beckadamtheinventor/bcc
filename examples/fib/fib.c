

long fib(uint16_t iterations) {
	long na, nb, nc;
	na = nb = 1;
	iterations--;
	while (iterations--) {
		nc = na;
		na = na + nb;
		nb = nc;
	}
	return na;
}

int main() {
	fib(20);
	fib(30);
	fib(40);
	fib(50);
}
