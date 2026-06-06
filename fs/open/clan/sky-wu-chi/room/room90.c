inherit ROOM;
void create() {
	set( "short", "$HIR$妖刀$HIG$村雨$HIB$ソ塚$NOR$" );
	set( "owner", "hild" );
	set( "object", ([
		"file10"   : "/open/mogi/dragon/obj/key",
		"amount2"  : 1,
		"file6"    : "/open/mogi/mountain/obj/frog-pill",
		"file1"    : "/open/capital/obj/mark",
		"amount9"  : 1,
		"file8"    : "/open/poison/obj/gall",
		"amount4"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/main/obj/unarmed-b",
		"amount10" : 1,
		"amount8"  : 1,
		"file3"    : "/open/gsword/obj1/bloodsword",
		"file9"    : "/open/capital/obj/4-2",
		"amount1"  : 1,
		"file4"    : "/open/area/house/npc/obj/red-stone",
		"amount5"  : 1,
		"file2"    : "/open/soldier/obj/blood",
		"amount3"  : 1,
	]) );
	set( "build", 10004 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room73.c",
		"north"     : "/open/clan/sky-wu-chi/room/room243",
	]) );
	set( "long", @LONG

       ';,       ,;;,                                             ,,,,         
        ;;         ;;           ,,;;;;;;;;;          ,,       ,;'''  ;;        
        ;;         ;;        ';;''''                 ;;    ,,        ''        
       ,;;;;;;  ,,,;;;;;;          ;,                ;;,,  ;                   
 ,,,,;;';    ;;;'  ;;              ,;,,,,,,,,,,    ,;;;''     ;;;;             
 '''' ,;;          ;;         ,,;;';;'''     ;;      ;'      ,;;'    ,         
     ,; ;,'  ,,,,, ;;        ''    ';  ,;    ;;;     ; ,   ,;';;,  ,;'         
    ;',;;     ,;;' ;;     ;;    ;'  ;  ;,,   ;;    ,,;'    ,,;';;; ',,         
   ;;;' ;          ;;     ;;,  ,,,' ;   ''  ,;;   '''      '';;';;  ';;;       
   ''';;;;     ,,  ;;     ;;;   '        ,,,;;'             ,;' ;;   ''        
       ';;      ';;;;      '             ''''               ;,,,;'             
                   ''                                         '                
LONG);
	setup();
	replace_program(ROOM);
}
