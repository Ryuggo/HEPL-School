using Newtonsoft.Json;

namespace APIContactor.TMDB;

public class TmdbContactor
{
    private HttpClient Client { get; set; }
    public string ApiUrl { get; set; }

    public TmdbContactor(string url, HttpClient cl)
    {
        ApiUrl = url;
        Client = cl;
    }

    public async Task<string> Get(string url)
    {
        HttpResponseMessage responseMessage = await Client.GetAsync(url).ConfigureAwait(false);
        //responseMessage.EnsureSuccessStatusCode();
        return await responseMessage.Content.ReadAsStringAsync().ConfigureAwait(false);
    }
    public async Task<string> Post(string url, string json)
    {
        StringContent queryString = new StringContent(JsonConvert.SerializeObject(json));

        HttpResponseMessage responseMessage = await Client.PostAsync(url, queryString).ConfigureAwait(false);
        responseMessage.EnsureSuccessStatusCode();
        return await responseMessage.Content.ReadAsStringAsync().ConfigureAwait(false);
    }
    public async Task<string> Delete(string url)
    {
        HttpResponseMessage responseMessage = await Client.DeleteAsync(url).ConfigureAwait(false);
        responseMessage.EnsureSuccessStatusCode();
        return await responseMessage.Content.ReadAsStringAsync().ConfigureAwait(false);
    }


    public string GetToken(string apiKey)
    {
        string url = ApiUrl + "/authentication/token/new?api_key=" + apiKey;
        var result = ResultToString(Get(url).Result);

        if(result["\"success\""] == "true")
            return result["\"request_token\""].Trim('\"');
        return "";
    }

    public string PostCreateSession(string apiKey, string token)
    {
        string url = ApiUrl + "/authentication/session/new?api_key=" + apiKey;
        var result = ResultToString(Post(url, token).Result);

        if (result["\"success\""] == "true")
            return result["\"session_id\""].Trim('\"');
        return "";
    }


    public string GetMovieImage(string apiKey, int id)
    {
        string url = ApiUrl + "/movie/" + id + "/images?api_key=" + apiKey;
        string tmp = Get(url).Result;
        string[] success = tmp.Split("{\"success\":");

        if(success.Length <= 1)
        {
            string[] result = tmp.Split("file_path\":\"");
            result = result[result.Length - 1].Split("\",\"");

            return result[0];
        }
        return "";
    }

    public void DelSession(string apiKey)
    {
        string url = ApiUrl + "/authentication/session?api_key=" + apiKey;
        Task<string> task = Delete(url);
    }

    private Dictionary<string, string> ResultToString(string result)
    {
        char[] trim = { '{', '}' };
        return result.Trim(trim)
                    .Split(',')
                    .Select(x => x.Split(':'))
                    .ToDictionary(x => x[0], x => x[1]);
    }
} 