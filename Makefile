SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SRCS))





ALL:libmymuduo.so

$(OBJS):%.o:%.cpp
	g++ -c $< -o $@ -fPIC


libmymuduo.so:$(OBJS)
	g++ -shared -o libmymuduo.so $^




clean:
	rm -f $(OBJS)

.PHONY:clean ALL
