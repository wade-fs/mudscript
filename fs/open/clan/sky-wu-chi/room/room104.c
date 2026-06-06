// Room : /open/clan/sky-wu-chi/room/room104.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "short", " 碎石小路 1" );
	set( "owner", "babycome" );
	set( "light_up", 1 );
	set( "object", ([
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 1,
		"file3"    : "/open/gsword/obj1/bpball",
		"file8"    : "/open/gsword/obj1/bpball",
		"file1"    : "/open/fire-hole/obj/w-pill",
		"amount2"  : 55,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"amount1"  : 18,
		"file2"    : "/open/fire-hole/obj/k-pill",
		"amount3"  : 1,
		"file4"    : "/open/gsword/obj1/bpball",
		"file10"   : "/open/gsword/obj1/bpball",
		"amount5"  : 2,
		"amount8"  : 1,
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 1,
		"amount6"  : 7,
	]) );
	set( "build", 10109 );
	set( "long", @LONG
東方是眾所皆知的天極殿，西方則是雄偉豪放的鎮
天西門，往天極殿的路程雖不長，但卻也是一個鳥鳴常
叫的美好地方。路旁的樹叢有著許許多多的可愛動物，
活潑的向你討食物呢！看來並不只有天道無極的幫眾們
喜愛這裡了。

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
		"east"      : "/open/clan/sky-wu-chi/room/room103.c",
]) );
	set( "cmkroom", 1 );
	setup();

	}
