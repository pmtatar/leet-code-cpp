# C++ STL Containers

Quick reference for sequence containers, container adapters, associative containers, `std::string`, and `std::bitset`.

---

## Contents

1. `std::array`
2. `std::vector`
3. `std::deque`
4. `std::list`
5. `std::forward_list`
6. `std::stack` (adapter)
7. `std::queue` (adapter)
8. `std::priority_queue` (adapter)
9. `std::set` & `std::multiset`
10. `std::unordered_set` & `std::unordered_multiset`
11. `std::map` & `std::multimap`
12. `std::unordered_map` & `std::unordered_multimap`
13. `std::string`
14. `std::bitset`
15. Iteration patterns

---

## 1. `std::array`

**Header:** `<array>`

### Description

Fixed-size container that wraps a C-style array with a standard STL interface.

### Internal implementation

- Contiguous memory.
- Stored directly inside the object (on the stack if declared locally).
- Size is fixed at compile time. No dynamic allocation.

### Memory management

- **`N * sizeof(T)`** (plus padding) lives **inside the object**; no dynamic growth.

### Key APIs

```cpp
std::array<int, 5> a;      // Fixed-size array of 5 integers

a.size();                  // Number of elements
a.empty();                 // true if size() == 0
a[i];                      // Element at i (no bounds check)
a.at(i);                   // Bounds-checked access (throws std::out_of_range)
a.front();                 // First element
a.back();                  // Last element
a.data();                  // Pointer to contiguous storage
a.fill(val);               // Assign val to every element
a.swap(other);             // Swap with another array (same type and size)
a.begin();                 // Iterator to first element
a.end();                   // Iterator past last (also rbegin, rend, cbegin, cend)
```

### Iteration

- **Walk all elements:** range-based `for`, index `0 … size()-1`, or iterators (random access).
- **Iteration members:** `begin`, `end`, `cbegin`, `cend`, `rbegin`, `rend`, `data`, `size`, `empty`.
- **Single-element access:** `front`, `back`, `operator[]`, `at`.

### Complexity

- **Access:** O(1)
- **Iteration:** O(n)

### Competitive programming tips

- Use for **fixed** max sizes (e.g. `std::array<int, MAXN>` globals); same performance as C arrays with a safer API.
- Default-initialize with `{{}}` or `std::array<int, N>{}` when you need zeros; avoid treating uninitialized `array` as zero-filled.

---

## 2. `std::vector`

**Header:** `<vector>`

### Description

Dynamic, resizable contiguous array. The default choice for most sequential storage.

### Internal implementation

- Contiguous heap memory.
- Capacity grows when full (common strategy: multiply capacity by a constant factor; exact growth is implementation-defined, not guaranteed to be ×2).
- **Reallocation** when capacity increases invalidates all iterators, pointers, and references to elements (unless `insert`/`erase`/`emplace` documentation says otherwise for the specific operation).

### Memory management

- **One heap buffer**; when `size == capacity`, the next append **reallocates** a larger block and **moves/copies** elements (capacity usually grows in **multiplicative** steps; factor is implementation-defined).
- **`reserve(n)`** cuts reallocations; **`erase` / `pop_back`** usually shrink `size` but **not** `capacity` until `shrink_to_fit` (non-binding), swap, or reassignment.

### Key APIs

```cpp
std::vector<int> v;        // Empty vector

v.push_back(x);            // Append copy of x at end
v.emplace_back(args...);   // Construct element in-place at end
v.pop_back();              // Remove last element (undefined if empty)

v.size();                  // Number of elements
v.capacity();              // Allocated slots before reallocation
v.empty();                 // true if size() == 0
v.reserve(n);              // Ensure capacity >= n; may reallocate
v.resize(n);               // Set size to n (default-insert or erase tail)
v.shrink_to_fit();         // Non-binding request to shrink capacity to size
v.clear();                 // Remove all elements; capacity may stay

v.data();                  // Pointer to underlying array (C APIs, contiguous span)
v[i];                      // Unchecked index access
v.at(i);                   // Bounds-checked index access
v.front();                 // First element
v.back();                  // Last element

v.insert(pos, val);        // Insert before iterator pos (overloads for count/range)
v.erase(pos);              // Erase at pos (or erase(first, last) for range)
v.assign(...);             // Replace contents (iterators, fill count, etc.)
```

