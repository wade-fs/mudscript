inherit ROOM;
void create() {
	set( "short", "元素空間" );
	set( "build", 12273 );
	set( "light_up", 1 );
	set( "exits", ([
		"northwest" : "/open/clan/sky-wu-chi/room/hall",
		"southwest" : "/open/clan/sky-wu-chi/room/hall",
		"west"      : "/open/clan/sky-wu-chi/room/hall",
		"up"        : "/open/clan/sky-wu-chi/room/hall",
		"down"      : "/open/clan/sky-wu-chi/room/hall",
		"south"     : "/open/clan/sky-wu-chi/room/hall",
		"north"     : "/open/clan/sky-wu-chi/room/hall",
		"east"      : "/open/clan/sky-wu-chi/room/hall",
		"southeast" : "/open/clan/sky-wu-chi/room/hall",
		"northeast" : "/open/clan/sky-wu-chi/room/room336",
	]) );
	set( "long", @LONG
這裡你看到了黑白紅藍綠黃這六種元素,而這六種元素正密集且不消散的
在這一空間裡移動,在移動的同時你看到一些不同元素的磨擦產生的一些
微小電子,而你看到這空間的中心有一個神秘的圓球正在吸取這些微小的電子
你不知道這是什麼東西,而且這圓球還不時的擩動著,彷彿像是一個活物
LONG);
	setup();
	replace_program(ROOM);
}
