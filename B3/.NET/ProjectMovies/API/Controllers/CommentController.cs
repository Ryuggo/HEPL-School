using Microsoft.AspNetCore.Mvc;
using BLL;
using DTO;

namespace API.Controllers;

[ApiController]
[Route("Comment")]
public class CommentController : ControllerBase
{
    private BllManager _myBLL = new BllManager();

    [HttpGet("GetValidate")]
    public IActionResult? GetValidate(int nbrMax)
    {
        try
        {
            return Ok(_myBLL.GetComments(nbrMax));
        }
        catch (Exception e)
        {
            Console.Error.WriteLine(e);
            throw;
        }
    }

    [HttpGet("GetCommentByIdMovie")]
    public IActionResult? GetCommentByIdMovie(int idMovie)
    {
        try
        {
            return Ok(_myBLL.GetCommentsOnMovieId(idMovie));
        }
        catch (Exception e)
        {
            Console.Error.WriteLine(e);
            throw;
        }
    }

    [HttpGet("InsertOnIdMovie")]
    public void InsertOnIdMovie(int idMovie, string comment, int evaluation)
    {
        try
        {
            _myBLL.InsertCommentOnMovieId(idMovie, comment, evaluation);
        }
        catch (Exception e)
        {
            Console.Error.WriteLine(e);
            throw;
        }
    }
    
    [HttpGet("ValidateByIdComment")]
    public void ValidateByIdComment(int idComment)
    {
        try
        {
            _myBLL.ValidateCommentById(idComment, true);
        }
        catch (Exception e)
        {
            Console.Error.WriteLine(e);
            throw;
        }
    }
}