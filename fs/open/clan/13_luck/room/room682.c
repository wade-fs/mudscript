inherit ROOM;
void create() {
	set( "short", "七彩虹橋" );
	set( "object", ([
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount8"  : 1,
		"amount10" : 1,
		"file3"    : "/open/magic-manor/obj/master_snake_head",
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"amount2"  : 1,
		"file1"    : "/open/magic-manor/obj/master_snake_head",
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/obj/master_snake_head",
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount5"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10155 );
	set( "owner", "zmud" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room683",
		"north"     : "/open/clan/13_luck/room/room681",
	]) );
	set( "long", @LONG

    通過七彩陣後，拿到了七根水晶，眼前又恢復彩色的
世界。經過陣裡的試煉，證明你有實力可以見到傳說中的
武神。你將水晶插入七彩鼎中，天邊出現一道七彩虹橋，
為你搭起進入武神居的路，你踏起絕世的輕功，飛快地通
過。

LONG);
	setup();
	replace_program(ROOM);
}
