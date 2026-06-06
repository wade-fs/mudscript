inherit ROOM;
void create() {
	set( "short", "魔法學徒-恩萊科" );
	set( "light_up", 1 );
	set( "object", ([
		"amount7"  : 1,
		"file7"    : "/obj/gift/hobowdan",
		"amount10" : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file6"    : "/obj/gift/hobowdan",
		"amount8"  : 1,
		"file9"    : "/obj/gift/hobowdan",
		"file2"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"file5"    : "/obj/gift/hobowdan",
		"amount2"  : 1,
		"file10"   : "/obj/gift/hobowdan",
		"file3"    : "/obj/gift/hobowdan",
		"file1"    : "/obj/gift/hobowdan",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"file8"    : "/obj/gift/hobowdan",
	]) );
	set( "build", 10035 );
	set( "owner", "ctx" );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room469.c",
		"east"      : "/open/clan/ou-cloud-club/room/room509.c",
		"south"     : "/open/clan/ou-cloud-club/room/room510.c",
		"north"     : "/open/clan/ou-cloud-club/room/room507.c",
		"down"      : "/open/clan/ou-cloud-club/room/room511",
		"west"      : "/open/clan/ou-cloud-club/room/room508.c",
	]) );
	set( "long", @LONG
魔法學徒恩萊科,出生於塞維納,一個位於索菲恩王國的小鎮
其本人對魔法知識相當感興趣,但是本身體質確不適合使用魔法,
但是在遇到魔法師維可多並拜其門下後,一生的際遇開始有者180
度的轉變,可說是拍案驚奇,精采絕輪,在4位魔法學徒中可無人比
的上恩萊科的遭遇。

LONG);
	setup();
	replace_program(ROOM);
}
