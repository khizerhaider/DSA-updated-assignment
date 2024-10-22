#include "node.h"

// Constructor implementation
Node::Node(const char* songName) {
    // Manually copy the song name from the input parameter to the song array
    // The loop runs until the song array is filled or the end of the song name is reached
    for (int i = 0; i < 50 && songName[i] != '\0'; ++i) {
        song[i] = songName[i];  // Copy each character individually
    }
    // Ensure the song array is null-terminated in case the songName is too long
    // This prevents reading beyond the end of the array
    //song[49] = '\0';  // Set the last element to null
    prev = nullptr;  // Initialize the previous node to null
    next = nullptr;  // Initialize the next node to null
}

// Setter for the previous node
void Node::setPrev(Node* Prev) {
    // Assign the provided node pointer to the 'prev' member
    prev = Prev;
}

// Setter for the next node
void Node::setNext(Node* Next) {
    // Assign the provided node pointer to the 'next' member
    next = Next;
}

// Setter for the song name
void Node::setSong(const char* Song) {
    // Manually copy the song name to the song array
    // The loop stops when either the end of the Song array or the 50th character is reached
    for (int i = 0; i < 50 && Song[i] != '\0'; ++i) {
        song[i] = Song[i];  // Copy each character individually
    }
    // Ensure the song array is null-terminated
    //song[49] = '\0';  // Set the last element to null
}

// Getter for the next node
Node* Node::getNext() {
    // Return the pointer to the next node
    return next;
}

// Getter for the previous node
Node* Node::getPrev() {
    // Return the pointer to the previous node
    return prev;
}

// Getter for the song name
const char* Node::getSong() const {
    // Return a constant pointer to the song array
    // The 'const' keyword ensures the array content cannot be modified by the caller
    return song;
}
