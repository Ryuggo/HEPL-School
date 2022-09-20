using Microsoft.EntityFrameworkCore;

namespace DAL;

public class DALManager
{
    private readonly MyDBContext _myDBContext = new();

    public DALManager() {}
    
    public IEnumerable<Actor> SelectActor(Func<Actor, bool> predicate)
    {
        return _myDBContext.Actors.Include(i => i.Movies).Where(predicate);
    }
    
    public IEnumerable<Type> SelectMovieTypes(Func<Type, bool> predicate)
    {
        return _myDBContext.Types.Include(i => i.Movies).Where(predicate);
    }
    
    public IEnumerable<Movie> SelectMovie(Func<Movie, bool> predicate)
    {
        return _myDBContext.Movies.Include(i => i.Actor).AsSplitQuery().Include(i => i.Type).Where(predicate);
    }
    public IEnumerable<Movie> SelectMovie()
    {
        return _myDBContext.Movies.Include(i => i.Actor).AsSplitQuery().Include(i => i.Type);
    }
    
    public IEnumerable<Comment> SelectComment(Func<Comment, bool> predicate)
    {
        return _myDBContext.Comments.Include(i => i.Movies).Where(predicate);
    }

    public void InsertComment(int idMovie, string comment, int evaluation)
    {
        Comment com = new Comment(comment, evaluation, DateTime.Now.ToUniversalTime());
        _myDBContext.Comments.Add(com);
        _myDBContext.Movies.Find(idMovie)?.Comment.Add(com);
    }

    public void UpdateComment(Comment c)
    {
        _myDBContext.Comments.Update(c);
    }

    public void InsertMovie(Movie m)
    {
        if (_myDBContext.Movies.Find(m.MovieId) == null)
            _myDBContext.Movies.Add(m);
        else
            _myDBContext.Movies.FirstOrDefault(fod => fod.MovieId == m.MovieId);
    }

    public void InsertActor(Actor ac, Movie m)
    {
        if (_myDBContext.Actors.Find(ac.ActorId) == null)
        {
            m.Actor.Add(ac);
            _myDBContext.Actors.Add(ac);
        }
        else
        {
            m.Actor.Add(_myDBContext.Actors.Find(ac.ActorId));/*
            var actor = _myDBContext.Actors.FirstOrDefault(fod => fod.ActorId == ac.ActorId);
            m.Actor.Add(actor);*/
        }
    }

    public void InsertDirector(Director di, Movie m)
    {
        if (_myDBContext.Directors.Find(di.DirectorId) == null)
        {
            _myDBContext.Directors.Add(di);
            m.Director.Add(di);
        }
        else
        {
            m.Director.Add(_myDBContext.Directors.Find(di.DirectorId));/*
            var director = _myDBContext.Directors.FirstOrDefault(fod => fod.DirectorId == di.DirectorId);
            m.Director.Add(director);*/
        }
    }

    public void InsertType(Type ty, Movie m)
    {
        if (_myDBContext.Types.Find(ty.TypeId) == null)
        {
            _myDBContext.Types.Add(ty);
            m.Type.Add(ty);
        }
        else
        {
            m.Type.Add(_myDBContext.Types.Find(ty.TypeId));/*
            var type = _myDBContext.Types.FirstOrDefault(fod => fod.TypeId == ty.TypeId);
            m.Type.Add(type);*/
        }
    }

    public void Save() { _myDBContext.SaveChanges(); }

    public void RemoveComment(Comment c)
    {
        _myDBContext.Comments.Remove(c);
    }
}
