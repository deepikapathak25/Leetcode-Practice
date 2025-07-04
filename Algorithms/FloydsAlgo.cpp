    🚀 Floyd’s Cycle Detection Algorithm
    ------------------------------------
    📘 Problem:
    Detect if a linked list or sequence has a cycle, and find the starting point of the cycle (if any).

    📘 Why Floyd’s?
    - Uses two pointers moving at different speeds (slow & fast).
    - Time: O(n)
    - Space: O(1)

    📘 Steps:
    1️⃣ Phase 1: Detect Cycle
        - Initialize two pointers slow and fast at head.
        - Move slow by 1 step, fast by 2 steps.
        - If slow == fast, a cycle exists. If fast reaches NULL, no cycle.

    2️⃣ Phase 2: Find Start of Cycle
        - Reset slow to head.
        - Move both slow and fast one step at a time.
        - The point they meet is the start of the cycle.

    ✅ Works because fast laps slow by a multiple of the cycle length.

    📘 Application:
    - Detect loop in linked list.
    - Detect duplicate number in array (treated as linked list).

    ----------------------------------------------------------------

    🚀 Two Pointer Approach
    -----------------------
    📘 Problem:
    Many array and linked list problems can be solved using two pointers.

    📘 Common Patterns:
    1️⃣ Opposite ends:
        - Used in sorted arrays to find pairs, reverse arrays, etc.
        - Example: check if array is palindrome.
        - Move left and right pointers toward each other.

    2️⃣ Fast & slow:
        - Used to find mid-point, detect cycles, etc.

    📘 Advantages:
    - Saves space by not creating copies.
    - Time: usually O(n)
    - Space: O(1)

    ----------------------------------------------------------------
