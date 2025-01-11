# Circular Queue Implementation

## Overview

This program demonstrates a Circular Queue data structure implementation in C. The Circular Queue is a linear data structure that follows the FIFO (First In, First Out) principle, but with the added benefit of utilizing unused spaces in the queue efficiently. This implementation includes basic queue operations like insertion, deletion, and display.

---

## Features

1. **Circular Queue Structure**:
   - The queue wraps around itself when the rear reaches the end, utilizing the unused space at the front.
   
2. **Queue Operations**:
   - **Insert**: Adds elements to the queue.
   - **Delete**: Removes elements from the queue.
   - **Display**: Shows the current state of the queue.
   
3. **Overflow and Underflow Handling**:
   - **Overflow**: The queue cannot accept more elements when it is full.
   - **Underflow**: The queue cannot delete elements when it is empty.

4. **Efficient Memory Usage**:
   - By implementing a circular structure, unused space in the queue is recycled.

---

## How It Works

1. **Input**:  
   - A sequence of colors is inserted into the queue, simulating a scenario like handling traffic lights or any other cyclic processes.

2. **Operations**:
   - **Insert Operation**: Elements are added to the rear of the queue.
   - **Delete Operation**: Elements are removed from the front of the queue.
   - The circular nature of the queue allows for efficient usage of available space.

3. **Output**:  
   - The queue's current state is displayed after each operation.

---

## Example

### Sample Input:
```c
const char* colors = "VIBGOYR";
```

### Sample Execution:
```bash
gcc circular_queue.c -o circular_queue
./circular_queue
```

### Sample Output:
```
Inserted V.
Queue: V

Inserted I.
Queue: V I

Inserted B.
Queue: V I B

Inserted G.
Queue: V I B G

Inserted O.
Queue: V I B G O

Inserted Y.
Queue: V I B G O Y

Inserted R.
Queue: V I B G O Y R

Overflow! Cannot insert V.
Queue: V I B G O Y R

Deleted V.
Queue: I B G O Y R

Deleted I.
Queue: B G O Y R
```

---

## Program Flow

1. **Queue Initialization**:
   - The queue is initialized with a fixed size (`MAX`) and a front (`f`) and rear (`r`) pointer.

2. **Insert Operation**:
   - Elements are inserted into the queue at the rear. If the queue is full, an overflow message is displayed.

3. **Delete Operation**:
   - Elements are deleted from the front. If the queue is empty, an underflow message is displayed.

4. **Display**:
   - The current contents of the queue are displayed from front to rear.

---

## Compilation and Execution

### Steps to Compile and Run:
1. Save the program in a file named `circular_queue.c`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program using:
   ```bash
   gcc circular_queue.c -o circular_queue
   ```
4. Run the program:
   ```bash
   ./circular_queue
   ```

---

## Limitations

1. **Fixed Size**:
   - The queue size is fixed at `MAX`. You can modify the `MAX` value to change the size of the queue.

2. **No Dynamic Resizing**:
   - The program does not support resizing the queue dynamically once it is full or empty.

---
