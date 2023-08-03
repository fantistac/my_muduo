SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SRCS))





ALL:mymuduo

$(OBJS):%.o:%.cpp
	g++ -c $< -o $@ -fPIC


mymuduo:$(OBJS)
	g++ -shared -o libmymuduo.so $^


clean:
	rm -f $(OBJS)

.PHONY:clean ALL
