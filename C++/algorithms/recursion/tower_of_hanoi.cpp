/**
 * Tower of Hanoi (Recursive)
 * 
 * Tower of Hanoi is a mathematical puzzle where we have three rods and n disks.
 * The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
 *      1) Only one disk can be moved at a time.
 *      2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack
 *          i.e. a disk can only be moved if it is the uppermost disk on a stack.
 *      3) No disk may be placed on top of a smaller disk.
 * 
 * Complexity
 *      Time: 
 *          Worst Case: 2^N
 *      Space: O(N)
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// Function to solve Tower of Hanoi
void tower_of_hanoi(int disks, char from_rod, char to_rod, char aux_rod) {
    
    // Base condition
    if(disks == 1) {
        cout << "Disk 1 moved from " << from_rod << " to " << to_rod << endl;
        return;
    }

    // shift n-1 disks from from_rod to aux_rod
    tower_of_hanoi(disks - 1, from_rod, aux_rod, to_rod);

    cout << "Disk " << disks << " moved from " << from_rod << " to " << to_rod << endl;

    // shift n-1 from aux_rod to to_rod
    tower_of_hanoi(disks - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int number_of_disks = 4;
    // A, B and C are name of rods
    tower_of_hanoi(number_of_disks, 'A', 'C', 'B');
    return 0;
}