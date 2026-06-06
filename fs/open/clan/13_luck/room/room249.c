inherit ROOM;
void create() {
	set( "short", "『涼亭』" );
	set( "owner", "poll" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/obj/wood-ball",
		"file10"   : "/open/magic-manor/obj/soil-ball",
		"file2"    : "/open/magic-manor/obj/wood-ball",
		"amount10" : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/obj/fire-ball",
		"file8"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount4"  : 1,
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount8"  : 1,
	]) );
	set( "build", 10038 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room248",
		"south"     : "/open/clan/13_luck/room/room252.c",
	]) );
	set( "long", @LONG
爬到了山上的最高峰，遙遠的望去，可以把遠方的城鎮納入眼底，而放
眼望過去，不只是遠方城鎮的景色，往遠方的東邊望過去，好像有座建築物
造在遠方的山上，只是因為距離的遙遠，好像就沒有看得很清楚了。而建造
在此的涼亭就是給遊客們休憩的地方，而有時候城鎮的百姓也會來這邊爬爬
山，健健身等等。
LONG);
	setup();
	replace_program(ROOM);
}
