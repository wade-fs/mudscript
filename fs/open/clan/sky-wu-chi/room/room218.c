inherit ROOM;
void create() {
	set( "short", "阿嚕米的專用MOB室" );
	set( "owner", "hild" );
	set( "object", ([
		"file10"   : "/open/gsword/obj1/bpball",
		"file1"    : "/open/gsword/obj1/bpball",
		"file6"    : "/open/gsword/obj1/bpball",
		"amount9"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/gsword/obj1/bpball",
		"amount6"  : 1,
		"file5"    : "/open/gsword/obj1/bpball",
		"amount10" : 1,
		"amount8"  : 1,
		"file9"    : "/open/gsword/obj1/bpball",
		"file3"    : "/open/gsword/obj1/bpball",
		"file4"    : "/open/gsword/obj1/bpball",
		"amount1"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/gsword/obj1/bpball",
		"amount7"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10028 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room209",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
這是$HIR$阿魯米$NOR$秘密練功的地方，他運用特權，將江湖上有
名望的武林人士都招募到這裡來，再運用迷魂大法，使他們
都一一陷入$YEL$神智不清$NOR$的狀態，而且只聽命於$HIR$阿魯米$NOR$一人，這
樣他便能專心練功。
LONG);
	setup();
	replace_program(ROOM);
}
