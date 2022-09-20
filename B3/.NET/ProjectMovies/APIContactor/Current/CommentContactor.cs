using DTO;
using Newtonsoft.Json;

namespace APIContactor.Current;

public class CommentContactor
{
    private HttpClient Client { get; set; }
    public string ApiUrl { get; set; }

    public CommentContactor(string url, HttpClient cl)
    {
        ApiUrl = url;
        Client = cl;
    }
    
    public async Task<string> Get(string url)
    {
        HttpResponseMessage responseMessage = await Client.GetAsync(url).ConfigureAwait(false);
        responseMessage.EnsureSuccessStatusCode();
        return await responseMessage.Content.ReadAsStringAsync().ConfigureAwait(false);
    }

    public List<CommentDTO>? GetValidate(int nbrMax)
    {
        string url = ApiUrl + "/GetValidate?nbrMax=" + nbrMax;
        return JsonConvert.DeserializeObject<List<CommentDTO>>(Get(url).Result);
    }

    public List<CommentDTO>? GetCommentByIdMovie(int idMovie)
    {
        string url = ApiUrl + "/GetCommentByIdMovie?idMovie=" + idMovie;
        return JsonConvert.DeserializeObject<List<CommentDTO>>(Get(url).Result);
    }

    public void InsertOnIdMovie(int idMovie, string comment, int evaluation)
    {
        string url = ApiUrl + "/InsertOnIdMovie?idMovie=" + idMovie + "&comment=" + comment + "&evaluation=" + evaluation;
        string res = Get(url).Result;
    }

    public void ValidateByIdComment(int idComment)
    {
        string url = ApiUrl + "/ValidateByIdComment?idComment=" + idComment;
        string res = Get(url).Result;
    }
}