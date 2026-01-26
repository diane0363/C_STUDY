/*
모든 알파벳 출력
(for, continue, break)
*/

int main()
{
    int newLine = 1;

    for (char alp = 'A'; alp <= 'z'; ++alp)
    {
        printf("%c = %d\t", alp, alp);

        if (newLine % 5 == 0)
            printf("\n");
        else if ((alp >= 'Z' && alp < 'a'))
        {
            alp = 'a' - 1;
            printf("\n");
            continue;
        }
        newLine++;
    }
}