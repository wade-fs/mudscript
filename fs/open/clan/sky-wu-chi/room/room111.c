 inherit ROOM;

void create()
{
        seteuid(getuid());
        set( "long", @LONG
你不知不覺的走進了一個神秘的小道，當你看到遠方出現一到靈
光..就不猶自主的牽引往前邁進！直到你回神後..眼前出現一座泛著
靈光的小屋，此時讓你心中有著不詳的預感..在你冒冷汗的同時，看
到遠方小屋旁有個一$YEL$木牌(sign)$NOR$，上面似乎寫了些什麼字！於是你起
了步往前究知，當你靠近時你感覺有一股靈氣直逼於你。
　　　　　　　　$HIW$(此地凝結一股很強大的靈氣)$NOR$

LONG);
        set( "no_transmit", 1 );
        set( "cmkroom", 1 );
        set( "no_clean_up", 0 );
        set( "exits", ([ /* sizeof() == 2 */
		"enter"     : "/open/clan/sky-wu-chi/room/room112.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
]) );
        set( "clan_room", "天道無極" );
        set( "item_desc", ([ /* sizeof() == 1 */
  "sign" : "此屋是【聖火教】太子(James) 所有。
",
]) );
	set( "short", "懶人‧神秘小道" );
	set( "owner", "lazycancer" );
	set( "object", ([
		"amount4"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/mon/obj/ghost-cloak",
		"file6"    : "/open/snow/obj/figring",
		"amount2"  : 1,
		"file8"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/daemon/class/blademan/obj/ublade",
		"amount10" : 1,
		"file7"    : "/open/poison/obj/blue_key",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/obj/gift/shenliwan",
	]) );
	set( "build", 10001 );
	set( "light_up", 1 );
        setup();

        }

