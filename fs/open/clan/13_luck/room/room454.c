inherit ROOM;
void create() {
	set( "short", "『飛燕崖』" );
	set( "owner", "poll" );
	set( "object", ([
		"amount1"  : 1,
		"file4"    : "/open/killer/headkill/obj/e_dag",
		"file2"    : "/open/killer/headkill/obj/e_dag",
		"file7"    : "/open/killer/headkill/obj/e_dag",
		"amount2"  : 1,
		"file1"    : "/open/killer/headkill/obj/e_dag",
		"amount8"  : 1,
		"file8"    : "/open/killer/headkill/obj/e_dag",
		"amount7"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10062 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room455",
		"south"     : "/open/clan/13_luck/room/room453",
	]) );
	set( "long", @LONG

     此地受群山包圍，為一處凹谷地形，比起其他地方來得暖和。你所站立
 的地方乃是凹谷內的一處山崖，崖上峭壁滿是燕子窩，此種西域黑燕較其他
 燕種在體型上來得小，也比較耐寒，黑燕啣來草枝、樹皮混合唾液在峭壁之
 上築蓋燕巢，每到秋冬兩季皆可看到為數可觀的黑燕從其他寒冷地帶成群飛
 來築巢，屆時燕啼不絕於耳，黑雲似的燕群更蔚為奇觀。

LONG);
	setup();
	replace_program(ROOM);
}
