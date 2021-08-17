class Country
{
    public:
        Country();
        int             LoadCountry(string);
        int             SearchForCountry(string);
        string          GetCapital(string);

    private:
        string          countries[50];
        string          capitals[50];
};

Country::Country()
{
    for (int i = 0; i < 50; i++)
    {
        countries[i] = "";
        capitals[i] = "";
    }
}

int Country::LoadCountry(string fileName)
{
    ifstream inFile;
    string  line = "";
    string temp[2];
    int count = 0;
    inFile.open(fileName);
    if (!inFile.is_open())
    {
        return -1;
    }
    else if (inFile.is_open())
    {
        while (count < 50 && getline(inFile, line))
        {
            split(line, ',', temp, 2);
            if (line != "")
            {
                countries[count] = temp[0];
                capitals[count] = temp[1];
                count++;
            }
        }
        return 0;
    }
    inFile.close();
}

int Country::SearchForCountry(string name)
{
    int count = -1;
    for (int i = 0; i < 50; i++)
    {
        if (countries[i] == name)
        {
            count = i;
        }
    }
    return count;
}

string Country::GetCapital(string Name)
{
    if(Name != "")
    {
        for (int i = 0; i < 50; i++)
        {
            if (countries[i] == Name)
            {
                return capitals[i];
            }
        }
    }
    else
    {
        return "";
    }
}