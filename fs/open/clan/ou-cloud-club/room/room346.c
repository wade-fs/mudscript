inherit ROOM;
void create() {
	set( "short", "秘Φ私藏館" );
	set( "owner", "enter" );
	set( "object", ([
		"file3"    : "/open/prayer/obj/boris-cloth",
		"amount5"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/wu/obj/armband",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/mogi/dragon/obj/power",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/dancer/obj/yuawaist",
		"file10"   : "/open/beggar/obj/wrists",
		"amount10" : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"file9"    : "/open/ghost-hole/obj/fire-spirit",
		"amount1"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
	]) );
	set( "build", 11104 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room347",
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
