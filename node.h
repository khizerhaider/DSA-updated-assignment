#ifndef NODE_H
#define NODE_H

class Node {
private:  // Private members
    Node* prev;  // Pointer to the previous node
    Node* next;  // Pointer to the next node
    char song[50];  // Array to store the song name

public:  // Public members
    Node(const char* songName);  // Constructor
    void setPrev(Node* Prev);  // Setter for the previous node
    void setNext(Node* Next);  // Setter for the next node
    void setSong(const char* Song);  // Setter for the song name
    Node* getNext();  // Getter for the next node
    Node* getPrev();  // Getter for the previous node
    const char* getSong() const;  // Getter for the song name
};

#endif // NODE_H
