#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void definirCor();
void cls();
void sleep_ms(unsigned int milliseconds);
void printSlow(const char* str, unsigned int delay);
void stats();
void readMessages();
void inventory();
void login();
void config();
void lerSenha();
void printPuzzle();
void puzzle();

int genRandInt(int menorI, int maiorI) {
    return (rand() % (maiorI - menorI + 1)) + menorI;
}

char senha[6], senhaCerta[6];
int aleatSenha, attempts = 3, resp;

void cls() {
    system(
        #ifdef _WIN32
            "cls"
        #else
            "clear"
        #endif
    );
}

void definirCor() {
    #ifdef _WIN32
        system("color A");
    #else
        printf("\033[0;32m");
    #endif
}

void gerarSenha() {
    aleatSenha = genRandInt(1,3);
    switch (aleatSenha) {
    case 1:
        senhaCerta[0] = 'r';
        senhaCerta[1] = 'o';
        senhaCerta[2] = 'm';
        senhaCerta[3] = 'a';
        senhaCerta[4] = 'n';
        break;
    case 2:
        senhaCerta[0] = 'g';
        senhaCerta[1] = 'r';
        senhaCerta[2] = 'e';
        senhaCerta[3] = 'e';
        senhaCerta[4] = 'k';
        break;
    case 3:
        senhaCerta[0] = 't';
        senhaCerta[1] = 'i';
        senhaCerta[2] = 't';
        senhaCerta[3] = 'a';
        senhaCerta[4] = 'n';
        break;
    default:
        senhaCerta[0] = 'c';
        senhaCerta[1] = 'r';
        senhaCerta[2] = 'e';
        senhaCerta[3] = 'e';
        senhaCerta[4] = 'p';
        break;
    }
}

void aleatoriedades() {
    gerarSenha();
}

void sleep_ms(unsigned int milliseconds) {
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        usleep(milliseconds * 1000);
    #endif
}

void printSlow(const char* str, unsigned int delay) {
    while (*str) {
        putchar(*str++);
        fflush(stdout);
        sleep_ms(delay);
    }
}

void stats() {
    cls();
    printSlow("Vault Statistics\n", 5);
    printf("\n");
    printSlow("Number of Residents: 279\n", 5);
    printSlow("Power Supply: 87%\n", 5);
    printSlow("Water Supply: 93%\n", 5);
    printSlow("Food Supply: 98%\n", 5);
    printSlow("Security Status: Secure\n", 5);
    printSlow("\nPress Enter to return to the main menu...", 5);
    getchar();
    getchar();
    login();
}

void readMessages() {
    cls();
    printSlow("Reading Messages...\n", 5);
    printf("\n");
    printSlow("Message from Vault 102:\n"
    "\"We are running low on water supply. Any assistance would be appreciated.\"\n\n"
    "Message from Vault 103:\n"
    "\"Our security system has malfunctioned. We are in need of technical support.\"\n\n"
    "Message from Vault 104:\n"
    "\"Celebrating 10 years of stable living. Thanks to Vault-Tec!\"\n",2);
    printSlow("\nPress Enter to return to the main menu...", 5);
    getchar();
    getchar();
    login();
}

void inventory() {
    cls();
    int invResp;
    printSlow("Which part of the inventory do you want to see ?\n\n",5);
    printSlow(
        "1 - Food Supplies\n"
        "2 - Medical Supplies\n"
        "3 - Weapons\n"
        "4 - Ammunition\n"
        "5 - Return\n"
        ": ",1);
    scanf(" %d", &invResp);
    switch (invResp) {
    case 1:
        cls();
        printSlow("Food Supplies:\n\n"
        "- 548 units of Canned Beans\n"
        "- 367 units of Purified Water\n"
        "- 219 units of Cram\n"
        "- 155 units of Blamco Mac & Cheese\n"
        "\nPress Enter to return to the inventory...", 5);
        getchar();
        getchar();
        inventory();
        break;
    case 2:
        cls();
        printSlow("Medical Supplies:\n\n"
        "- 58 units of Stimpaks\n"
        "- 34 units of RadAway\n"
        "- 25 units of Rad-X\n"
        "- 17 units of Anabol\n"
        "\nPress Enter to return to the inventory...", 5);
        getchar();
        getchar();
        inventory();
        break;
    case 3:
        cls();
        printSlow("Weapons:\n\n"
        "- 7x Laser Rifle\n"
        "- 25x 10mm Pistol\n"
        "- 5x Combat Shotgun\n"
        "- 5x Gauss Rifle\n"
        "- 1x Fat Man\n"
        "- 3x Plasma Gun\n"
        "\nPress Enter to return to the inventory...", 5);
        getchar();
        getchar();
        inventory();
        break;
    case 4:
        cls();
        printSlow("Ammunition:\n\n"
        "- 431 microfusion cells\n"
        "- 987 rounds of 10mm\n"
        "- 522 rounds of .308\n"
        "- 385 rounds of Shotgun Shells\n"
        "- 1 Mini Nuke\n"
        "\nPress Enter to return to the inventory...", 5);
        getchar();
        getchar();
        inventory();
        break;
    case 5:
        login();
        break;
    default:
        login();
        break;
    }
}

