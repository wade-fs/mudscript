inherit ROOM;
void create() {
	set( "short", "$HIG$康適美$NOR$" );
	set( "owner", "dracula" );
	set( "object", ([
		"amount8"  : 137,
		"file8"    : "/open/mogi/castle/obj/sspill",
		"amount3"  : 751,
		"amount1"  : 378,
		"file4"    : "/open/doctor/pill/sky_pill",
		"file10"   : "/open/magic-manor/ghost/obj/trigram-pill",
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount9"  : 566,
		"amount5"  : 678,
		"amount10" : 15,
		"file7"    : "/open/doctor/pill/human_pill",
		"amount4"  : 274,
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount2"  : 2821,
		"file5"    : "/open/fire-hole/obj/y-pill",
		"file6"    : "/open/doctor/pill/gnd_pill",
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 44,
		"file1"    : "/open/fire-hole/obj/p-pill",
		"amount6"  : 296,
	]) );
	set( "build", 14592 );
	set( "exits", ([
		"enter"     : "/open/clan/ou-cloud-club/room/room87",
	]) );
	set( "long", @LONG

                             ':::.              
             .... .....:::::  ::::              
        :.::'':::' ::'   ::'  :::'   ':..       
        '::   ::'  ':. ..::    ::     ':::.     
         ::...::    ::''''     ::       ''      
         ':''          ..      ::.              
              .....:::'::::.   '::   .....      
         ':::'''':::    :::'   .:::::'''        
           ::....:::::::::: ':''::'     ..      
           :::''':::    ::       ::     ::::    
           '::   :::...:::       ::.    :::'    
            ::::::::'''''         ::   :::'     
                 :::              :::.:::       
              ...:::::::::::       :::::        
      .::::::::'':::'              .:::         
         '       :::             .::::::.       
                 :::           .::'   ':::.  :: 
                 :::        ..:''      '::::::: 
                 :::      .'''           '::::: 
                  '                         ':::

LONG);
	setup();
	replace_program(ROOM);
}
