inherit ROOM;
void create()
{
        set("short", "藥圃");
        set("long", @LONG
古云 :「醫者可救人，也可殺人。」這句話不假，現在在你眼前的都
是至毒之草，遍地都是，有奪命一瞬間的斷腸草，九節菖蒲，七日草等等
，但是你忽然想到，最毒之物，七步之內，必有解藥這句話。
LONG
        );
        set("can_search",1);
        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r5.c",
  "east" : __DIR__"r3.c",
]));
        set("no_clean_up", 0);

        setup();
        }


