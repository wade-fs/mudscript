// Room : /open/clan/sky-wu-chi/room/room83.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "short", "$HIB$雷極殿$NOR$" );
	set( "object", ([
		"amount5"  : 1,
		"amount2"  : 95,
		"file9"    : "/open/fire-hole/obj/w-pill",
		"file5"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount3"  : 2,
		"file4"    : "/open/killer/obj/fire-knife",
		"amount9"  : 3,
		"file8"    : "/open/killer/obj/atman_pill",
		"amount7"  : 1,
		"file2"    : "/open/mon/obj/mon-pill",
		"file7"    : "/open/gsword/obj1/karmor",
		"amount8"  : 132,
		"amount4"  : 1,
	]) );
	set( "build", 10033 );
	set( "owner", "mudu" );
	set( "light_up", 1 );
	set( "long", @LONG
'在今日的fs,變態玩家層出不窮,連要賺個殺氣都有點困難,也因為如此
大家都想找殺手幫忙自己提升殺氣,所以殺手玩家變成每位玩家要打變態npc前的
尋找對象,wiz有鑑於此特地開放了一隻npc,用來提供玩家打些特定物品來換取你
所需要的殺氣,此處就存放著可以換取殺氣的物.
LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
		"west"      : "/open/clan/sky-wu-chi/room/room82",
		"mudu"      : "/open/clan/sky-wu-chi/room/room246",
]) );
	set( "cmkroom", 1 );
	setup();

	}
