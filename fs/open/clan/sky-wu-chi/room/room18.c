// Room : /open/clan/sky-wu-chi/room/room18.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "clan_room", "天道無極" );
	set( "long", @LONG
這裡是長長通道的開端，放眼望去這通道似乎是沒有盡
頭的，因為不管你怎麼看、怎麼用力的看，那盡頭似乎都隱
藏在遙不可及的盡頭、一個未可知的盡頭。你仔細觀察了四
週的擺設之後，終於決定孤卒一躑，頭也不回的往前大步走
去。

LONG);
	set( "short", "$HIC$馬房前的通道$NOR$" );
	set( "owner", "herozero" );
	set( "object", ([
		"amount10" : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/obj/wood-ball",
		"file10"   : "/open/magic-manor/obj/magic-sign",
		"amount1"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/ghost-hole/obj/light-spirit",
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 12169 );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"north"     : "/open/clan/sky-wu-chi/room/room79.c",
		"east"      : "/open/clan/sky-wu-chi/room/room150",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
]) );
	set( "no_clean_up", 0 );
	set( "cmkroom", 1 );
	setup();

	}
