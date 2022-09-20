using DAL;
using APIContactor.TMDB;
using System.Configuration;

namespace DBCreation;

public class Program
{
    private static DALManager _myDAL = new DALManager();
    public static void Main(string[] args)
    {
        AppContext.SetSwitch("Npgsql.EnableLegacyTimestampBehavior", true);


        Console.WriteLine("Lecture du Document Texte");
        ReadTxt();


        Console.WriteLine("\n\n\n\nMise à jour des PosterPath");
        GetTmdb _get = new GetTmdb();

        string? api = ConfigurationManager.AppSettings["ApiKey"];
        _get.Tmdb.GetToken(api);
        //_get.Tmdb.PostCreateSession(api, _get.Tmdb.GetToken(api));

        int j = 0;
        foreach (Movie mov in _myDAL.SelectMovie())
        {
            mov.PosterPath = _get.Tmdb.GetMovieImage(api, mov.MovieId);
            j++;

            if (j == 50)
            {
                Console.WriteLine(mov.ToString());
                _myDAL.Save();
                j = 0;
            }
        }
        _myDAL.Save();

        //_get.Tmdb.DelSession(api);
    }

    private static void ReadTxt()
    {
        int j = 0;
        string? folder = ConfigurationManager.AppSettings["Folder"];
        foreach (string line in File.ReadLines(@folder))
        {
            Movie movie = new Movie();
            int i = 0;
            foreach (string attribute in line.Split('‣'))
            {
                switch (i)
                {
                    case 0: movie.MovieId = attribute.Equals("") ? 0 : int.Parse(attribute);
                        break;
                    case 1: movie.Title = attribute;
                        break;
                    case 2: movie.OriginalTitle = attribute;
                        break;
                    case 3: movie.ReleaseDate = attribute.Equals("") ? new DateTime(01, 01, 01) : DateTime.Parse(attribute);
                        break;
                    case 4: movie.Status = attribute;
                        break;
                    case 5: movie.VoteAverage = attribute.Equals("") ? 0.0 : double.Parse(attribute);
                        break;
                    case 6: movie.VoteCount = attribute.Equals("") ? 0 : int.Parse(attribute);
                        break;
                    case 7: movie.Runtime = attribute.Equals("") ? 0 : int.Parse(attribute);
                        break;
                    case 8: movie.Certification = attribute; 
                        break;
                    case 9: movie.PosterPath = attribute;
                        break;
                    case 10: movie.Budget = attribute.Equals("") ? 0 : int.Parse(attribute);
                        break;
                    case 11: movie.Tagline = attribute;
                        break;
                    case 12: funcType(attribute, movie);
                        break;
                    case 13: funcDirector(attribute, movie);
                        break;
                    case 14: funcActor(attribute, movie);
                        break;
                }
                i++;
                if (i == 12)
                    _myDAL.InsertMovie(movie);
            }
            j++;
            
            if(j == 50)
            {
                Console.WriteLine(movie.ToString());
                _myDAL.Save();
                j = 0;
            }
        }
        _myDAL.Save();
    }

    private static void funcType(string attribute, Movie movie)
    {
        foreach (string row in attribute.Split('‖'))
        {
            DAL.Type type = new DAL.Type();

            int i = 0;
            foreach (string content in row.Split('․'))
            {
                if(!content.Equals(""))
                {
                    switch (i)
                    {
                        case 0:
                            type.TypeId = int.Parse(content);
                            break;
                        case 1:
                            type.Name = content;
                            break;
                    }
                }
                i++;
            }

            if (i != 0 && type.Name != null)
                _myDAL.InsertType(type, movie);
        }
    }

    private static void funcDirector(string attribute, Movie movie)
    {
        foreach (string row in attribute.Split('‖'))
        {
            Director director = new Director();

            int i = 0;
            foreach (string content in row.Split('․'))
            {
                if (!content.Equals(""))
                {
                    switch (i)
                    {
                        case 0:
                            director.DirectorId = int.Parse(content);
                            break;
                        case 1:
                            director.Name = content;
                            break;
                    }
                }
                i++;
            }

            if (i != 0 && director.Name != null)
                _myDAL.InsertDirector(director, movie);
        }
    }

    private static void funcActor(string attribute, Movie movie)
    {
        foreach (string row in attribute.Split('‖'))
        {
            Actor actor = new Actor();

            int i = 0;
            foreach (string content in row.Split('․'))
            {
                if(!content.Equals(""))
                {
                    switch (i)
                    {
                        case 0: 
                            actor.ActorId = int.Parse(content);
                            break;
                        case 1: 
                            actor.Name = content;
                            break;
                        case 2: 
                            actor.CharacterName = content;
                            break;
                    }
                }
                i++;
            }

            if (i != 0 && actor.Name != null && actor.CharacterName != null)
                _myDAL.InsertActor(actor, movie);
        }
    }
}