namespace APIContactor.TMDB;

public class GetTmdb : IDisposable
{
    private HttpClient Client { get; set; }
    public string ApiUrl { get; set; }
    public TmdbContactor Tmdb { get; set; }
    
    public GetTmdb()
    {
        ApiUrl = "https://api.themoviedb.org/3";
        HttpClientHandler clientHandler = new HttpClientHandler();
        clientHandler.ServerCertificateCustomValidationCallback = (sender, cert, chain, sslPolicyErrors) =>
        {
            return true;
        };
        Client = new HttpClient(clientHandler);

        Tmdb = new TmdbContactor(ApiUrl, Client);
    }

    public void Dispose()
    {
        Client?.Dispose();
    }
}