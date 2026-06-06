inherit ROOM;
void create() {
	set( "short", "芭樂園" );
	set( "owner", "bladewind" );
	set( "object", ([
		"file10"   : "/open/capital/obj/blade2",
		"amount4"  : 1,
		"file1"    : "/open/wu/obj/figring",
		"amount10" : 1,
		"amount9"  : 1,
		"amount5"  : 165,
		"file5"    : "/open/killer/obj/atman_pill",
		"amount1"  : 1,
		"amount3"  : 10,
		"file3"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file8"    : "/open/tendo/obj/chaosbelt",
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"file4"    : "/open/killer/obj/fire-knife",
		"amount8"  : 1,
		"amount2"  : 470,
		"file9"    : "/open/killer/obj/fire-knife",
		"amount7"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/killer/obj/s_pill",
		"file7"    : "/open/wind-rain/obj/sun_red_cloth",
	]) );
	set( "light_up", 1 );
	set( "build", 10628 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room438.c",
		"north"     : "/open/clan/ou-cloud-club/room/room729",
		"west"      : "/open/clan/ou-cloud-club/room/room175.c",
	]) );
	set( "long", @LONG
  這裡是火焰鴨和小雯種芭樂的地方,房間的正中央有一顆大大的芭樂,這隻芭樂
的命相當的苦,他為了火焰鴨和小雯小敏的幸福,不惜放棄原來當殺手的志向,轉
去當個可憐的小書生,再孤立無援的地方努力生存,終於解開了傲雲沒有人會的飄
陽之謎,現在正在努力的修煉中,以便能夠更上一層樓,

LONG);
	setup();
	replace_program(ROOM);
}
