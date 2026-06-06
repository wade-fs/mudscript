inherit ROOM;
void create() {
	set( "short", "tooth" );
	set( "owner", "hild" );
	set( "light_up", 1 );
	set( "build", 10054 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room49",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"zsa"       : "/open/clan/sky-wu-chi/room/room256.c",
		"south"     : "/open/clan/sky-wu-chi/room/room230.c",
	]) );
	set( "long", @LONG

            ,,                                ;'
           ';;                         ;  ,,;;;'
            ;;             ,,;;;'  ,,, ;   ,;
            ;;           ,    ;'   ';  ; ,'
            ;;           ;   ,;,,      ,;'
            ;;      ',,  ;,  ;;'      '  ,,,;';,
  ,,,;'     ;;       ';;             ,;'';     ;'
 ;;;'      ,;;                      ;  ,,;;;  ;;
 ''       ';;;                      ;,' ;;    ;'
                                      ,,;;;,,,;
                                             '
LONG);
	setup();
	replace_program(ROOM);
}
