inherit ROOM;
void create() {
	set( "short", "愛麗絲" );
	set( "owner", "filia" );
	set( "object", ([
		"file4"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file8"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount8"  : 1,
		"file6"    : "/open/gsword/obj1/bpball",
		"amount10" : 1,
		"file1"    : "/open/killer/obj/kill_yar_head",
		"amount5"  : 1,
		"file7"    : "/open/killer/obj/dagger",
		"file9"    : "/open/ghost-hole/obj/light-spirit",
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file10"   : "/open/gsword/obj1/bpball",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"amount7"  : 1,
		"file5"    : "/open/ghost-hole/obj/light-spirit",
		"amount3"  : 1,
	]) );
	set( "build", 15006 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room533",
	]) );
	set( "long", @LONG
這裡是FF7主角之一愛麗絲的家，裡面可是放滿了各種魔石
，其中包括了在FF7中的魔石，還有在FF各系列中所有的魔石，
另外愛麗絲身上也有隨身帶一個魔石,那個魔石就是她母親送給
她的白色魔石，這顆白色魔石就綁在愛麗絲頭髮的辨子上。

LONG);
	setup();
	replace_program(ROOM);
}
