inherit ROOM;
void create() {
	set( "short", "私藏館" );
	set( "owner", "enter" );
	set( "object", ([
		"amount4"  : 1,
		"amount9"  : 2,
		"file10"   : "/obj/gift/xiandan",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount10" : 1,
		"file9"    : "/open/fire-hole/obj/g-pill",
		"amount8"  : 1,
		"file3"    : "/open/ghost-hole/obj/light-spirit",
		"amount5"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount6"  : 550,
		"amount7"  : 439,
		"amount2"  : 1,
		"file2"    : "/open/beggar/obj/arms",
		"file4"    : "/open/beggar/obj/neck",
		"amount1"  : 1,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"file5"    : "/open/wu/obj/armband",
		"file8"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
	]) );
	set( "build", 10693 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room119.c",
		"west"      : "/open/clan/ou-cloud-club/room/room353",
		"east"      : "/open/clan/ou-cloud-club/room/room349.c",
	]) );
	set( "long", @LONG
此處放著劍君十二恨的私藏防具，可用來激發內力用，桌上
擺的有金風細雨樓那打來的$HIR$夕霞紅紗$NOR$，魔刀門的$HIC$魔法盾$NOR$，跟舞清
風身上的$HIY$妖幻披肩$NOR$，$HIY$頭帶$NOR$，$HIY$護膝$NOR$，跟瀧山任正晴的$HIR$陽炎臂環$NOR$及$HIY$狂
龍翔天破$NOR$，而桌後椅上則擺著$YEL$混沌腰帶$NOR$，$HIC$羅剎女飾$NOR$跟$HIY$幸運草環$NOR$．

LONG);
	setup();
	replace_program(ROOM);
}
