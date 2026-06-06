inherit ROOM;
void create() {
	set( "short", "廚房" );
	set( "owner", "djlh" );
	set( "object", ([
		"amount4"  : 1,
		"file4"    : "/open/killer/obj/k_ring",
	]) );
	set( "build", 10050 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room53.c",
		"enter"     : "/open/clan/13_luck/room/room82",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這是一間充滿香味的廚房，一走進這裡，你可以聞到這邊傳來陣
陣的飯香，眼前一道道美位的佳餚讓你滿嘴的口水直流，肚子更咕嚕
咕嚕的叫了起來。沒想這一位聖火教嫡傳弟子不但武功一流，連廚藝
都令人讚嘆不已，真是莫測高深。


LONG);
	setup();
	replace_program(ROOM);
}
