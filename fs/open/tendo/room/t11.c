// Room: /open/tendo/room/t09.c

inherit ROOM;

void create()
{
	set("short", "集書房");
	set("long", @LONG
淡淡的書味，混雜著若有似無的幽香。一排排的書架上堆滿了大
大小小書籍。除了四書五經之外，大部分都是關於法術和煉藥的書冊
，其中也不乏流傳已久的古書和捲軸。一位少女正辛勤地整理書架上
凌亂的書本。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"t10",
]));
        set("objects",([
	"/open/tendo/npc/chii" : 1,
        ]));
	set("light_up",1);
	setup();
}
