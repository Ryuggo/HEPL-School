namespace WebApplication1.Models;

public class CommentWeb
{
    public int IdComment { get; set; }
    public string Text { get; set; }
    public int Evaluation { get; set; }
    public DateTime DateComment { get; set; }
    public bool Validate { get; set; }

    public CommentWeb(int id, string text, int evaluation, DateTime dateComment)
    {
        IdComment = id;
        Text = text;
        Evaluation = evaluation;
        DateComment = dateComment;
        Validate = false;
    }

    public CommentWeb()
    {
        
    }
}