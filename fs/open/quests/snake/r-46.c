inherit ROOM;

void create()
{
	set("short","蛇寨 中廳");
	set("long",@LONG
你來到了蛇寨的中半段，等於已經深入蛇寨中心，腳下有一條繩
索，似乎可以通往蛇寨的地下室，東西兩旁擺滿了許多的兵器與蛇籠
，看來你得小心一點才是。
LONG);
	set("no_transmit",1);
	set("exits",([
"east":__DIR__"r-47",
"west":__DIR__"r-55",
"down":__DIR__"r-45",
]));
	setup();
}
