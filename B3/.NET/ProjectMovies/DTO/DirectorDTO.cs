namespace DTO;

public class DirectorDTO
{
    public int IdDirector { get; set; }
    public string Name { get; set; }

    public DirectorDTO(int id, string name)
    {
        IdDirector = id;
        Name = name;
    }
}