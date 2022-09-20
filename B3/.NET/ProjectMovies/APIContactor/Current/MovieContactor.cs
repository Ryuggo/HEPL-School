using DTO;
using Newtonsoft.Json;

namespace APIContactor.Current;

public class MovieContactor
{
    private HttpClient Client { get; set; }
    public string ApiUrl { get; set; }
    private JsonSerializerSettings settings = new JsonSerializerSettings() { DateFormatString = "MM-dd-yyyy" };

    public MovieContactor(string url, HttpClient cl)
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

    public List<MovieDTO>? GetByPartialActorName(string name, int from, int nbrMax)
    {
        string url = ApiUrl + "/GetByPartialActorName?name=" + name + "&from=" + from + "&nbrMax=" + nbrMax;
        return JsonConvert.DeserializeObject<List<MovieDTO>>(Get(url).Result, settings);
    }

    public List<MovieDTO>? GetByPartialMovieName(string name, int from, int nbrMax)
    {
        string url = ApiUrl + "/GetByPartialMovieName?name=" + name + "&from=" + from + "&nbrMax=" + nbrMax;
        return JsonConvert.DeserializeObject<List<MovieDTO>>(Get(url).Result, settings);
    }

    public List<MovieDTO>? GetAll(int from, int nbrMax)
    {
        string url = ApiUrl + "/GetAll?from=" + from + "&nbrMax=" + nbrMax;
        return JsonConvert.DeserializeObject<List<MovieDTO>>(Get(url).Result, settings);
    }

    public List<FullMovieDTO>? GetMovieByIdMovie(int idMovie)
    {
        string url = ApiUrl + "/GetMovieByIdMovie?idMovie=" + idMovie;
        return JsonConvert.DeserializeObject<List<FullMovieDTO>>(Get(url).Result, settings);
    }
}