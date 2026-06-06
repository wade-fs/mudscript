// Room : /open/clan/sky-wu-chi/room/room15.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "cmkroom", 1 );
	set( "light_up", 1 );
	set( "long", @LONG

這裡是我想上的小窩，但是我想上以前的名字好像叫死亡人生，
不知為何要改姓換明，是跟誰有關？看到門口的牌子會讓你想
一探究竟我想上神秘的房間，因為我想上總是喜歡稿東稿西的。
其門口除了房內好像北邊還有一個武道館，難道那是我想上開
的武館，沒想到這種人也會收徒弟。世界真奇妙。

LONG);
	set( "short", "水雁" );
	set( "owner", "cong" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room291",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "object", ([
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"amount9"  : 1,
		"file10"   : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"amount8"  : 1,
		"file8"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file5"    : "/autoload/killer/ski_dream",
		"file7"    : "/daemon/class/blademan/obj/shield",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
	]) );
	set( "build", 10027 );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	setup();

	}
