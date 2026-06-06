// Room : /open/clan/ou-cloud-club/room/room24.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
你來到一個空間極度異常的區域‧‧‧只見周圍有著
八個拱型的洞，並且透發出七彩光芒，難道這裡就是本莊
的奇象之一【$HBBLU$八$HBYEL$方$HBRED$殺$HBCYN$靈$HBGRN$道$NOR$】，據說這裡是為了讓幫眾更受
一層的試煉，所以本莊莊主便以任令空間切割的功力，將
此區域分為八個空間，並通往八個神秘的世界，除此之外
，老一輩的長老還說，八個通道最後會到達一個最終的區
域，而且竟然連莊主本人也未到達，而那個神秘的區域可
以令任何人得到驚濤駭俗、傾覆天下的能力‧‧‧


                    $HIY$天界$NOR$
                 
              $HIC$龍界$NOR$         $HIM$幻界$NOR$       
         
        $YEL$天竺$NOR$     $HBBLU$八$HBYEL$方$HBRED$殺$HBCYN$靈$HBGRN$道$NOR$      $CYN$朝鮮$NOR$

              $HIB$靈界$NOR$         $HIG$妖界$NOR$  

                    $HIR$地獄$NOR$



LONG);
	set( "short", "$HBBLU$八$HBYEL$方$HBRED$殺$HBCYN$靈$HBGRN$道$NOR$" );
	set( "owner", "snowy" );
	set( "object", ([
		"amount9"  : 1,
		"file4"    : "/open/gsword/obj1/bbladeball",
		"amount7"  : 1,
		"file3"    : "/open/gsword/obj1/bbladeball",
		"file7"    : "/open/gsword/obj1/blosword",
		"file1"    : "/open/gsword/obj1/bbladeball",
		"file9"    : "/open/gsword/obj1/blosword",
		"amount2"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/gsword/obj1/bbladeball",
		"amount1"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10030 );
	set( "clan_room", "傲雲山莊" );
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 3 */
		"west"      : "/open/clan/ou-cloud-club/room/room25.c",
		"down"      : "/open/clan/ou-cloud-club/room/room22",
		"north"     : "/open/clan/ou-cloud-club/room/room12.c",
]) );
	set( "light_up", 1 );
	setup();

	}
