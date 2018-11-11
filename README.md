<h1><center>SPLAY TREE VS RED BLACK TREE</center></h1>
<body>
 <b>Splay tree</b>: A splay tree is an efficient implementation of a balanced binary search
tree that takes advantage of locality in the keys used in incoming lookup
requests. For many applications, there is excellent key locality. A good
example is a network router. A network router receives network packets at a
high rate from incoming connections and must quickly decide on which
outgoing wire to send each packet, based on the IP address in the packet. The
router needs a big table (a map) that can be used to look up an IP address and
find out which outgoing connection to use. If an IP address has been used
once, it is likely to be used again, perhaps many times. Splay trees can provide
good performance in this situation. Importantly, splay trees offer amortized
O(log n) performance; a sequence of M operations on an n-node splay tree
takes O(M log n) time.A splay tree is a binary search tree. It has one
interesting difference,whenever an element is looked up in the tree, the splay
tree reorganizes to move that element to the root of the tree, without breaking
the binary search tree invariant.If the next lookup request is for the same
element it can be returned immediately..<br><br>
<b>Red Black Tree</b>: Red-Black trees are a popular tree structure for real time applications. A
Red Black Tree is a type of self-balancing binary search tree, in which every
node is colored with eithe red or black. The red black tree satisfies all theproperties of the binary search tree but there are some additional properties
which were added in a Red Black Tree. The height of a Red-Black tree is
O(Logn) where (n is the number of nodes in the tree).<br>
 <b>Properties of Red Black Tree:</b><br>
• The root node should always be black in color.<br>
• Every null child of a node is black in red black tree.<br>
• There are no two adjacent red nodes i.e a red node cannot have a red
parent or a red child.<br>
• Every simple path from the root node to the (downward) leaf node
contains the same number of black nodes.<br><br>
We will compare this two trees based on different operations:<br>
    1.Insertion.<br>
    2.Searching.<br>
    3.Deletion.<br><br>
    <b>Insertion </b>
    <p>Consider three different cases while inserting elements into the tree<br>1.Elements inserted in ascending order.<br><img src="images/ascending insertion.png"><br>2.Elements inserted in descending order.<br><img src="images/descending insertion.png"><br>3.Elements inserted in random order.<br><img src="images/random insertion.png"><br>
    </p></body>
    <body><u><b>Observation for inserting elements</b></u><p><b>Case 1&2:</b>Skew trees will be formed in splay tree because of performing splaying operation after each insertion of element and bringing that to the root,whereas in red-black tree there will be multiple rotations inorder to maintain the property of red-black trees so inserting elements either in ascending order or in descending order will take more time in red-black tree when compared to splay tree<br>
<b>Case 3:</b>While inserting elements in random order splay tree will take more time when compared to red-black tree because splay will bring the newly inserted element to the rooot after each insertion but red-black tree maintains its property while inserting elements into the tree by performing appropraite</p></body>
<body><u><b>Search</b></u>
<p>To find the performance of search operation in both trees we wil insert 100000 random elements in both the trees</p><u><b>Observation for searching elements</b></u><img src="images/searching repeatedly.png"><br>
<p><b>Case 1:</b> We are performing search operation of constant element for multiple times say(1,100,1000,10000) due to splaying property of splay tree there will be huge time gap between this two trees,in splay tree after first search operation it will brimg that constant searched element into the root and for next search operations it will take constant time to access that element whereas in red-black trees it takes the same amount of time for every of search operation of that constant element<br><img src="images/random search.png"><br>
<b>Case 2:</b>we are searching random elements multiple times say(1,100,1000,10000), in this case red-black trees performs better than splay trees because after every search opeation the splay structure will be changed whereas the structure of red-black tree remains constant</p>
<body>
<u><b>Delete</b></u><br><b>Observation for deleting elements</b><img src="images/random delete.png"><br>
    <p>      Here we are deleting a random number for multiple times say(100,1000,5000,10000).Splay tree will take more time when compared to red-black tree because while deleting element we will first search that element and bring that element to the root and delete that element and make inorder succesor as the root whereas in red-black tree we will search that element and delete it and we will perform approprate rotations to make the properties of the red black tree</p></body>
    <body><u><b>Conclusion</b></u>
   <p>1.If our application has more number of insert operation than search operation prefer <b>red-black tree.</b><br>
   2.If our application has repeated number of search operation for the same element prefer <b>splay tree</b>(cache implementation).</p></body>
