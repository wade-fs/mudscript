inherit ROOM;
void create() {
	set( "short", "長恨歌" );
	set( "owner", "marshal" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/magic-manor/obj/master_snake_head",
		"amount8"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount6"  : 1,
		"file3"    : "/open/magic-manor/obj/master_snake_head",
		"file1"    : "/open/magic-manor/obj/master_snake_head",
		"file10"   : "/obj/gift/unknowdan",
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"amount10" : 1,
		"amount1"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10014 );
	set( "exits", ([
		"ddt"       : "/open/clan/sky-wu-chi/room/room512.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG

漢皇重色思傾國，御宇多年求不得。楊家有女初長成，養在深閨人未識。
天生麗質難自棄，一朝選在君王側。回眸一笑百媚生，六宮粉黛無顏色。
春寒賜浴華清池，溫泉水滑洗凝脂。侍兒扶起嬌無力，始是新承恩澤時。
雲鬢花顏金步搖，芙蓉帳暖度春宵。春宵苦短日高起，從此君王不早朝。
承歡侍宴無閑暇，春從春遊夜專夜。後宮佳麗三千人，三千寵愛在一身。
金屋妝成嬌侍夜，玉樓宴罷醉和春。姊妹弟兄皆列土，可憐光彩生門戶。
遂令天下父母心，不重生男重生女。驪宮高處入青雲，仙樂風飄處處聞。
緩歌慢舞凝絲竹，盡日君王看不足。漁陽鼙鼓動地來，驚破霓裳羽衣曲。
LONG);
	setup();
	replace_program(ROOM);
}
