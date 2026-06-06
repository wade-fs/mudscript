inherit ROOM;
void create() {
	set( "short", "秘Φ私藏館" );
	set( "owner", "enter" );
	set( "object", ([
		"file7"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"amount2"  : 1,
		"file9"    : "/open/killer/headkill/obj/world_dag",
		"amount9"  : 1,
		"file5"    : "/open/wu/obj/armband",
		"file1"    : "/open/prayer/obj/boris-cloth",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10342 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room346",
		"west"      : "/open/clan/ou-cloud-club/room/room348",
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
