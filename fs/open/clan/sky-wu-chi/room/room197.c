inherit ROOM;
void create() {
	set( "short", "$HIY$【平南書院】 $HIG$中庭$NOR$" );
	set( "owner", "lonsan" );
	set( "object", ([
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/obj/maun-shadow-blade",
		"file1"    : "/open/magic-manor/obj/magic-sign",
		"amount6"  : 1,
		"amount10" : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/wu/npc/obj/armband",
		"file6"    : "/open/ping/questsfan/obj/key",
		"amount3"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount1"  : 1,
		"file7"    : "/open/ping/obj/cloud",
		"amount4"  : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/sky/obj/lucky_grasslink",
	]) );
	set( "build", 10370 );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room199",
		"east"      : "/open/clan/sky-wu-chi/room/room198",
		"south"     : "/open/clan/sky-wu-chi/room/room139.c",
	]) );
	set( "long", @LONG
經過一道拱門，你來到了平南書院的中庭，這裡是一片寬闊的地方，四周以圍
牆跟其他區域隔開，連接四面的區域都有一個拱型門作為通道，在東南方有一個小
池子，池子中央有一個涼亭，名曰：〔靜心亭〕，有一座九曲橋連接到那兒。在東
邊是一片銀杏林，林內飼養著許多奇珍異獸，性情都是十分溫馴，還有一座草蘆座
落在林中央。在中庭的中央是一片大廣場，常常會有許多的活動是在這裡舉行，西
北有一座假山，上面還有一個小瀑布，西南方是一排排的公佈欄，上面張貼的有各
式各樣的海報或是一些重要的命令。
LONG);
	setup();
	replace_program(ROOM);
}
