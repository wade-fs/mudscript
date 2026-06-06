inherit ROOM;
void create() {
	set( "short", "密Φ藏之武館" );
	set( "object", ([
		"amount8"  : 228,
		"amount4"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"file7"    : "/open/capital/obj/blade2",
		"amount5"  : 567,
		"amount6"  : 548,
		"file2"    : "/open/mon/obj/flower-claw",
		"amount7"  : 1,
		"file1"    : "/open/capital/obj/blade2",
		"amount10" : 1,
		"file9"    : "/daemon/class/fighter/star",
		"file10"   : "/obj/gift/xiandan",
		"amount9"  : 1,
		"file8"    : "/open/ping/obj/poison_pill",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/doctor/pill/gnd_pill",
		"file5"    : "/open/doctor/pill/sky_pill",
		"file4"    : "/obj/gift/unknowdan",
	]) );
	set( "owner", "enter" );
	set( "build", 10026 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room351",
		"east"      : "/open/clan/ou-cloud-club/room/room353",
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
