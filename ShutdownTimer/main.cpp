#include <cstdlib>
#include <iostream>

using namespace std;

void ConvTime();

int main() {
    int i;

    while(1)
    {

        cout
                << "1. Shut PC down with timer \n2. Shut PC down normally (takes about half a minute) \n3. restart PC \n4. Cancel \n5. Exit"
                << endl;

        cin >> i;

        switch (i) {
            case 1: {
                ConvTime();
                break;
            }

            case 2: {
                system("shutdown -s");
                break;
            }

            case 3: {
                system("shutdown -r");
                break;
            }

            case 4: {
                system("shutdown -a");
                break;
            }

            case 5: {
                return 0;
            }

            default:
                return 0;
        }
    }
}

void ConvTime()
{
    char txt[25] ="shutdown -s -t ";
    int timer;

    cout << "Choose the amount of time for the timer:" << endl << "maximum amount of minutes = 166" << endl;
    cin >> timer;

    if(timer > 166)
        return;

    timer *= 60;

    for(int i = 0; i < 4; i++)
    {
        txt[14+(4-i)]=(timer % 10) + 48;

        timer /= 10;
    }

    system(txt);

    return;
}