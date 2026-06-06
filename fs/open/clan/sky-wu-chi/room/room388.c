inherit ROOM;
void create() {
	set( "short", "玉樓春" );
	set( "owner", "intel" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10116 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room389",
	]) );
	set( "long", @LONG

洛陽正值芳菲節，穠豔清香向間發。

游絲有意苦相榮，垂柳無端爭贈別。

杏花紅處青山缺，山畔行人山下歌。

今宵誰肯遠相隨？惟有疾寥孤館月。

LONG);
	setup();
	replace_program(ROOM);
}
