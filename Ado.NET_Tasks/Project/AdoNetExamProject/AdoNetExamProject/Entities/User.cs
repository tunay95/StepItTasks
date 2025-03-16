namespace AdoNetExamProject.Entities;

public enum UserRole
{
    Admin,
    User
}

public class User
{
    public int Id { get; set; }
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public string Username { get; set; }
    public string Password { get; set; }
    public DateTime? BirthDate { get; set; }
    public UserRole? UserRole { get; set; }
    public List<UserQuiz> UserQuizzes { get; set; } = [];

}
