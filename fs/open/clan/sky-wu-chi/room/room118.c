inherit ROOM;
void create() {
	set( "short", "天天開館" );
	set( "object", ([
		"file7"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount4"  : 1,
		"amount9"  : 1,
		"amount1"  : 2778,
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"amount3"  : 1,
		"file9"    : "/obj/gift/lingzhi",
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"amount2"  : 1,
		"file1"    : "/open/killer/obj/hate_knife",
		"file5"    : "/open/killer/obj/k_ring",
		"amount6"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10034 );
	set( "light_up", 1 );
	set( "owner", "client" );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room15",
	]) );
	set( "long", @LONG

這裡是我想上所開的天天開館，其名字意義要為天天開心，在這裡
和風薰柳，花香醉人，正是南國春光漫爛的季節。

大門門上茶杯大小的銅釘閃閃發光，門頂匾額寫著『天大地大，為我最樂。』

而站在門前有一個看起來像是朝廷命官的人，此人是我想上的
第二女弟子神算殺殺殺，為人鐵面無私，有現任女包青天之名。
但是我想上是惡名滿天飛，難道這是傳說中的愛超越一切嗎？
或許她的房間應該在我想上的內房才對。我想上最好期盼
老婆大人不要發現他們的關係(奸情)?。

LONG);
	setup();
	replace_program(ROOM);
}
