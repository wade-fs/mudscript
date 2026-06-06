// Room: /open/su/room/hall_2.c

inherit ROOM;

void create()
{
        set("short", "總衙前廳");
        set("long", @LONG
站在這裡，隱約可以聽到威武壯聲，似乎是無塵大人正在升堂。經
過這個前廳之後，就可以到達總衙大堂了。
LONG);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hall",
  "north" : __DIR__"hall_3",
]));

        setup();
}
