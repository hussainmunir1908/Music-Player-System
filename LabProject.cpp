#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

struct song {
    int number;
    string title;
    string artist_name;
    float duration = 0;
    string genre;
};

struct BSTNode {
    song data;
    BSTNode* left;
    BSTNode* right;
};

struct Node {
    song data;
    Node* next;
};

//Initialise Song Library
Node* createSongLibrary() {
    song songs[] = {
        {1, "Levitating", "Dua Lipa", 3.23, "Pop"},
        {2, "Shape of You", "Ed Sheeran", 3.54, "Pop"},
        {3, "Tera Ban Jaunga", "Akhil Sachdeva", 3.56, "Romantic"},
        {4, "Tum Hi Ho", "Arijit Singh", 4.22, "Romantic"},
        {5, "Shallow", "Lady Gaga & Bradley Cooper", 3.58, "Pop"},
        {6, "Blinding Lights", "The Weeknd", 3.20, "Pop"},
        {7, "Raabta", "Arijit Singh", 4.12, "Romantic"},
        {8, "Despacito", "Luis Fonsi", 3.47, "Pop"},
        {9, "Afreen Afreen", "Nusrat Fateh Ali Khan", 6.23, "Classical"},
        {10, "Dil Dhadakne Do", "Farhan Akhtar", 4.35, "Dance"},
        {11, "See You Again", "Wiz Khalifa", 3.50, "Pop"},
        {12, "Naatu Naatu", "Rahul Sipligunj & Kaala Bhairava", 3.42, "Dance"},
        {13, "Chaiyya Chaiyya", "Sukhwinder Singh", 6.52, "Dance"},
        {14, "Hawayein", "Arijit Singh", 4.50, "Romantic"},
        {15, "Senorita", "Farhan Akhtar, Hrithik Roshan", 3.40, "Dance"},
        {16, "Shape of You", "Ed Sheeran", 3.54, "Pop"},
        {17, "Zaroorat", "Mustafa Zahid", 3.55, "Romantic"},
        {18, "Tajdar-e-Haram", "Atif Aslam", 5.40, "Classical"},
        {19, "Rolling in the Deep", "Adele", 3.48, "Pop"},
        {20, "Pasoori", "Ali Sethi", 4.02, "Pop"},
    };

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < 20; i++) {
        Node* newNode = new Node;
        newNode->data = songs[i];
        newNode->next = NULL;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Display song library
void displayLibrary(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        cout << "Song Number: " << current->data.number << endl;
        cout << "Title: " << current->data.title << endl;
        cout << "Artist: " << current->data.artist_name << endl;
        cout << "Duration: " << current->data.duration << " minutes" << endl;
        cout << "Genre: " << current->data.genre << endl;
        cout << "-----------------------------" << endl;
        current = current->next;
    }
}

class Playlist {
private:
    Node* head;

public:
    string name;

    Playlist() {
        head = NULL; // Initialize playlist as empty
    }

    void setname(string s) {
        name = s;
    }

    void addNode(Node*& library, string choice) {
        Node* newNode = new Node;
        newNode->next = nullptr;

        Node* temp = library; //temp variable to traverse the library
        while (temp != nullptr) {
            if (temp->data.title == choice) {
                newNode->data = temp->data; // Copy song data
                break;
            }
            temp = temp->next;
        }

        if (head == nullptr) {
            head = newNode; // Set as head if playlist is empty
        }
        else {
            Node* temp2 = head;
            while (temp2->next != nullptr) {
                temp2 = temp2->next; // Traverse to the end of the playlist
            }
            temp2->next = newNode; // Append to the end
        }
    }

    void addSong(Node*& library) {
        cin.ignore();
        displayLibrary(library);
        string choice;
        cout << "Please write the title of the song you wish to select: " << endl;
        getline(cin, choice);
        addNode(library, choice);
    }

