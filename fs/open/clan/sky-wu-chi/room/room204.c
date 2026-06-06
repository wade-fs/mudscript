inherit ROOM;
void create() {
	set( "short", "特殊物品房間" );
	set( "owner", "yuki" );
	set( "object", ([
		"amount1"  : 40,
		"file4"    : "/open/magic-manor/obj/water-ball",
		"file6"    : "/open/ping/obj/poison_pill",
		"amount4"  : 1,
		"file1"    : "/open/fire-hole/obj/w-pill",
		"amount6"  : 2,
	]) );
	set( "build", 10098 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room162",
	]) );
	set( "long", @LONG
這裡是小二的人頭間
放著各式各樣的人頭
有焚天魔王的人頭
有黃金甲龍的人頭
有獨孤嵊的人頭
有林宏昇的人頭
還有七色迴路魔將的人頭
黑白雙煞的人頭
和殺手需要的人頭
真的是應有盡有
看來這裡是小二為了展示他的戰利品而開的room
看來小二也真夠強的了
LONG);
	setup();
	replace_program(ROOM);
}
