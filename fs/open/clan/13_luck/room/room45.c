inherit ROOM;
void create() {
	set( "short", "湖邊小屋" );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room690",
	]) );
	set( "object", ([
		"amount10" : 1,
		"amount5"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file9"    : "/open/prayer/obj/boris-boots",
		"amount4"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/scholar/obj/icefan",
		"amount3"  : 1,
		"amount6"  : 1,
		"file6"    : "/daemon/class/fighter/figring",
		"amount2"  : 1,
		"file8"    : "/open/mogi/castle/obj/lochagem",
		"file7"    : "/daemon/class/blademan/obj/shield",
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"amount8"  : 1,
		"file2"    : "/daemon/class/bonze/puty_pullium",
		"amount7"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10092 );
	set( "long", @LONG

  $HIY$ .            
  $HIY$   \ _ /    $HIW$ .-='-. $HIR$_db_     $HIW$ .--==-,
  $HIY$ -= (_) =-  $HIW$(_  (  $HIR$_IIII_   $HIW$_(    )  `.
  $HIY$   /   \    $HIW$  (    $HIR$|    |$HIW$-.(  ` ,_  `  )
  $HIY$     '      $HIW$   '-._$HIR$HHHHHH$HIW$  `)---' `'--'    $NOR$$WHT$=.=$NOR$
  $HIR$                   |.   |$HIW$--`                    $NOR$$WHT$=.=$NOR$
  $HIR$                   |    |     $NOR$$WHT$ =.=$NOR$
  $HIR$         _H___,=====;___|           $NOR$$WHT$=.=$NOR$
  $HIR$      n_/____/____/``\__\$NOR$
  $HIR$     /__|:: :|. .|:::|::|     $NOR$$WHT$             =.=$NOR$
  $HIR$  _%&|__&%_ _|_ _|_ H|__|__$NOR$
  $HIG$ jgs` ;;;;` ;;;;' ;;' ';;;;``;;-.$NOR$
  $HIG$ .  ' ` ;;'  `;;;  `;'   `;  .`' `\$NOR$
  $HIG$ . '  .  `' .  `';.    '   .   .  |$HIC$^-`^~_^^~``-^^_~^^-`^~$NOR$
  $YEL$    '    `    `      '   `    '   ;$HIB$_~ -   _-~  _`  ~  -_ `$NOR$


    $HIW$一間樸實的湖邊小屋，四周的風景有如畫一般地美麗，湖水拍打
的岸邊，空中的鳥兒愉悅地展翅翱翔，坐在沙灘上欣賞著水天一色的
美景，傾聽浪花拍岸海鳥爭鳴交織而成的天賴，多麼愜意，在屋旁正
有一個人盤坐在樹下，這個人難道就是傳說中的..........。$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
