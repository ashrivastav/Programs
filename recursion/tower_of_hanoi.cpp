#include <iostream>
using namespace std;


void tower_of_hanoi(int disks, char from_peg, char to_peg, char aux_peg)
{
    if(disks == 1) {
        cout << "Move peg from " << from_peg << " to peg " << to_peg << endl;
        return;
    }

    tower_of_hanoi(disks -1, from_peg, aux_peg, to_peg);
    cout << "Move peg from " << from_peg << " to peg " << to_peg << endl;
    tower_of_hanoi(disks -1, aux_peg, to_peg, from_peg);
}

int main()
{
    int disks;
    cout << "Enter the number of disks to transfer : " ;
    cin >> disks;
    tower_of_hanoi(disks, 'A','B','C');
}
