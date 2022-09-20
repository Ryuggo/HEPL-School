using System;
using System.Linq;
using Microsoft.EntityFrameworkCore;
using DAL;
using DTO;
using NUnit.Framework;
using Type = DAL.Type;

namespace TestDAL;

public class Tests
{
    private static readonly DALManager _myDAL = new DALManager();
    [SetUp]
    public void Setup()
    {
    }

    [Test]
    public void TestInsertIntoDatabase()
    {
        try
        {
            Console.WriteLine("---- Movies");
            Movie m = new Movie(
                "title222",
                "originalTitle",
                new DateTime(2021, 12, 02),
                "status",
                5.0,
                123,
                24,
                "certification",
                "",
                987654,
                "tagline"
            );
            _myDAL.InsertMovie(m);
            _myDAL.Save();

            Console.WriteLine("---- Actors");
            _myDAL.InsertActor(new Actor("actor name", "character name"), m);
            _myDAL.Save();

            Console.WriteLine("---- Directors");
            _myDAL.InsertDirector(new Director("director name"), m);
            _myDAL.Save();

            Console.WriteLine("---- Types");
            _myDAL.InsertType(new Type("type"), m);
            _myDAL.Save();

            Console.WriteLine("---- Comments");
            _myDAL.InsertComment(m.MovieId, "text", 8);
            _myDAL.Save();

            Assert.Pass();
        }
        catch (DbUpdateException e)
        {
            Console.WriteLine(e);
            Assert.Fail();
            throw;
        }
    }

    [Test]
    public void TestSelectFromDatabase()
    {
        try
        {
            Console.WriteLine("---- All Movies");
            var res1 = _myDAL.SelectMovie().Take(10);
            foreach (var x in res1)
                Console.WriteLine(x);
            Console.WriteLine("");
            
            Console.WriteLine("---- Movie");
            var res2 = _myDAL.SelectMovie(s => s.Title == "title" && s.OriginalTitle == "originalTitle");
            foreach (var x in res2)
                Console.WriteLine(x);
            Console.WriteLine("");

            Console.WriteLine("---- Actors");
            var res3 = _myDAL.SelectActor(s => s.Name == "actor name");
            foreach (var x in res3)
                Console.WriteLine(x);
            Console.WriteLine("");

            Console.WriteLine("---- Types");
            var res4 = _myDAL.SelectMovieTypes(s => s.Name == "type");
            foreach (var x in res4)
                Console.WriteLine(x);
            Console.WriteLine("");

            Console.WriteLine("---- Comments");
            var res5 = _myDAL.SelectComment(s => s.Text == "text" && s.Evaluation == 8);
            foreach (var x in res5)
                Console.WriteLine(x);
            Console.WriteLine("");
            
            Assert.Pass();
        }
        catch (DbUpdateException e)
        {
            Console.WriteLine(e);
            Assert.Fail();
            throw;
        }
    }
}