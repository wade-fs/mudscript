// Room : /open/clan/sky-wu-chi/room/room49.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
    一走進房間,你隱約聞到一股奇怪的草藥味,讓你感到異常難受,
而在北面的牆上,刻著一行字 「再回首,已是百年身」 顯現出主人深厚的功力
你的目光接著轉向房間的右半邊,你看到了許多貼上封條的寶箱,
在你走近寶箱之時,忽然從房間一角射出一些暗器,赫然竟是「黑血神針」
你驚險的躲過暗器,也嚇出一身冷汗,你心中只想著要趕緊離開這裡.
LONG);
	set( "short", "belt" );
	set( "owner", "hild" );
	set( "object", ([
		"amount4"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount6"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount2"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount7"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount10" : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-belt",
	]) );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room215.c",
		"south"     : "/open/clan/sky-wu-chi/room/room330.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room42.c",
		"west"      : "/open/clan/sky-wu-chi/room/room153.c",
		"up"        : "/open/clan/sky-wu-chi/room/room255",
	]) );
	set( "build", 10010 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
