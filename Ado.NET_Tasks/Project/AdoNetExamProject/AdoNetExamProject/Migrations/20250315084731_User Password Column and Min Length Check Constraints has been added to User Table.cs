using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace AdoNetExamProject.Migrations
{
    /// <inheritdoc />
    public partial class UserPasswordColumnandMinLengthCheckConstraintshasbeenaddedtoUserTable : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropIndex(
                name: "IX_Options_QuestionId_Text",
                table: "Options");

            migrationBuilder.AlterColumn<DateTime>(
                name: "BirthDate",
                table: "Users",
                type: "datetime2",
                nullable: true,
                oldClrType: typeof(DateTime),
                oldType: "datetime2");

            migrationBuilder.AddColumn<string>(
                name: "Password",
                table: "Users",
                type: "nvarchar(15)",
                maxLength: 15,
                nullable: false,
                defaultValue: "");

            migrationBuilder.AlterColumn<int>(
                name: "QuestionId",
                table: "Options",
                type: "int",
                nullable: true,
                oldClrType: typeof(int),
                oldType: "int");

            migrationBuilder.AlterColumn<bool>(
                name: "IsCorrect",
                table: "Options",
                type: "bit",
                nullable: true,
                oldClrType: typeof(bool),
                oldType: "bit");

            migrationBuilder.AddCheckConstraint(
                name: "CK_FirstName_MinValue",
                table: "Users",
                sql: "LEN([FirstName]) >= 3");

            migrationBuilder.AddCheckConstraint(
                name: "CK_LastName_MinValue",
                table: "Users",
                sql: "LEN([LastName]) >= 3");

            migrationBuilder.AddCheckConstraint(
                name: "CK_Username_MinValue",
                table: "Users",
                sql: "LEN([Username]) >= 5");

            migrationBuilder.AddCheckConstraint(
                name: "CK_Statement_MinValue",
                table: "Questions",
                sql: "LEN([Statement]) >= 3");

            migrationBuilder.CreateIndex(
                name: "IX_Options_QuestionId_Text",
                table: "Options",
                columns: new[] { "QuestionId", "Text" },
                unique: true,
                filter: "[QuestionId] IS NOT NULL");

            migrationBuilder.AddCheckConstraint(
                name: "CK_CategoryName_MinValue",
                table: "Categories",
                sql: "LEN([Name]) >= 3");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropCheckConstraint(
                name: "CK_FirstName_MinValue",
                table: "Users");

            migrationBuilder.DropCheckConstraint(
                name: "CK_LastName_MinValue",
                table: "Users");

            migrationBuilder.DropCheckConstraint(
                name: "CK_Username_MinValue",
                table: "Users");

            migrationBuilder.DropCheckConstraint(
                name: "CK_Statement_MinValue",
                table: "Questions");

            migrationBuilder.DropIndex(
                name: "IX_Options_QuestionId_Text",
                table: "Options");

            migrationBuilder.DropCheckConstraint(
                name: "CK_CategoryName_MinValue",
                table: "Categories");

            migrationBuilder.DropColumn(
                name: "Password",
                table: "Users");

            migrationBuilder.AlterColumn<DateTime>(
                name: "BirthDate",
                table: "Users",
                type: "datetime2",
                nullable: false,
                defaultValue: new DateTime(1, 1, 1, 0, 0, 0, 0, DateTimeKind.Unspecified),
                oldClrType: typeof(DateTime),
                oldType: "datetime2",
                oldNullable: true);

            migrationBuilder.AlterColumn<int>(
                name: "QuestionId",
                table: "Options",
                type: "int",
                nullable: false,
                defaultValue: 0,
                oldClrType: typeof(int),
                oldType: "int",
                oldNullable: true);

            migrationBuilder.AlterColumn<bool>(
                name: "IsCorrect",
                table: "Options",
                type: "bit",
                nullable: false,
                defaultValue: false,
                oldClrType: typeof(bool),
                oldType: "bit",
                oldNullable: true);

            migrationBuilder.CreateIndex(
                name: "IX_Options_QuestionId_Text",
                table: "Options",
                columns: new[] { "QuestionId", "Text" },
                unique: true);
        }
    }
}
