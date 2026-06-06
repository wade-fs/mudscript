inherit ROOM;
void create() {
	set( "short", "密Φ藏之武館" );
	set( "object", ([
		"amount4"  : 981,
		"file10"   : "/obj/gift/hobowdan",
		"file6"    : "/open/mogi/castle/obj/sspill",
		"amount10" : 1,
		"amount8"  : 1,
		"file3"    : "/obj/gift/unknowdan",
		"amount5"  : 950,
		"file1"    : "/obj/gift/xiandan",
		"amount6"  : 991,
		"file2"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 1,
		"file7"    : "/obj/gift/unknowdan",
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount3"  : 1,
	]) );
	set( "owner", "enter" );
	set( "build", 10028 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room350",
		"east"      : "/open/clan/ou-cloud-club/room/room352",
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
