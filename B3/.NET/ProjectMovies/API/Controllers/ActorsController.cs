using Microsoft.AspNetCore.Mvc;
using BLL;

namespace API.Controllers;

[ApiController]
[Route("Actor")]
public class ActorsController : ControllerBase
{
    private static BllManager _myBLL = new BllManager();

    [HttpGet("GetActorByIdMovie")]
    public IActionResult GetActorByIdMovie(int idMovie)
    {
        try
        {
            return Ok(_myBLL.GetListActorsByIdMovie(idMovie));
        }
        catch (Exception e)
        {
            Console.Error.WriteLine(e);
            throw;
        }
    }

    [HttpGet("GetFavorite")]
    public IActionResult GetFavorite(int nbrMin, int nbrMax)
    {
        try
        {
            return Ok(_myBLL.GetFavoriteActors(nbrMin, nbrMax));
        }
        catch (Exception e)
        {
            Console.Error.WriteLine(e);
            throw;
        }
    }
}