inherit ROOM;
void create() {
	set( "short", "『臥房』" );
	set( "owner", "poll" );
	set( "build", 105 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room445",
		"east"      : "/open/clan/13_luck/room/room447.c",
	]) );
	set( "long", @LONG
  
     你正站在臥房，看著這裡整齊劃一的建築形式，以及臥房內乾淨樸素的
 傢具，臥房的房間內不約而同的皆掛有兵器，可能是居安思危的觀念已經深
 植全體墨教上下的心中，連睡覺也不忘強敵在前。房間中散發著陣陣香氣，
 讓你疲累的身心，想在這裡休息一下。

LONG);
	setup();
	replace_program(ROOM);
}
