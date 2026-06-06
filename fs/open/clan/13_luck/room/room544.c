inherit ROOM;
void create() {
	set( "short", "白龍室" );
	set( "owner", "mill" );
	set( "object", ([
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file1"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 200,
		"amount2"  : 200,
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount5"  : 100,
		"amount1"  : 200,
		"amount3"  : 200,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file4"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "build", 10675 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room530",
	]) );
	set( "long", @LONG

　　此處存放著珍貴的白龍精元，乃由火龍幻界的六色光龍中的白光
火龍身上取出的。服下一顆後，便可暫時提升你的防禦能力，亦為前
往火龍幻界的必需品。白光火龍鎮守在白色結界當中，其職責是抵擋
那些想侵犯火龍王的愚昧人們。

LONG);
	setup();
	replace_program(ROOM);
}
