namespace WebApplication1.Models;

public class ActorWeb
{
    public string Name { get; set; }
    public string Character { get; set; }
    public int NbrMovie { get; set; }
    
    public ActorWeb() {}

    public ActorWeb(string name, string character, int nbrMovie)
    {
        Name = name;
        Character = character;
        NbrMovie = nbrMovie;
    }
}