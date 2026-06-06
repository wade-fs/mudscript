inherit ROOM;

void create()
{
	set("short","地下通道");
	set("long",@LONG
    昏天暗地的洞穴內，可以依稀看到上面鬆軟的泥土還有些沙粒緩
緩掉落，四周傳來「ㄒ一、ㄙㄨㄛ」的聲音，令人不禁精神緊繃！
LONG);
	set("exits",([
	"west":__DIR__"u02",
	]));
	set("objects",([
	__DIR__"npc/earthworm":1,
	]));
	set("no_transmit",1);
	setup();
}
