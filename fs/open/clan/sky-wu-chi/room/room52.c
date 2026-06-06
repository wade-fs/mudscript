// Room : /open/clan/sky-wu-chi/room/room52.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
眼觀四面，耳聽八方，來到了二樓，不禁感到
想不到世上美的地方，盡是在眼前，正是自已所身
處的世界，想不到把眼光看得遠一點，就能得到如
此的體會，那心裡也想到登高必自彌，覺得人外有
人，山外有山，這層道理了。

LONG);
	set( "short", "$HIC$通天閣二樓$NOR$" );
	set( "owner", "conpse" );
	set( "object", ([
		"amount6"  : 1,
		"file9"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "build", 10005 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room40",
	]) );
	set( "light_up", 1 );
	set( "item_desc", ([ /* sizeof() == 1 */
  "window" : "中央驛站 - 
    這兒就是最最出名的驛站，鑣局的車隊, 來往於沙漠的駱駝隊, 甚
至是牛馬騾車, 幾乎只要你叫得出名字的交通工具這兒都有。
    白雲在天空中飄來飄去。
    太陽剛從東方的地平線升起。
   「小辣椒」賣火柴的小辣妹(Sale girl)




ㄟ～～～這邊看得到中央驛站耶
",
]) );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
