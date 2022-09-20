namespace DTO;

public class ActorDTO
{
    public int IdActor { get; set; }
    public string Name { get; set; }
    public string Character { get; set; }
    public int NbrMovie { get; set; }
    
    public ActorDTO() {}

    public ActorDTO(int id, string name, string character, int nbrMovie)
    {
        IdActor = id;
        Name = name;
        Character = character;
        NbrMovie = nbrMovie;
    }
}