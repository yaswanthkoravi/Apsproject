Project Title : Splay Tree and comparision wrt Red-Black Tree
Team members  : K.Yaswanth<br>
                SVL.Sarath

   
    

Technologies to be used
Title 	Details
Languages 	C, C++, Python, Markdown
Tools 	Sublime Text, Git



We aim to deliver the project as a menu driven program which allows user to build a binary heap with all the standard heap functions and a merge function which works in O(log n) time. Along with that compare its performance with AVL and
End User Documentation
Binomial heap functionalities implementation:-

    go to directory of project and simply run g++ -o binomial binomialheap.cpp command through terminal.
    The corresponding .out will be generated. Execute this file using the command ./binomial.out .
    A menu will be prompted requesting for the operation to be performed.
        Press 1 to insert. Then provide the value to be inserted in the binomial heap.
        Press 2 to extract min. Returns the minimum value present in the the binomial heap.
        Press 3 to decrease key. Terminal will prompt for old key. Provide the old key following with the new key(It should be smaller than the old key).Old key will be replaced with the new key(smaller value). If the new value is greater than the old value, then the program will show the error message.
        Press 4 to delete a value from the binomial heap and then provide the value to be deleted.
        Press 5 to quit from the menu driven program.
        Press 6 to print the binomial heap.

Performance Comparison with AVL tree :-
Time analysis for insertion and deletion in Binomial heap:-

    go to directory of project and simply run g++ -o comparebinomial comp_analysis.cpp command through terminal.
    The corresponding .out will be generated. Execute this file using the command ./comparebinomial.out .
    The terminal will prompt for filename:- There are three input files:-
        random.txt - contains around 20.000 random numbers.
        sorted.txt - contains numbers 1-20,00,000 in increasing order.
        reverse.txt - contains numbers 1-20,00,000 in descending order . Provide the filename accordingly.
    The terminal will prompt for the numbers of values to be inserted from the file(Maximum value can be 20,00,000).
    The program will create a binomial heap which contains the number of values that are selected in prior step and data will be from the file that was selected earlier. The same program will delete all the values inserted. At the end, it will show the time taken during insertion and time taken for the deletion of all the elements in the binomial heap.

Time analysis for insertion and deletion in AVL tree:-

    go to directory of project and simply run g++ -o compareavl avl.cpp command through terminal.
    The corresponding .out will be generated. Execute this file using the command ./compareavl.out .
    The terminal will prompt for filename:- There are three input files:-
        random.txt - contains around 20.000 random numbers.
        sorted.txt - contains numbers 1-20,00,000 in increasing order.
        reverse.txt - contains numbers 1-20,00,000 in descending order . Provide the filename accordingly.
    The terminal will prompt for the numbers of values to be inserted from the file(Maximum value can be 20,00,000).
    The program will create a AVL tree which contains the number of values that are selected in prior step and data will be from the file that was selected earlier. The same program will delete all the values inserted. At the end, it will show the time taken during insertion and time taken for the deletion of all the elements in the AVL tree.

Graph demonstarting the performance analysis for insert, search and delete operations between Binomial Heap and AVL tree:-

Insert Comparison on Random data
Insert Comparison on Sorted data
Deletion Comparison on Random data
Deletion Comparison on Sorted data
Implementation of Prim's Algorithm using Binomial heap :-

    go to directory of project and simply run g++ -o prim prims.cpp command through terminal.
    The corresponding .out will be generated. Execute this file using the command ./prim.out .
    There are two input files:-
        prim1.txt - contains a graph information that has 20 vertices and 159 edges.
        prim2.txt - contains a graph information that has 5 vertices and 8 edges.
        Input File format:-
        First line contains number of vertices followed by number of edges(n).
        There are following n lines that conatins information about edges. Source, destination and weight of the edges.
    Output:-
        The edges that will be present in the Minimum Spanning tree(Format:- Source Destination )
        Weight of the minimum spanning tree

Online resources


