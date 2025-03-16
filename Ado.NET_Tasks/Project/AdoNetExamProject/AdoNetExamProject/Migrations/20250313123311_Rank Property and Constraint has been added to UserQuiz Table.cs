using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace AdoNetExamProject.Migrations
{
    /// <inheritdoc />
    public partial class RankPropertyandConstrainthasbeenaddedtoUserQuizTable : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "Rank",
                table: "UserQuizzes",
                type: "int",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddCheckConstraint(
                name: "CK_Rank",
                table: "UserQuizzes",
                sql: "Rank >= 0");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropCheckConstraint(
                name: "CK_Rank",
                table: "UserQuizzes");

            migrationBuilder.DropColumn(
                name: "Rank",
                table: "UserQuizzes");
        }
    }
}
