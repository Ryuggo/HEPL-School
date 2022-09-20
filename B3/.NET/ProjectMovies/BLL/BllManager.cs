using DTO;
using DAL;

namespace BLL;

public class BllManager
{
    private static DALManager _myDAL = new DALManager();

    public List<LightActorDTO> GetListActorsByIdMovie(int idMovie)
    {
        var res = _myDAL.SelectActor(s => s.Movies.Any(a => a.MovieId == idMovie));

        List<LightActorDTO> list = new List<LightActorDTO>();
        foreach (var x in res)
            list.Add(new LightActorDTO(x.ActorId, x.Name, x.CharacterName));

        return list;
    }

    public List<MovieTypeDTO> GetListMovieTypesByIdMovie(int idMovie)
    {
        var res = _myDAL.SelectMovieTypes(s => s.Movies.Any(a => a.MovieId == idMovie));

        List<MovieTypeDTO> list = new List<MovieTypeDTO>();
        foreach (var x in res)
            list.Add(new MovieTypeDTO(x.TypeId, x.Name));

        return list;
    }

    public List<MovieDTO> FindListMovieByPartialActorName(string nameActor, int from, int nbrMax)
    {
        var res = _myDAL.SelectMovie(s => s.Actor.Any(a => a.Name.ToLower().Contains(nameActor.ToLower()))).Skip(from).Take(nbrMax);

        List<MovieDTO> list = new List<MovieDTO>();
        foreach (var x in res)
            list.Add(x.MovieToDTO());

        return list;
    }
    public List<FullMovieDTO> FindListFullMovieByPartialActorName(string nameActor, int from, int nbrMax)
    {
        var res = _myDAL.SelectMovie(s => s.Actor.Any(a => a.Name.ToLower().Contains(nameActor.ToLower()))).Skip(from).Take(nbrMax);

        List<FullMovieDTO> list = new List<FullMovieDTO>();
        List<ActorDTO> listActor = new List<ActorDTO>();
        foreach (var x in res)
        {
            foreach (var z in x.Actor)
                listActor.Add(z.ActorToDTO());
            list.Add(new FullMovieDTO(x.MovieToDTO(), listActor, new List<MovieTypeDTO>()));
        }

        return list;
    }

    public List<MovieDTO> FindListMovieByPartialMovieName(string nameMovie, int from, int nbrMax)
    {
        var res = _myDAL.SelectMovie(a => a.Title.ToLower().Contains(nameMovie.ToLower())).Skip(from).Take(nbrMax);

        List<MovieDTO> list = new List<MovieDTO>();
        foreach (var x in res)
            list.Add(x.MovieToDTO());

        return list;
    }

    public List<MovieDTO> FindListMovie(int from, int nbrMax)
    {
        var res = _myDAL.SelectMovie().Skip(from).Take(nbrMax);

        List<MovieDTO> list = new List<MovieDTO>();
        foreach (var x in res)
            list.Add(x.MovieToDTO());

        return list;
    }

    public List<ActorDTO> GetFavoriteActors(int nbrMin, int nbrMax)
    {
        var res = _myDAL.SelectActor(s => s.Movies.Count > nbrMin).Take(nbrMax)
            .Select(s => new ActorDTO(s.ActorId, s.Name, s.CharacterName, s.Movies.Count));

        List<ActorDTO> list = new List<ActorDTO>();
        foreach (var x in res)
            list.Add(x);

        return list;
    }

    public List<FullMovieDTO> GetFullMovieDetailsByIdMovie(int idMovie)
    {
        var res = _myDAL.SelectMovie(s => s.MovieId == idMovie);

        List<FullMovieDTO> list = new List<FullMovieDTO>();
        List<ActorDTO> listActor = new List<ActorDTO>();
        List<MovieTypeDTO> listType = new List<MovieTypeDTO>();
        foreach (var x in res)
        {
            foreach (var z in x.Actor)
                listActor.Add(z.ActorToDTO());
            foreach (var z in x.Type)
                listType.Add(z.TypeToDTO());

            list.Add(new FullMovieDTO(x.MovieToDTO(), listActor, listType));
        }
        return list;
    }

    public void InsertCommentOnMovieId(int idMovie, string comment, int evaluation)
    {
        _myDAL.InsertComment(idMovie, comment, evaluation);
        _myDAL.Save();
    }

    public List<CommentDTO> GetComments(int nbrMax)
    {
        IEnumerable<Comment> res;
        if (nbrMax > 0)
            res = _myDAL.SelectComment(s => s.Validate == true).Take(nbrMax);
        else
            res = _myDAL.SelectComment(s => s.Validate == true);

        List<CommentDTO> list = new List<CommentDTO>();
        foreach (var x in res)
            list.Add(new CommentDTO(x.CommentId, x.Text, x.Evaluation, x.DateComment));

        return list;
    }

    public List<CommentDTO> GetCommentsOnMovieId(int idMovie)
    {
        var res = _myDAL.SelectComment(s => s.Movies.Any(a => a.MovieId == idMovie));

        List<CommentDTO> list = new List<CommentDTO>();
        foreach (var x in res)
            list.Add(new CommentDTO(x.CommentId, x.Text, x.Evaluation, x.DateComment, x.Validate));

        return list;
    }

    public void ValidateCommentById(int idComment, bool validate)
    {
        var res = _myDAL.SelectComment(s => s.CommentId == idComment).First();
        res.Validate = validate;
        _myDAL.UpdateComment(res);
        _myDAL.Save();
    }

    public void DeleteCommentById(int idComment)
    {
        var res = _myDAL.SelectComment(s => s.CommentId == idComment).First();
        _myDAL.RemoveComment(res);
        _myDAL.Save();
    }

    public void UpdateCommentById(int idComment, string text)
    {
        var res = _myDAL.SelectComment(s => s.CommentId == idComment).First();
        res.Text = text;
        _myDAL.UpdateComment(res);
        _myDAL.Save();
    }


    public List<MovieDTO> SearchOrAnd(string txt, int posSearch, int pagination)
    {
        IEnumerable<MovieDTO>? list = new List<MovieDTO>();

        string[] txtNOT = txt.Split("!");
        string[] txtOR = txtNOT[0].Split("|");

        // OR + AND
        foreach (string ors in txtOR) {
            string[] txtAND = ors.Split("&");

            // Movie
            IEnumerable<MovieDTO>? lMovie = FindListMovieByPartialMovieName(txtAND[0], posSearch, pagination - list.Count());

            foreach (string ands in txtAND) {
                lMovie = lMovie.Where(x => x.Title.ToLower().Contains(ands.Trim().ToLower()));
            }

            list = list.Union(lMovie);
            if (list.Count() >= 20) break;

            // Actors
            IEnumerable<FullMovieDTO>? lActor = FindListFullMovieByPartialActorName(txtAND[0], posSearch, pagination - list.Count());

            foreach (string ands in txtAND) {
                lActor = lActor.Where(x => x.Actors.Any(a => a.Name.ToLower().Contains(ands.Trim().ToLower())));
            }

            IEnumerable<MovieDTO>? lMovieActor = new List<MovieDTO>();
            foreach (FullMovieDTO movie in lActor) {
                lMovieActor = lMovieActor.Append(movie.Movie);
            }

            list = list.Union(lMovieActor);
            if (list.Count() >= 20) break;
        }

        // NOT
        if (txtNOT.Length != 1) {
            IEnumerable<string> nots = txtNOT[1].Split(",");

            foreach (string not in nots) {
                list = list.Where(x => !x.Title.ToLower().Contains(not.Trim().ToLower()));
            }
        }

        return list.ToList();
    }
}