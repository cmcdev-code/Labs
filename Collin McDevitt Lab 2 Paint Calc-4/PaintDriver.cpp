#include "Room.h"
#include <iostream>

int main() {
    std::cout << "Collin McDevitt Lab 2 CSCN 112 \n";

    room user;

    while (user.getWantsRoomsPainted())//will keep looping till they enter -1
    {
        user.setAndCallUserInput();
    }

    system("pause");
    return 0;
}