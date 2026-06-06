inherit ROOM;
void create() {
	set( "short", "$HIC$雲$HIY$渡$HIG$山$NOR$" );
	set( "build", 10456 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room246",
		"east"      : "/open/clan/time-limit/room/room247.c",
		"north"     : "/open/clan/time-limit/room/room197.c",
	]) );
	set( "long", @LONG
雲渡山是百世經論一頁書的居所,雲渡山充滿神聖之氣,所謂'山不在高 有仙則名 水
不在深 有龍則靈',因為聖者一頁書讓雲渡山成為中原武林的主要根據地,一頁書是
武林第一人,其以暴治暴的治世方式,對惡人決不手軟,成為正道人士的精神領袖,而
一頁書也身先士卒,贏得夥伴的絕對信任

LONG);
	setup();
	replace_program(ROOM);
}
