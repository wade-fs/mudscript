// Room : /open/clan/sky-wu-chi/room/room112.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
你進入了太子的神秘小屋裡..看著裡面的裝飾，使你感覺到有一
股很神秘的力量似的！你無意間看到牆上懸掛著一個$HIY$告示板 (Board)$NOR$
，在往裡面走看到了許多奇奇怪怪的物品，讓你看都看不懂..導致你
頭昏腦脹的很不舒服！恨不得趕緊離開此地..
　　　　　　　　$HIC$(此地凝聚一股很強大的寒氣)$NOR$

LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
  "out" : "/open/clan/sky-wu-chi/room/room111",
]) );
	set( "clan_room", "天道無極" );
	set( "item_desc", ([ /* sizeof() == 1 */
  "board" : "這裡是屋主 太子(James)的發呆、蹲內力、休息..之處。
",
]) );
	set( "short", "懶人‧神秘小屋 " );
	set( "owner", "lazycancer" );
	set( "object", ([
		"file2"    : "/obj/gift/hobowdan",
		"file4"    : "/open/killer/obj/k_ring",
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"file3"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file8"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
	]) );
	set( "build", 10068 );
	set( "light_up", 1 );
	setup();

	}
