#include <algorithm>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

/*
Comparison of STL Containers and Their Iterators

1. Vector:
   - Underlying implementation: Dynamic array
   - Characteristics:
     - Contiguous memory storage
     - Fast random access (O(1))
     - Fast insertion/deletion at the end (O(1))
     - Slow insertion/deletion at the beginning or middle (O(n))
     - Automatic resizing when capacity is reached
   - Iterators:
     - Random-access iterators
     - Supports all iterator operations: ++, --, +=, -=, +, -, <, >, ==, !=
     - May be invalidated by insertion or deletion

2. List:
   - Underlying implementation: Doubly-linked list
   - Characteristics:
     - Non-contiguous memory storage
     - Slow random access (O(n))
     - Fast insertion/deletion anywhere in the list (O(1))
     - No need for resizing
   - Iterators:
     - Bidirectional iterators
     - Supports: ++, --, ==, !=
     - Not invalidated by insertion or deletion (except erased element)

3. Deque (Double-ended queue):
   - Underlying implementation: Multiple chunks of contiguous memory
   - Characteristics:
     - Fast random access (O(1))
     - Fast insertion/deletion at both ends (O(1))
     - Slower insertion/deletion in the middle (O(n))
     - More complex memory management than vector
   - Iterators:
     - Random-access iterators
     - Supports all iterator operations: ++, --, +=, -=, +, -, <, >, ==, !=
     - May be invalidated by insertion or deletion

4. Stack:
   - Underlying implementation: Usually built on top of deque (can be vector or list)
   - Characteristics:
     - LIFO (Last-In-First-Out) behavior
     - Fast insertion/deletion at one end (top) (O(1))
     - No random access
   - Iterators:
     - Does not provide iterators
     - Access limited to top element only

5. Queue:
   - Underlying implementation: Usually built on top of deque
   - Characteristics:
     - FIFO (First-In-First-Out) behavior
     - Fast insertion at one end (back) and deletion at the other end (front) (O(1))
     - No random access
   - Iterators:
     - Does not provide iterators
     - Access limited to front and back elements

6. Priority Queue:
   - Underlying implementation: Usually a max-heap built on top of vector
   - Characteristics:
     - Keeps elements in order based on their priority
     - Fast access to the highest priority element (O(1))
     - Fast insertion (O(log n))
     - Fast deletion of highest priority element (O(log n))
     - No random access
   - Iterators:
     - Does not provide iterators
     - Access limited to top (highest priority) element

7. Set:
   - Underlying implementation: Self-balancing binary search tree (often red-black tree)
   - Characteristics:
     - Stores unique elements in sorted order
     - Fast search, insertion, and deletion (O(log n))
     - No direct element modification (must remove and reinsert)
     - Elements can only be inserted or removed, not modified in-place
   - Iterators:
     - Bidirectional iterators
     - Supports: ++, --, ==, !=
     - Not invalidated by insertion or deletion (except erased element)

8. Multiset:
   - Underlying implementation: Self-balancing binary search tree
   - Characteristics:
     - Like set, but allows duplicate elements
     - Elements stored in sorted order
     - Fast search, insertion, and deletion (O(log n))
     - No direct element modification
   - Iterators:
     - Bidirectional iterators
     - Supports: ++, --, ==, !=
     - Not invalidated by insertion or deletion (except erased element)

9. Unordered Set:
   - Underlying implementation: Hash table
   - Characteristics:
     - Stores unique elements in no particular order
     - Very fast average search, insertion, and deletion (O(1))
     - Worst case O(n) if many hash collisions
     - No direct element modification
   - Iterators:
     - Forward iterators
     - Supports: ++, ==, !=
     - May be invalidated by insertion when rehashing occurs

10. Map:
  - Underlying implementation: Self-balancing binary search tree
  - Characteristics:
      - Stores key-value pairs with unique keys in sorted order by key
      - Fast search, insertion, and deletion (O(log n))
      - Direct access to values via keys using operator[]
  - Iterators:
      - Bidirectional iterators
      - Supports: ++, --, ==, !=
      - Not invalidated by insertion or deletion (except erased element)

11. Unordered Map:
  - Underlying implementation: Hash table
  - Characteristics:
      - Stores key-value pairs with unique keys in no particular order
      - Very fast average search, insertion, and deletion (O(1))
      - Worst case O(n) if many hash collisions
      - Direct access to values via keys using operator[]
  - Iterators:
      - Forward iterators
      - Supports: ++, ==, !=
      - May be invalidated by insertion when rehashing occurs

12. Multimap:
  - Underlying implementation: Self-balancing binary search tree
  - Characteristics:
      - Like map, but allows duplicate keys
      - Keys sorted in specified order
      - Fast search, insertion, and deletion (O(log n))
      - No direct access via operator[], must use methods like find() and equal_range()
  - Iterators:
      - Bidirectional iterators
      - Supports: ++, --, ==, !=
      - Not invalidated by insertion or deletion (except erased element)

Key Iterator Differences:
1. Capability:
   - Vector and deque provide powerful random-access iterators.
   - List, set, multiset, map, and multimap provide bidirectional iterators for sequential traversal.
   - Unordered set and unordered map provide forward iterators, supporting only single-direction traversal.
   - Stack, queue, and priority_queue don't provide iterators.

2. Invalidation:
   - Vector iterators can be invalidated by insertions or deletions, especially if resizing occurs.
   - List iterators remain valid except when the pointed-to element is erased.
   - Deque iterators can be invalidated by insertions or deletions at boundaries.
   - Associative container's iterators (set, multiset, map, multimap) are stable, and insertions/deletions don't affect validity except for erased elements.
   - Unordered container's iterators (unordered_set, unordered_map) may invalidate iterators during rehashing.

3. Operations:
   - Random-access iterators (vector, deque) support full pointer arithmetic (e.g., it + n).
   - Bidirectional iterators (list, set, multiset, map, multimap) support sequential increment and decrement (++ and --).
   - Forward iterators (unordered_set, unordered_map) support only single-step forward traversal.

4. Performance:
   - Iterators from vector and deque benefit from contiguous (or near-contiguous) memory, leading to improved cache locality.
   - List iterators may incur performance overhead due to non-contiguous memory.
   - Associative container's iterators (set, multiset, map, multimap) offer efficient ordered traversal with operations typically in O(log n).
   - Unordered container's iterators (unordered_set, unordered_map) provide average constant time operations (O(1)), though worst-case scenarios may degrade to O(n) during rehashing.

When choosing a container, consider not only the container's characteristics but also the iterator capabilities you need for your specific use case.
*/

