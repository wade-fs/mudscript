inherit ROOM;
void create() {
	set( "short", "貓房" );
	set( "owner", "cong" );
	set( "object", ([
		"amount5"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/magic-manor/obj/magic-sign",
		"amount1"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
		"file6"    : "/open/wu/npc/obj/armband",
		"amount2"  : 1,
	]) );
	set( "build", 10052 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room95.c",
		"east"      : "/open/clan/sky-wu-chi/room/room225.c",
		"north"     : "/open/clan/sky-wu-chi/room/room224.c",
		"out"       : "/open/clan/sky-wu-chi/room/room120.c",
		"west"      : "/open/clan/sky-wu-chi/room/room223.c",
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
