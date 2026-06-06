inherit ROOM;
void create() {
	set( "short", "稅捐處" );
	set( "owner", "officer" );
	set( "object", ([
		"file1"    : "/open/fire-hole/obj/g-pill",
		"amount1"  : 123,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room400",
	]) );
	set( "build", 10157 );
	set( "light_up", 1 );
	set( "long", @LONG
國立中央大學最近話題不斷，繼蔣公銅像斷頭事件，又有老師主持的網
站，竟然有人獸交的照片，校方認為有辱校譽，打算追究負責老師何春蕤，
這個爭議網站目前已經被教育部關閉了在學術界和兩性話題上，頗受爭議的
中央大學性別研究室，最近又遭人檢舉，在網路上，刊登人獸雜交照片

LONG);
	setup();
	replace_program(ROOM);
}
