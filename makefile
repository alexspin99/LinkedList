List_Test: Linked_List.o List_Test.o
	g++ Linked_List.o List_Test.o -o List_Test
Linked_List.o: Linked_List.h Linked_List.cpp 
	g++ -c Linked_List.cpp
List_Test.o: Linked_List.h List_Test.cpp 
	g++ -c List_Test.cpp