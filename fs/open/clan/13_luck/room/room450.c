inherit ROOM;
void create() {
	set( "short", "『武器儲藏室』" );
	set( "owner", "poll" );
	set( "object", ([
		"file6"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount1"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount3"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount2"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount4"  : 1,
	]) );
	set( "build", 10083 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room449",
		"east"      : "/open/clan/13_luck/room/room452.c",
	]) );
	set( "long", @LONG
  
     這裡是墨教的武器儲藏室，近年來墨教遭受很多武林幫派的侵襲，所以
 戰爭不斷，雖然墨教提倡非攻，但是別人來攻擊時，也要有適當的防衛武力
 於是這裡放著各式各樣的兵器。這裡有幾座熔鐵的火爐正冒著烈火此處負責
 墨教兵器的研發製作工作，擔當指導的老鐵匠頭子們從事這行已經幾十年的
 工夫，他們的火候自然不在話下。幾個火紅膚色的中年鐵匠上身脫得精光，
 全神貫注鑄造刀劍。

LONG);
	setup();
	replace_program(ROOM);
}
