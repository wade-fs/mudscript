inherit ROOM;
void create() {
	set( "short", "【我想上的內房】" );
	set( "owner", "cong" );
	set( "object", ([
		"amount4"  : 1,
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"amount10" : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "light_up", 1 );
	set( "build", 10353 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room158",
		"down"      : "/open/clan/sky-wu-chi/room/room27",
	]) );
	set( "long", @LONG

這裡是我想上預定二老婆的房間，為了防止被老婆大人刀神燕仔發現，
特地做出一個內房不讓任何人發現，我想上真是一個不知羞恥的小色龜。
而且還要在作出更多的內房好滿足自己的慾望。但是大老婆會發現嗎?
你邪惡地對著大家說著，大家瞎子吃餛飩─心裡有數。
也因此而創出《性情心法》的強力絕學。

LONG);
	setup();
	replace_program(ROOM);
}
