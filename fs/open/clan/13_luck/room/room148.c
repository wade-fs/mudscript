inherit ROOM;
void create() {
	set( "short", "沙漠" );
	set( "owner", "apple" );
	set( "object", ([
		"file8"    : "/open/fire-hole/obj/b-pill",
		"file7"    : "/open/ghost-hole/obj/fire-spirit",
		"file1"    : "/open/mon/obj/mon-pill",
		"amount8"  : 707,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 263,
		"amount9"  : 14,
		"amount4"  : 159,
		"file5"    : "/open/mon/obj/thousand-nectar",
		"file4"    : "/open/ping/obj/poison_pill",
		"amount6"  : 191,
		"amount7"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 60,
		"file6"    : "/open/fire-hole/obj/g-pill",
		"file9"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 119,
		"amount5"  : 11,
	]) );
	set( "build", 12214 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room54",
	]) );
	set( "long", @LONG
你在不知不覺中走到了這片荒無的沙漠，已不知身
處在何方，放眼望去一片沙地，讓身處在這的你不知該
往何處走去，這時在你的身旁吹起了一陣狂風，好像在
警示你踏入了不該踏入的領域，你鼓起了勇氣逆著狂風
，尋找著這陣狂風的源頭，這時你發現在狂風中有一處
異象，於是你向著這個未知地前進。
LONG);
	setup();
	replace_program(ROOM);
}
