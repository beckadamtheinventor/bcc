

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
	cleartty();
    print("fib(20)=");
    printuint(fib(20));
    newline();
    print("fib(30)=");
    printuint(fib(30));
    newline();
    print("fib(40)=");
    printuint(fib(40));
    newline();
    print("fib(50)=");
    printuint(fib(50));
    newline();
    waitkeycycle();
}
