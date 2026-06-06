inherit ROOM;
void create() {
	set( "short", "武器房" );
	set( "owner", "panhermes" );
	set( "object", ([
		"file1"    : "/open/killer/obj/bellstar",
		"amount4"  : 15,
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"amount3"  : 1,
		"amount6"  : 200,
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"file4"    : "/open/killer/obj/black",
		"amount7"  : 2000,
		"amount5"  : 60,
		"file5"    : "/open/killer/obj/atman_pill",
		"file6"    : "/open/killer/obj/s_pill",
		"amount1"  : 4296,
		"file7"    : "/open/killer/obj/hate_knife",
		"amount2"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10051 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room210",
	]) );
	set( "long", @LONG
這裡所放的正是罕世珍寶，所有名家武器防具盡收其內，刀光劍影四散飛射，
其不是有人舞劍，而是名刀名劍所散發出的霸氣，房內正中間的兩方掛著兩幅
字聯盜亦有盜，俠盜高飛，而中間放著正是罕聞寄寶無名寶刀，他在散發出無
與倫比的霸氣，使別人不敢輕易進入此房間。
LONG);
	setup();
	replace_program(ROOM);
}