### Iteration

- **Walk all elements:** same as `array`: range-based `for`, index, or iterators (random access).
- **Iteration members:** `begin`, `end`, `cbegin`, `cend`, `rbegin`, `rend`, `data`, `size`, `empty`.
- **Single-element access:** `front`, `back`, `operator[]`, `at`.

### Complexity

- **Access:** O(1)
- **Push back / emplace back:** O(1) amortized
- **Insert/erase (middle):** O(n) due to shifting

### Competitive programming tips

- Call **`reserve(n)`** when the final size (or an upper bound) is known—cuts reallocations in tight time limits.
- Prefer **`emplace_back`** over `push_back` when constructing in place; **`back()`** after push for the last element.

---

## 3. `std::deque`

**Header:** `<deque>`

### Description

Double-ended queue: efficient growth and shrink at both ends.

### Internal implementation

- Typically **segmented** blocks (not one single contiguous allocation like `vector`).
- Since **C++17**, `deque` has `data()` when `!empty()`; the storage model is still usually chunk-based, so cache locality differs from `vector`.

### Memory management

- **Chunked heap blocks** + index structure; front/back growth adds blocks instead of reallocating the whole sequence like `vector`.
- **`capacity()`-style shrink** is not exposed; memory after many **`pop`**s may fall slowly or lag (implementation-dependent).

### Key APIs

```cpp
std::deque<int> dq;        // Empty deque

dq.push_front(x);          // Insert copy at front
dq.push_back(x);           // Insert copy at back
dq.pop_front();            // Remove first element
dq.pop_back();             // Remove last element

dq[i];                     // Unchecked random access by index
dq.at(i);                  // Bounds-checked random access
dq.front();                // First element
dq.back();                 // Last element
dq.begin();                // Iterator to first element
dq.end();                  // Iterator past last element
dq.data();                 // C++17+: pointer to first element (if non-empty)
```

### Iteration

- **Walk all elements:** range-based `for`, index (`operator[]`, `at`), or iterators — same patterns as `vector` (random access).
- **Iteration members:** `begin`, `end`, `cbegin`, `cend`, `data` (C++17+, if non-empty), `size`, `empty`.
- **Single-element access:** `front`, `back`, `operator[]`, `at`.

### Complexity

- **Access ends / index:** O(1)
- **Push/pop front or back:** O(1)
- **Insert/erase (middle):** O(n)

### Competitive programming tips

- Classic **sliding-window monotonic queue** pattern: **`push_back` / `pop_back`** on one side and **`pop_front`** on the other, all **O(1)** amortized.
- Prefer **`deque`** over **`vector`** when you need **`push_front` / `pop_front`** in addition to back operations.

---

## 4. `std::list`

**Header:** `<list>`

### Description

Doubly linked list: stable iterators on insert/erase of other nodes; no random access.

### Internal implementation

- Nodes with value, prev, and next pointers.
- Non-contiguous; worse locality than `vector`/`deque` for sequential scans.

### Memory management

- **One heap allocation per node** on insert; **freed** on erase. Footprint ~**linear** in `n` with **extra per-node overhead** vs `vector`.

### Key APIs

```cpp
std::list<int> l;          // Empty list

l.push_back(x);            // Insert at back
l.push_front(x);           // Insert at front
l.insert(pos, val);        // Insert before iterator pos
l.erase(pos);              // Erase at pos (or erase(first, last) for range)
l.remove(val);             // Erase all elements equal to val
l.remove_if(pred);         // Erase all elements satisfying predicate
l.splice(pos, other);      // Move nodes from other before pos (O(1) per node)
l.sort();                  // Sort list (typically O(n log n))
l.merge(other);            // Merge sorted other into sorted list (empties other)
l.reverse();               // Reverse element order
l.unique();                // Erase consecutive duplicate elements
```

### Iteration

- **Walk all elements:** range-based `for`, or iterator loops with `++` and `--` (bidirectional). **No** `operator[]` / random index by position — use iterators or linear search.
- **Iteration members:** `begin`, `end`, `cbegin`, `cend`, `rbegin`, `rend`, `size`, `empty`.
- **Single-element access:** `front`, `back` only (ends of the list).

### Complexity

- **Insert/erase at known iterator:** O(1)
- **Element access by index / search:** O(n)

### Competitive programming tips

