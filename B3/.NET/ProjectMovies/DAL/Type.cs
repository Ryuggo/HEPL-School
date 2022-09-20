using DTO;

namespace DAL;

public class Type
{
    public int TypeId { get; set; }
    public string Name { get; set; }
    public ICollection<Movie> Movies { get; set; }

    public Type()
    {
        Movies = new List<Movie>();
    }

    public Type(string name)
    {
        TypeId = 0;
        Name = name;
        Movies = new List<Movie>();
    }

    public override string ToString()
    {
        return "Type -> " + TypeId + " | " + Name;
    }

    public MovieTypeDTO TypeToDTO()
    {
        return new MovieTypeDTO(TypeId, Name);
    }
}