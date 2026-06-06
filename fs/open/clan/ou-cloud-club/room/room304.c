inherit ROOM;
void create() {
	set( "short", "$HIR$愛情$NOR$" );
	set( "object", ([
		"file2"    : "/open/capital/obj/king-ring",
		"file7"    : "/daemon/class/bonze/puty_pullium",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"file8"    : "/daemon/class/blademan/obj/shield",
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"amount4"  : 3,
		"amount5"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/capital/guard/gring",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/dancer/obj/maple_ribbon",
		"amount3"  : 1,
		"amount7"  : 1,
		"file6"    : "/daemon/class/fighter/armband",
	]) );
	set( "owner", "bleak" );
	set( "build", 10078 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room319",
		"west"      : "/open/clan/ou-cloud-club/room/room302",
	]) );
	set( "long", @LONG
世上若只有一件事能洗去人們的憔悴，那就是情人的淚。
人生的初戀只有一次，就正如死亡也只有一次一樣。
原來能為自己所愛的人吃苦，竟也是一種快樂，
只是世上有幾人能享受到這種快樂。
人為什麼總是對自己已得到的情感不加以珍惜，卻在失去後
再追悔呢？
而這種痛苦，本來就是人類最古老，最深邃的痛苦。
愛情不是占有的，而是供給與犧牲的。
LONG);
	setup();
	replace_program(ROOM);
}
