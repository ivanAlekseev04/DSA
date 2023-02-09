# Sorting algorithms

###### **Adaptive** - can have different performance with fully sorted and partially sorted.
###### **In-place** - doesn’t need additional space.

## Bubble sort *(N^2)*
```
- Stable 
- Adaptive 
- Small sizes
- In-place
```

## Selection sort *(N^2)*
```
- May be stable 
- Best complexity is N^2 
- Small sizes 
- Not adaptive 
- Problems with duplicates 
- In-place
```

## Insertion sort *(N^2)*
```
- Adaptive 
- In-place 
- Reverse order -> max time; already sorted -> min time 
- Stable 
- In-place
```

## Counting sort *(N + K)*
```
- Not in-place
- Works only with positive values [0, 1e6]
- May be stable
```

## Merge sort *(NLogN)*
```
- Stable by default
- For large size (fast)/small size (not so as other algorithms)
- Not in-place
- Not adaptive 
- Can be paralleled
```

## Quick sort *(N^2)*
```
- “Divide & conquer” algorithm
- Worst case 1 (picking min/max element as a pivot)
- Worst case 2 (array is already sorted in increasing/decreasing order)
- May be stable
- In-place 
- Stable 
- Large data sets/ not good for small sizes 
```
