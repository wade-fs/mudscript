// Room : /open/clan/ou-cloud-club/room/room28.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "神秘實驗室" );
	set( "object", ([
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount9"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armor",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-shield",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount10" : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount1"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-shield",
	]) );
	set( "owner", "snowy" );
	set( "build", 10017 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room3",
  "west" : "/open/clan/ou-cloud-club/room/room46.c",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
這裡陳列著大量的巨型試管,裡面裝滿了綠色的液體,以及
一具具失去生命跡象的人體,看來這裡是惡魔城的實驗室了,
,試管裡的人,眼神空洞,身旁流動的液體,則帶著白白黃黃的
各式凝結物,腦漿,骨髓就這樣無遮攔的到處流動著...
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
