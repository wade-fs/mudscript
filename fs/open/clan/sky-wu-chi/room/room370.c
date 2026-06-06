inherit ROOM;
void create() {
	set( "short", "$HIC$微笑$HIW$販賣店$NOR$" );
	set( "owner", "smile" );
	set( "object", ([
		"file4"    : "/open/killer/obj/s_pill",
		"file8"    : "/open/fire-hole/obj/k-pill",
		"amount10" : 3,
		"file7"    : "/obj/gift/xisuidan",
		"amount4"  : 1920,
		"amount8"  : 5,
		"amount5"  : 510,
		"file10"   : "/open/ping/obj/poison_pill",
		"file9"    : "/open/fire-hole/obj/w-pill",
		"amount6"  : 135,
		"file6"    : "/open/killer/obj/s_pill",
		"amount7"  : 1,
		"file5"    : "/open/killer/obj/s_pill",
		"amount9"  : 5,
	]) );
	set( "build", 15287 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/sky-wu-chi/room/room138",
		"east"      : "/open/clan/sky-wu-chi/room/room369.c",
	]) );
	set( "long", @LONG
    ;這是微笑ㄉ資源回收區,裡面收齊ㄌ許多能回收ㄉ資源;;在別人ㄉ眼裡全是不值錢ㄉ垃圾,在微笑ㄉ眼裡卻是能回收ㄉ資源;;一些值得他回收ㄉ資源;這時你不由得懷疑微笑ㄉ眼睛長在哪裡;;竟然收集ㄌ那麼多ㄉ垃圾;;;不過也許垃圾裏藏著寶貝也說不定呢 ~~~;
LONG);
	setup();
	replace_program(ROOM);
}
