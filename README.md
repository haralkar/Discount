Discount
========
Demonstration of C++ classes to calculate discount of product to be sold to customers, at some discount.
Current implementation uses in memory storage without any persistence.

Design idea:
![Data and Storage Isolation](https://github.com/haralkar/Discount/blob/master/Images/designSketch.png)

Interfaces
----------

###Storing
Storing and retrieving data is done via **IDataStorage** template class. 
Current implementation for memory is the **LocalStorage** that uses a map to keep track of stored objects.
Database or file storage could be implemented from the **IDataStorage** interface

###Data objects
**IData** is the common ancestor to all data objects, four objects have been implemented:

* **Client**  name.
* **Product** name, price
* **Rebate** name and percentage rebate, inheriting from this class can implement more complex rebates.
* **Order** client and product id, and the number of items.


Isolation
---------
Implementation knowledge is isolated at the same two points:

* **StorageHousing** keeps track of the database access point. 
* **DataFactory** creates new instances of the above data objects, then uses **StorageHousing** to store the data.

External source code
--------------------
Factory pattern was adapted from [Cale Dunlap](http://www.codeproject.com/Articles/363338/Factory-Pattern-in-Cplusplus)'s implementation.
