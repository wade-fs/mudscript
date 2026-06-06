inherit ROOM;
void create() {
	set( "short", "秘Φ私藏館" );
	set( "owner", "enter" );
	set( "object", ([
		"amount10" : 414,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 800,
		"file8"    : "/open/doctor/pill/sky_pill",
		"amount8"  : 931,
		"file3"    : "/open/gsword/obj1/blosword",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/ghost-hole/obj/fire-spirit",
		"file5"    : "/daemon/class/bonze/buddha_staff",
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/doctor/pill/gnd_pill",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/beggar/obj/neck",
		"amount2"  : 800,
		"file9"    : "/open/ghost-hole/obj/fire-spirit",
		"amount3"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10053 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room348",
		"west"      : "/open/clan/ou-cloud-club/room/room132.c",
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
