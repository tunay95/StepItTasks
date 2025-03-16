using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace AdoNetExamProject.Migrations
{
    /// <inheritdoc />
    public partial class UserPasswordMinValueCheckConstrainthasbeenaddedtoUserTable : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddCheckConstraint(
                name: "CK_Password_MinValue",
                table: "Users",
                sql: "LEN([Password]) >= 6");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropCheckConstraint(
                name: "CK_Password_MinValue",
                table: "Users");
        }
    }
}
