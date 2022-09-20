namespace WebApplication1.Models;

public class MovieWeb
{
    public int IdMovie { get; set; }
    public string Title { get; set; }
    public string OriginalTitle { get; set; }
    public DateOnly ReleaseDate { get; set; }
    public string Status { get; set; }
    public double VoteAverage { get; set; }
    public int VoteCount { get; set; }
    public string Runtime { get; set; }
    public string Certification { get; set; }
    public string PosterPath { get; set; }
    public int Budget { get; set; }
    public string Tagline { get; set; }
    
    public MovieWeb() {}
    public MovieWeb(int idMovie, string title, string originalTitle, DateOnly releaseDate, string status, double voteAverage, int voteCount, string runtime, string certification, string posterPath, int budget, string tagline)
    {
        IdMovie = idMovie;
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
    }
}