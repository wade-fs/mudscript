inherit ROOM;
void create() {
	set( "short", "密Φ藏之武館" );
	set( "owner", "enter" );
	set( "object", ([
		"amount1"  : 400,
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount3"  : 1,
		"amount8"  : 995,
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"amount4"  : 1,
		"amount2"  : 603,
		"amount6"  : 800,
		"amount10" : 1,
		"amount5"  : 1041,
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"file9"    : "/open/magic-manor/obj/master_snake_head",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/obj/master_snake_head",
		"file1"    : "/open/doctor/pill/ice_pill",
		"file5"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "build", 10035 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room352",
		"east"      : "/open/clan/ou-cloud-club/room/room132",
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
