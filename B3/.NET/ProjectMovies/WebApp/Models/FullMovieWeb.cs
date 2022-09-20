using DTO;

namespace WebApplication1.Models;

public class FullMovieWeb
{
    public MovieWeb Movie { get; set; }
    public List<ActorWeb> Actors { get; set; }
    public List<TypeWeb> Types { get; set; }
    
    public FullMovieWeb()
    {
        Movie = new MovieWeb();
        Actors = new List<ActorWeb>();
        Types = new List<TypeWeb>();
    }

    public FullMovieWeb(MovieWeb movie, List<ActorWeb> actors, List<TypeWeb> types)
    {
        Movie = movie;
        Actors = actors;
        Types = types;
    }
    
    public FullMovieWeb(MovieDTO m, List<ActorDTO> a, List<MovieTypeDTO> t)
    {
        Movie = new MovieWeb(m.IdMovie, m.Title, m.OriginalTitle, DateOnly.FromDateTime(m.ReleaseDate), m.Status, m.VoteAverage, m.VoteCount, m.Runtime, m.Certification, m.PosterPath, m.Budget, m.Tagline);
        
        Actors = new List<ActorWeb>();
        foreach (var x in a)
            Actors.Add(new ActorWeb(x.Name, x.Character, x.NbrMovie));
        
        Types = new List<TypeWeb>();
        foreach (var x in t)
            Types.Add(new TypeWeb(x.Name));
    }
}