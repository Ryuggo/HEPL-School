using DTO;
using Newtonsoft.Json;

namespace APIContactor.Current;

public class ActorContactor
{
    private HttpClient Client { get; set; }
    public string ApiUrl { get; set; }

    public ActorContactor(string url, HttpClient cl)
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

    public List<LightActorDTO>? GetActorByIdMovie(int idMovie)
    {
        string url = ApiUrl + "/GetActorByIdMovie?idMovie=" + idMovie;
        return JsonConvert.DeserializeObject<List<LightActorDTO>>(Get(url).Result);
    }

    public List<ActorDTO>? GetFavorite(int nbrMin, int nbrMax)
    {
        string url = ApiUrl + "/GetFavorite?nbrMin=" + nbrMin + "&nbrMax=" + nbrMax;
        return JsonConvert.DeserializeObject<List<ActorDTO>>(Get(url).Result);
    }
}