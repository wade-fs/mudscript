///open/prayer/room/hole/4.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	走到這裡,血紅色的濃霧越來越濃,腥味撲鼻,整個胃都開始翻攪
	起來!!偶爾還有聽到悉索悉索的聲音!!難不成是怪物要出現了.
	...... 

LONG	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"3",
	"east":__DIR__"12",
	"west":__DIR__"11",
]));
        set("objects",([ /* sizeof() == 1 */
	"/open/prayer/npc/ditail-snake2" : 1,
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