- Rare in contests vs **`vector`**; use when you need **O(1) splice** or **stable iterators** while mutating elsewhere.
- **`list::sort`** is stable-friendly and avoids the extra `O(n log n)` memory of `std::sort` on arrays (still `O(n log n)` time).

---

## 5. `std::forward_list`

**Header:** `<forward_list>`

### Description

Singly linked list. Minimal per-node overhead; only forward iteration.

### Internal implementation

- Node: value + next pointer.
- No `size()` member by design (computing size would be O(n)); use `std::distance` if needed.

### Memory management

- Same as **`list`** but **smaller nodes**; **no `reserve`**.

### Key APIs

```cpp
std::forward_list<int> fl; // Empty forward list

fl.push_front(x);          // Insert at front
fl.pop_front();            // Remove first element
fl.before_begin();         // Iterator before first (for insert_after at head)
fl.insert_after(pos, val); // Insert new element after iterator pos
fl.erase_after(pos);       // Erase element after pos
fl.remove(val);            // Remove all elements equal to val
fl.remove_if(pred);        // Remove all elements satisfying predicate
fl.splice_after(pos, other); // Move nodes from other after pos
```

### Iteration

- **Walk all elements:** range-based `for`, or forward iterator loops (`++` only). Use `before_begin` with `insert_after` / `erase_after` to change the head.
- **Iteration members:** `before_begin`, `begin`, `end`, `cbegin`, `cend`, `empty` (no `size()` member).
- **Single-element access:** `front` only (no `back`).

### Complexity

- **Insert/erase after position:** O(1)
- **Search:** O(n)

### Competitive programming tips

- Slightly **lighter** than `list`; same **no `size()`** pain—use only when memory or forward-only logic matters.
- Almost always **`vector`** or **`deque`** wins for speed; consider `forward_list` mainly for **very large** sparse adjacency-style structures.

---

## 6. `std::stack` (adapter)

**Header:** `<stack>`

### Description

LIFO (last-in, first-out) interface over an underlying sequence container.

### Internal implementation

- Default container: `std::deque`. Alternatives: `std::vector`, `std::list` (must satisfy `back` + `push_back` + `pop_back`).

### Memory management

- **No overhead** beyond the chosen underlying container (`deque` by default).

### Key APIs

```cpp
std::stack<int> st;        // Empty stack (default: deque backing)

st.push(x);                // Push copy onto top
st.emplace(args...);       // Construct element in-place on top
st.pop();                  // Remove top element (returns void)
st.top();                  // Reference to top element
st.empty();                // true if no elements
st.size();                 // Number of elements
```

### Iteration

- **Walk all elements:** no `begin` / `end` — drain with **`top` + `pop`** (LIFO) until empty.
- **Iteration members:** none (adapter has no iterators).
- **Single-element access:** `top` (current top); `push` / `emplace` to add; `pop` to remove top; `empty`, `size`.

### Complexity

- **Operations:** O(1) relative to underlying container

### Competitive programming tips

- **`stack<int>`** (default `deque`) for **DFS**, **parentheses / bracket** problems, **monotonic stack** (next greater element).
- Pattern: **`while (!st.empty()) { ... st.top(); st.pop(); }`**—`pop` returns **`void`**; read `top` first.

---

## 7. `std::queue` (adapter)

**Header:** `<queue>`

### Description

FIFO (first-in, first-out) interface.

### Internal implementation

- Default container: `std::deque`.

### Memory management

- Same as underlying **`deque`** (default): **no** separate adapter allocation.

### Key APIs

```cpp
std::queue<int> q;         // Empty queue (default: deque backing)

q.push(x);                 // Insert at back (enqueue)
q.emplace(args...);        // Construct in-place at back
q.pop();                   // Remove front element (returns void)
q.front();                 // Reference to front element
q.back();                  // Reference to back element
q.empty();                 // true if no elements
q.size();                  // Number of elements
```

### Iteration

- **Walk all elements:** no `begin` / `end` — drain with **`front` + `pop`** (FIFO) until empty.
- **Iteration members:** none (adapter has no iterators).
- **Single-element access:** `front` / `back` (peek either end); `push` / `emplace` at back; `pop` at front; `empty`, `size`.

### Complexity

- **Operations:** O(1) relative to underlying container

### Competitive programming tips

