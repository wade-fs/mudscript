inherit ROOM;
void create() {
	set( "short", "血痕居-英雄廳" );
	set( "owner", "holeman" );
	set( "build", 10774 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room305.c",
		"north"     : "/open/clan/sky-wu-chi/room/room513.c",
		"south"     : "/open/clan/sky-wu-chi/room/room515",
		"east"      : "/open/clan/sky-wu-chi/room/room516.c",
		"up"        : "/open/clan/sky-wu-chi/room/room519.c",
		"west"      : "/open/clan/sky-wu-chi/room/room517.c",
	]) );
	set( "long", @LONG

血是男兒血  夢是男兒夢  放眼江湖誰敢爭鋒  誰敢爭鋒  舉世稱英雄

多少男兒情  盡在俠義中  蕩盡人間事不平  事不平  江湖義氣重

血是男兒血  夢是男兒夢  放眼江湖誰敢爭鋒  舉世稱英雄

多少男兒情  盡在俠義中  蕩盡人間事不平  江湖義氣重

騎快馬 開硬弓  豪情  刀厚重 劍輕靈  要做就做大英雄



LONG);
	setup();
	replace_program(ROOM);
}