// Pair
void examplesPair() {
  cout << "~~~~~ Pair Example ~~~~~" << "\n";

  pair<int, int> p1 = {1, 2};
  cout << "First: " << p1.first << ", Second: " << p1.second << "\n";
}

// Vector
void examplesVector() {
  cout << "~~~~~ Vector Example ~~~~~" << "\n";

  // Initialize vectors
  vector<int> arr = {1, 2, 3, 4, 5};

  // 1. Size operations
  cout << "Size: " << arr.size() << "\n";          // Number of elements
  cout << "Capacity: " << arr.capacity() << "\n";  // Allocated space
  cout << "Empty?: " << arr.empty() << "\n";       // Check if empty

  // 2. Element access
  cout << "First element: " << arr.front() << "\n";  // First element
  cout << "Last element: " << arr.back() << "\n";    // Last element
  cout << "Element at 2: " << arr[2] << "\n";        // Using operator[]
  cout << "Element at 2: " << arr.at(2) << "\n";     // Using at()

  // 3. Modifiers
  arr.push_back(6);            // Add element at end
  arr.pop_back();              // Remove last element
  arr.insert(arr.begin(), 0);  // Insert at beginning
  arr.erase(arr.begin());      // Remove first element

  // 4. Iterator operations
  cout << "Elements: ";
  for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {  // NOLINT(modernize-loop-convert)
    cout << *it << " ";
  }
  cout << "\n";

  // 5. Reverse iterator
  cout << "Reverse elements: ";
  for (vector<int>::reverse_iterator it = arr.rbegin(); it != arr.rend(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  // 6. Other operations
  arr.clear();       // Remove all elements
  arr.resize(10);    // Resize vector
  arr.reserve(100);  // Reserve capacity

  // 7. Range-based for loop (modern way)
  vector<int> nums = {1, 2, 3, 4, 5};
  for (const int& num : nums) {
    cout << num << " ";
  }
  cout << "\n";
}

// List
void examplesList() {
  cout << "~~~~~ List Example ~~~~~" << "\n";

  // Initialize list
  list<int> myList = {1, 2, 3, 4, 5};

  // 1. Size operations
  cout << "Size: " << myList.size() << "\n";     // Number of elements
  cout << "Empty?: " << myList.empty() << "\n";  // Check if empty

  // 2. Element access
  cout << "First element: " << myList.front() << "\n";  // First element
  cout << "Last element: " << myList.back() << "\n";    // Last element

  // 3. Modifiers
  myList.push_back(6);   // Add element at end
  myList.push_front(0);  // Add element at beginning
  myList.pop_back();     // Remove last element
  myList.pop_front();    // Remove first element

  // Insert element
  auto it = next(myList.begin(), 2);
  myList.insert(it, 10);

  // Remove element
  it = find(myList.begin(), myList.end(), 3);
  if (it != myList.end()) {
    myList.erase(it);
  }

  // 4. Iterator operations
  cout << "Elements: ";
  for (list<int>::iterator iter = myList.begin(); iter != myList.end(); ++iter) {  // NOLINT(modernize-loop-convert)
    cout << *iter << " ";
  }
  cout << "\n";

  // 5. Reverse iterator
  cout << "Reverse elements: ";
  for (list<int>::reverse_iterator riter = myList.rbegin(); riter != myList.rend(); ++riter) {
    cout << *riter << " ";
  }
  cout << "\n";

  // 6. Other operations
  myList.sort();     // Sort the list
  myList.unique();   // Remove consecutive duplicates
  myList.reverse();  // Reverse the list

  list<int> anotherList = {100, 200, 300};
  myList.splice(myList.end(), anotherList);  // Move elements from anotherList to myList

  // 7. Range-based for loop (modern way)
  cout << "Final elements: ";
  for (const int& num : myList) {
    cout << num << " ";
  }
  cout << "\n";
}

// Deque
void examplesDeque() {
  cout << "~~~~~ Deque Example ~~~~~" << "\n";

  // Initialize deque
  deque<int> dq = {1, 2, 3, 4, 5};

  // 1. Size operations
  cout << "Size: " << dq.size() << "\n";          // Number of elements
  cout << "Empty?: " << dq.empty() << "\n";       // Check if empty
  cout << "Max size: " << dq.max_size() << "\n";  // Maximum size deque can reach

  // 2. Element access
  cout << "First element: " << dq.front() << "\n";  // First element
  cout << "Last element: " << dq.back() << "\n";    // Last element
  cout << "Element at 2: " << dq[2] << "\n";        // Using operator[]
  cout << "Element at 2: " << dq.at(2) << "\n";     // Using at()

  // 3. Modifiers
  dq.push_back(6);   // Add element at end
  dq.push_front(0);  // Add element at beginning
  dq.pop_back();     // Remove last element
  dq.pop_front();    // Remove first element

  // Insert element
  auto it = dq.begin() + 2;
  dq.insert(it, 10);

  // Remove element
  it = find(dq.begin(), dq.end(), 3);
  if (it != dq.end()) {
    dq.erase(it);
  }

  // 4. Iterator operations
  cout << "Elements: ";
  for (deque<int>::iterator iter = dq.begin(); iter != dq.end(); ++iter) {  // NOLINT(modernize-loop-convert)
    cout << *iter << " ";
  }
  cout << "\n";

  // 5. Reverse iterator
  cout << "Reverse elements: ";
  for (deque<int>::reverse_iterator riter = dq.rbegin(); riter != dq.rend(); ++riter) {
    cout << *riter << " ";
  }
  cout << "\n";

  // 6. Other operations
  dq.clear();          // Remove all elements
  dq.resize(5, 1);     // Resize deque to 5 elements, fill new elements with 1
  dq.shrink_to_fit();  // Reduce capacity to fit current size

  // 7. Range-based for loop (modern way)
  cout << "Final elements: ";
  for (const int& num : dq) {
    cout << num << " ";
  }
  cout << "\n";

  // 8. Capacity
  cout << "Size: " << dq.size() << "\n";
  // Note: deque doesn't have a capacity() function like vector
}

// Stack
void examplesStack() {
  cout << "~~~~~ Stack Example ~~~~~" << "\n";

  // Initialize stack
  stack<int> stk;
  stk.push(1);
  stk.push(2);
  stk.push(3);
  stk.push(4);
  stk.push(5);

  // 1. Size operations
  cout << "Size: " << stk.size() << "\n";     // Number of elements
  cout << "Empty?: " << stk.empty() << "\n";  // Check if empty

  // 2. Element access
  cout << "Top element: " << stk.top() << "\n";  // Access top element

  // 3. Modifiers
  stk.push(6);  // Add element at top
  stk.pop();    // Remove top element

  // 4. Traversal (using temporary stack)
  cout << "Elements (top to bottom): ";
  stack<int> temp = stk;
  while (!temp.empty()) {
    cout << temp.top() << " ";
    temp.pop();
  }
  cout << "\n";

  // 5. Using stack for reversing elements
  vector<int> vec = {1, 2, 3, 4, 5};
  stack<int> reverseStack;
  for (int num : vec) {
    reverseStack.push(num);
  }
  cout << "Reversed elements: ";
  while (!reverseStack.empty()) {
    cout << reverseStack.top() << " ";
    reverseStack.pop();
  }
  cout << "\n";

  // 6. Other operations
  stack<int> anotherStack;
  anotherStack.swap(stk);  // Swap contents with another stack
}

// Queue
void examplesQueue() {
  cout << "~~~~~ Queue Example ~~~~~" << "\n";

  // Initialize queue
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  // 1. Size operations
  cout << "Size: " << q.size() << "\n";     // Number of elements
  cout << "Empty?: " << q.empty() << "\n";  // Check if empty

  // 2. Element access
  cout << "Front element: " << q.front() << "\n";  // First element
  cout << "Back element: " << q.back() << "\n";    // Last element

  // 3. Modifiers
  q.push(6);  // Add element at end
  q.pop();    // Remove first element

  // 4. Traversal (using temporary queue)
  cout << "Elements (front to back): ";
  queue<int> temp = q;
  while (!temp.empty()) {
    cout << temp.front() << " ";
    temp.pop();
  }
  cout << "\n";

  // 5. Other operations
  queue<int> anotherQueue;
  anotherQueue.swap(q);  // Swap contents with another queue
}

// Priority Queue
void examplesPriorityQueue() {
  cout << "~~~~~ Priority Queue Example ~~~~~" << "\n";

  // Initialize priority queue (max heap by default)
  priority_queue<int> pq;
  pq.push(3);
  pq.push(1);
  pq.push(4);
  pq.push(2);
  pq.push(5);

  // 1. Size operations
  cout << "Size: " << pq.size() << "\n";     // Number of elements
  cout << "Empty?: " << pq.empty() << "\n";  // Check if empty

  // 2. Element access
  cout << "Top element: " << pq.top() << "\n";  // Access top (maximum) element

  // 3. Modifiers
  pq.push(6);  // Add element
  pq.pop();    // Remove top element

  // 4. Traversal (using temporary priority queue)
  cout << "Elements (in decreasing order): ";
  priority_queue<int> temp = pq;
  while (!temp.empty()) {
    cout << temp.top() << " ";
    temp.pop();
  }
  cout << "\n";

  // 5. Min heap example
  priority_queue<int, vector<int>, greater<>> minPQ;
  minPQ.push(3);
  minPQ.push(1);
  minPQ.push(4);
  minPQ.push(2);
  minPQ.push(5);

  cout << "Min heap elements (in increasing order): ";
  while (!minPQ.empty()) {
    cout << minPQ.top() << " ";
    minPQ.pop();
  }
  cout << "\n";

  // 6. Using priority queue with custom type
  struct Task {
    int priority;
    string name;
    Task(int p, string n) : priority(p), name(std::move(n)) {}
  };

  struct CompareTask {
    bool operator()(const Task& t1, const Task& t2) {
      return t1.priority < t2.priority;
    }
  };

  priority_queue<Task, vector<Task>, CompareTask> taskPQ;
  taskPQ.push(Task(2, "Medium priority task"));  // NOLINT(modernize-use-emplace)
  taskPQ.push(Task(1, "Low priority task"));     // NOLINT(modernize-use-emplace)
  taskPQ.push(Task(3, "High priority task"));    // NOLINT(modernize-use-emplace)

  cout << "Processing tasks by priority:" << "\n";
  while (!taskPQ.empty()) {
    cout << "Processing: " << taskPQ.top().name << " (Priority: " << taskPQ.top().priority << ")" << "\n";
    taskPQ.pop();
  }
}

// Set
void examplesSet() {
  cout << "~~~~~ Set Example ~~~~~" << "\n";

  // Initialize set
  set<string> mySet = {"banana", "apple", "cherry", "date"};

  // 1. Size operations
  cout << "Size: " << mySet.size() << "\n";     // Number of elements
  cout << "Empty?: " << mySet.empty() << "\n";  // Check if empty

  // 2. Insertion
  mySet.insert("elderberry");
  auto [it, inserted] = mySet.insert("apple");  // Try to insert duplicate
  if (!inserted) {
    cout << "apple was not inserted, already exists" << "\n";
  }

  // 3. Traversal (elements are always in sorted order)
  cout << "Elements (sorted): ";
  for (const string& fruit : mySet) {
    cout << fruit << " ";
  }
  cout << "\n";

  // 4. Search
  auto findIt = mySet.find("cherry");
  if (findIt != mySet.end()) {
    cout << "Found cherry in the set" << "\n";
  }

  // 5. Erase
  mySet.erase("banana");
  cout << "After erasing banana: ";
  for (const string& fruit : mySet) {
    cout << fruit << " ";
  }
  cout << "\n";

  // 6. Lower and upper bound
  auto lower = mySet.lower_bound("cherry");
  auto upper = mySet.upper_bound("elderberry");
  cout << "Elements from cherry to elderberry: ";
  for (auto iter = lower; iter != upper; ++iter) {
    cout << *iter << " ";
  }
  cout << "\n";

  // 7. Custom comparator (reverse order)
  set<string, greater<>> reverseSet(mySet.begin(), mySet.end());
  cout << "Elements in reverse order: ";
  for (const string& fruit : reverseSet) {
    cout << fruit << " ";
  }
  cout << "\n";

  // 8. Set operations
  set<string> set1 = {"apple", "banana", "cherry"};
  set<string> set2 = {"banana", "cherry", "date"};

  set<string> unionSet;
  set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
            inserter(unionSet, unionSet.begin()));

  cout << "Union of set1 and set2: ";
  for (const string& fruit : unionSet) {
    cout << fruit << " ";
  }
  cout << "\n";

  // 9. Extract and insert
  auto node = mySet.extract("cherry");
  node.value() = "grape";  // Modify the extracted node
  mySet.insert(std::move(node));

  cout << "After extracting cherry and inserting grape: ";
  for (const string& fruit : mySet) {
    cout << fruit << " ";
  }
  cout << "\n";
}

// Multiset
void examplesMultiset() {
  cout << "~~~~~ Multiset Example ~~~~~" << "\n";

  // Initialize multiset
  multiset<int> myMultiset = {5, 2, 8, 2, 1, 9, 3, 7, 3};

  // 1. Size operations
  cout << "Size: " << myMultiset.size() << "\n";     // Number of elements
  cout << "Empty?: " << myMultiset.empty() << "\n";  // Check if empty

  // 2. Insertion
  myMultiset.insert(4);
  myMultiset.insert(2);  // Duplicate insertion is allowed

  // 3. Traversal
  cout << "Elements: ";
  for (const int& num : myMultiset) {
    cout << num << " ";
  }
  cout << "\n";

  // 4. Count occurrences
  cout << "Count of 2: " << myMultiset.count(2) << "\n";
  cout << "Count of 6: " << myMultiset.count(6) << "\n";

  // 5. Erase
  myMultiset.erase(2);  // Erases all occurrences of 2
  cout << "After erasing all 2s: ";
  for (const int& num : myMultiset) {
    cout << num << " ";
  }
  cout << "\n";

  // 6. Equal range
  auto [lower, upper] = myMultiset.equal_range(3);
  cout << "Elements in equal range of 3: ";
  for (auto it = lower; it != upper; ++it) {
    cout << *it << " ";
  }
  cout << "\n";
}

// Unordered set
void examplesUnorderedSet() {
  cout << "~~~~~ Unordered Set Example ~~~~~" << "\n";

  // Initialize unordered_set
  unordered_set<string> mySet = {"apple", "banana", "cherry", "date"};

  // 1. Size operations
  cout << "Size: " << mySet.size() << "\n";     // Number of elements
  cout << "Empty?: " << mySet.empty() << "\n";  // Check if empty

  // 2. Insertion
  mySet.insert("elderberry");
  auto [it, inserted] = mySet.insert("apple");  // Try to insert duplicate
  if (!inserted) {
    cout << "apple was not inserted, already exists" << "\n";
  }

  // 3. Traversal (elements may not be in insertion order)
  cout << "Elements (unordered): ";
  for (const string& fruit : mySet) {
    cout << fruit << " ";
  }
  cout << "\n";

  // 4. Search
  auto findIt = mySet.find("cherry");
  if (findIt != mySet.end()) {
    cout << "Found cherry in the set" << "\n";
  }

  // 5. Erase
  mySet.erase("banana");
  cout << "After erasing banana: ";
  for (const string& fruit : mySet) {
    cout << fruit << " ";
  }
  cout << "\n";

  // 6. Bucket interface
  cout << "Number of buckets: " << mySet.bucket_count() << "\n";
  cout << "Load factor: " << mySet.load_factor() << "\n";

  // 7. Custom hash function and equality
  struct CustomHash {
    size_t operator()(const string& s) const {
      return hash<string>{}(s) ^ (hash<size_t>{}(s.length()) << 1);
    }
  };

  struct CustomEqual {
    bool operator()(const string& lhs, const string& rhs) const {
      return lhs.length() == rhs.length() && lhs == rhs;
    }
  };

  unordered_set<string, CustomHash, CustomEqual> customSet = {"cat", "dog", "bird"};
  cout << "Custom unordered set: ";
  for (const string& animal : customSet) {
    cout << animal << " ";
  }
  cout << "\n";

  // 8. Reserve and rehash
  mySet.reserve(20);  // Reserve space for at least 20 elements
  cout << "Bucket count after reserve: " << mySet.bucket_count() << "\n";

  mySet.rehash(30);  // Set number of buckets to at least 30
  cout << "Bucket count after rehash: " << mySet.bucket_count() << "\n";
}

void examplesMap() {
  cout << "~~~~~ Map Example ~~~~~" << "\n";

  // Initialize map
  map<string, int> fruitMap = {{"apple", 1}, {"banana", 2}, {"cherry", 3}};

  // 1. Size operations
  cout << "Map size: " << fruitMap.size() << "\n";
  cout << "Map empty?: " << fruitMap.empty() << "\n";

  // 2. Element access and insertion
  fruitMap["date"] = 4;
  cout << "Value of 'banana': " << fruitMap["banana"] << "\n";

  // 3. Traversal (elements are always in sorted order by key)
  cout << "Map elements (sorted by key): ";
  for (const auto& pair : fruitMap) {
    cout << pair.first << ":" << pair.second << " ";
  }
  cout << "\n";

  // 4. Search
  auto findIt = fruitMap.find("cherry");
  if (findIt != fruitMap.end()) {
    cout << "Found cherry in the map with value: " << findIt->second << "\n";
  }

  // 5. Erase
  fruitMap.erase("banana");
  cout << "After erasing banana: ";
  for (const auto& pair : fruitMap) {
    cout << pair.first << ":" << pair.second << " ";
  }
  cout << "\n";

  // 6. Using map with custom comparator
  map<string, int, greater<>> reverseMap(fruitMap.begin(), fruitMap.end());
  cout << "Map with reverse order: ";
  for (const auto& pair : reverseMap) {
    cout << pair.first << ":" << pair.second << " ";
  }
  cout << "\n";

  // 7. Performance measurement
  clock_t start = clock();
  for (int i = 0; i < 100000; ++i) {
    (void)fruitMap[to_string(i)];  // Suppress unused value warning
  }
  clock_t end = clock();
  cout << "Time taken by map: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << "\n";
}

void examplesUnorderedMap() {
  cout << "~~~~~ Unordered Map Example ~~~~~" << "\n";

  // Initialize unordered_map
  unordered_map<string, int> animalMap = {{"cat", 1}, {"dog", 2}, {"bird", 3}};

  // 1. Size operations
  cout << "Unordered map size: " << animalMap.size() << "\n";
  cout << "Unordered map empty?: " << animalMap.empty() << "\n";

  // 2. Element access and insertion
  animalMap["fish"] = 4;
  cout << "Value of 'dog': " << animalMap["dog"] << "\n";

  // 3. Traversal (elements may not be in insertion order)
  cout << "Unordered map elements: ";
  for (const auto& pair : animalMap) {
    cout << pair.first << ":" << pair.second << " ";
  }
  cout << "\n";

  // 4. Search
  auto findIt = animalMap.find("bird");
  if (findIt != animalMap.end()) {
    cout << "Found bird in the unordered map with value: " << findIt->second << "\n";
  }

  // 5. Erase
  animalMap.erase("dog");
  cout << "After erasing dog: ";
  for (const auto& pair : animalMap) {
    cout << pair.first << ":" << pair.second << " ";
  }
  cout << "\n";

  // 6. Bucket interface
  cout << "Number of buckets: " << animalMap.bucket_count() << "\n";
  cout << "Load factor: " << animalMap.load_factor() << "\n";

  // 7. Performance measurement
  clock_t start = clock();
  for (int i = 0; i < 100000; ++i) {
    (void)animalMap[to_string(i)];  // Suppress unused value warning
  }
  clock_t end = clock();
  cout << "Time taken by unordered_map: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << "\n";
}

void examplesMultimap() {
  cout << "~~~~~ Multimap Example ~~~~~" << "\n";

  // Initialize multimap
  multimap<string, int> studentScores;

  // 1. Insertion (allows duplicate keys)
  studentScores.insert({"Alice", 85});
  studentScores.insert({"Bob", 92});
  studentScores.insert({"Alice", 90});  // Another score for Alice
  studentScores.insert({"Charlie", 78});
  studentScores.insert({"Bob", 88});  // Another score for Bob

  // 2. Size operations
  cout << "Multimap size: " << studentScores.size() << "\n";
  cout << "Multimap empty?: " << studentScores.empty() << "\n";

  // 3. Traversal (elements are sorted by key)
  cout << "All student scores: " << "\n";
  for (const auto& entry : studentScores) {
    cout << entry.first << ": " << entry.second << "\n";
  }

  // 4. Finding elements with a specific key
  string searchName = "Alice";
  cout << "\nScores for " << searchName << ":" << "\n";
  auto range = studentScores.equal_range(searchName);
  for (auto it = range.first; it != range.second; ++it) {
    cout << it->first << ": " << it->second << "\n";
  }

  // 5. Counting elements with a specific key
  cout << "\nNumber of scores for Bob: " << studentScores.count("Bob") << "\n";

  // 6. Erasing elements
  int erasedCount = (int)studentScores.erase("Charlie");
  cout << "Erased " << erasedCount << " entries for Charlie" << "\n";

  // 7. Erasing specific element using iterator
  auto it = studentScores.find("Bob");
  if (it != studentScores.end()) {
    studentScores.erase(it);  // Erase only the first score for Bob
    cout << "Erased one score for Bob" << "\n";
  }

  // 8. Final multimap state
  cout << "\nFinal student scores: " << "\n";
  for (const auto& entry : studentScores) {
    cout << entry.first << ": " << entry.second << "\n";
  }

  // 9. Using custom comparator (reverse order)
  multimap<string, int, greater<>> reverseScores;
  for (const auto& entry : studentScores) {
    reverseScores.insert(entry);
  }

  cout << "\nScores in reverse alphabetical order: " << "\n";
  for (const auto& entry : reverseScores) {
    cout << entry.first << ": " << entry.second << "\n";
  }

  // 10. Performance comparison with map
  multimap<int, int> largeMultimap;
  map<int, int> largeMap;

  clock_t start = clock();
  for (int i = 0; i < 100000; ++i) {
    largeMultimap.insert({i % 1000, i});  // Introduces duplicates
  }
  clock_t end = clock();
  cout << "\nTime taken to insert 100,000 elements into multimap: "
       << double(end - start) / CLOCKS_PER_SEC << " seconds" << "\n";

  start = clock();
  for (int i = 0; i < 100000; ++i) {
    (void)largeMap[i];  // No duplicates - suppress unused value warning
  }
  end = clock();
  cout << "Time taken to insert 100,000 elements into map: "
       << double(end - start) / CLOCKS_PER_SEC << " seconds" << "\n";
}

int main() {
  try {
    // Pair
    examplesPair();

    // Vector
    examplesVector();

    // List
    examplesList();

    // Deque
    examplesDeque();

    // Stack
    examplesStack();

    // Queue
    examplesQueue();

    // Priority Queue
    examplesPriorityQueue();

    // Set
    examplesSet();

    // Multiset
    examplesMultiset();

    // Unordered Set
    examplesUnorderedSet();

    // Map
    examplesMap();

    // Unordered Map
    examplesUnorderedMap();

    // Multimap
    examplesMultimap();

    return 0;

  } catch (exception& e) {
    cout << "Error: " << e.what() << "\n";
    return 1;
  } catch (...) {
    cout << "Unknown error" << "\n";
    return 1;
  }
}
