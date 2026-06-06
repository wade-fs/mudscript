// Room : /open/clan/sky-wu-chi/room/room107.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", " 碎石小路 4" );
	set( "object", ([
		"file5"    : "/open/fire-hole/obj/b-pill",
		"file1"    : "/open/fire-hole/obj/p-pill",
		"amount4"  : 37,
		"file2"    : "/open/fire-hole/obj/k-pill",
		"amount2"  : 32,
		"amount5"  : 5,
		"amount1"  : 5,
		"amount3"  : 31,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file4"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "owner", "kuraki" );
	set( "build", 10190 );
	set( "light_up", 1 );
	set( "long", @LONG
西方是眾所皆知的天極殿，東方則是雄偉豪放的鎮
天東門，往天極殿的路程雖不長，但卻也是一個鳥鳴常
叫的美好地方。路旁的樹叢有著許許多多的可愛動物，
活潑的向你討食物呢！看來並不只有天道無極的幫眾們
喜愛這裡了。

LONG);
	set( "clan_room", "天道無極" );
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"west"      : "/open/clan/sky-wu-chi/room/room105.c",
]) );
	set( "cmkroom", 1 );
	setup();

	}
