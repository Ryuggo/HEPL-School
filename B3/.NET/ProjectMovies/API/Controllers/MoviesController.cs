using Microsoft.AspNetCore.Mvc;
using BLL;

namespace API.Controllers;

[ApiController]
[Route("Movie")]
public class MoviesController : ControllerBase
{
    private BllManager _myBLL = new BllManager();

    [HttpGet("GetByPartialActorName")]
    public IActionResult? GetByPartialActorName(string name, int from, int nbrMax)
    {
        try
        {
            return Ok(_myBLL.FindListMovieByPartialActorName(name, from, nbrMax));
        }
        catch (Exception e)
        {
            Console.Error.WriteLine(e);
            throw;
        }
    }

    [HttpGet("GetFullByPartialActorName")]
    public IActionResult? GetFullByPartialActorName(string name, int from, int nbrMax)
    {
        try
        {
            return Ok(_myBLL.FindListFullMovieByPartialActorName(name, from, nbrMax));
        }
        catch (Exception e)
        {
            Console.Error.WriteLine(e);
            throw;
        }
    }

    [HttpGet("GetByPartialMovieName")]
    public IActionResult? GetByPartialMovieName(string name, int from, int nbrMax)
    {
        try
        {
            return Ok(_myBLL.FindListMovieByPartialMovieName(name, from, nbrMax));
        }
        catch (Exception e)
        {
            Console.Error.WriteLine(e);
            throw;
        }
    }

    [HttpGet("GetAll")]
    public IActionResult? GetAll(int from, int nbrMax)
    {
        try
        {
            return Ok(_myBLL.FindListMovie(from, nbrMax));
        }
        catch (Exception e)
        {
            Console.Error.WriteLine(e);
            throw;
        }
    }

    [HttpGet("GetMovieByIdMovie")]
    public IActionResult? GetMovieByIdMovie(int idMovie)
    {
        try
        {
            return Ok(_myBLL.GetFullMovieDetailsByIdMovie(idMovie));
        }
        catch (Exception e)
        {
            Console.Error.WriteLine(e);
            throw;
        }
    }
}