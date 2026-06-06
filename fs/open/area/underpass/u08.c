inherit ROOM;

void create()
{
	set("short","地下通道");
	set("long",@LONG
    經過了剛剛的死鬥，終於來到了這裡，寬敞的空間讓你一吐剛剛
緊張的死鬥，一切看起來是如此的平靜，與剛剛生死之間相差甚遠，
四周依稀的可以看到黑影晃動，「看樣子還是小心點好」心中不禁冒
出這樣的想法！
LONG);
	set("exits",([
	"east":__DIR__"u07",
	"north":__DIR__"u09",
	"south":__DIR__"u10",
	"west":__DIR__"u11",
	]));
	set("no_transmit",1);
	setup();
}
