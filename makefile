all: c c++

c:
	$(MAKE) -C C
c++:
	$(MAKE) -C C++
clean:
	$(MAKE) clean -C C 
	$(MAKE) clean -C C++
