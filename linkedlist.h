#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

class LinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    
    LinkedList();   // Constructor
    ~LinkedList();  // Destructor
    Node* curpoint ;
    Node* getNextsong(); // Get the next song
    Node* getPrevsong(); // Get the previous song
    void addSong(const char* songName);  // Add song to the list
    void removeSong(const char* songName);  // Remove song by name
    void displayPlaylist() const;  // Display all songs in the list
    void displayreversedlist() const;
    void insertAfter(const char* targetSong, const char* newSong);
    bool compareStrings(const char* str1, const char* str2) const ;
    bool searchSong(const char* songName) ; // Search for a song
    
    
};

#endif // LINKEDLIST_H
