SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.c, %.o, $(SRCS))





ALL:mymuduo

$(OBJS):%.o:%.cpp
	g++ -c $< -o $@ -fPIC


mymuduo:$(OBJS)
	g++ -shared -o libmymuduo.so $^
