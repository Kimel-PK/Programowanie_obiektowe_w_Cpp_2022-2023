#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template <typename T>
class Song {
	public:
	T author;
	T title;
	
	Song (T author, T title) : author(author), title(title) {
		cout << "Utworzono piosenke " << author << " - " << title << endl;
	}
	
	~Song () {
		cout << "Usunieto piosenke " << author << " - " << title << endl;
	}
};

template <typename T>
unique_ptr<Song<T>> SongFactory (T author, T title) {
	return make_unique<Song<T>>(author, title);
}

int main () {
	
	{
		auto song = SongFactory(L"Michael Jackson", L"Beat It");
	}
	
	{
		vector<unique_ptr<Song<string>>> songs;
		songs.push_back (SongFactory(string ("jeden"), string ("jeden")));
		songs.push_back (SongFactory(string ("dwa"), string ("dwa")));
		songs.push_back (SongFactory(string ("trzy"), string ("trzy")));
		songs.push_back (SongFactory(string ("cztery"), string ("cztery")));
		songs.push_back (SongFactory(string ("piec"), string ("piec")));
		
		for (auto &song : songs) {
			cout << song->author << " - " << song->title << endl;
		}
	}
}