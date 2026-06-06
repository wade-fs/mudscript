inherit ROOM;
void create() {
	set( "short", "藏劍居" );
	set( "owner", "warhammer" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room442",
	]) );
	set( "object", ([
		"amount7"  : 1,
		"amount1"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/light-spirit",
		"file5"    : "/obj/gift/xisuidan",
		"file1"    : "/open/gsword/obj1/bpball",
		"amount6"  : 1,
		"amount10" : 1,
		"file8"    : "/open/ghost-hole/obj/light-spirit",
		"file10"   : "/open/gsword/obj1/bpball",
		"file3"    : "/open/ghost-hole/obj/light-spirit",
		"file2"    : "/open/gsword/obj1/bpball",
		"file6"    : "/open/ghost-hole/obj/light-spirit",
		"amount5"  : 1,
		"file9"    : "/open/ghost-hole/obj/fire-spirit",
		"amount4"  : 210,
		"amount9"  : 1,
		"file4"    : "/open/killer/obj/atman_pill",
		"amount2"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 11262 );
	set( "long", @LONG
這裡是佾雲遨遊神州各地後收藏寶物的地方, 裡面的寶物都相當珍貴
其中又以由鑽石所打造的防具最為亮眼, 傳說穿上此防具的佾雲無人能敵,
你可以四處逛逛並且想像一下佾雲的英姿, 右邊的牆壁雕刻著人型招式,
你心想或許這就是佾雲成名江湖最得意的招式
LONG);
	setup();
	replace_program(ROOM);
}