- Default for **BFS**, **level-order** traversal, **0-1 BFS** (with `deque`), simulation queues.
- Same **`pop` is `void`** pattern as stack: always **`front()`** (or `back()` if needed) before **`pop()`**.

---

## 8. `std::priority_queue` (adapter)

**Header:** `<queue>`; `<functional>` for `std::greater`

### Description

Priority queue: by default a **max-heap** (largest element on top).

### Internal implementation

- Default underlying container: `std::vector`, with heap operations (`push_heap` / `pop_heap` style).

### Memory management

- Default **`vector`** backing → **same realloc / `capacity` growth** as `std::vector`; heap sift does not allocate except on buffer grow.

### Key APIs

```cpp
std::priority_queue<int> max_pq; // Max-heap: largest element on top

std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq; // Min-heap

max_pq.push(x);            // Insert and restore heap order
max_pq.emplace(args...);   // Construct in-place and restore heap
max_pq.pop();              // Remove top (largest in max-heap)
max_pq.top();              // Reference to top (best according to Compare)
max_pq.empty();            // true if no elements
max_pq.size();             // Number of elements
```

### Iteration

- **Walk all elements:** no `begin` / `end` — drain with **`top` + `pop`** in heap order.
- **Iteration members:** none (adapter has no iterators).
- **Single-element access:** `top` (best element by `Compare`); `push` / `emplace`; `pop`; `empty`, `size`.

### Complexity

- **Push / pop:** O(log n)
- **Top / empty / size:** O(1)

### Competitive programming tips

- **Max-heap** by default; **min-heap:** `priority_queue<T, vector<T>, greater<T>>` (needs `#include <functional>`).
- **`Dijkstra`**, **merge k sorted lists**, **streaming median**, **top-k**—all PQ-shaped; for **`long long`** costs, use **`pair<ll,int>`** with custom `greater` / struct `Compare`.
- **`emplace`** avoids extra moves when pushing heavy structs.

---

## 9. `std::set` & `std::multiset`

**Header:** `<set>`

### Description

- **`set`:** Sorted unique keys.
- **`multiset`:** Sorted keys; duplicates allowed.

### Internal implementation

- Typically a balanced binary search tree (e.g. red–black tree). Exact structure is implementation-defined.

### Memory management

- **One tree node per element** on the heap (insert → alloc, erase → free); **Θ(n)** total with tree overhead—many small allocs, no single growing buffer.

### Key APIs

```cpp
std::set<int> s;           // Empty sorted set (unique keys)

s.insert(x);               // Insert x (set returns pair<iterator,bool>)
s.emplace(args...);        // Construct element in-place
s.erase(x);                // Erase by key (multiset: all equal keys)
s.erase(it);               // Erase single element at iterator
s.find(x);                 // Iterator to x or end() if absent
s.count(x);                // 0 or 1 in set; may exceed 1 in multiset
s.contains(x);             // C++20+: true if x is present
s.lower_bound(x);          // First element not less than x
s.upper_bound(x);          // First element greater than x
s.equal_range(x);          // Subrange of all elements equal to x
```

### Iteration

- **Walk all elements:** range-based `for`, or iterators with `++` / `--` (bidirectional). Keys appear in **sorted** order for `set` / `multiset`.
- **Iteration members:** `begin`, `end`, `cbegin`, `cend`, `empty`, `size`.
- **Single-element / lookup:** `find`, `contains` (C++20), `count`, `lower_bound`, `upper_bound`, `equal_range`.

### Complexity

- **Search / insert / erase:** O(log n)

### Competitive programming tips

- **`lower_bound(x)`** → first element **≥ x**; **`upper_bound(x)`** → first **> x**—template for “how many `< x`”, coordinate compression, order statistics on values.
- **`multiset`:** **`erase(x)`** removes **all** copies; to remove **one**, use **`ms.erase(ms.find(x))`** (check `find != end` first).
- Sorted iteration is **free** after inserts; use **`set`** when you need **order + uniqueness** and **`unordered_*`** is not enough.

---

## 10. `std::unordered_set` & `std::unordered_multiset`

**Header:** `<unordered_set>`

### Description

Hash-based sets. Average O(1) operations; **no sorted order**. `unordered_multiset` allows duplicate keys.

### Internal implementation

- Hash table with buckets; collision resolution is implementation-defined (often chaining).

