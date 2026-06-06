// Room: /open/port/room/r3-4.c

inherit ROOM;

void create()
{
        set("short", "東大街");
        set("long", @LONG

    北邊是間醫館，想必就是與金刀門併稱金刀銀針的《銀針門》，
而兩派掌門之間交情頗深，且忌惡如仇，但銀針門並不像金刀門一樣
讓人感覺富麗堂皇，反而使人感覺非常寒酸，但是從外面看起來卻十
分的乾淨。

LONG
        );
        set("light_up", 1);
        set("objects", ([ ]));
        set("outdoors", "/open/port");
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"r3-3",
  "north" : "/open/doctor/room/d1",
  "south" : __DIR__"r3-6",
]));
        set("no_clean_up", 0);

        setup();
        }


