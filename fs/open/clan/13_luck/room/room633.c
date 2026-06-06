inherit ROOM;
void create() {
	set( "short", "詩劍山莊大門" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room632",
		"west"      : "/open/clan/13_luck/room/room594",
	]) );
	set( "long", @LONG

     
                               ◣            ◢
                             ║■■■■■■■■║
                    ◢══════ 詩劍山莊 ══════◣
                     ║田田║田田║  田田  ║田田║田田║
                     回回回回回回回回回回回回回回回回回回
            ◢■■■■■■■■■■■■■■■■■■■■■■■■■■◣
                ║  田║田田║田田║│▉▉│║田田║田田║田  ║
              回回回回回回回回回回回│▉▉│回回回回回回回回回回回
             =====================◢════◣=====================
          ▄█≡≡≡≡≡≡≡≡≡◢◤════◥◣≡≡≡≡≡≡≡≡≡█▄

 一座朔大的健築物讓你驚奇，此地就是名滿江湖的詩劍山莊所在地‧

LONG);
	setup();
	replace_program(ROOM);
}
