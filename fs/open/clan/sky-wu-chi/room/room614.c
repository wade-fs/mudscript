inherit ROOM;
void create() {
	set( "short", "ddt雜物間-5" );
	set( "owner", "cong" );
	set( "object", ([
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount9"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10546 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room617",
		"south"     : "/open/clan/sky-wu-chi/room/room559",
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
