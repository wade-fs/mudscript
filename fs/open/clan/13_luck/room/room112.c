inherit ROOM;
void create() {
	set( "short", "EMC吃飯會議室" );
	set( "owner", "adeyzit" );
	set( "object", ([
		"file1"    : "/open/killer/outsea/dstone",
		"amount6"  : 1,
		"file5"    : "/open/gsword/obj/ring-1",
		"file7"    : "/open/doctor/obj/needle9",
		"amount1"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/mogi/village/obj/mogi_ring",
		"file3"    : "/open/gsword/obj/yuskirt",
		"amount5"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10191 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room104",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
裡面有著營長經理老大買的微波爐,抽屜會放些晚上加班
吃的餅乾跟泡麵..還有每天煮的咖啡都會在裡面
每天中午不是出去吃飯,就是在這邊吃著便當..
牛肉麵,或是海鮮鍋..不然有時也會買些好料放在這...CCC
這裡雖然麻雀雖小..但是五臟可是據全的..
LONG);
	setup();
	replace_program(ROOM);
}
