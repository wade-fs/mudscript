inherit ROOM;
void create() {
	set( "short", "洗腳間" );
	set( "object", ([
		"file9"    : "/open/mogi/dragon/obj/key",
		"amount7"  : 1,
		"file8"    : "/open/wind-rain/obj/sun_red_cloth",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/open/dancer/obj/yuawaist",
		"file7"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount3"  : 1,
		"file4"    : "/open/wu/obj/figring",
		"amount1"  : 10,
		"file1"    : "/obj/stone/suipian",
		"amount8"  : 1,
		"amount2"  : 48,
		"file2"    : "/obj/stone/powder",
		"amount9"  : 1,
		"amount5"  : 79,
		"amount4"  : 1,
	]) );
	set( "item_desc", ([
		"大木桶" : @ITEM
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10171 );
	set( "owner", "washfoot" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room122",
	]) );
	set( "long", @LONG
你一進來忽然發現一股香味撲鼻而來，正中央擺著一個大桶
子，裡面放滿了花瓣，好像很好喝的樣子。你拿起旁邊的杓子裝
了滿滿一杓，正要拿來喝時，看到桶子旁一行小字『洗腳水』！！
一陣噁心涌上心頭，你摀著嘴奪門而出
LONG);
	setup();
	replace_program(ROOM);
}
