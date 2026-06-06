// Room : /open/clan/sky-wu-chi/room/room120.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$【$HIC$元氣門$HIW$】$NOR$" );
	set( "owner", "cong" );
	set( "object", ([
		"file4"    : "/open/magic-manor/obj/golden-ball",
		"file8"    : "/open/magic-manor/obj/wood-ball",
		"amount8"  : 1,
		"file7"    : "/open/mon/obj/mon-pill",
		"amount4"  : 1,
		"amount10" : 44,
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"file9"    : "/open/mogi/castle/obj/lochagem",
		"amount1"  : 1,
		"file6"    : "/open/mogi/castle/obj/sspill",
		"amount6"  : 10,
		"file1"    : "/open/magic-manor/obj/fire-ball",
		"amount7"  : 33,
		"amount3"  : 16291,
		"file3"    : "/open/killer/obj/hate_knife",
		"amount9"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10172 );
	set( "cmkroom", 1 );
	set( "long", @LONG
你往大門走近一看，門口上面大大正正的寫了二個字$HIC$元氣$NOR$(vigor)，你一看就明白了
這是霹靂貓所居住的地方，怪不得這邊傳來一陣陣的貓味，前面的兩名貓侍衛大概不
會讓你輕易通過吧，你心想，如果給他們一點Diamond，也許，就能見到霹靂貓本人了。

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"enter"     : "/open/clan/sky-wu-chi/room/room242.c",
]) );
	set( "clan_room", "天道無極" );
	setup();

	}
