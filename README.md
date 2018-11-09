<h1><center>SPLAY TREE VS RED BLACK TREE</center></h1>
<body>
 <b>Splay tree</b>: In splay trees accessing a node moves it to the top, no other balance conditions are guaranteed. Whereas the balance of a BST is dependent upon the only the order in which nodes were inserted into the tree, splay tree balance is dependent upon the order in which they were accessed.The worst case scenario for balance is when nodes are accessed in ascending or descending order. Random access is generally OK on average,although this doesn’t necessarily yield the multi access advantage. It is most efficient, nearly constant time, to access a recently accessed node. An example use case is a cache (files may be accessed multiple times).<br><br>


<b>Red Black Tree</b>: Red-Black trees are a popular tree structure for real time applications. They are used in the Linux Kernel, as well as the C++ STL (map).Red-black trees are height balanced. Since find operations are bound by height for worst case analysis,and since find operations are inherent in many other operations (such as insertand delete), maintaining height balance for a tree increases efficiency.  The findalgorithm loses efficiency when compared to AVL trees which maintain both heightand weight balance.  However, maintaining balance in a red-black tree is moreefficient than an AVL tree, making it a better choice for some real-time applications.<br><br>
We will compare this two trees based on different operations:<br>
    1.Insertion.<br>
    2.Searching.<br>
    3.Deletion.<br><br>
    <u> <b>Insertion <b></u>
    <p>Consider three different cases while inserting elements into the tree<br>1.Elements inserted in ascending order.<br><img src="images/ascending insertion.png">
    2.Elements inserted in descending order.<br>
    <img src="images/descending insertion.png">3.Elements inserted in random order.<br><img src="images/random insertion.png">
    </p></body>
    <body><u><b>Observation for inserting elements<b></u><p><b>Case 1&2:</b>Skew trees will be formed in splay tree because of performing splaying operation after each insertion of element and bringing that to the root,whereas in red-black tree there will be multiple rotations inorder to maintain the property of red-black trees so inserting elements either in ascending order or in descending order will take more time in red-black tree when compared to splay tree<br>
<b>Case 3:</b>While inserting elements in random order splay tree will take more time when compared to red-black tree because splay will bring the newly inserted element to the rooot after each insertion but red-black tree maintains its property while inserting elements into the tree by performing appropraite</p></body>
<body><u><b>Search</b></u>
<p>To find the performance of search operation in both trees we wil insert 100000 random elements in both the trees</p><u><b>Observation for searching elements<b></u><img src="images/searching repeatedly.png">
<p><b>Case 1:</b> We are performing search operation of constant element for multiple times say(1,100,1000,10000) due to splaying property of splay tree there will be huge time gap between this two trees,in splay tree after first search operation it will brimg that constant searched element into the root and for next search operations it will take constant time to access that element whereas in red-black trees it takes the same amount of time for every of search operation of that constant element<br><img src="images/random search.png">
<b>Case 2:</b>we are searching random elements multiple times say(1,100,1000,10000), in this case red-black trees performs better than splay trees because after every search opeation the splay structure will be changed whereas the structure of red-black tree remains constant</p>
<body>
<u><b>Delete</b></u><br><b>Observation for deleting elements</b><img src="images/random delete.png">
    <p>      Here we are deleting a random number for multiple times say(100,1000,5000,10000).Splay tree will take more time when compared to red-black tree because while deleting element we will first search that element and bring that element to the root and delete that element and make inorder succesor as the root whereas in red-black tree we will search that element and delete it and we will perform approprate rotations to make the properties of the red black tree</p></body>
    <body><u><b>Conclusion<b></u>
   <p>1.If our application has more number of insert operation than search operation prefer <b>red-black tree.</b><br>
   2.If our application has repeated number of search operation for the same element prefer <b>splay tree</b>(cache implementation).</p></body>
