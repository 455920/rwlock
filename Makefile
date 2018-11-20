test:rwlock.cpp
	g++ -o $@ $^ -lpthread

.PHONY:clean
clean:
	rm -rf test
