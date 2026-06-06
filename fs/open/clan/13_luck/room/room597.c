inherit ROOM;
void create() {
	set( "short", "刑天樓馬槽" );
	set( "owner", "roarii" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room598",
	]) );
	set( "long", @LONG
不知不覺你走到了刑天樓的馬槽，這裡養的馬都是天下
名馬。因為聖堂不單單是槍術世家同時也培養了不少的鐵騎
，所以好馬對他們是十分重要的。在這這麼大的馬槽裡，你
忽然看見一名中年男子在此打掃。瞧他一身孔武有力的身材
，不像是掃地的！莫非他就是聖堂四守的聖˙血狼。

LONG);
	setup();
	replace_program(ROOM);
}
