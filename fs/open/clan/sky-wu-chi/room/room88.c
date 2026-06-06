// Room : /open/clan/sky-wu-chi/room/room88.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "short", "通道盡頭" );
	set( "owner", "herozero" );
	set( "object", ([
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 79,
		"file4"    : "/obj/gift/hobowdan",
		"amount8"  : 1,
		"amount2"  : 10,
		"amount4"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"file2"    : "/open/mogi/dragon/obj/power",
		"file1"    : "/open/doctor/pill/sky_pill",
		"amount3"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/obj/gift/shenliwan",
	]) );
	set( "light_up", 1 );
	set( "build", 10400 );
	set( "long", @LONG
這裡是通道的盡頭，來到這兒你不禁憋住呼吸，神經緊
張的東張西望，彷彿有什麼東西會突然從盡頭冒出來。但你
放眼望去，那盡頭卻又散發著和煦的光芒，這下你可丈二金
鋼般摸不著頭腦了。你低下頭，將腳步輕輕提起，小心翼翼
的往盡頭處走去，一邊走心中還一邊唸著阿彌陀佛，恨不得
這時佛祖就在你身邊。

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
		"south"     : "/open/clan/sky-wu-chi/room/room84",
]) );
	set( "cmkroom", 1 );
	setup();

	}
