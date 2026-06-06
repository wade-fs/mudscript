inherit ROOM;
void create() {
	set( "short", "血痕居-地獄道-八熱地獄" );
	set( "owner", "holeman" );
	set( "build", 10246 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room530.c",
		"north"     : "/open/clan/sky-wu-chi/room/room529.c",
		"southeast" : "/open/clan/sky-wu-chi/room/room536",
		"northeast" : "/open/clan/sky-wu-chi/room/room534.c",
		"up"        : "/open/clan/sky-wu-chi/room/room298.c",
		"northwest" : "/open/clan/sky-wu-chi/room/room533.c",
		"southwest" : "/open/clan/sky-wu-chi/room/room535.c",
		"south"     : "/open/clan/sky-wu-chi/room/room532.c",
		"east"      : "/open/clan/sky-wu-chi/room/room531.c",
	]) );
	set( "long", @LONG

    惡趣的眾生，是因為行不善業，特別是因貪、瞋、癡所造的惡業
，而墮落到輪迴中最痛苦、最黑暗的地方。尤其是地獄道，從墮入開
始到離開的期間，只有無比的痛苦，沒有任何快樂可言。地獄的眾生
就像大地灰塵一樣多，他們之所以會墮入地獄，大部分是因為前世常
用瞋恨心傷害眾生，讓眾生痛苦，不管是用肢體、語言或其他方式傷
害，都變成墮入地獄的因。


LONG);
	setup();
	replace_program(ROOM);
}
