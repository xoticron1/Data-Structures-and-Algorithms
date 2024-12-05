//Personal KPOP Album Collection Management System (Title, Artist, Release Year, Genre)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Album {
    string title;
    string artist;
    int releaseYear;
    string genre;
};

void addAlbum(vector<Album>& collection);
void displayAlbums(const vector<Album>& collection);
void updateAlbum(vector<Album>& collection, int index);
void deleteAlbum(vector<Album>& collection, int index);

int main() {
    vector<Album> albumCollection;
    int choice, index;

    do {
        cout << "\n--- K-pop Album Collection ---\n";
        cout << "1. Add Album\n";
        cout << "2. Display All Albums\n";
        cout << "3. Update Album\n";
        cout << "4. Delete Album\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                addAlbum(albumCollection);
                break;
            case 2:
                displayAlbums(albumCollection);
                break;
            case 3:
                cout << "Enter the album index to update: ";
                cin >> index;
                cin.ignore();
                updateAlbum(albumCollection, index - 1); 
                break;
            case 4:
                cout << "Enter the album index to delete: ";
                cin >> index;
                cin.ignore();
                deleteAlbum(albumCollection, index - 1); 
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}

void addAlbum(vector<Album>& collection) {
    Album newAlbum;
    cout << "Enter album title: ";
    getline(cin, newAlbum.title);
    cout << "Enter artist: ";
    getline(cin, newAlbum.artist);
    cout << "Enter release year: ";
    cin >> newAlbum.releaseYear;
    cin.ignore(); 
    cout << "Enter genre: ";
    getline(cin, newAlbum.genre);

    collection.push_back(newAlbum);
    cout << "Album added successfully!" << endl;
}

void displayAlbums(const vector<Album>& collection) {
    if (collection.empty()) {
        cout << "No albums in the collection." << endl;
        return;
    }

    for (size_t i = 0; i < collection.size(); i++) {
        cout << "Album " << i + 1 << ":" << endl;
        cout << "Title: " << collection[i].title << endl;
        cout << "Artist: " << collection[i].artist << endl;
        cout << "Release Year: " << collection[i].releaseYear << endl;
        cout << "Genre: " << collection[i].genre << endl;
        cout << "-------------------------" << endl;
    }
}

void updateAlbum(vector<Album>& collection, int index) {
    if (index < 0 || index >= collection.size()) {
        cout << "Invalid index!" << endl;
        return;
    }

    Album& albumToUpdate = collection[index];
    cout << "Enter new album title (current: " << albumToUpdate.title << "): ";
    getline(cin, albumToUpdate.title);
    cout << "Enter new artist (current: " << albumToUpdate.artist << "): ";
    getline(cin, albumToUpdate.artist);
    cout << "Enter new release year (current: " << albumToUpdate.releaseYear << "): ";
    cin >> albumToUpdate.releaseYear;
    cin.ignore();
    cout << "Enter new genre (current: " << albumToUpdate.genre << "): ";
    getline(cin, albumToUpdate.genre);

    cout << "Album updated successfully!" << endl;
}

void deleteAlbum(vector<Album>& collection, int index) {
    if (index < 0 || index >= collection.size()) {
        cout << "Invalid index!" << endl;
        return;
    }

    collection.erase(collection.begin() + index);
    cout << "Album deleted successfully!" << endl;
}