### Memory management

- **Bucket table + entries** on the heap; high **load factor** triggers **rehash** (new buckets, **O(n)** move of all elements). **`reserve`** lowers how often that happens.
- **`erase`** may not shrink **bucket_count** immediately.

### Key APIs

```cpp
std::unordered_set<int> us; // Empty hash set

us.insert(x);              // Insert element (may rehash)
us.emplace(args...);       // Construct in-place
us.erase(x);               // Erase by key
us.erase(it);              // Erase element at iterator
us.find(x);                // Iterator to x or end()
us.count(x);               // 0 or 1 (unordered_multiset: may be >1)
us.contains(x);            // C++20+: true if present
us.reserve(n);             // Hint bucket count to reduce rehashes
us.rehash(n);              // Set bucket count to at least n
us.load_factor();          // Average elements per bucket (size/buckets)
us.max_load_factor();      // Get/set max load before rehash
us.bucket_count();         // Current number of buckets
```

### Iteration

- **Walk all elements:** range-based `for` or forward iterator traversal; **order is unspecified** (not sorted).
- **Iteration members:** `begin`, `end`, `cbegin`, `cend`, `empty`, `size`.
- **Single-element / lookup:** `find`, `contains` (C++20), `count`.

### Complexity

- **Search / insert / erase:** O(1) average, **O(n)** worst case (many collisions or poor hash)

### Competitive programming tips

- **`reserve(2 * expected_n)`** (or `reserve(n)` with a margin) is standard to avoid **rehash stalls** on many platforms.
- For **`pair` / `tuple` keys**, supply a **custom hash** (e.g. splitmix64-based); avoid `hash<long long> % MOD` as a primary hash on adversarial input.
- **`reserve`** does not insert elements—pair with actual inserts; **`max_load_factor(0.7f)`** is occasionally tuned in heavy hash maps.

---

## 11. `std::map` & `std::multimap`

**Header:** `<map>`

### Description

- **`map`:** Sorted unique keys mapped to values.
- **`multimap`:** Sorted keys; duplicate keys allowed.

### Internal implementation

- Typically balanced BST. Stored type is `std::pair<const Key, T>`.

### Memory management

- **Tree node per entry** (like `set`); **`operator[]`** can **insert a default** and allocate **before** you assign.

### Key APIs

```cpp
std::map<int, std::string> mp; // Empty sorted map (unique keys)

mp[k] = v;                 // Insert default if missing, then assign value
mp.at(k);                  // Access value; throws std::out_of_range if missing
mp.insert({k, v});         // Insert pair (no overwrite if key exists)
mp.emplace(k, v);          // Construct pair in-place
mp.erase(k);               // Erase by key
mp.erase(it);              // Erase at iterator
mp.find(k);                // Iterator to pair or end()
mp.contains(k);            // C++20+: true if key exists
mp.lower_bound(k);         // First key not less than k
mp.upper_bound(k);         // First key greater than k

// C++17: try_emplace(k, args...) — insert only if k missing; returns pair<iterator,bool>
// insert_or_assign(k, v) — insert or overwrite mapped value
```

### Iteration

- **Walk all elements:** range-based `for` (e.g. `auto [k, v]` in C++17), or bidirectional iterators; keys sorted by `<` for `map` / `multimap`.
- **Iteration members:** `begin`, `end`, `cbegin`, `cend`, `empty`, `size`.
- **Single-element / lookup:** `find`, `contains` (C++20), `lower_bound`, `upper_bound`, `equal_range`, `count`; **`std::map` only:** `at`, `operator[]`.

### Complexity

- **Search / insert / erase:** O(log n)

**Note:** Prefer `insert`/`emplace` or `contains` + `insert` when you must **not** create entries accidentally; `operator[]` always inserts if the key is absent.

### Competitive programming tips

- **`lower_bound` / `upper_bound`** on keys work like `set`; great for **timeline / interval** maps and **ordered statistics** on keys.
- Use **`try_emplace(k, args...)`** (C++17) or **`insert_or_assign`** when you want **conditional insert** without `operator[]` side effects.
- For **freq + order**, sometimes **`map<int,int>`** beats maintaining both `unordered_map` and `vector` of keys—pick by constant factors vs `log n`.

---

## 12. `std::unordered_map` & `std::unordered_multimap`

