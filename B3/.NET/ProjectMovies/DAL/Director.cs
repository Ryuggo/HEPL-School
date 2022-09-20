namespace DAL;

public class Director
{
    public int DirectorId { get; set; }
    public string Name { get; set; }
    public ICollection<Movie> Movies { get; set; }

    public Director()
    {
        Movies = new List<Movie>();
    }

    public Director(string name)
    {
        DirectorId = 0;
        Name = name;
        Movies = new List<Movie>();
    }

    public override string ToString()
    {
        return "Director -> " + DirectorId + " | " + Name;
    }
}