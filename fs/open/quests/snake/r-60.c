inherit ROOM;

void create()
{
	set("short","蛇寨 二層迴廊");
	set("long",@LONG
迴廊不斷的延伸，陰暗與潮濕的氣味也漸漸地加重，一股酸臭味
使你忍不住地摀住鼻子，兩旁的石壁迫使著你只能照著唯一的通道行
走，你無奈的搖了搖頭，只好捏著鼻子繼續趕路。
LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/crazy_snake":3,
]));
	set("exits",([
"south":__DIR__"r-59",
"west":__DIR__"r-61",
]));
	setup();
}
