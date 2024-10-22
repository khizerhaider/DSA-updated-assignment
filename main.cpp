#include <iostream>
#include "linkedlist.h"

using namespace std;

int main() {
    LinkedList playlist;
    int choice;
    char input[50];
    char target[50];
    Node* currentSong = nullptr; // Pointer to keep track of the current song

    // Menu-driven structure with a while loop for the playlist
    while (true) {
        // Display menu options
        cout << "\n--- Songs Playlist Menu ---\n";
        cout << "1. Add a song\n";
        cout << "2. Remove a song\n";
        cout << "3. Display playlist\n";
        cout << "4. Display playlist in reverse\n";
        cout << "5. Insert a song after a specific song\n";
        cout << "6. Search for a song\n";
        cout << "7. Play Next Song\n";
        cout << "8. Play Previous Song\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform the selected operation
        switch (choice) {
            case 1: // Add a song
                cout << "Enter the song name (up to 50 characters): ";
                cin.ignore(); // Clear input buffer
                cin.getline(input, 50); // Taking char array as input
                playlist.addSong(input);
                cout << "Song added: " << input << endl;
                break;

            case 2: // Remove a song
                cout << "Enter the song name to remove: ";
                cin.ignore(); // Clear input buffer
                cin.getline(input, 50); // Taking char array as input
                playlist.removeSong(input);
                break;

            case 3: // Display the playlist
                cout << "\nCurrent Playlist:\n";
                playlist.displayPlaylist();
                break;

            case 4: // Display the playlist in reverse
                cout << "\nPlaylist in Reverse Order:\n";
                playlist.displayreversedlist();
                break;

            case 5: // Insert a song after a specific song
                cout << "Enter the name of the existing song: ";
                cin.ignore(); // Clear input buffer
                cin.getline(target, 50); // Taking target song as input
                cout << "Enter the new song name to insert: ";
                cin.getline(input, 50); // Taking new song name as input
                playlist.insertAfter(target, input);
                break;

            case 6: // Search for a song
                cout << "Enter the song name to search for: ";
                cin.ignore(); // Clear input buffer
                cin.getline(input, 50); // Taking char array as input
                if (playlist.searchSong(input)) {
                    cout << "Song found: " << input << endl;
                } else {
                    cout << "Song not found: " << input << endl;
                }
                break;

            case 7: // Play next song
                if (playlist.curpoint == nullptr) {
                    cout << "No current song. Please start with a song!" << endl;
                } else {
                    
                        playlist.getNextsong();
                        cout << "Playing next song: " << playlist.curpoint->getSong() << endl;
                  
                }
                break;

            case 8: // Play previous song
                if (playlist.curpoint == nullptr) {
                    cout << "No current song. Please start with a song!" << endl;
                } else {
                    
            
                    playlist.getPrevsong();
                    cout << "Playing previous song: " << playlist.curpoint->getSong() << endl;
                    
                }
                break;

            case 9: // Exit the program
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;

            default: // Invalid choice
                cout << "Invalid choice! Please select an option from the menu." << endl;
        }
    }

    return 0;
}
