class Song
{
    public:
        Song();
        Song(string, string, int);
        void                setTitle(string);
        string              getTitle();
        void                setArtist(string);
        string              getArtist();
        void                setDownloads(int);
        int                 getDownloads();
        double              grossRevenue(double);
        
    private:
        string              title;
        string              artist;
        int                 downloads;
};

Song::Song()
{
    title = "";
    artist = "";
    downloads = 0;
}

Song::Song(string hit, string name, int num)
{
    title = hit;
    artist = name;
    downloads = num;
}

void Song::setTitle(string melody)
{
    title = melody;
}

string Song::getTitle()
{
    return title;
}

void Song::setArtist(string call)
{
    artist = call;
}

string Song::getArtist()
{
    return artist;
}

void Song::setDownloads(int clicks)
{
    downloads = clicks;
}
int Song::getDownloads()
{
    return downloads;
}

double Song::grossRevenue(double price)
{
    double revenue = price * downloads;
    return revenue;
}