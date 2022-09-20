using System;
using System.Collections.Generic;
using NUnit.Framework;
using BLL;
using DTO;

namespace TestBLL;

public class Tests
{
    private static readonly BllManager _myBLL = new BllManager();
    [SetUp]
    public void Setup()
    {
    }

    [Test]
    public void TestGetListActorsByIdMovie()
    {
        List<LightActorDTO> list = _myBLL.GetListActorsByIdMovie(2);
        foreach (var x in list)
            Console.WriteLine(x.IdActor + " - " + x.Name + " - " + x.Character);
        
        Assert.Pass();
    }

    [Test]
    public void TestGetListMovieTypesByIdMovie()
    {
        List<MovieTypeDTO> list = _myBLL.GetListMovieTypesByIdMovie(2);
        foreach (var x in list)
            Console.WriteLine(x.TypeId + " - " + x.Name);
        
        Assert.Pass();
    }

    [Test]
    public void TestFindListMovieByPartialActorName()
    {
        List<MovieDTO> list = _myBLL.FindListMovieByPartialActorName("Matti", 0, 2);
        foreach (var x in list)
            Console.WriteLine(x.IdMovie + " - " + x.Title);
        
        Assert.Pass();
    }

    [Test]
    public void TestGetFavoriteActors()
    {
        List<ActorDTO> list = _myBLL.GetFavoriteActors(2, 20);
        foreach (var x in list)
            Console.WriteLine(x.IdActor + " - " + x.Name + " - " + x.Character);
        
        Assert.Pass();
    }

    [Test]
    public void TestGetFullMovieDetailsByIdMovie()
    {
        List<FullMovieDTO> list = _myBLL.GetFullMovieDetailsByIdMovie(2);
        foreach (var x in list)
            Console.WriteLine(x.Movie.IdMovie + " - " + x.Movie.Title);
        
        Assert.Pass();
    }

    [Test]
    public void TestInsertCommentOnMovieId()
    {
        _myBLL.InsertCommentOnMovieId(2, "Sous l'océan", 8);
        
        Assert.Pass();
    }

    [Test]
    public void TestGetComments()
    {
        List<CommentDTO> list = _myBLL.GetComments(5);
        foreach (var x in list)
            Console.WriteLine(x.IdComment + " - " + x.Text + " - " + x.Evaluation);
        
        Assert.Pass();
    }

    [Test]
    public void TestValidateCommentById()
    {
        _myBLL.ValidateCommentById(1, true);
        
        Assert.Pass();
    }

    [Test]
    public void TestGetCommentsOnMovieId()
    {
        List<CommentDTO> list = _myBLL.GetCommentsOnMovieId(2);
        foreach (var x in list)
            Console.WriteLine(x.IdComment + " - " + x.Text + " - " + x.Evaluation);
        
        Assert.Pass();
    }
}