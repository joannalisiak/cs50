#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validate_arguments(int arguments);
bool validate_key(string key);
bool validate_key_length(string key);
bool validate_key_alphabetic(string key);
bool validate_key_unique(string key);
char encrypt_character(char character, string key);


int main(int argc, string argv[])
{
    bool arguments_valid = validate_arguments(argc);
    if (arguments_valid != true)
    {
        return 1;
    }

    bool key_valid = validate_key(argv[1]);
    if (key_valid != true)
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string key = argv[1];

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char encrypted_character = encrypt_character(plaintext[i], key);
        printf("%c", encrypted_character);
    }
    printf("\n");

    return 0;

}

char encrypt_character(char character, string key)
{
    if (isalpha(character))
    {
        bool is_upper = isupper(character);

        character = toupper(character);
        char first_alphabet_letter = 'A';
        int index = character - first_alphabet_letter;
        char encrypted_character = key[index];

        if (!is_upper)
        {
            encrypted_character = tolower(encrypted_character);
        }

        return encrypted_character;
    }
    else
    {
        return character;
    }
}

bool validate_arguments(int arguments)
{
    bool valid = true;

    if (arguments != 2)
    {
        printf("Usage: ./substitution KEY\n");
        valid = false;
    }

    return valid;
}

bool validate_key(string key)
{
    bool valid = true;

    bool valid_length = validate_key_length(key);

    bool valid_alphabetic = validate_key_alphabetic(key);

    bool valid_unique = validate_key_unique(key);

    if (!valid_length || !valid_alphabetic || !valid_unique)
    {
        valid = false;
    }

    return valid;
}

bool validate_key_length(string key)
{
    bool valid = true;

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        valid = false;
    }

    return valid;
}

bool validate_key_alphabetic(string key)
{
    bool valid = true;

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            valid = false;
        }
    }

    return valid;
}

bool validate_key_unique(string key)
{
    bool valid = true;

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (key[i] == key[j])
            {
                printf("Key must not contain repeated characters.\n");
                valid = false;
            }
        }
    }

    return valid;
}
