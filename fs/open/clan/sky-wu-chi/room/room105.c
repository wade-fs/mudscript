// Room : /open/clan/sky-wu-chi/room/room105.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", " 碎石小路 3" );
	set( "object", ([
		"amount8"  : 1,
		"file7"    : "/open/doctor/obj/feather",
		"amount9"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/gblade/obj/sa-head",
		"amount1"  : 406,
		"amount5"  : 1,
		"file9"    : "/open/ghost-hole/obj/light-spirit",
		"amount3"  : 1,
		"file4"    : "/open/mogi/dragon/obj/dragon-head",
		"amount2"  : 1,
		"file6"    : "/open/doctor/obj/feather",
		"amount7"  : 1,
		"file3"    : "/open/mogi/dragon/obj/dragon-head",
		"file8"    : "/open/doctor/obj/feather",
		"amount4"  : 1,
		"file1"    : "/obj/poison/faint_poison",
		"file5"    : "/open/mogi/dragon/obj/dragon-head",
	]) );
	set( "build", 14251 );
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
		"west"      : "/open/clan/sky-wu-chi/room/room6.c",
		"east"      : "/open/clan/sky-wu-chi/room/room107.c",
]) );
	set( "cmkroom", 1 );
	setup();

	}
