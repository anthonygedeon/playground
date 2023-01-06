int five() {
	return 5;
}

int main() {
	int a { 2 };
	int b { 2 + 3 };
	int c { (2 * 3) + 4 };
	int d { b };
	int e { five() };

	return 0;
}
