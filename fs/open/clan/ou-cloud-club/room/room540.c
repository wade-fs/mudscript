inherit ROOM;
void create() {
	set( "short", "小說頻道" );
	set( "owner", "ctx" );
	set( "object", ([
		"file7"    : "/obj/gift/unknowdan",
		"amount9"  : 1,
		"file3"    : "/obj/gift/unknowdan",
		"file2"    : "/obj/gift/unknowdan",
		"file10"   : "/obj/gift/unknowdan",
		"file5"    : "/obj/gift/unknowdan",
		"amount1"  : 1,
		"amount3"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"amount10" : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file4"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"file9"    : "/obj/gift/unknowdan",
		"file1"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 12219 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room495.c",
		"up"        : "/open/clan/ou-cloud-club/room/room545",
		"south"     : "/open/clan/ou-cloud-club/room/room543.c",
		"north"     : "/open/clan/ou-cloud-club/room/room541.c",
		"east"      : "/open/clan/ou-cloud-club/room/room544.c",
		"west"      : "/open/clan/ou-cloud-club/room/room542.c",
	]) );
	set( "long", @LONG
這裡是ctx最常去的一個很多網路奇幻文學的網站,裡面有相
當多的文章,其中包括了赫氏門徒、風月大陸、風姿物語(我意天
下)、異世帝王行、江山如此多嬌、校園裡的驅魔女孩等等,這個
奇幻文學網站可說是數一數二的以相當多有人氣度的作家在此駐
站出書，想看奇幻文學不來這就是太浪費了。

LONG);
	setup();
	replace_program(ROOM);
}
