namespace DTO;

public class FullMovieDTO
{
    public MovieDTO Movie { get; set; }
    public List<ActorDTO> Actors { get; set; }
    public List<MovieTypeDTO> Types { get; set; }


    public FullMovieDTO()
    {
        Movie = new MovieDTO();
        Actors = new List<ActorDTO>();
        Types = new List<MovieTypeDTO>();
    }

    public FullMovieDTO(MovieDTO movie, List<ActorDTO> actors, List<MovieTypeDTO> types)
    {
        Movie = movie;
        Actors = actors;
        Types = types;
    }
}