inherit ROOM;
void create() {
	set( "short", "小二的電腦室" );
	set( "light_up", 1 );
	set( "build", 10040 );
	set( "owner", "suzukiami" );
	set( "exits", ([
		"west"      : "/open/clan/demon_castle/room/room11",
		"down"      : "/open/clan/demon_castle/room/room15",
		"north"     : "/open/clan/demon_castle/room/room13",
	]) );
	set( "long", @LONG
這裡堆滿了電腦零件,可是能夠組起來的電腦只有一台.
期中考過了,希望除了英文以外全部都能pass.
聽說limit要結婚了...
如果他不找我去...
hi
我就去搶婚
LONG);
	setup();
	replace_program(ROOM);
}
