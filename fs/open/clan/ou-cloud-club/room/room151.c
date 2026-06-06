inherit ROOM;
void create() {
	set( "short", "糯米雞" );
	set( "owner", "ecs" );
	set( "light_up", 1 );
	set( "object", ([
		"amount4"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/killer/headkill/obj/world_dag",
		"file2"    : "/open/mogi/castle/obj/lochagem",
		"file3"    : "/open/killer/obj/s_pill",
		"file7"    : "/open/killer/headkill/obj/world_dag",
		"amount5"  : 1,
		"file5"    : "/open/killer/headkill/obj/f_dag",
		"file8"    : "/open/killer/headkill/obj/f_dag",
		"file6"    : "/open/killer/headkill/obj/f_dag",
		"amount10" : 1,
		"amount1"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"amount3"  : 1263,
		"file4"    : "/open/killer/headkill/obj/f_dag",
		"amount6"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 11193 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room178.c",
		"north"     : "/open/clan/ou-cloud-club/room/room438",
	]) );
	set( "long", @LONG
古巴比倫王頒布了漢摩拉比法典 刻在黑色的玄武岩 距今已經三千七百多年
妳在櫥窗前       凝視碑文的字眼   我卻在旁靜靜欣賞妳那張我深愛的臉
祭司 神殿 征戰 弓箭 是誰的從前      喜歡在人潮中妳只屬於我的那畫面
經過蘇美女神身邊    我以女神之名許願      思念像底格里斯河般的漫延
 
LONG);
	setup();
	replace_program(ROOM);
}
