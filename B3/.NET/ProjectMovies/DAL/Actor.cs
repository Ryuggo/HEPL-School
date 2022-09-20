using DTO;

namespace DAL;

public class Actor
{
    public int ActorId { get; set; }
    public string Name { get; set; }
    public string CharacterName { get; set; }
    public ICollection<Movie> Movies { get; set; }
    
    public Actor()
    {
        Movies = new List<Movie>();
    }

    public Actor(string name, string character)
    {
        ActorId = 0;
        Name = name;
        CharacterName = character;
        Movies = new List<Movie>();
    }

    public override string ToString()
    {
        return "Actor -> " + ActorId + " | " + Name + " | " + CharacterName;
    }

    public ActorDTO ActorToDTO()
    {
        return new ActorDTO(ActorId, Name, CharacterName, Movies.Count);
    }
}