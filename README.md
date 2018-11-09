<h1><center>SPLAY TREE VS RED BLACK TREE</center></h1>
<body>
* **Splay tree**: In splay trees accessing a node moves it to the top, no other balance conditions are guaranteed. Whereas the balance of a BST is dependent upon the only the order in which nodes were inserted into the tree, splay tree balance is dependent upon the order in which they were accessed.The worst case scenario for balance is when nodes are accessed in ascending or descending order. Random access is generally OK on average,although this doesn’t necessarily yield the multi access advantage. It is most efficient, nearly constant time, to access a recently accessed node. An example use case is a cache (files may be accessed multiple times).<br><br>


* **Red Black Tree**: Red-Black trees are a popular tree structure for real time applications. They are used in the Linux Kernel, as well as the C++ STL (map).Red-black trees are height balanced. Since find operations are bound by height for worst case analysis,and since find operations are inherent in many other operations (such as insertand delete), maintaining height balance for a tree increases efficiency.  The findalgorithm loses efficiency when compared to AVL trees which maintain both heightand weight balance.  However, maintaining balance in a red-black tree is moreefficient than an AVL tree, making it a better choice for some real-time applications.<br><br>
We will compare this two trees based on different operations:<br>
    1.Insertion.<br>
    2.Searching.<br>
    3.Deletion.<br><br>
    <u> <b>Insertion <b></u>
    <p>Consider three different cases while inserting elements into the tree<br>1.Elements inserted in ascending order.<br><img src="images/ascending insertion.png">
    2.Elements inserted in descending order.<br>
    <img src="descending insertion.png">3.Elements inserted in random order.<br><img src="random insertion.png">
    </p></body>
    
