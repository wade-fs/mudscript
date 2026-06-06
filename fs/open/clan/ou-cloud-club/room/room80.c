// Room : /open/clan/ou-cloud-club/room/room80.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "月球" );
	set( "object", ([
		"file8"    : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"file5"    : "/open/main/room/sp/stone",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/gsword/obj1/sadsword",
		"file7"    : "/obj/gift/shenliwan",
		"file9"    : "/obj/gift/xisuidan",
		"amount7"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file4"    : "/open/gsword/obj1/blosword",
		"amount8"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10140 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room193.c",
		"enter"     : "/open/clan/ou-cloud-club/room/room574",
	]) );
	set( "no_clean_up", 0 );
	set( "long", @LONG
. ． . ． . ． . ． . ． . ． . ． . ． . ． . ． . ． . ． . ． . ． . ． . ． 
.你照片還在床頭 卻在你摔上電話之後 看得我心痛 當你後悔傷了我 已褪色的玫瑰卻沒.  
 有恢復成鮮紅  I LOVE YOU   你說得太多 而抱歉能代表什麼 你知道我是愛你的 但是 . 
.那又怎麼樣呢 難道你就可以利用我的捨不得 反覆把我傷得透徹 我知道 你是愛我的但.  
.是 那又怎麼樣呢 難道我就該對你無止盡的寬赦 任你把愛情變成負荷    ＹＯＫＯ    . 
 .╭────────█◤█ ███ ◣  ◢ █  █ █◤█ ███───────╮.  
. │+   +   +   +   █     █  █ ▋  █ █◢█ █◢█   █ +   +   +   +  │ . 
 .│  +   +   +   + ◥◤█ █  █ █◣█ █◤█ █◤█   █  那又怎麼樣呢？│   
．╰────────█◢█ █◢█ █  ◣ █  █ █  █   █────────╯ . 

LONG);
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	setup();

	}
