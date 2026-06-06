inherit ROOM;
void create() {
	set( "short", "$HIW$黑輪臥房 - $HIC$藏寶室$NOR$" );
	set( "owner", "radio" );
	set( "object", ([
		"file9"    : "/open/mogi/dragon/obj/key",
		"amount9"  : 1,
		"file5"    : "/open/scholar/obj/iron",
		"amount5"  : 1,
		"amount10" : 1,
		"file10"   : "/open/mogi/dragon/obj/key",
	]) );
	set( "item_desc", ([
		"osword" : @ITEM





黑輪臥房守護者


ITEM,
		"oblade" : @ITEM



黑輪臥房守護者


ITEM,
	]) );
	set( "build", 10088 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room41.c",
		"south"     : "/open/clan/hell/room/room53",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
此房為黑輪平時從武林中，獲得的希世珍
寶，或是仙丹妙藥，所置放的地方，你想上前
一覽這些希室珍寶，不料卻跑出了兩個首位阻
擋‧

臥房守護者「一生持刀不用刀」一刀萬殺(oblade)
臥房守護者「一生用劍不持劍」一劍萬生(osword)

LONG);
	setup();
	replace_program(ROOM);
}
