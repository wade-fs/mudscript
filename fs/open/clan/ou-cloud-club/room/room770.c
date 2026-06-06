inherit ROOM;
void create() {
	set( "short", "樹枝上" );
	set( "object", ([
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/obj/lunar-heart",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file10"   : "/obj/gift/xiandan",
		"file1"    : "/open/magic-manor/obj/lunar-heart",
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount8"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
	]) );
	set( "owner", "snowy" );
	set( "build", 10920 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room769",
	]) );
	set( "long", @LONG
四周都是巨大的樹木，直聳天際，此時你才注意到地上彷彿升起了一團
霧氣，待在這久一點，聞久了那種氣味，頭開始昏昏沈沈了起來，原來這片
森林處處都瀰漫著瘴氣，從踏進森林一直到這也不知道吸了多少的毒氣了，
想到為了不想昏迷於這片森林中不由趕緊摀住鼻子，飛也似的離開這。
LONG);
	setup();
	replace_program(ROOM);
}
