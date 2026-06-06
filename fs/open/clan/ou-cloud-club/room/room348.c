inherit ROOM;
void create() {
	set( "short", "秘Φ私藏館" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/sspill",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/open/prayer/obj/boris-cloth",
		"amount8"  : 800,
		"amount9"  : 800,
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 800,
		"amount5"  : 800,
		"amount6"  : 800,
		"file2"    : "/obj/gift/xisuidan",
		"amount2"  : 1,
		"amount10" : 800,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 1,
		"amount3"  : 1,
		"amount1"  : 800,
		"file5"    : "/open/mogi/castle/obj/ninepill",
	]) );
	set( "owner", "enter" );
	set( "build", 10056 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room347",
		"west"      : "/open/clan/ou-cloud-club/room/room349",
	]) );
	set( "long", @LONG
此處放著劍君十二恨的私藏防具，可用來激發內力用，桌上
擺的有金風細雨樓那打來的$HIR$夕霞紅紗$NOR$，魔刀門的$HIC$魔法盾$NOR$，跟舞清
風身上的$HIY$妖幻披肩$NOR$，$HIY$頭帶$NOR$，$HIY$護膝$NOR$，跟瀧山任正晴的$HIR$陽炎臂環$NOR$及$HIC$狂
龍翔天破$NOR$，而桌後椅上則擺著$YEL$混沌腰帶$NOR$，$HIC$羅剎女飾$NOR$跟$HIY$幸運草環$NOR$．

LONG);
	setup();
	replace_program(ROOM);
}
