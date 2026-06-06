// Room : /open/clan/sky-wu-chi/room/room72.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIC$欣$HIR$ソ$HIY$絕世居$NOR$" );
	set( "object", ([
		"file1"    : "/open/ping/questsfan/obj/diamond_armor",
		"file6"    : "/open/ghost-hole/obj/light-spirit",
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 1,
		"file9"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount4"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/mogi/castle/obj/leave",
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_hands",
		"amount7"  : 1,
		"file2"    : "/open/capital/obj/king-boots",
		"file4"    : "/open/capital/obj/king-belt",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10801 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room169.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"west"      : "/open/clan/sky-wu-chi/room/room127.c",
		"enter"     : "/open/clan/sky-wu-chi/room/room55.c",
	]) );
	set( "long", @LONG
     ｜ ‧   ●  ‧     ‧     ‧ ‧ ◢◣  ‧ ● ‧  ◢◣◥██◣
       －‧－ ‧ ‧    ‧ ‧  ● ‧ ‧  ◢█◣‧ ‧    ◢██◣◥██◣ ● ‧
         ｜︿︿ ∩∩    ◢◣  ‧    ● ◢██◣ ●  ‧  ██▉████ 
         （  т）   ） ◢█◣  ●  ‧ ◢███◣ ‧  ● █│▉█┼┼█
         （  т）   ）◢██◣  [0▁▂▄▅▇█▇▆▅▄▃▂█│▉█████▁▂▃
        ▔▔∫▔ ∫ [0██████████████████小欣-溫暖ソ窩-████
LONG);
	set( "no_transmit", 1 );
	set( "clan_room", "天道無極" );
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	setup();

	}
