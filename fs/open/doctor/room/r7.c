inherit ROOM;

void create()
{
        set("short", "藥圃");
        set("long", @LONG

    經過迷陣的傳送，你來到了這裡，大概素玩迷宮太
    久了，這裡的景物有一點模模糊糊的。

LONG
        );
        set("can_search",1);
        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r6",
  "south" : __DIR__"r8",
]));
        set("no_clean_up", 0);

        setup();
        }