**Header:** `<unordered_map>`

### Description

Hash table of key–value pairs. No key ordering.

### Internal implementation

- **Bucket-based hash table**; each slot holds or references **`pair<const Key, T>`** (or equivalent) entries. Collision strategy is implementation-defined (often **separate chaining** with nodes per bucket).

### Memory management

- Same as **`unordered_set`**: buckets + pairs; **rehash** when load grows. **`reserve` / `rehash`** reduce repeated **O(n)** table grows.
- **`operator[]`** can insert a default (may **rehash** like any insert).

### Key APIs

```cpp
std::unordered_map<int, int> um; // Empty hash map

um[k] = v;                 // Insert with default value if key missing, then assign
um.at(k);                  // Access value; throws if key missing
um.insert({k, v});         // Insert pair
um.emplace(k, v);          // Construct pair in-place
um.erase(k);               // Erase by key
um.find(k);                // Iterator to pair or end()
um.contains(k);            // C++20+: true if key exists
um.reserve(n);             // Reserve buckets (rehash hint)
um.rehash(n);              // At least n buckets
um.load_factor();          // size() / bucket_count()
um.max_load_factor();      // Get/set max load before rehash

// C++17: try_emplace(k, args...) — like map; insert only if key missing
// insert_or_assign(k, v) — insert or overwrite mapped value
```

### Iteration

- **Walk all elements:** range-based `for` or forward iterator traversal over `pair<const Key, T>`; **key order unspecified**.
- **Iteration members:** `begin`, `end`, `cbegin`, `cend`, `empty`, `size`.
- **Single-element / lookup:** `find`, `contains` (C++20); **`unordered_map` only:** `at`, `operator[]`.

### Complexity

- **Search / insert / erase:** O(1) average, O(n) worst case

### Competitive programming tips

- Default **frequency / memo / adjacency** container when order does not matter; **`um.reserve(n)`** before bulk inserts when **`n`** is known (queries, edges).
- **`operator[]`** default-constructs then assigns—fine for counters (`um[x]++`), risky for non-trivial `T` or when absence must stay absent.
- **`find` + `end()`** checks work on all C++ versions; **`contains`** is shorter on **C++20** and up.

---

## 13. `std::string`

**Header:** `<string>`

### Description

Owning sequence of characters (`char`); behaves like a sequence container with string-specific helpers.

### Internal implementation

- Contiguous `char` storage.
- Many implementations use **SSO (small string optimization)** so short strings avoid heap allocation; the “small” threshold is **implementation-defined** (often on the order of 15–22 characters on 64-bit libstdc++/libc++, not guaranteed).

### Memory management

- **SSO:** small strings often **inline** in the object; past the threshold, a **heap buffer** grows with **realloc**-style **`capacity()`** bumps (like `vector<char>`).
- **`erase` / `clear`** drop `size`; **`capacity`** may stay high until **`shrink_to_fit`** (non-binding) or reassignment.

### Key APIs

```cpp
std::string s = "Hello";   // Initialize from string literal

s.size();                  // Length in chars (same as length())
s.length();                // Same as size()
s.empty();                 // true if no characters
s.capacity();              // Allocated capacity before reallocation
s.push_back('c');          // Append single character
s.pop_back();              // Remove last character
s.append(str);             // Append string (many overloads: C string, count, etc.)
s += str;                  // Append via operator+=
s.c_str();                 // const char* null-terminated view
s.data();                  // C++17+: char* for non-const string (contiguous)

s.substr(pos, len);        // Substring from pos of length len
s.find(str);               // Find substring (npos if not found)
s.find(c);                 // Find character (npos if not found)
s.rfind(str);              // Find last occurrence (npos if not found)
s.erase(pos, len);         // Erase len characters starting at pos
s.insert(pos, str);        // Insert str before pos (index or iterator overloads)
s.replace(pos, len, str);  // Replace len chars at pos with str

std::to_string(42);        // Convert arithmetic type to string
std::stoi("42");           // Parse int (throws invalid_argument / out_of_range)
```

### Iteration

- **Walk all elements:** range-based `for` over `char`, index loop with `operator[]` / `at`, or iterators (random access, contiguous).
- **Iteration members:** `begin`, `end`, `cbegin`, `cend`, `data`, `c_str`, `size` / `length`, `empty`.
- **Single-element access:** `front`, `back`, `operator[]`, `at`.