void login() {
    cls();
    printSlow("Property of Vault-Tec\n", 5);
    printSlow("Welcome Overseer\n", 5);
    printSlow("What would you like to do ?\n\n", 5);
    printSlow(
        "1 - Vault Stats\n"
        "2 - Read Messages\n"
        "3 - Inventory\n"
        "4 - Config\n"
        "5 - Exit\n\n"
        ": ",1);
    scanf(" %d", &resp);
    switch(resp) {
        case 1:
            stats();
            break;
        case 2:
            readMessages();
            break;
        case 3:
            inventory();
            break;
        case 4:
            config();
            break;
        case 5:
            cls();
            printSlow("Thank You For Choosing Vault-Tec!", 5);
            sleep_ms(2500);
            break;            
        default:
            break;
    }
}

void config() {
    cls();
    printSlow("Vault 101 Configuration\n\n"
    "1 - Turret Control\n"
    "2 - Vault Door Control\n"
    "3 - Lighting Control\n"
    "4 - Climate Control\n"
    "5 - Back to Main Menu\n\n"
    ": ",5);
    int configResp;
    scanf(" %d", &configResp);
    switch (configResp) {
        case 1:
            cls();
            printSlow("Turret Control\n\n"
            "Status: Online\n"
            "Mode: Defensive\n"
            "\nPress Enter to return to the configuration menu...",5);
            getchar();
            getchar();
            config();
            break;
        case 2:
            cls();
            printSlow("Vault Door Control\n\n"
            "Status: Closed\n"
            "Override: Available\n"
            "\nPress Enter to return to the configuration menu...",5);
            getchar();
            getchar();
            config();
            break;
        case 3:
            cls();
            printSlow("Lighting Control\n\n"
            "Status: Normal\n"
            "Override: Available\n"
            "\nPress Enter to return to the configuration menu...",5);
            getchar();
            getchar();
            config();
            break;
        case 4:
            cls();
            printSlow("Climate Control\n\n"
            "Temperature: 22 C\n"
            "Humidity: 45%%\n"
            "\nPress Enter to return to the configuration menu...",5);
            getchar();
            getchar();
            config();
            break;
        case 5:
            login();
            break;
        default:
            config();
            break;
    }
}

void lerSenha() {
    printSlow("Enter Password Now: ", 5);
    fgets(senha, 6, stdin);
    size_t len = strlen(senha);
    if (len > 0 && senha[len - 1] == '\n') {
        senha[len - 1] = '\0';
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void printPuzzle() {
    printSlow(
      "\n0xFac69 ->/]{/.appl}  0xFa@EA ->:|/*&flake\n"
        "0xFad2k ->e]:$|+[;3!  0xFadEE ->;:>&#¨0}-@\n"
        "0xFadEA ->build}-(+@  0xFad02 ->^greek_$(<\n"
        "0xFadEC ->+./^/titan  0xFadE6 ->@*{&,/}*/:\n"
        "0xFadE6 ->@*{&,/}*/:  0xFadEC ->+./^/roman\n"
        "0xFad02 ->^blush_$(<  0xFadEA ->creep}-(+@\n"
        "0xFadEE ->;:>&#*0}-@  0xFad2k ->*]:$|+[;3!\n"
        "0xFa@EA ->:|/*&where  0xFac69 ->/]{/stake}\n\n"
    , 1);
}

void puzzle() {
    cls();
    printSlow("Wrong Password!", 5);
    sleep_ms(2000);
    cls();
    printSlow("ROBCO Industries (TM) Termlink Protocol\n", 5);
    switch (attempts) {
        case 3:
            printSlow("3 attempts Left!\n", 5);
            break;
        case 2:
            printSlow("2 attempts Left!\n", 5);
            break;   
        case 1:
            printSlow("1 attempt Left!\n", 5);
            break;     
        default:
            break;
    }
    printPuzzle();
    lerSenha();
    if (strcmp(senha, senhaCerta) == 0) {
        cls();
        printSlow("Access Granted!\n", 5);
        sleep_ms(2500);
        login();
    } else {
        attempts--;
        if (attempts == 0) {
            cls();
            printSlow("Terminal Blocked!\n", 5);
            sleep_ms(2500);
        } else {
            puzzle(); 
        }
    }
}

int main() {
    srand(time(NULL));
    aleatoriedades();
    definirCor();
    cls();
    sleep_ms(1000);
    printSlow("Welcome to ROBCO Industries (TM) Termlink\n", 5);
    printSlow("Clearance: Overseer Eyes Only\n\n", 5);
    lerSenha();
    if (strcmp(senha, senhaCerta) == 0) {
        cls();
        printSlow("Access Granted!\n", 5);
        sleep_ms(2500);
        login();
    } else {
        puzzle();
    }
    return 0;
}
