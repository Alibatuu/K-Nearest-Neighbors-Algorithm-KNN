# K-Nearest-Neighbors-Algorithm-KNN

In this project, the test points created at random locations were grouped using the K-NN algorithm. In this regard, 4 classes and a driver code have been created.

## Design

### Point

In this class, 30 different points were randomly generated before the test. The rand15 function created for this was used. The values determined with the help of the generate function were set into the vector created for the category information of each point. Then the x and y coordinates, categories and indexes of the points are sent into a vector created in Distance type.

### Distance

The default constructor structure was created by setting the group value to -1 and the distance value to 0 which consists of 4 parameters. The reason why it was created in this way is that there are no group and distance values in the future test point operations. This class contains functions to be used in grouping. Index information, group information, point information and distance information are used with the help of these functions.

### Calculate

K-NN algorithm is applied in this class. By taking the Point class as inherit, the points and the information of the points are used. In this class, a vector is created for test points and random values are sent to this vector. Then, the given main vector(points) in this vector were sent with their indexes. Then the distance calculations were made and recorded in the points vector. The points vector was sorted according to the distance data and the group numbers of the vector were examined according to the K value received from the user. At the end of this examination, it was found to which group the test point belonged. These operations were performed for 10 test points and each step was printed on the screen. Then the Graph class is called to examine the graph.

### Graph

In this class, the data was visualized and tried to be transferred to the user more clearly. First, an image was created for the background and a coordinate system was created by scaling this image according to the points. Then, since the symbols of each group are designed differently, an information box has been added to the upper right in a way that the user can understand. Then all the points and the necessary information of these points are printed on the screen.
Finally, it was passed to the part of adding points to the graph. All points are placed on the image in scale, with the symbol of each group being different.

## Execution

The project starts by creating an object of the Calculate class in the driver code. The setValues
function is called in the constructor of this class and the function inside the Point class is
executed. First, the coordinates and groups of 30 points are determined here. Then, a K value is
taken from the user and information about how many points to look at is obtained. Indexes,
coordinates of points and group information are set to the points vector created in the distance
type. Then again, the constructor of the calculate class is reached and the knn function, which
will run the K-NN algorithm, is called with the points vector. Here, test points are created and
distance-dependent operations are performed. Then, depending on the number of K, the closest
points are looked and group information of these points is obtained. Whichever group is more in
the light of the received group information, that group number becomes the group of the test
point. In this project, for example, if the number of K is 3 and the group of the closest 3 points is
different (for example, group0:1 group1:1 group2:1), the group of the test point is determined as
0. After these operations, an object of the Graph class is created to draw graphs. In the
constructor of this class, the drawGraph function is called with the points data and the
coordinate system is drawn on the created image. Here, all points and the coordinate and group
information of these points are printed on the screen. Then, an information box is created for
the user to distinguish the points, and each point is shown on the graph in the information box
according to the shapes.

## Output

![image](https://user-images.githubusercontent.com/88314234/161598544-1faf218b-8a65-4c58-90e1-1643a3a4b41c.png)

![image](https://user-images.githubusercontent.com/88314234/161598568-60b218ce-2127-46cc-b835-a6a6d40113e0.png)

![image](https://user-images.githubusercontent.com/88314234/161598591-17ff2fb3-7dcb-4500-aa76-85c76626dc52.png)

![image](https://user-images.githubusercontent.com/88314234/161598607-97c1ab17-486f-4005-95c3-8a78d9a6fc96.png)

![image](https://user-images.githubusercontent.com/88314234/161598619-1f18ed60-1404-495c-9668-ecd426980077.png)

## Anything A Person May Need To Know While Testing My Program
Only the K value is taken from the user. This value is the information of how many points to look
at. There is no limitation for the values that the user can enter here, but it is recommended to
enter odd numbers. The reason for this is that when an odd number is entered, the probability
of finding the same number of groups of closest points decreases. When the code is run, the first
30 points are printed directly. The user can observe these values on the screen. After the K value
is entered, operations are performed for each point and the necessary information is printed on
the screen.
