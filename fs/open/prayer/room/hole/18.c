///open/prayer/room/hole/18.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	地上一些魔獸的爪印比一般人的手有數倍之大，萬一這爪子打在人
	的身上，可不是"如稻草般飛出去"而已，你不禁頭皮發麻，打了個
	哆嗦，心想不入虎穴，焉得虎子，老子豁出去了.....

LONG	);
    set("objects", ([ /* sizeof() == 2 */
   "/open/prayer/npc/cuirass-dragon" : 1,		
   "/open/prayer/npc/carapace-bee" : 1,		
]));
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"9",
  "west" : __DIR__"8",
  "south":__DIR__"20",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
