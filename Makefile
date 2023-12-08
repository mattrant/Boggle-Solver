all:
	g++ -o boggle trie_node.cpp trie.cpp die.cpp board.cpp solver.cpp main.cpp
clean:
	rm -f boggle
