inherit ROOM;
void create() {
	set( "short", "逍遙居" );
	set( "owner", "cong" );
	set( "object", ([
		"amount6"  : 1,
		"amount7"  : 1,
		"amount1"  : 26573,
		"file2"    : "/open/magic-manor/obj/fon-sky-sword",
		"file6"    : "/open/mogi/dragon/obj/dragon-head",
		"amount5"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
		"file5"    : "/open/killer/headkill/obj/world_dag",
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/killer/obj/hate_knife",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount9"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10257 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room371.c",
		"north"     : "/open/clan/sky-wu-chi/room/room161.c",
		"up"        : "/open/clan/sky-wu-chi/room/room389",
		"west"      : "/open/clan/sky-wu-chi/room/room67.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
一進門就可以看到門上高高掛起的牌匾寫著逍遙居三個偌大ㄉ字
想必是楊逍的居所,裡面莊嚴的氣氛令人覺得有點可怕
且散發著一股令人窒息的空氣像是內力深厚的高手就在裡面
原來是楊消息日練功留下的餘勁若是沒有深厚的內功恐怕
一進去就會被這股深厚的內力所震傷

LONG);
	setup();
	replace_program(ROOM);
}
