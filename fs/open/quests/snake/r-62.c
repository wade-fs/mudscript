inherit ROOM;

void create()
{
	set("short","蛇寨 三層大廳");
	set("long",@LONG
這裡的空氣，較先前的更加難聞，除了酸臭味以外，另外還夾雜
著屍體的腐臭味，地上充滿了許多的蛆，也有許多的毒蛇爬行其間，
你甚至還看到一些蛇以吞食蛆為食物，真是令人大開眼界。
LONG);
	set("no_transmit",1);
	set("exits",([
"east":__DIR__"r-63",
"down":__DIR__"r-61",
]));
	setup();
}
