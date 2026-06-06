inherit ROOM;
void create() {
	set( "short", "ddt雜物間-8" );
	set( "owner", "cong" );
	set( "object", ([
		"amount10" : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount3"  : 1,
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount7"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 1,
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount6"  : 1,
	]) );
	set( "build", 10104 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room616",
	]) );
	set( "long", @LONG
這裡舉目所見都是一大堆的廢物你試圖從這一堆東西中找出
有用的寶物，不過這顯然是個很大的挑戰但你還是不死心的努力
終於在一番搜尋之下你找到了一罐純喫茶，先喝一口茶再來找找
或許才是一個好方法，你深深的喝了一大口，呼~真是透心涼阿
LONG);
	setup();
	replace_program(ROOM);
}
