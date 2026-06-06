inherit ROOM;
void create() {
	set( "short", "聚靈山莊房" );
	set( "owner", "son" );
	set( "object", ([
		"amount3"  : 1,
		"file6"    : "/obj/gift/xiandan",
		"file3"    : "/obj/gift/xiandan",
		"amount10" : 1,
		"file10"   : "/obj/gift/xisuidan",
		"file9"    : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"file8"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"amount4"  : 1,
		"file7"    : "/obj/gift/xiandan",
		"amount1"  : 1,
		"amount2"  : 1,
		"file2"    : "/obj/gift/xiandan",
		"amount9"  : 1,
		"file1"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"amount5"  : 1,
		"file5"    : "/obj/gift/xiandan",
		"file4"    : "/obj/gift/xiandan",
	]) );
	set( "build", 11928 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room70",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    當小南的功力恢復到昔日後，就繼續往更艱難的區域探險，現在來
到幾乎是狂想空間最難的區域『聚靈山莊』，聚靈山莊內的莊主，目前
尚未有人任何的人看過他的真面目，因為要見他莊主必須要經過聚靈八
結，五行塔，才能見到莊主，劇說見到莊主的人，莊主會傳授一件非常
珍貴的寶物....
 
妳發覺青色的迷霧圍繞正在妳四周


LONG);
	setup();
	replace_program(ROOM);
}
