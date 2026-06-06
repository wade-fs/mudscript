inherit ROOM;
void create() {
	set( "short", "武器陳列室" );
	set( "object", ([
		"amount3"  : 969,
		"file10"   : "/open/magic-manor/obj/sun-heart",
		"file3"    : "/open/ping/obj/poison_pill",
		"amount10" : 1,
		"amount2"  : 638,
		"file2"    : "/open/ping/obj/poison_pill",
		"amount5"  : 675,
		"amount8"  : 654,
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/obj/sun-heart",
		"amount1"  : 1,
		"amount9"  : 738,
		"amount4"  : 604,
		"file6"    : "/open/magic-manor/obj/lunar-heart",
		"amount7"  : 1,
		"file7"    : "/obj/gift/unknowdan",
		"file4"    : "/open/ping/obj/poison_pill",
		"file5"    : "/open/ping/obj/poison_pill",
		"file8"    : "/open/ping/obj/poison_pill",
		"file9"    : "/open/ping/obj/poison_pill",
	]) );
	set( "owner", "zmud" );
	set( "build", 10288 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room539",
	]) );
	set( "long", @LONG

    在地窖的旁邊竟然還有一間放滿武器防具的房間,讓你大吃一驚武器的種類,多的無法去盤算而
且所放置的都是世上所名傳的兵器,像開天三靈器--連陽劍--紫玉蝶蘭--夜千鳥,削鐵如泥的椅天劍
與屠龍刀,還有火龍幻界的火龜盾,還有湛藍武聖獨孤嵊的魔龍戒,都整齊的放在這間房子裡,可見主
人花的很多心血在收藏這些寶物.

LONG);
	setup();
	replace_program(ROOM);
}
