inherit ROOM;
void create()
{
        set("short", "藥圃");
        set("long", @LONG

    這裡是園地內較高的坡地，所以在這裡建
    了一座高臺，用來晒曬剛採下的藥材。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"r11-1",
  "south" : __DIR__"r10",
  "east" : __DIR__"r8",
]));
        set("can_search",1);
        set("no_clean_up", 0);
        set("outdoors", 1);

        setup();
        }