### Complexity

- **Index access:** O(1)
- **Append / assign / substring:** O(length involved)
- **Find (substring, naive):** O(n·m) for pattern length m in string length n

### Competitive programming tips

- **`ios::sync_with_stdio(false); cin.tie(nullptr);`** plus **`getline`** / **`cin >> s`** is the usual I/O pattern; watch **leading/trailing spaces** in problem statements.
- **`s += c`** / **`push_back`** in a loop: call **`s.reserve(total_len)`** when final length is known (e.g. building answer) to avoid repeated reallocations.
- For **read-only** slices of literals or `string` parameters, **`std::string_view`** (C++17) avoids copies—pair with care about **lifetime** (don’t view temporaries).

---

## 14. `std::bitset`

**Header:** `<bitset>`

### Description

Fixed-size sequence of `N` bits, where `N` is a **compile-time constant**. Useful for compact flags, subsets of a small universe, and bitwise logic—not a dynamic growable bit vector (for that, consider `vector<bool>` or a dedicated bit-vector library).

### Internal implementation

- Typically packed into words (`unsigned long` or similar); exact layout is implementation-defined.

### Memory management

- **`N` bits fixed at compile time**, stored **in-object** (typically a few words); **no** runtime growth or heap for the bits themselves.

### Key APIs

```cpp
std::bitset<16> b;              // 16 bits, all zero by default
std::bitset<8> b2("1010");      // Construct from '0'/'1' character string

b.set();                        // Set every bit to 1
b.set(pos);                     // Set bit at pos to 1
b.set(pos, val);                // Set bit at pos to val (0 or 1)
b.reset();                      // Clear all bits to 0
b.reset(pos);                   // Clear bit at pos
b.flip();                       // Toggle all bits
b.flip(pos);                    // Toggle bit at pos
b.test(pos);                    // Read bit as bool (throws if pos out of range)
b[pos];                         // Reference to bit at pos (no range check)

b.count();                      // Number of bits set to 1
b.size();                       // Template width N
b.any();                        // true if any bit is 1
b.none();                       // true if all bits are 0
b.all();                        // C++20+: true if all bits are 1

b.to_string();                  // std::string of '0' and '1' characters
b.to_ulong();                   // Convert to unsigned long (throws overflow_error)
b.to_ullong();                  // Convert to unsigned long long (throws overflow_error)

b &= c;                         // Bitwise AND with bitset c (same size)
b |= c;                         // Bitwise OR assign
b ^= c;                         // Bitwise XOR assign
b <<= n;                        // Left-shift fill with 0
b >>= n;                        // Right-shift
b == c;                         // true if all bits equal
b != c;                         // true if any bit differs
```

### Iteration

- **Walk all bits:** index `0 … size()-1` with `test` or `operator[]`, or iterate the characters of `to_string()` (allocates a `std::string`). No standard `begin`/`end` for the bits in typical C++17/20.
- **Iteration-related members:** `size`, `test`, `operator[]`, `to_string`.
- **Single-bit access:** read with `test` / `operator[]`; write with `set` / `reset` / `flip` at an index; whole-bitset queries: `count`, `any`, `none`, `all` (C++20).

### Complexity

- **Single-bit `set` / `reset` / `flip` / `test` / `[]`:** O(1)
- **Whole-bitset ops (`count`, `<<`, `&`, etc.):** O(N / word_size)—effectively O(N) in number of bits for complexity class

### Competitive programming tips

- Use for **small N** subset DP / bitmask DP where **`N ≤ 64`** (or your fixed template `N`); bitwise ops are **very fast**.
- **`b._Find_next(i)`** (libstdc++ extension) speeds “iterate set bits”—**not portable**; on strict portability use index loop or carry your own bit tricks.
- **`vector<unsigned long long>`** (manual blocks) if you need **runtime-sized** bitsets beyond fixed `N`.

---

## 15. Iteration patterns

### Overview

How you walk elements depends on the container: most support **range-based `for`** and **`begin` / `end`**; adapters use **`top`/`pop`** or **`front`/`pop`**. See **`### Iteration`** in **§1–§14** for **walk all elements**, **iteration members**, and **single-element / lookup** APIs per type.

### Sequence containers (`array`, `vector`, `deque`, `string`)

