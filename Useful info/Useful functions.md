## Strings
* strlen(const char* str) [return length of the string without '\0']
* strcmp(const char* f, const char* s) [return 0 if are equal; <0 if f is less than s; >0 if f is greater than s]
* strcpy(char* to,  const char* from)
* strcat(char* start, const char* end) [concats "end" to the "start"]
* long strtol(const char *restrict nptr, char **restrict endptr, int base); [restrict nptr = string with written value; restrict endptr = need to be 0 to read till '\0'; base = means the base of value in str, whether is in binary(2), hex(16), octal(8) or decimal format(10)]
* strtok(char* str, char* delim) [gives next piece of string until the "delim"]
```c++
  char* test = "Some text"; 
  cout << strtok(test, " ") << '\n';
  // Output 1: "Some"
  cout << strtok(NULL, " ") << '\n'; 
  // Output 2: "text"
  // "NULL" means that we continue with prev string
```

## Iterators
* min_element(iterator to begin, iterator to end) [returns iterator to the min element; can be de-referenced with "*"]
* max_element(iterator to begin, iterator to end) [returns iterator to the max element; can be de-referenced with "*"]
-> int maxVal = *max_element(arr, arr + size);
* upper_bound(iterator begin, iterator end, initial value) [returns an iterator to the first element bigger than "initial value" or iterator after end of array/collection if not found]
* upper_bound(iterator begin, iterator end, initial value) [returns an iterator to the first element not less than "initial value". If  "initial value" is less than minimal value in array/collection, than index to the first element is returned or 0 index after dereferencing. If "initial value" is bigger than biggest value in array/collection, than iterator after end of array/collection if not found]
* binary_search(iter begin, iter end, value) [works exactly like binary search. Only with sorted collections]
* advance(iterator, positions to move from current place) [change current iterator pasted in parameters]
* next(iterator, positions to move from current place) [returns new iterator with changed position]

## Formatting
* fixed [fix precision that will be stated next to it in cout statement]
* setprecision(decimal digits after after dot for double)
```c++
cout << fixed << setprecision(2) << pi ; 
// Output: 3.14
```

## Other
* is_sorted(begin, end, lambda to compare) [function that determines, whether the array is sorted according to the stated lambda function order or is not]
```c++
is_sorted(arr, arr + size, [](int f, int s) {return f > s;})
```
