main_func: main_func.c
	gcc -Wall -Werror -o main_func main_func.c
clean:
	rm main_func
run:
	./main_func