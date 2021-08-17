class DogTrack
{
    public:
        DogTrack();
        DogTrack(string);
        bool        AddDog(double, string);
        double      CalcAvgSpeed();
        int         CountAvailable(double);
        int         CountAvailableBreeds(string);

    private:
        string              name;
        vector<double>      speeds;
        vector<string>      breeds;
};