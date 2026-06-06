inherit ROOM;
void create()
{
        set("short", "藥圃");
        set("long", @LONG

    靠著彎延的小路你來到了這裡，發覺這裡的藥草
    與中土的不大一樣，抬頭看了看掛在樹上的指標
    ，上面寫的:

          一號栽種區: 南蠻藥草試種實驗地區。
                                                          
LONG
        );
        set("can_search",1);
        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"r5.c",
  "south" : __DIR__"r3.c",
  "north" : __DIR__"r1.c",
]));
        set("no_clean_up", 0);

        setup();
        }


