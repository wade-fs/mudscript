inherit ROOM;
void create() {
	set( "short", "$HIC$【$NOR$防器房$HIC$】$NOR$小新" );
	set( "owner", "sir" );
	set( "light_up", 1 );
	set( "build", 10000 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room24",
	]) );
	set( "long", @LONG
小新家最強的防器室就是在此了，裡面的防具因為不是小
新所能拿到的，所以更顯得它的重要，由於只有打經驗值時會
穿，所以平常是很少用到的，這裡不但是小新管最嚴利的地方
之一，更是不能讓別人來的禁地。不過當然還是有例外的時候
啦。。。哈

LONG);
	setup();
	replace_program(ROOM);
}
