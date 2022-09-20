namespace DTO
{
    public class MovieTypeDTO
    {
        public int TypeId { get; set; }
        public string Name { get; set; }
        
        public MovieTypeDTO() {}

        public MovieTypeDTO(int id, string name)
        {
            TypeId = id;
            Name = name;
        }
    }
}