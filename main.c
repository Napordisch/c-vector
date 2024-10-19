int main() {
	Vector vector_a = CreateVector(5, 1, 0);
	for (unsigned int i = 0; i < vector_a.amount; ++i) {
		printf("%d ", vector_a.array[i]);
	}
	printf("\n");
	AppendToVector(&vector_a, 10);
		for (unsigned int i = 0; i < vector_a.amount; ++i) {
		printf("%d ", vector_a.array[i]);
	}
	printf("\n");
	DeleteVector(&vector_a);
}