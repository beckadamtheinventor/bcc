

long fib(long iterations) {
	long na, nb, nc;
	na = nb = 1;
	if (iterations < 2) {
		return na;
	}
	while (iterations--) {
		nc = na;
		na = na + nb;
		nb = nc;
	}
	return na;
}

int main() {
	char key = 0;
	long num = 1;
	while (key != sk_b) {
		cleartty();
		print("fib(", 0x7fff);
		printuint(num);
		printline(")=");
		printuint(fib(num));
		key = waitkeycycle();
		if (key == sk_up) {
			num++;
		} else if (key == sk_down && num > 1) {
			num--;
		} else if (key == sk_right) {
			num = num + 16;
		} else if (key == sk_left) {
			num = num - 16;
		}
	}
}
