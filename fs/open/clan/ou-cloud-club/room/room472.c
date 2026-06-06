inherit ROOM;
void create() {
	set( "short", "$HIW$光子力研究所$NOR$" );
	set( "object", ([
		"file8"    : "/open/ping/questsfan/obj/diamond_hands",
		"file5"    : "/open/ping/questsfan/obj/diamond_belt",
		"file4"    : "/open/ping/questsfan/obj/diamond_cloak",
		"file6"    : "/open/ping/questsfan/obj/diamond_boots",
		"amount7"  : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_skirt",
		"file1"    : "/open/ping/questsfan/obj/diamond_armor",
		"file7"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/ping/questsfan/obj/diamond_legging",
		"amount8"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10270 );
	set( "owner", "emperor" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room183",
	]) );
	set( "long", @LONG
這是無敵鐵金剛的駕駛員--兜‧甲兒--的秘密基地<<光子力研究所>>
裡面擺著甲兒所駕駛過的歷代鐵金剛..
還有大魔神..木蘭號..亞芙蘿黛A..阿強一號也都停放在這裡面....
雖然舊的鐵金剛都已退休了......但甲兒依然很愛惜它們...一有空便到
這裡來看它們........隨時他把它們擦拭得一塵不染.....
劍‧鐵也..莎也嘉..阿強..和兜博士正聚在一起愉快的聊著天....
你看......前方不遠處正擦拭著鐵金剛的人不就是------
魔神皇帝的駕駛員兜‧甲兒嗎???
LONG);
	setup();
	replace_program(ROOM);
}
