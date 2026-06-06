inherit ROOM;
void create() {
	set( "short", "$HIC$【$HIW$秘密藥房$HIC$】$HIW$小新$NOR$" );
	set( "owner", "sir" );
	set( "light_up", 1 );
	set( "build", 10080 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room24",
	]) );
	set( "long", @LONG
在這房間裡所放的是小新難得的天人聖藥，吃了不但
提神補氣，更能起死回生，站在一旁的小弟，本來弱小不
禁風雨，但吃了一個小小的藥丸後，變得身體力壯。。。
找一找私乎能找到許多不常看到的東西。。。一旁的不是
男人的聖品嗎。。。

LONG);
	setup();
	replace_program(ROOM);
}
