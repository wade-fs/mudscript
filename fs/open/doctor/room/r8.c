inherit ROOM;
void create()
{
        set("short", "藥圃");
  set ("long", @LONG

   這裡有著整齊的花圃，正是銀針門的栽種區..

LONG);
        set("can_search",1);
        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r9",
  "north" : __DIR__"r7",
  "west" : __DIR__"r11",
]));
        set("no_clean_up", 0);

        setup();
        }