    void printPlaylist() {
        if (head == NULL) {
            cout << "The playlist is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "Playlist:" << endl;
        int numb = 1;

        while (temp != NULL) {
            cout << "Number " << numb << ": ";
            cout << "Title: " << temp->data.title << endl;
            cout << "Artist: " << temp->data.artist_name << endl;
            cout << "Duration: " << temp->data.duration << " minutes" << endl;
            cout << "Genre: " << temp->data.genre << endl;
            cout << "-----------------------" << endl;

            temp = temp->next;
            numb++;
        }
    }

    void removeSong_Playlist() {
        if (head == NULL) { // Check if playlist is empty
            cout << "Playlist is empty!" << endl;
            return;
        }

        printPlaylist();
        cout << endl;
        cin.ignore();

        string choice;
        cout << "Enter the title of the song you wish to remove: ";
        getline(cin, choice);

        

        Node* temp = head; //temp variable to traverse the playlist

        if (head->data.title == choice) { // if the song to delete is the first song
            Node* temp2 = head;
            head = head->next;
            delete temp2;
            cout << "Song Removed!" << endl;
            return;
        }

        while (temp != NULL && temp->next != NULL) {
            if (temp->next->data.title == choice) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                cout << "Song Removed!" << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Song not found!" << endl;
    }

    Node* recommend(Node*& library) {
        if (head == NULL) {
            cout << "Playlist Empty!" << endl;
            return NULL;
        }
        int pop = 0, romantic = 0, dance = 0, classical = 0; // Genre counters
        Node* temp = head;

        // Count the genres in the playlist
        while (temp != nullptr) {
            if (temp->data.genre == "Pop") pop++;
            else if (temp->data.genre == "Romantic") romantic++;
            else if (temp->data.genre == "Dance") dance++;
            else if (temp->data.genre == "Classical") classical++;
            temp = temp->next;
        }

        // Determine the user's interest
        string interest;
        if (pop >= romantic && pop >= dance && pop >= classical) interest = "Pop";
        else if (romantic >= pop && romantic >= dance && romantic >= classical) interest = "Romantic";
        else if (dance >= pop && dance >= romantic && dance >= classical) interest = "Dance";
        else if (classical >= pop && classical >= dance && classical >= romantic) interest = "Classical";

        // Create a new list of recommended songs
        Node* newList = nullptr;
        Node* newListTail = nullptr;

        Node* temp2 = library;

        while (temp2 != nullptr) {
            if (temp2->data.genre == interest) {
                // Create a new node for the recommendation list
                Node* newNode = new Node;
                newNode->data = temp2->data;
                newNode->next = nullptr;

                if (newList == nullptr) {
                    newList = newNode; // Initialize the new list
                    newListTail = newNode;
                }
                else {
                    newListTail->next = newNode; // Append to the list
                    newListTail = newNode;
                }
            }

            temp2 = temp2->next;
        }

        return newList;
    }

    void fetchRecommend(Node*& list, Node* library) {
        if (list == nullptr) {
            cout << "No more recommendations available!" << endl;
            return;
        }

        // Keep track of whether a song was added
        bool songAdded = false;

        while (list != nullptr) {
            cout << "Recommended song: " << list->data.title << endl;
            cout << "Based on genre: " << list->data.genre << endl;

            string choice;
            cout << "Would you like to add this song to the playlist? (Yes/No) " << endl;
            cin >> choice;

            if (choice == "No") {
                // Move to the next song without adding it
                list = list->next;
            }
            else if (choice == "Yes") {
                // Add the song to the playlist
                addNode(library, list->data.title);
                songAdded = true;
                // Move to the next song after adding the current one
                list = list->next;
            }

            // If a song was added, exit the loop to prevent multiple additions
            if (songAdded) {
                break;
            }
        }
    }




};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(song newSong) {
        Node* newNode = new Node;
        newNode->data = newSong;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;  // Free the memory of the dequeued song
    }

    bool isEmpty() {
        return front == nullptr;
    }


};

class BST {
private:
    BSTNode* root;

