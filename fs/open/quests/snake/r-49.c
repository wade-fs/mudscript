inherit ROOM;

void create()
{
	set("short","蛇寨 中廳");
	set("long",@LONG
你的眼睛掃過放置於牆角旁的櫃子，上面擺滿了密密麻麻的藥罐
，一旁放置著一些刑具與刑台，上面還有幾條被剝了皮的蛇，與拔了
毒牙的蛇，還不斷的蠕動著，看起來十分的噁心。
LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/crazy_snake":2,
]));
	set("exits",([
"west":__DIR__"r-50",
"north":__DIR__"r-48",
]));
	setup();
}
