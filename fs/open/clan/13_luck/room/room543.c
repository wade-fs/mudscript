inherit ROOM;
void create() {
	set( "short", "紅龍室" );
	set( "owner", "mill" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"amount10" : 300,
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 300,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 300,
		"amount5"  : 300,
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 300,
		"amount3"  : 300,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 300,
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 300,
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 300,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 300,
	]) );
	set( "build", 10113 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room530",
	]) );
	set( "long", @LONG

　　此處存放著珍貴的紅龍精元，乃由火龍幻界的六色光龍中的紅光
火龍身上取出的。服下一顆後，便可暫時提升你的輕功能力，亦為前
往火龍幻界的必需品。紅光火龍鎮守在紅色結界當中，其職責是抵擋
那些想侵犯火龍王的愚昧人們。

LONG);
	setup();
	replace_program(ROOM);
}
