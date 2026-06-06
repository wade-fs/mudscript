// Room : /open/clan/sky-wu-chi/room/room103.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "short", " 碎石小路 2" );
	set( "object", ([
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/gsword/obj1/bbladeball",
		"file7"    : "/open/gsword/obj1/bbladeball",
		"amount1"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
		"file1"    : "/open/gsword/obj1/bbladeball",
		"amount6"  : 1,
		"file3"    : "/open/gsword/obj1/bbladeball",
		"amount10" : 1,
		"file8"    : "/open/gsword/obj1/bbladeball",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10072 );
	set( "light_up", 1 );
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
		"west"      : "/open/clan/sky-wu-chi/room/room104.c",
		"east"      : "/open/clan/sky-wu-chi/room/room4.c",
]) );
	set( "cmkroom", 1 );
	setup();

	}
