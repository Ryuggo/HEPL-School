using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using WebApplication1.Models;
using APIContactor.Current;
using DTO;
using BLL;

namespace WebApplication1.Controllers;

public class HomeController : Controller
{
    private readonly GetRequest _get = new GetRequest();
    private BllManager bll = new BllManager();

    private readonly ILogger<HomeController> _logger;

    public HomeController(ILogger<HomeController> logger)
    {
        _logger = logger;
    }

    public IActionResult Index(string search, int from)
    {
        List<MovieDTO> list;
        if (search != null)
        {
            list = bll.SearchOrAnd(search, from, 20);

            ViewBag.Search = search.Replace("&", "%26");
        }
        else
        {
            list = _get.Movie.GetAll(from, 20) ?? new List<MovieDTO>();
        }

        List<MovieWeb> mv = new List<MovieWeb>();
        foreach (var x in list)
            mv.Add(new MovieWeb(x.IdMovie, x.Title, x.OriginalTitle, DateOnly.FromDateTime(x.ReleaseDate), x.Status, x.VoteAverage, x.VoteCount, x.Runtime, x.Certification, x.PosterPath, x.Budget, x.Tagline));

        ViewBag.Index = from;
        ViewBag.MovieWeb = mv;

        return View();
    }
    
    public IActionResult Detail(int idMovie)
    {
        ViewBag.AddedComm = false;
        if (Request.Method == "POST")
        {
            _get.Comment.InsertOnIdMovie(idMovie, Request.Form["comm"], Int16.Parse(Request.Form["eval"]));
            ViewBag.AddedComm = true;
        }

        FullMovieDTO mov = (_get.Movie.GetMovieByIdMovie(idMovie) ?? new List<FullMovieDTO>()).ElementAt(0);

        List<CommentWeb> lCommentWeb = new List<CommentWeb>();
        List<CommentDTO> list = _get.Comment.GetCommentByIdMovie(idMovie) ?? new List<CommentDTO>();
        list = list.Where(x => x.Validate == true).ToList();
        foreach (var x in list)
            lCommentWeb.Add(new CommentWeb(x.IdComment, x.Text, x.Evaluation, x.DateComment));

        ViewBag.FullMovieWeb = new FullMovieWeb(mov.Movie, mov.Actors, mov.Types);
        ViewBag.LCommentWeb = lCommentWeb;

        return View();
    }

    public IActionResult Privacy()
    {
        return View();
    }

    [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
    public IActionResult Error()
    {
        return View(new ErrorViewModel {RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier});
    }
}