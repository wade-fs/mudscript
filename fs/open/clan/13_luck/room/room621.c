inherit ROOM;
void create() {
	set( "short", "正廳逸嵐居" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room624",
	]) );
	set( "long", @LONG

    喜愛文學的刑棠若嵐自小就不愛練武，為何他成為詩劍山莊第二代
莊主，因為他老爸是第一代莊主，於大限將至前將全身功力強灌至刑棠
若嵐身上，照理說強灌六十年的功力，早該爆體而亡，令人難以致信的
是刑棠若嵐居然沒事，至於他的武功沒人知道，只知道不要惹他生氣，
因為還沒看過哪一個惹他生氣的人，還能活著讓人看見的，為此前莊主
留下了兩個耆老即詩，劍兩堂堂主，協助刑棠若嵐管理詩劍山莊

LONG);
	setup();
	replace_program(ROOM);
}
