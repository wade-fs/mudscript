// Room : /open/clan/sky-wu-chi/room/room113.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "cmkroom", 1 );
	set( "item_desc", ([ /* sizeof() == 1 */
  "sign" : "此屋是【聖火教】太子(James) 所有。
",
]) );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 3 */
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room114.c",
]) );
	set( "short", "小飛俠‧神秘小道" );
	set( "owner", "heronotme" );
	set( "object", ([
		"amount4"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file6"    : "/open/magic-manor/obj/evil-kill-claw",
		"file1"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount10" : 1,
		"file2"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount3"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount2"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10003 );
	set( "light_up", 1 );
	set( "long", @LONG
你不知不覺的走進了一個神秘的小道，當你看到遠方出現一到靈
光..就不猶自主的牽引往前邁進！直到你回神後..眼前出現一座泛著
靈光的小屋，此時讓你心中有著不詳的預感..在你冒冷汗的同時，看
到遠方小屋旁有個一木牌(sign)，上面似乎寫了些什麼字！於是你起
了步往前究知，當你靠近時你感覺有一股靈氣直逼於你。

　　　　　　　　$HIW$(此地凝聚一股很強大的靈氣)$NOR$
LONG);
	set( "no_transmit", 1 );
	set( "clan_room", "天道無極" );
	setup();

	}
