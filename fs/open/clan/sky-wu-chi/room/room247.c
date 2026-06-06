inherit ROOM;
void create() {
	set( "short", "旺仔房" );
	set( "owner", "hild" );
	set( "build", 1 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"east"      : "/open/clan/sky-wu-chi/room/room248.c",
	]) );
	set( "light_up", 1 );
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
