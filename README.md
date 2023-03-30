## Hash Tables
- This directory contains a simple implementation of a `hash table`. The `hash table` is implemented with two collision resolution techniques: `chaining` and `linear probing`.

## Assignment :page_with_curl:
- For this programming assignment, you will implement a Hash Table with both chaining and linear probing solutions to collisions. 
    - Create a class to represent each entry in your Hash Table, i.e. each entry holds a 
      {key,value}
    - Create a class to represent your Hash Table, where you will implement two different 
    - insert functions. 
    - Have one insert function that supports chaining. Note that each entry on your hash table 
    - must now have access to the next entry in a sequence. 
    - Have one insert function that support linear probing. 
    - Count total number of collisions per insertion function. 
    - Make sure to print out relevant information for the user.
### Implementation
- Implementation includes a hash table with both chaining and linear probing solutions to collisions. The `HashTable` class has two `insert functions`: `insert_with_chaining` and `insert_with_linear_probing`. The `insert_with_chaining` function uses chaining to handle collisions, while the `insert_with_linear_probing` function uses linear probing. Additionally, the `HashTable `class keeps track of the total number of collisions for each insertion method (`chain_collisions` and `linear_collisions` variables), which are printed out at the end of the program.
### Entry
- This class represents an entry in the hash table. Each entry contains a key and a value, and a pointer to the next entry in the chain.

### HashTable
- This class represents the hash table itself. It contains a vector of pointers to Entry objects, representing the table, and a size, representing the size of the table. The class also tracks the number of collisions with each collision resolution technique.

## Collision Resolution Techniques
### Chaining
With chaining, if a collision occurs, the collided entry is added to a linked list that is anchored to the original entry.

### Linear Probing
With linear probing, if a collision occurs, the program looks for the next available slot in the table and places the entry there.

