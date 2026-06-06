inherit ROOM;
void create() {
	set( "short", "$YEL$泥腳$MAG$夫人$CYN$的店$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armband",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "owner", "car" );
	set( "build", 10032 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room6",
	]) );
	set( "long", @LONG
這是專為情侶所開的店,每張桌子都是兩人座,桌上擺著情人樹,
樹枝上掛著一些小紙條,紙條上寫著甜言蜜語讓當下的情侶們不怕忘詞,
昏暗的燈光下已經有幾對情侶在接吻了,派西衛斯理和潘妮清水也在其中,
收音機撥放著抒情歌曲,浪漫極了,真不愧是約會的聖地

LONG);
	setup();
	replace_program(ROOM);
}
