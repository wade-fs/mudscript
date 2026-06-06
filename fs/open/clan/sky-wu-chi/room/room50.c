// Room : /open/clan/sky-wu-chi/room/room50.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "long", @LONG
你走進了一片水裡，而且越走越下去，而在水裡的藍色水晶也正
向你發出攻擊，你看到從水晶四周散發出像水刀一樣的堅銳物質且越
聚越多，在你猶豫的那一瞬間，萬道的水刀像你激射過來，你開始閃
躲，並拿出你的武器在阻檔，但是卻好像沒見到水晶又像要停歇的樣
子還是像你射了過來，你發覺情況不妙，你趕緊向出口逃逸。只是這
樣真的就能夠脫離的了危險嗎?

LONG);
	set( "short", "藍色水晶結界" );
	set( "owner", "hild" );
	set( "object", ([
		"amount4"  : 1,
		"file9"    : "/open/mon/obj/ghost-helmet",
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-claw",
		"file2"    : "/obj/npc/obj/golden_armor",
		"file7"    : "/open/killer/obj/s_pill",
		"amount7"  : 63,
		"amount6"  : 1,
	]) );
	set( "build", 12029 );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 3 */
		"out"       : "/open/clan/sky-wu-chi/room/room22",
		"west"      : "/open/clan/sky-wu-chi/room/room123",
		"north"     : "/open/clan/sky-wu-chi/room/room76.c",
		"east"      : "/open/clan/sky-wu-chi/room/room75.c",
		"south"     : "/open/clan/sky-wu-chi/room/room149.c",
]) );
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道無極" );
	set( "item_desc", ([ /* sizeof() == 1 */
  "stone" : "",
]) );
	setup();

	}
