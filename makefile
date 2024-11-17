.PHONY: clean

simpledb: $(wildcard src/*.cpp)
	g++ -Iinclude -o $@ $^
	
clean:
	rm simpledb
