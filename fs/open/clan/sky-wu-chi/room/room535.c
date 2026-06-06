inherit ROOM;
void create() {
	set( "short", "血痕居-極熱地獄" );
	set( "owner", "holeman" );
	set( "build", 18574 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room530",
		"northeast" : "/open/clan/sky-wu-chi/room/room528",
		"east"      : "/open/clan/sky-wu-chi/room/room532.c",
	]) );
	set( "long", @LONG

    在有著熊熊火焰、燃燒得非常炙熱的房屋中，閻羅獄卒用三叉
鐵矛把眾生叉起來燒烤。鐵叉刺入眾生的頭、心和肛門。就像人們
烤魚、烤乳豬一樣，還在上面包上鐵皮，滾來滾去燒烤。

    他們的壽命有半個中劫，無法用人間壽命的時間來計算。


LONG);
	setup();
	replace_program(ROOM);
}
