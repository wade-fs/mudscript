inherit ROOM;
void create() {
	set( "short", "馬房" );
	set( "owner", "kaien" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room346",
	]) );
	set( "object", ([
		"file4"    : "/open/mon/obj/ghost-claw",
		"amount4"  : 1,
		"file8"    : "/open/mon/obj/ghost-claw",
		"file9"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "item_desc", ([
		"金鋼石" : @ITEM
一粒醜不拉幾的石頭，上面刻著，〔極武上尊是大豬頭〕
ITEM,
	]) );
	set( "build", 10102 );
	set( "light_up", 1 );
	set( "long", @LONG

    秦將軍一生曾有過兩匹戰馬。黃驃馬在先，後又從尚師徒手中得到
呼雷。秦將軍南征北戰若是缺了座下寶馬，早屍橫沙場了。因此他對自
己的兩匹戰馬有特殊的感情。而這兩批戰馬似乎聽的懂主人的話，使得
秦將軍如虎添翼，因此將軍對這兩匹馬的馬房修的舒適異常，而且還有
專人照顧。

LONG);
	setup();
	replace_program(ROOM);
}
