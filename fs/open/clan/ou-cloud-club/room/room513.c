inherit ROOM;
void create() {
	set( "short", "校園的驅魔女孩" );
	set( "light_up", 1 );
	set( "object", ([
		"file2"    : "/obj/gift/bingtang",
		"amount9"  : 1,
		"amount7"  : 1,
		"file10"   : "/obj/gift/bingtang",
		"file4"    : "/obj/gift/lingzhi",
		"file9"    : "/obj/gift/bingtang",
		"amount8"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file3"    : "/obj/gift/lingzhi",
		"file5"    : "/obj/gift/bingtang",
		"amount6"  : 1,
		"amount4"  : 1,
		"file8"    : "/obj/gift/lingzhi",
		"file1"    : "/obj/gift/lingzhi",
		"amount10" : 1,
		"file6"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"amount2"  : 1,
		"file7"    : "/obj/gift/lingzhi",
	]) );
	set( "build", 10011 );
	set( "owner", "ctx" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room511",
	]) );
	set( "long", @LONG
一個16歲被邪靈附身得大病的女孩, 雖經高人指點被治好病
逃過了一劫,但似乎命中注定逃不了妖魔的糾纏,一個際遇回到40
0多年前的日本戰國時代,救出與自己息息相關的人物, 18歲的大
學新鮮人的生活裡,她又將開始與邪靈遭遇...

LONG);
	setup();
	replace_program(ROOM);
}
