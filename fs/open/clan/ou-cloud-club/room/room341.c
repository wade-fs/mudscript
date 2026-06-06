inherit ROOM;
void create() {
	set( "short", "火蜥蜴屠宰場" );
	set( "light_up", 1 );
	set( "object", ([
		"file2"    : "/open/common/obj/liz_meat",
		"amount5"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/common/obj/liz_meat",
		"amount6"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/common/obj/liz_meat",
		"file10"   : "/open/common/obj/liz_meat",
		"file7"    : "/open/common/obj/liz_meat",
		"file9"    : "/open/common/obj/liz_meat",
		"file8"    : "/open/common/obj/liz_meat",
		"amount9"  : 1,
		"amount10" : 1,
		"file4"    : "/open/common/obj/liz_meat",
		"file3"    : "/open/common/obj/liz_meat",
		"file5"    : "/open/common/obj/liz_meat",
		"amount7"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 11930 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room131",
	]) );
	set( "long", @LONG

              :..                                         :..                                         :..               
              :::                                         :::                                         :::               
              ::                                          ::                                          ::                
              ::        ......                            ::        ......                            ::        ......  
           ...::...''''''''':::.                       ...::...''''''''':::.                       ...::...''''''''':::.
 '::''''''   ::              ::'             '::''''''   ::              ::'             '::''''''   ::              ::'
  ::        ::  .            ::               ::        ::  .            ::               ::        ::  .            :: 
  ::       :'    '::..       ::               ::       :'    '::..       ::               ::       :'    '::..       :: 
  ::     .'        ':::      ::               ::     .'        ':::      ::               ::     .'        ':::      :: 
  ::    '    .        '      ::               ::    '    .        '      ::               ::    '    .        '      :: 
  ::         :::             ::               ::         :::             ::               ::         :::             :: 
  ::         ::              ::               ::         ::              ::               ::         ::              :: 
  ::        :'  '...         ::               ::        :'  '...         ::               ::        :'  '...         :: 
  ::      .:'     '::..      ::               ::      .:'     '::..      ::               ::      .:'     '::..      :: 
 .:'    .'          '::.     ::              .:'    .'          '::.     ::              .:'    .'          '::.     :: 
 ::                   '      ::              ::                   '      ::              ::                   '      :: 
.::                          ::             .::                          ::             .::                          :: 
:::                         .::             :::                         .::             :::                         .:: 
 :'                    '':..:::              :'                    '':..:::              :'                    '':..::: 
                          ':::'                                       ':::'                                       ':::' 
                            ''                                          ''                                          ''  


LONG);
	setup();
	replace_program(ROOM);
}
