/**/

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <fcntl.h>

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    
    return 0;
}

void clear_screen() {
    printf("\033[2J\033[H");
}


int main(){

    int duration;
    printf("Enter clock duration in seconds: ");
    scanf("%d", &duration);
    while(getchar() != '\n');

    time_t start_time = time(NULL);
    int elapsed = 0;

    printf("Clock starting! Press any key to stop...\n");
    sleep(2);

    while (elapsed < duration)
    {
        clear_screen();

        elapsed = (int)difftime(time(NULL), start_time);
        int remaining = duration - elapsed;
        int minutes = elapsed / 60;
        int seconds = elapsed % 60;

        printf("\n");
        printf("    ┌────────────┐\n");
        printf("    │    %02d:%02d   │\n", minutes, seconds);
        printf("    └────────────┘\n");
        printf("\n");
        printf("        Elapsed:   %d seconds\n", elapsed);
        printf("      Remaining: %d seconds\n", remaining);
        printf("      Progress:  [");

        int progress = (elapsed * 20) / duration;
        for (int i = 0; i < 20; i++)
        {
            if (i < progress) printf("█");
            else printf("░");
        }
        printf("] %d%%\n", (elapsed * 100) / duration);

        if (kbhit())
        {
            printf("\n    Stopped by user after %d seconds!\n", elapsed);
            break;
        }
        
        sleep(1);
    }
    
    if (elapsed >= duration) {
        printf("\n    Time's up! %d seconds completed.\n", duration);
    }  

    return 0;
}

