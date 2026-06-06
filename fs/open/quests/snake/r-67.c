inherit ROOM;

void create()
{
	set("short","蛇寨 副蛇座");
	set("long",@LONG
在你眼前有一座巨大的蛇雕座椅，十分的尊貴華麗，每片蛇鱗片
都是用價值不斐的翡翠作成的，蛇眼是有著鮮血般紅焰的紅寶石所製
成的，座椅是雪片白般的大理石，極度奢侈的一個蛇型座椅。
LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/liu_snake":1,
]));
	set("exits",([
"south":__DIR__"r-66",
"north":__DIR__"r-68",
]));
	setup();
}