    BSTNode* insert(BSTNode*& node, song newSong) {
        if (node == nullptr) {
            node = new BSTNode;
            node->data = newSong;
            node->left = nullptr;
            node->right = nullptr;
        }
        else if (newSong.duration < node->data.duration) {
            node->left = insert(node->left, newSong);
        }
        else {
            node->right = insert(node->right, newSong);
        }
        return node;
    }

    // Function for inorder traversal
    void inorder(BSTNode*& node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << "Title: " << node->data.title << endl;
            cout << "Artist: " << node->data.artist_name << endl;
            cout << "Duration: " << node->data.duration << " minutes" << endl;
            cout << "Genre: " << node->data.genre << endl;
            cout << "-----------------------------" << endl;
            inorder(node->right);
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(song newSong) {
        root = insert(root, newSong);
    }

    void displaySortedSongs() {
        if (root == nullptr) {
            cout << "No songs in history!" << endl;
        }
        else {
            cout << "Songs sorted by duration:" << endl;
            inorder(root);
        }
    }
};

Node* findSong(Node* library, const string& title) {
    while (library != nullptr) {
        if (library->data.title == title) {
            return library;
        }
        library = library->next;
    }
    return nullptr;
}

// Function to select and play a song
void playSong(Node*& library, Playlist& playlist, BST& history) {
    string choice;
    cout << "Would you like to select a song from the library or your playlist? (Library/Playlist): ";
    cin >> choice;
    cin.ignore();

    Node* selectedSong = nullptr;

    if (choice == "Library") {
        displayLibrary(library);
        cout << "Enter the title of the song you wish to play: ";
        string title;
        getline(cin, title);
        selectedSong = findSong(library, title);
    }
    else if (choice == "Playlist") {
        playlist.printPlaylist();
        cout << "Enter the title of the song you wish to play: ";
        string title;
        getline(cin, title);
        selectedSong = findSong(playlist.recommend(library), title);
    }

    if (selectedSong == nullptr) {
        cout << "Song not found!" << endl;
        return;
    }

    // Print currently playing song info
    system("cls");  // Clear the screen for better presentation
    cout << "Now playing:" << endl;
    cout << "-----------------------------" << endl;
    cout << "Title: " << selectedSong->data.title << endl;
    cout << "Artist: " << selectedSong->data.artist_name << endl;
    cout << "Duration: " << selectedSong->data.duration << " minutes" << endl;
    cout << "Genre: " << selectedSong->data.genre << endl;
    cout << "-----------------------------" << endl;

    // Add the song to history
    history.insert(selectedSong->data);
    cout << "Song added to history!" << endl;
    system("pause");  // Pause to allow user to read the output
}

// Function to get recommendations based on playlist genre
void getRecommendations(Node*& library, Playlist myPlaylist) {
    Node* recommended = myPlaylist.recommend(library);
    myPlaylist.fetchRecommend(recommended, library);
}

int main() {
    // Create song library
    Node* library = createSongLibrary();

    // Create playlist
    Playlist myPlaylist;
    myPlaylist.setname("My Playlist");

    // Create history tree
    BST history;

    int choice;
    do {
        system("cls");  // Clear the screen before displaying the menu
        cout << "--- Music Player ---" << endl;
        cout << "1. Add a song to playlist" << endl;
        cout << "2. Play a song" << endl;
        cout << "3. View playlist" << endl;
        cout << "4. View sorted history" << endl;
        cout << "5. Get song recommendations" << endl;
        cout << "6. Delete song from Playlsit" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            myPlaylist.addSong(library);
            break;
        case 2:
            playSong(library, myPlaylist, history);
            break;
        case 3:
            system("cls");
            myPlaylist.printPlaylist();
            system("pause");
            break;
        case 4:
            system("cls");
            history.displaySortedSongs();
            system("pause");
            break;
        case 5:
            system("cls");
            getRecommendations(library, myPlaylist);
            system("pause");
            break;
        case 6:
            system("cls");
            myPlaylist.removeSong_Playlist();
            system("pause");
            break;
        case 7:
            cout << "\nExiting..";
            break;
        }
    } while (choice != 7);

    return 0;
}
