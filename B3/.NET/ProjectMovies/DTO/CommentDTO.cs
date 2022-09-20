namespace DTO;

public class CommentDTO
{
    public int IdComment { get; set; }
    public string Text { get; set; }
    public int Evaluation { get; set; }
    public DateTime DateComment { get; set; }
    public bool Validate { get; set; }


    public CommentDTO(int id, string text, int evaluation, DateTime dateComment)
    {
        IdComment = id;
        Text = text;
        Evaluation = evaluation;
        DateComment = dateComment;
        Validate = false;
    }
    public CommentDTO(int id, string text, int evaluation, DateTime dateComment, bool validate)
    {
        IdComment = id;
        Text = text;
        Evaluation = evaluation;
        DateComment = dateComment;
        Validate = validate;
    }

    public CommentDTO()
    {
        
    }
}