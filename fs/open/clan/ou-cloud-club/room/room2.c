// Room : /open/clan/ou-cloud-club/room/room2.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG

                                      oo$$
                                    o    $
                            o$$$$o$     $$
                        oo   o$o$      $$
                oo   oo      $$       $$ 
              o$  $o       o o      o$  
            o$     $    o$$ $$$   o$  $$
           $oo o   $$o$$  o$$ $$o$  o$$$o
                $ $o  $o  o$  $$$  o$ o$$$o
                  $$$o $$  $$$ oo$$  o$ o$ $oo
                 $$o$$o$$o$o$$$   oo$$$$  o$  $$$o
                $ $$o$$$$$$$o$o$$$$$$$ o$          $oo
               o$$o$o$ $ $ $ $ o$o$$                  $o
             o$  o    $$$ $             o   oo$o        $o
           o $  o  o o o            o$o$o    $  $o$ooo   $$o
         o$  o o    o o     o  o  o  $   $o$      ooo$     $$
        o$  o     o oo     o         o$o   ooo $  $          $o
       $          o$ o   o          o$  o  $    o  $ooo       $$
     o$          $$  o  o          $  o$ $  oooo$        $o    $$o
     $            $   o   o       $   $oo$o     oooo $  $  $    $$
    $       $$    o           o   $$          $    $  o $$ $     $o
   $        $o      o                $ o$  $o $o    o $$  o$     $$
   $    o   $  o        o  o     o          $o $ooo$    o$        $
   o        $o  o  o       o$         $o$          ooo o$o        $o
   $        $$ o            $          $ooooooo $$   $$          $$o
   $$    o   $$    o        $o            o   $o$               o$$o o 
   o$o    o  o $   o  o      $$oo       o                      o$$ oo$o$ o
   $$$$o   o o     o o  o  o                  o              o$$  $ ooo o o
       $$oo  o     o o  o   o         o   o               oo$$$       o oo o
      o o$$$$ooo o o    o    o$oo                   o oo$$$ ooo $    $  o o
         o o  $$ $$o$o$oooo$ o  $$$$o$oo$oooooooo$o$o$$ $ $ $ $ $o   o o
                    $ $$$$$$$$$ $   $ $ o $$    $ $ $ $ $           $ o
                    $o oo o o      $  oo $          o o o          o
                       o ooo          o oo  o         ooooo o     
                                       o o          

LONG);
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "short", "$HIC$傲雲$HIR$錢莊$NOR$" );
	set( "object", ([
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount7"  : 1,
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/obj/master_snake_head",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/master_snake_head",
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"amount10" : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"amount8"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/magic-manor/obj/master_snake_head",
		"file7"    : "/open/magic-manor/obj/master_snake_head",
		"amount1"  : 1,
		"amount5"  : 1,
	]) );
	set( "item_desc", ([
		"board" : @ITEM
c_deposit          幫派錢莊存錢(暫時存入，還能領出)
c_donate           幫派錢莊捐錢(不能在領出，貢獻給幫派)
要c_donate前需先c_deposit存入才行
ITEM,
	]) );
	set( "build", 11604 );
	set( "exits", ([ /* sizeof() == 1 */
		"east"      : "/open/clan/ou-cloud-club/room/hall.c",
]) );
	set( "light_up", 1 );
	setup();

	}
