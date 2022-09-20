using DTO;

namespace DAL;

public class Movie
{
    public int MovieId { get; set; }
    public string Title { get; set; }
    public string OriginalTitle { get; set; }
    public DateTime ReleaseDate { get; set; }
    public string Status { get; set; }
    public double VoteAverage { get; set; }
    public int VoteCount { get; set; }
    public int Runtime { get; set; }
    public string Certification { get; set; }
    public string PosterPath { get; set; }
    public int Budget { get; set; }
    public string Tagline { get; set; }
    public ICollection<Type> Type { get; set; }
    public ICollection<Actor> Actor { get; set; }
    public ICollection<Director> Director { get; set; }
    public ICollection<Comment> Comment { get; set; }

    public Movie()
    {
        MovieId = 0;
        Title = "";
        OriginalTitle = "";
        ReleaseDate = new DateTime(2000, 01, 01);
        Status = "";
        VoteAverage = 0;
        VoteCount = 0;
        Runtime = 0;
        Certification = "";
        PosterPath = "";
        Budget = 0;
        Tagline = "";
        Type = new List<Type>();
        Actor = new List<Actor>();
        Director = new List<Director>();
        Comment = new List<Comment>();
    }

    public Movie(string title, string originalTitle, DateTime releaseDate, string status, double voteAverage, int voteCount, int runtime, string certification, string posterPath, int budget, string tagline)
    {
        MovieId = 0;
        Title = title;
        OriginalTitle = originalTitle;
        ReleaseDate = releaseDate;
        Status = status;
        VoteAverage = voteAverage;
        VoteCount = voteCount;
        Runtime = runtime;
        Certification = certification;
        PosterPath = posterPath;
        Budget = budget;
        Tagline = tagline;
        Type = new List<Type>();
        Actor = new List<Actor>();
        Director = new List<Director>();
        Comment = new List<Comment>();
    }

    public override string ToString()
    {
        return "Movie -> " + MovieId + " | " + Title + " | " + OriginalTitle + " | " + ReleaseDate + " | " + Status + " | " + VoteAverage + " | " + VoteCount + " | " + 
            Runtime + " | " + Certification + " | " + PosterPath + " | " + Budget + " | " + Tagline;
    }
    
    public MovieDTO MovieToDTO()
    {
        return new MovieDTO(MovieId, Title, OriginalTitle, ReleaseDate, Status, VoteAverage, VoteCount, Runtime.ToString(), Certification, PosterPath, Budget, Tagline);
    }
}
