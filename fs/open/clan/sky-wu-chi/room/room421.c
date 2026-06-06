inherit ROOM;
void create() {
	set( "short", "壁櫥裡的暗門" );
	set( "owner", "yuki" );
	set( "build", 10004 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room422",
		"east"      : "/open/clan/sky-wu-chi/room/room420.c",
	]) );
	set( "long", @LONG
這是隱藏在壁櫥中的暗門，存在的原因不明，製作人的不明，作用
不明，特殊原因不明，背後的意義不明，隱藏的原因不明，背後
會發生的陰謀不明，這是一扇謎的一般的暗門，至於作用跟使用發法
ㄟ．．．．就跟你說是暗門當然是通往某個地方，至於使用的方法當然是打開他呀，笨！
LONG);
	setup();
	replace_program(ROOM);
}

