// Room : /open/clan/sky-wu-chi/room/room114.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "cmkroom", 1 );
	set( "item_desc", ([ /* sizeof() == 1 */
  "board" : "這裡是屋主 太子(James)的發呆、蹲內力、休息..之處。
",
]) );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
		"west"      : "/open/clan/sky-wu-chi/room/room113.c",
]) );
	set( "short", "小飛俠‧神秘小屋" );
	set( "owner", "heronotme" );
	set( "object", ([
		"file10"   : "/open/mon/obj/ghost-legging",
		"amount10" : 1,
		"amount5"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file4"    : "/daemon/class/fighter/armband",
		"amount7"  : 1,
		"amount1"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"amount8"  : 1,
		"file2"    : "/open/scholar/obj/icefan",
		"amount2"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file3"    : "/open/port/obj/wolf_ring",
		"amount3"  : 1,
		"file5"    : "/daemon/class/fighter/figring",
		"amount9"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10004 );
	set( "long", @LONG
    西方是眾所皆知的天極殿，東方則是雄偉豪放的鎮
天東門，往天極殿的路程雖不長，但卻也是一個鳥鳴常
叫的美好地方。路旁的樹叢有著許許多多的可愛動物，
活潑的向你討食物呢！看來並不只有天道無極的幫眾們
喜愛這裡了。
LONG);
	set( "no_transmit", 1 );
	setup();

	}
