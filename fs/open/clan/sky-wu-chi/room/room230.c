inherit ROOM;
void create() {
	set( "short", "other" );
	set( "owner", "hild" );
	set( "build", 10037 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room255",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這是一小喵專用的防具間 , 這裡放著各式各樣的防具 , 為
世界防具最為齊全之地 , 你看到各種奇怪的防具 , 所謂工欲善
其事 ,必先利其器 , 看來 ,你也該為自己選把像樣的防具 , 好
闖蕩江湖 .你可以看看(list)參觀一下這裡的防具 ?

LONG);
	setup();
	replace_program(ROOM);
}
