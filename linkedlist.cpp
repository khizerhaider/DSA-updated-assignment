#include "linkedlist.h"
#include<iostream>
using namespace std;
// Constructor
LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    curpoint = nullptr;
}
// Destructor
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->getNext(); // Use getter
        delete current;
        current = nextNode;
    }
}

// Add a new song to the end of the playlist
void LinkedList::addSong(const char* songName) {
    Node* newNode = new Node(songName);

    if (head == nullptr) {
        // The list is empty
        head = newNode;
        tail = newNode;
    } else {
        // Append to the list
        tail->setNext(newNode); // Use setter
        newNode->setPrev(tail); // Use setter
        tail = newNode;
    }
}

// Helper function to manually compare two strings
bool LinkedList::compareStrings(const char* str1, const char* str2) const {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    // Check if both strings ended simultaneously
    return (str1[i] == '\0' && str2[i] == '\0');
}

// Remove a song by its name without using strcmp
void LinkedList::removeSong(const char* songName) {
    Node* current = head;

    while (current != nullptr) {
        if (compareStrings(current->getSong(), songName)) {
            // Match found, remove the node
            if (current == head) {
                head = current->getNext();
                if (head != nullptr) {
                    head->setPrev(nullptr);
                }
            } else if (current == tail) {
                tail = current->getPrev();
                if (tail != nullptr) {
                    tail->setNext(nullptr);
                }
            } else {
                current->getPrev()->setNext(current->getNext()); // Use getters
                current->getNext()->setPrev(current->getPrev()); // Use getters
            }

            delete current;
            cout << "Removed string: " << songName << endl;
            return;
        }
        current = current->getNext(); // Use getter
    }

    cout << "string not found: " << songName << endl;
}

// Display all songs in the playlist
void LinkedList::displayPlaylist() const {
    Node* current = head;
    cout<<endl;
    if (current == nullptr) {
        cout << "The playlist is empty!" << endl;
        return;
    }

    while (current != nullptr) {
        cout << current->getSong() << "->"; // Use getter
        current = current->getNext(); // Use getter
    }
}
void LinkedList::displayreversedlist() const {
    Node* current = tail; // Start from the tail

    if (current == nullptr) {
        cout << "The playlist is empty!" << endl;
        return;
    }

    while (current != nullptr) {
        cout << current->getSong(); // Use getter
        if (current->getPrev() != nullptr) {
            cout << " -> "; // Only print the arrow if there is a previous node
        }
        current = current->getPrev(); // Move to the previous node
    }
    cout << endl; // End the line after displaying all songs
}

// Insert a new song after a specific node by song name
void LinkedList::insertAfter(const char* targetSong, const char* newSong) {
    Node* current = head;

    // Traverse the list to find the target song
    while (current != nullptr) {
        if (compareStrings(current->getSong(), targetSong)) {
            // Match found, insert new node after the current node
            Node* newNode = new Node(newSong);
            newNode->setNext(current->getNext()); // Use setter to set the next node
            newNode->setPrev(current); // Link the new node to the current node
            
            if (current->getNext() != nullptr) {
                current->getNext()->setPrev(newNode); // Update the next node's previous pointer
            } else {
                tail = newNode; // Update tail if we are at the end
            }
            
            current->setNext(newNode); // Link current node to the new node
            cout << "Inserted string: " << newSong << " after " << targetSong << endl;
            return;
        }
        current = current->getNext(); // Use getter to move to the next node
    }

    cout << "Song not found: " << targetSong << endl; // If target song not found
}
// linkedlist.cpp

// Check if a song exists in the playlist
bool LinkedList::searchSong(const char* songName) {
    Node* current = head;
    while (current != nullptr) {
        if (compareStrings(current->getSong(), songName)) {
            curpoint = current;
            return true; // Song found
        }
        current = current->getNext(); // Use getter
    }
    return false; // Song not found
}

// Get the next song
Node* LinkedList::getNextsong() {
    curpoint = curpoint->getNext(); // Use getter
    return curpoint;
}

// Get the previous song
Node* LinkedList::getPrevsong() {
    curpoint = curpoint->getPrev(); // Use getter
    return  curpoint;
}

