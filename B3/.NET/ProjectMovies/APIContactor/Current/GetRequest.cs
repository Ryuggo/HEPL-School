namespace APIContactor.Current;

public class GetRequest : IDisposable
{
    private HttpClient Client { get; set; }
    public string ApiUrl { get; set; }
    public MovieContactor Movie { get; set; }
    public ActorContactor Actor { get; set; }
    public CommentContactor Comment { get; set; }
    
    public GetRequest()
    {
        ApiUrl = "https://localhost:7265";
        HttpClientHandler clientHandler = new HttpClientHandler();
        clientHandler.ServerCertificateCustomValidationCallback = (sender, cert, chain, sslPolicyErrors) =>
        {
            return true;
        };
        Client = new HttpClient(clientHandler);
        
        Movie = new MovieContactor(ApiUrl + "/Movie", Client);
        Actor = new ActorContactor(ApiUrl + "/Actor", Client);
        Comment = new CommentContactor(ApiUrl + "/Comment", Client);
    }

    public void Dispose()
    {
        Client?.Dispose();
    }
}