#
include < stdio.h > #include < conio.h > #include < graphics.h >

    void main() {

        int x, y;
        int l, r, d, u;

        char ch;

        int a[8][2];

        int i, j, k;
        int key;

        int c;
        int b;
        int f;

        int gd = DETECT, gm;
        initgraph( & gd, & gm, "C:\\TC\\BGI");
        cleardevice();
        clrscr();

        ch = 'y';

        while (ch == 'y' || ch == 'Y') {

            a[7][0] = 330;
            a[7][1] = 240;

            a[6][0] = 340;
            a[6][1] = 240;

            a[5][0] = 350;
            a[5][1] = 240;

            a[4][0] = 360;
            a[4][1] = 240;

            a[3][0] = 370;
            a[3][1] = 240;

            a[2][0] = 380;
            a[2][1] = 240;

            a[1][0] = 390;
            a[1][1] = 240;

            a[0][0] = 400;
            a[0][1] = 240;

            l = r = u = d = 0;
            x = y = 0;
            r = 1;

            j = 8;
            f = 0;

            setbkcolor(7);

            for (;;) /*  start of main  loop   */ {

                for (k = 1; k < j; k++) {
                    if ((a[0][0]) == a[k][0] && a[0][1] == a[k][1])
                        f = 1;
                }

                if ((a[0][0] + 10) == 640 || (a[0][0]) == 0 || a[0][1] == 0 || (a[0][1] + 10) == 480 || f == 1) /*  boundary  collision   */
                    break;

                for (k = 0; k < j; k++) /*   printing the snake parts  */ {
                    setfillstyle(SLASH_FILL, YELLOW);
                    bar(a[k][0], a[k][1], a[k][0] + 10, a[k][1] + 10);
                }

                if (kbhit()) /*  keyboard hit check   */ {
                    c = getch();
                    if (c != 0)
                        goto SKIP;
                    b = getch();
                }

                if (b == 80 && u != 1) /*    down key check  */ {
                    d = 1;
                    l = r = u = 0;
                }

                if (b == 72 && d != 1) /*  up key check   */ {
                    u = 1;
                    l = r = d = 0;
                }

                if (b == 75 && r != 1) /*  left key check  */ {
                    l = 1;
                    d = r = u = 0;
                }

                if (b == 77 && l != 1) /*  right key check  */ {
                    r = 1;
                    l = d = u = 0;
                }

                SKIP:

                    for (i = j - 1; i > 0; i--) /*  values swapping   */ {
                        a[i][0] = a[i - 1][0];
                        a[i][1] = a[i - 1][1];

                    }

                if (r == 1) {
                    a[0][0] += 10;

                }

                if (d == 1) {
                    a[0][1] += 10;

                }

                if (l == 1) {
                    a[0][0] -= 10;

                }

                if (u == 1) {
                    a[0][1] -= 10;

                }

                delay(80);
                cleardevice();

            }

            sound(500);
            delay(200);
            sound(400);
            delay(200);
            sound(150);
            delay(100);
            nosound();

            settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
            outtextxy(55, 320, "YOU FAILED!!!  ");

            settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
            outtextxy(25, 360, "WANNA PLAY AGAIN PRESS 'Y' ELSE 'N' ");

            KEYPRESS:
                ch = getche();

            if (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')
                goto KEYPRESS;

            cleardevice();

        }

        closegraph();
    }
