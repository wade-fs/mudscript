inherit ROOM;

void create()
{
	set("short","地下通道");
	set("long",@LONG
    地上有一條長長的爬行痕跡，周遭還有小小的足跡，很難想像是
何種生物生活在這種環境下。
LONG);
	set("exits",([
	"east":__DIR__"u01",
	"west":__DIR__"u03",
	]));
	set("objects",([
	__DIR__"npc/chimaera":1,
	]));
	set("no_transmit",1);
	setup();
}
