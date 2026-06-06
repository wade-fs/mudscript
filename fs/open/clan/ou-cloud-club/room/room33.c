inherit ROOM;
void create() {
	set( "short", "修‧羅‧界" );
	set( "owner", "del" );
	set( "object", ([
		"file1"    : "/open/killer/obj/k_ring",
		"file2"    : "/open/area/fortress/npc/obj/token",
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"amount2"  : 1,
		"file3"    : "/open/tendo/obj/chaosbelt",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10011 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room232.c",
		"north"     : "/open/clan/ou-cloud-club/room/room88",
		"east"      : "/open/clan/ou-cloud-club/room/room229.c",
		"south"     : "/open/clan/ou-cloud-club/room/room230",
	]) );
	set( "long", @LONG

       ,,      ;;                            ,,,
       ;;;    ;;,,;;,             ;;'';;'';;  ;;;
      ,;;    ,;  ,;;'              ;  '; ,;,,,;'
     ,;' , ,' '';;'                '''''' ,  ''
    ,;;, ;;   ,;'';;,,            ;;     ,;' ';;
   ;' ;; ;;,,'' ;;  ';;;;''      ;' ,;, ,; ,,,,,;''
      ;; ;;   ,;',,            ,;,,,;' ;';   ';,,
      ;; ;;  '  ,;'             ' ;' ;,  ; ''';'
      ;; '   ,,;' ,;;           ,;;''''  ; ,,;;'''
      ;;    ''  ,;;'           ,   , ';  ;   ,;,,,,,
      ;       ,;;'              ;, ''   ,;'''''''''
          ,,;''                 ''      ';


LONG);
	setup();
	replace_program(ROOM);
}
