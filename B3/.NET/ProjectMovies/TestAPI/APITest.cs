using System.Linq;
using APIContactor.Current;
using NUnit.Framework;

namespace TestAPI;

public class Tests
{
    private readonly GetRequest _get = new GetRequest();
    
    [SetUp]
    public void Setup()
    {
    }

    [Test]
    public void TestGetByPartialActorName()
    {
        if (!_get.Movie.GetByPartialActorName("Matti", 0, 10).Any())
            Assert.Fail("GetByPartialActorName Failed");
        
        Assert.Pass();
    }

    [Test]
    public void TestGetByPartialMovieName()
    {
        if(!_get.Movie.GetByPartialMovieName("Ar", 0, 10).Any())
            Assert.Fail("GetByPartialMovieName Failed");
        
        Assert.Pass();
    }

    [Test]
    public void TestGetAll()
    {
        if(!_get.Movie.GetAll(0, 10).Any())
            Assert.Fail("GetAll Failed");
        
        Assert.Pass();
    }

    [Test]
    public void TestGetMovieByIdMovie()
    {
        if(!_get.Movie.GetMovieByIdMovie(2).Any())
            Assert.Fail("GetMovieByIdMovie Failed");
        
        Assert.Pass();
    }

    [Test]
    public void TestGetActorByIdMovie()
    {
        if(!_get.Actor.GetActorByIdMovie(2).Any())
            Assert.Fail("GetActorByIdMovie Failed");
        
        Assert.Pass();
    }

    [Test]
    public void TestGetFavorite()
    {
        if(!_get.Actor.GetFavorite(0, 10).Any())
            Assert.Fail("GetFavorite Failed");
        
        Assert.Pass();
    }

    [Test]
    public void TestGetValidate()
    {
        if(!_get.Comment.GetValidate(10).Any())
            Assert.Fail("GetValidate Failed");
        
        Assert.Pass();
    }

    [Test]
    public void TestGetCommentByIdMovie()
    {
        if(!_get.Comment.GetCommentByIdMovie(2).Any())
            Assert.Fail("GetCommentByIdMovie Failed");
        
        Assert.Pass();
    }

    [Test]
    public void TestInsertOnIdMovie()
    {
        _get.Comment.InsertOnIdMovie(2, "Bof", 3);
        
        Assert.Pass();
    }

    [Test]
    public void TestValidateByIdComment()
    {
        _get.Comment.ValidateByIdComment(1);
        
        Assert.Pass();
    }
}