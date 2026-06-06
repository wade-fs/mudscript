inherit ROOM;
void create() {
	set( "short", "$HIM$公$HIG$開$HIB$亭$NOR$" );
	set( "build", 10040 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room255",
		"south"     : "/open/clan/time-limit/room/room196.c",
		"north"     : "/open/clan/time-limit/room/room199.c",
	]) );
	set( "long", @LONG
公開亭是一個大涼亭,經常有武林人士聚集,討論最近武林發生了什麼事,一旁的佈告
欄則為貼佈告之用,最常出現的佈告莫過於挑戰書了,果然佈告欄上正貼著白馬縱橫挑
戰炎熇兵燹的佈告,秦假先搬出張桌子充當莊家,準備要大賭一番,業途靈則穿梭在人
群中收錢,笑得合不攏嘴

LONG);
	setup();
	replace_program(ROOM);
}
