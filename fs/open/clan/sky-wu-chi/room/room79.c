// Room : /open/clan/sky-wu-chi/room/room79.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "short", "通道前段" );
	set( "owner", "herozero" );
	set( "light_up", 1 );
	set( "object", ([
		"amount3"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/prayer/obj/lin-head",
		"amount4"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/obj/soil-ball",
		"amount7"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/dancer/obj/yuawaist",
		"file7"    : "/open/quests/snake/npc/obj/snake_gem",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/mogi/castle/obj/fire_book",
		"amount9"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/obj/soil-ball",
		"file6"    : "/obj/gift/hobowdan",
	]) );
	set( "build", 12891 );
	set( "long", @LONG
筆直的通道，一直通往盡頭的馬房，四周沒有任何物品 
地上卻鋪著高級的地毯，真是令人起疑。除此之外牆上還懸 
有巨大的火把，那搖曳的火光把整個通道照耀既明亮又詭異
，不禁令你毛骨悚然。你深深的吸了一口氣，運起心法中最
上乘的鎮心術，將心神收攝心無旁鶩的專心走去。

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "south" : "/open/clan/sky-wu-chi/room/room18",
  "north" : "/open/clan/sky-wu-chi/room/room84.c",
]) );
	set( "cmkroom", 1 );
	setup();

	}
