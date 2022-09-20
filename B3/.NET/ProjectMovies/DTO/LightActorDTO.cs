namespace DTO;

public class LightActorDTO
{
    public int IdActor { get; set; }
    public string Name { get; set; }
    public string Character { get; set; }

    public LightActorDTO(int id, string name, string character)
    {
        IdActor = id;
        Name = name;
        Character = character;
    }
}