Random-access sequences support **index loops**, **iterators**, and **range-for**.

```cpp
std::vector<int> v = {1, 2, 3};

// Range-based for (read-only)
for (const int& x : v) { /* use x */ }

// Index loop (needs random access: array, vector, deque, string)
for (std::size_t i = 0; i < v.size(); ++i) { /* use v[i] */ }

// Classic iterators
for (auto it = v.begin(); it != v.end(); ++it) { /* use *it */ }
for (auto it = v.cbegin(); it != v.cend(); ++it) { /* const view */ }
```

### `std::list`

Bidirectional iterators: range-for and two-way iterator loops; **no** `operator[]`.

```cpp
std::list<int> lst = {1, 2, 3};

for (const int& x : lst) { /* use x */ }

for (auto it = lst.begin(); it != lst.end(); ++it) { /* forward */ }
for (auto it = lst.rbegin(); it != lst.rend(); ++it) { /* reverse */ }
```

### `std::forward_list`

Forward-only: range-for walks front to back. Insert/erase often uses **`before_begin()`** with **`insert_after` / `erase_after`** (not shown below).

```cpp
std::forward_list<int> fl = {1, 2, 3};

for (const int& x : fl) { /* use x */ }

for (auto it = fl.begin(); it != fl.end(); ++it) { /* only ++it, no --it */ }
```

### `std::set`, `std::multiset`, `std::unordered_set`, `std::unordered_multiset`

Each element is a **key** (const in ordered sets). Range-for visits elements in **sorted** order for ordered sets, **unspecified** order for unordered sets.

```cpp
std::set<int> s = {3, 1, 2};
for (const int& k : s) { /* k is 1, 2, 3 */ }

std::unordered_set<int> us = {3, 1, 2};
for (const int& k : us) { /* order not guaranteed */ }
```

### `std::map`, `std::multimap`, `std::unordered_map`, `std::unordered_multimap`

Each entry is a **`std::pair<const Key, T>`** (or `const Key` / `T` references via structured bindings).

```cpp
std::map<int, std::string> m = {{1, "a"}, {2, "b"}};

for (const auto& p : m) { /* p.first, p.second */ }

for (const auto& [k, val] : m) { /* C++17 structured binding */ }

for (auto it = m.begin(); it != m.end(); ++it) {
    // it->first is key, it->second is value
}
```

### `std::bitset`

`std::bitset` has **no** `begin()` / `end()` in the standard library (so **no** range-based `for` over bits). Use an **index loop** or walk a **`to_string()`** result (extra allocation).

```cpp
std::bitset<8> b("00001111");

for (std::size_t i = 0; i < b.size(); ++i) {
    bool bit = b[i];      // proxy converts to bool; b.test(i) is bounds-checked
    (void)bit;
}

for (char ch : b.to_string()) { // '0' or '1'; allocates a new string
    (void)ch;
}
```

### Adapters (`stack`, `queue`, `priority_queue`)

Adapters **do not** expose iterators or range-for over all elements. Typical approach: **`top`/`front` + `pop`** in a loop until empty (each `pop` removes an element). To walk without consuming, use a different structure or a copy of the adapter’s state.

```cpp
std::stack<int> st;        // Empty stack

st.push(1);                // Bottom of logical stack
st.push(2);                // Top

while (!st.empty()) {     // Drain from top to bottom
    int x = st.top();      // Inspect top element
    st.pop();              // Remove top (returns void)
    (void)x;               // Process x
}
```

Same **`while (!q.empty()) { ... front(); pop(); }`** pattern for `std::queue`:

```cpp
std::queue<int> q;
q.push(1);
q.push(2);

while (!q.empty()) {
    int x = q.front();      // Next to leave the queue
    q.pop();                // Remove front (void)
    (void)x;
}
```

For **`std::priority_queue`**, use **`top()`** then **`pop()`** like the stack example (highest priority at `top()` for the default max-heap).

### Competitive programming tips

- Prefer **range-based `for`** over index loops when you don’t need the index—less boilerplate, fewer off-by-one bugs.
- On maps, **`for (const auto& [k, v] : mp)`** (C++17) is concise; use **`const auto&`** when not mutating entries.
- **Do not** drain **`stack` / `queue` / `priority_queue`** by popping unless you mean to **consume** them; take a **copy** or redesign if you need two passes.
