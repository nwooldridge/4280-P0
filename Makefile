CC=g++
TARGET=P0
OBJS=P0.o tree.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

P0.o: 
	$(CC) -c P0.cpp

tree.o:
	$(CC) -c tree.cpp


clean:
	rm -f *.o *.preorder *.postorder *.inorder $(TARGET)
