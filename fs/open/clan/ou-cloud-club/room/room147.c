inherit ROOM;
void create() {
	set( "short", "棄刀塚" );
	set( "owner", "del" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"amount4"  : 9,
		"file3"    : "/open/killer/memory/static",
		"amount5"  : 1,
		"file1"    : "/open/killer/memory/static",
		"file8"    : "/open/scholar/obj/icefan",
		"file4"    : "/open/mon/obj/mon-pill",
		"amount1"  : 1,
		"file2"    : "/open/killer/memory/static",
		"file10"   : "/open/capital/obj/4-4",
		"amount8"  : 1,
		"file5"    : "/open/killer/memory/static",
		"amount10" : 1,
		"amount6"  : 1,
		"file6"    : "/obj/gift/lingzhi",
	]) );
	set( "light_up", 1 );
	set( "build", 10095 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room88",
		"east"      : "/open/clan/ou-cloud-club/room/room191.c",
	]) );
	set( "long", @LONG

            ;,
          ,,,;;,,;,,                                ';;,   ;,,,,,;'';;,
       '''';;' ,,              ,,,,,,,,;;;;;;,       ;;   ,;'      ;;'''
        ,,;;,;''';             ''' ;;;     ;;'       ;;   '' ;;;;''
       ,;   ;;  ;;',,,,            ;;      ;;     ,,,,;;;'  ,;;'   ;;,
   ,,,,,;;,';;'';'''''''          ;;      ;;'        ';   ,;';;,  ;;'
        ';,,;;,;;                ;;'      ;;          ;,,,,,,;';;'
         '  ;;,,,,,,,          ,;;       ,;;      ,,,;;'  ;;; ;;;;;,
     ''''';;;;;,    '         ,;'    ,, ,;;      ';''    '  ;;' ;;';;;,,,
        ,;;';;';;,,        ,''        ';;;'               ,;'  ;;;  '''
      ,;''  ;;  ';;;;,,,               ''                '   ;,;;'
    ''      ;;    ''''''                                      '''


LONG);
	setup();
	replace_program(ROOM);
}
