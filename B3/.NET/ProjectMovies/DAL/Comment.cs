using DTO;

namespace DAL;

public class Comment
{
    public int CommentId { get; set; }
    public string Text { get; set; }
    public int Evaluation { get; set; }
    public DateTime DateComment { get; set; }
    public bool Validate { get; set; }
    public ICollection<Movie> Movies { get; set; }

    public Comment()
    {
        Movies = new List<Movie>();
    }

    public Comment(string text, int evaluation, DateTime dateComment)
    {
        CommentId = 0;
        Text = text;
        Evaluation = evaluation;
        DateComment = dateComment;
        Validate = true;
        Movies = new List<Movie>();
    }

    public Comment(CommentDTO c)
    {
        CommentId = c.IdComment;
        Text = c.Text;
        Evaluation = c.Evaluation;
        DateComment = c.DateComment;
        Validate = c.Validate;
        Movies = new List<Movie>();
    }

    public override string ToString()
    {
        return "Comment -> " + CommentId + " | " + Text + " | " + Evaluation + " | " + DateComment + " | " + Validate;
    }
}
