inherit ROOM;
void create()
{
        set("short", "藥圃");
  set ("long", @LONG

    這裡是藥材胚苗的存放室，一棟獨立的小間豎立
    在田埂的正中央，從那裡面傳來濃郁的青草味..

LONG);

        set("can_search",1);
        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r4",
  "north" : __DIR__"r6",
  "east" : __DIR__"r2",
]));
        set("no_clean_up", 0);

        setup();
        }


