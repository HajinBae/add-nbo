#Makefile

TARGET=add-nbo

all: $(TARGET)

$(TARGET): main.o
	g++ -o $(TARGET) main.o

main.o: main.cpp

clean:
	rm -f $(TARGET)
	rm -f *.o

