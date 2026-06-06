inherit ROOM;
void create() {
	set( "short", "鳳凰樓二樓" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room146.c",
		"south"     : "/open/clan/13_luck/room/room122.c",
		"down"      : "/open/clan/13_luck/room/room99.c",
		"up"        : "/open/clan/13_luck/room/room102.c",
		"north"     : "/open/clan/13_luck/room/room123.c",
		"east"      : "/open/clan/13_luck/room/room535",
	]) );
	set( "long", @LONG

    在店小二的引領，你沿著燈火照亮的樓梯往上爬，來到了鳳凰樓
二樓的通道，往你的廂房走去。廂房已打掃乾淨，桌上放置著一壺剛
泡好的凍頂烏龍茶，你坐了下來，邊品嚐這上好的烏龍茶，邊欣賞遠
處的風景，真是好不愜意。

LONG);
	setup();
	replace_program(ROOM);
}
