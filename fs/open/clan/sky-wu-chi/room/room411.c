inherit ROOM;
void create() {
	set( "short", "$HIW$千年靈芝櫃$NOR$" );
	set( "light_up", 1 );
	set( "build", 10032 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room293",
	]) );
	set( "long", @LONG
這裡存放著昂貴的千年靈芝，是主人千辛萬苦收集而來的，沒經過
主人的同意，　請不要亂拿歐，否則會被當作是小偷然後被主人抓起來
ａｒｕｂａ無限大Ｘ１００的次方數歐！！！然後掛在神秘洞窟的門口
三天，再一腳踹去北極冰源陪北極熊跟企鵝作伴歐！！！
LONG);
	setup();
	replace_program(ROOM);
}
