inherit ROOM;
void create() {
	set( "short", "$HIC$微笑$HIW$房間$NOR$" );
	set( "owner", "smile" );
	set( "object", ([
		"file3"    : "/open/killer/headkill/obj/f_dag",
		"file4"    : "/open/killer/headkill/obj/world_dag",
		"amount1"  : 9,
		"file2"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file10"   : "/obj/gift/unknowdan",
		"amount7"  : 15,
		"amount9"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount5"  : 1,
		"file5"    : "/open/killer/headkill/obj/w_dag",
		"file6"    : "/open/mogi/castle/obj/sspill",
		"file1"    : "/open/killer/obj/s_pill",
		"file7"    : "/open/killer/obj/black",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount6"  : 4,
		"amount4"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10670 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"west"      : "/open/clan/sky-wu-chi/room/room370.c",
	]) );
	set( "long", @LONG

這是微笑ㄉ資源回收區,裡面收齊ㄌ許多能回收ㄉ資源

在別人ㄉ眼裡全是不值錢ㄉ垃圾,在微笑ㄉ眼裡卻是能回收ㄉ資源

一些值得他回收ㄉ資源;這時你不由得懷疑微笑ㄉ眼睛長在哪裡

竟然收集ㄌ那麼多ㄉ垃圾;

不過也許垃圾裏藏著寶貝也說不定呢 ~~~

LONG);
	setup();
	replace_program(ROOM);
}
