using Microsoft.EntityFrameworkCore;
using System.Configuration;

namespace DAL;

public class MyDBContext : DbContext
{
    public DbSet<Movie> Movies { get; set; }
    public DbSet<Actor> Actors { get; set; }
    public DbSet<Director> Directors { get; set; }
    public DbSet<Type> Types { get; set; }
    public DbSet<Comment> Comments { get; set; }
    
    /*
    public MyDBContext() : base("MyContextDB")
    {
        //Database.SetInitializer<MyDBContext>(new MyInitializer());
    }
    */
    public MyDBContext() : base(new DbContextOptions<MyDBContext>())
    {
    }
    
    
    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        string connect = "Host=" + ConfigurationManager.AppSettings["Host"];
        connect += ";Port=" + ConfigurationManager.AppSettings["Port"];
        connect += ";Database=" + ConfigurationManager.AppSettings["Database"];
        connect += ";Username=" + ConfigurationManager.AppSettings["Username"];
        connect += ";Password=" + ConfigurationManager.AppSettings["Password"];

        connect = "Host=localhost;Port=5432;Database=postgres;Username=postgres;Password=123";

        optionsBuilder.UseNpgsql(@connect);
    }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<Movie>().ToTable("Movies");
        modelBuilder.Entity<Actor>().ToTable("Actors");
        modelBuilder.Entity<Director>().ToTable("Directors");
        modelBuilder.Entity<Type>().ToTable("Types");
        modelBuilder.Entity<Comment>().ToTable("Comments");
    }
}
