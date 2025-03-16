using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace AdoNetExamProject.Migrations
{
    /// <inheritdoc />
    public partial class UniquewasreassignedaccordingtothequestionId : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropIndex(
                name: "IX_Options_QuestionId",
                table: "Options");

            migrationBuilder.DropIndex(
                name: "IX_Options_Text",
                table: "Options");

            migrationBuilder.CreateIndex(
                name: "IX_Options_QuestionId_Text",
                table: "Options",
                columns: new[] { "QuestionId", "Text" },
                unique: true);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropIndex(
                name: "IX_Options_QuestionId_Text",
                table: "Options");

            migrationBuilder.CreateIndex(
                name: "IX_Options_QuestionId",
                table: "Options",
                column: "QuestionId");

            migrationBuilder.CreateIndex(
                name: "IX_Options_Text",
                table: "Options",
                column: "Text",
                unique: true);
        }
    }
}
