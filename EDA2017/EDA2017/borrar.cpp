#define N 8
int A[N] = { 0 };
void* suma(void* arg) {
	int* params = (int*)arg;
	int i, sum = 0;
	for (i = params[0]; i <= params[1]; i++)
		sum += A[i];
	params[0] = sum;
	return NULL;
}
int main(int argc, char* argv[])
{
	int pid, n, i, fd;
	pthread_t th1, th2;
	int arg1[2], arg2[2];
	pid = fork();
	if (pid == 0) {
		for (i = 0; i<N; i++)
			A[i] = i;
	}
	else {
		wait(NULL);
	}
	arg1[0] = 0; arg1[1] = N / 2 - 1;
	arg2[0] = N / 2; arg2[1] = N - 1;
	pthread_create(&th1, NULL, suma, (void*)arg1);
	pthread_create(&th2, NULL, suma, (void*)arg2);
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	printf("pid=%d ppid=%d resultado: %d + %d = %d\n", getpid(), getppid(), arg1[0], arg2[0], arg1[0] + arg2[0]);
	return